#include "mainwindow.h"
#include <QDebug>
#include <QSettings>
#include <QTimer>
#include "canbus.h" // Підключаємо CanBus
#include "cannelloniframe.h"
#include "canthread.h"
#include "scalehorizontal.h"
#include "scalevertical.h"
#include "scriptcommands.h"
#include "structs.h"
#include "ui_mainwindow.h"
#include "biascalibration.h"
#include <opencv2/opencv.hpp>
#include <fstream>

VideoThread::VideoThread(QObject *parent)
    : QThread(parent)
    , running(false)
    , horizontMarkerValue(0)
    , verticalMarkerValue(0)
{}

VideoThread::~VideoThread()
{
    stop();
}

void VideoThread::setPipeline(const std::string &pipeline)
{
    gstPipeline = pipeline;
}

void VideoThread::setHorizontMarkerValue(float value)
{
    if (value > 30) {
        horizontMarkerValue = 30;
    } else if (value < -30) {
        horizontMarkerValue = -30;
    } else {
        horizontMarkerValue = value;
    }
    emit horizontMarkerValueChanged(static_cast<int>(horizontMarkerValue));
}

void VideoThread::setVerticalMarkerValue(float value)
{
    if (value > 30) {
        verticalMarkerValue = 30;
    } else if (value < -30) {
        verticalMarkerValue = -30;
    } else {
        verticalMarkerValue = value;
    }
    emit verticalMarkerValueChanged(static_cast<int>(verticalMarkerValue));
}

void VideoThread::run()
{
    running = true;
    cap.open(gstPipeline, cv::CAP_GSTREAMER);

    if (!cap.isOpened()) {
        qDebug() << "Cannot open the stream";
        emit frameReady(QImage());
        return;
    }

    ScaleVertical scaleVertical;
    ScaleHorizontal scaleHorizontal;
    //double angle = 0; // Кут обертання у градусах

    cv::Mat frame;
    while (running) {
        cap >> frame;
        if (frame.empty())
            continue;


        // Визначення чорних смуг і автоматичне встановлення ROI по першому кадру
        if (!roiSet)
        {
            videoConfig = loadVideoConfig();

            //initROIFromConfig();
            //videoConfig.roi = initROIAutoDetect(frame);

            videoConfig.fullFrame = cv::Rect(0, 0, frame.cols, frame.rows); // Запам'ятати повний кадр для оптичного перехрестя

        }



        // Якщо ROI вже знайдено — обрізаємо кадр
        if (roiSet && videoConfig.roi.width > 0 && videoConfig.roi.height > 0 &&
            videoConfig.roi.x >= 0 && videoConfig.roi.y >= 0 &&
            videoConfig.roi.x + videoConfig.roi.width <= frame.cols &&
            videoConfig.roi.y + videoConfig.roi.height <= frame.rows)
        {
            frame = frame(videoConfig.roi);
        }



        // Draw crosshair in the center
        //cv::Point center(frame.cols / 2, frame.rows / 2);
        videoConfig.opticalCenter = cv::Point(videoConfig.fullFrame.width / 2 - videoConfig.roi.x,
                                              videoConfig.fullFrame.height / 2 - videoConfig.roi.y); // оптичне (юстоване) перехрестя. Визначається з повного кадру (необрізаного)

        cv::Point center = videoConfig.opticalCenter;

        // Якщо кадр обрізаний, перераховуємо координати центру в межах ROI
        //cv::Point center(videoConfig.opticalCenter.x - videoConfig.roi.x,
        //                 videoConfig.opticalCenter.y - videoConfig.roi.y);


        cv::Scalar crossColor(255, 255, 0); // Червоний колір
        int thickness = 1;
        int length = 250;

        // Horizontal line
        cv::line(frame,
                 cv::Point(center.x - length, center.y),
                 cv::Point(center.x + length, center.y),
                 crossColor,
                 thickness);

        // Vertical line
        cv::line(frame,
                 cv::Point(center.x, center.y - length),
                 cv::Point(center.x, center.y + length),
                 crossColor,
                 thickness);

        // Центр в обрізаному кадрі (просто для порівняння)
        center = cv::Point(frame.cols / 2, frame.rows / 2);
        crossColor = cv::Scalar(255, 0, 0); // Червоний колір
        thickness = 1;
        length = 25;

        // Horizontal line
        cv::line(frame,
                 cv::Point(center.x - length, center.y),
                 cv::Point(center.x + length, center.y),
                 crossColor,
                 thickness);

        // Vertical line
        cv::line(frame,
                 cv::Point(center.x, center.y - length),
                 cv::Point(center.x, center.y + length),
                 crossColor,
                 thickness);

        // Малювання ВПЗ
        if(!isSwitched){
            cv::Rect rectV2 = getVideo2RectInVideo1(videoConfig);
            cv::rectangle(frame, rectV2, cv::Scalar(0, 0, 255), 1);
        }


        // Draw the scale and markers


        // if(isRotated){
        //     scaleVertical.drawScaleRotated(frame, cv::Scalar(0, 0, 0), 2, STROKED, verticalMarkerValue);
        //     scaleHorizontal.drawScale(frame, cv::Scalar(0, 0, 0), 2, STROKED, horizontMarkerValue);

        // }
        // else{
        //     scaleVertical.drawScale(frame, cv::Scalar(0, 0, 0), 2, STROKED, verticalMarkerValue);
        //     scaleHorizontal.drawScale(frame, cv::Scalar(0, 0, 0), 2, STROKED, horizontMarkerValue);
        // }

        //cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
        QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        emit frameReady(image.copy());

        emit frameSizeAvailable(frame.cols, frame.rows, videoConfig); // передаємо розміри кадра для кліка мішкою
    }

    cap.release();
}

void VideoThread::stop()
{
    running = false;
    wait();
}


// std::map<std::string, int> VideoThread::readROIConfig(const std::string& filename) {

//     std::map<std::string, int> roiParams = { {"x",0}, {"y",0}, {"width",0}, {"height",0} };

//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         std::cerr << "Не вдалося відкрити файл: " << filename << std::endl;
//         return roiParams;
//     }

//     std::string line;
//     while (std::getline(file, line)) {
//         if (line.empty() || line[0] == '[') continue;
//         size_t eqPos = line.find('=');
//         if (eqPos != std::string::npos) {
//             std::string key = line.substr(0, eqPos);
//             int value = std::stoi(line.substr(eqPos+1));
//             roiParams[key] = value;
//         }
//     }
//     return roiParams;
// }

// void VideoThread::initROIFromConfig() {
//     auto roiParams = readROIConfig("C:/qt_projects/git/VIDEO_GUI/config.ini");
//     roi = cv::Rect(roiParams["x"], roiParams["y"], roiParams["width"], roiParams["height"]);
//     roiSet = true;
// }

VideoConfig VideoThread::loadVideoConfig() {
    VideoConfig cfg{};
    QString path = QCoreApplication::applicationDirPath() + "/config.ini";
    QSettings settings(path, QSettings::IniFormat);

    // ROI
    settings.beginGroup("ROI");
    int x = settings.value("x", 0).toInt();
    int y = settings.value("y", 0).toInt();
    int w = settings.value("width", 0).toInt();
    int h = settings.value("height", 0).toInt();
    settings.endGroup();
    cfg.roi = cv::Rect(x, y, w, h);

    roiSet = true;

    // Video1
    settings.beginGroup("Video1");
    cfg.fovVideo1.width  = settings.value("w", 0.0).toFloat();
    cfg.fovVideo1.height = settings.value("h", 0.0).toFloat();
    settings.endGroup();

    // Video2
    settings.beginGroup("Video2");
    cfg.fovVideo2.width  = settings.value("w", 0.0).toFloat();
    cfg.fovVideo2.height = settings.value("h", 0.0).toFloat();
    settings.endGroup();
    return cfg;
}


cv::Rect VideoThread::initROIAutoDetect(cv::Mat frame){
    cv::Rect roi;
    // Конвертація в ч/б
    cv::Mat gray;
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, gray, cv::Size(5, 5), 0);

    // Пошук контурів
    cv::Mat thresh;
    cv::threshold(gray, thresh, 0, 255, cv::THRESH_BINARY + cv::THRESH_OTSU);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(thresh, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    if (!contours.empty()) {
        // Найбільший контур
        size_t largestContourIdx = 0;
        double maxArea = 0;
        for (size_t i = 0; i < contours.size(); ++i) {
            double area = cv::contourArea(contours[i]);
            if (area > maxArea) {
                maxArea = area;
                largestContourIdx = i;
            }
        }

        roi = cv::boundingRect(contours[largestContourIdx]);
        roiSet = true;
    }
    return roi;
}

cv::Rect VideoThread::getVideo2RectInVideo1(const VideoConfig& cfg) {
    // пікселі на градус
    float pxPerDegX = cfg.roi.width  / cfg.fovVideo1.width;
    float pxPerDegY = cfg.roi.height / cfg.fovVideo1.height;

    // розміри Video2 в пікселях
    int video2WidthPx  = static_cast<int>(pxPerDegX * cfg.fovVideo2.width);
    int video2HeightPx = static_cast<int>(pxPerDegY * cfg.fovVideo2.height);

    // координати верхнього лівого кута (по центру)
    int x = cfg.opticalCenter.x - video2WidthPx/2;
    int y = cfg.opticalCenter.y - video2HeightPx/2;

    return cv::Rect(x, y, video2WidthPx, video2HeightPx);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , videoThread1(nullptr)
    , videoThread2(nullptr)
    , canBus(nullptr)
    , rotationAngle(0)
    ,
    /*messageQueue(localMessageQueue),*/ localMessageQueue(1000)
{
    ui->setupUi(this);



    connect(ui->measure_mode,
            &QComboBox::currentIndexChanged,
            this,
            &MainWindow::onMeasureModeChanged);
    onMeasureModeChanged(ui->measure_mode->currentIndex());

    connect(ui->frequency_mode,
            &QComboBox::currentIndexChanged,
            this,
            &MainWindow::onFrequencyModeChanged);
    onFrequencyModeChanged(ui->frequency_mode->currentIndex());

    on_start_b_clicked(); // Start video on launch

    connect(videoThread1, &VideoThread::frameSizeAvailable, this, &MainWindow::onFrameSizeAvailable);
    connect(videoThread2, &VideoThread::frameSizeAvailable, this, &MainWindow::onFrameSizeAvailable);

    videoLabel = qobject_cast<ClickableLabel*>(ui->videoLabel);
    videoLabel->setDebugLabel(ui->labelOutput);

    connect(ui->videoLabel, &ClickableLabel::clickedAt, this, &MainWindow::onLabelClicked);



    // // Встановлюємо позначки під слайдером
    // ui->horizontalSlider->setTickPosition(QSlider::TicksBelow);
    // ui->horizontalSlider->setTickInterval(10);  // Інтервал між позначками
    // ui->horizontalSlider->setRange(-30, 30);    // Встановлюємо діапазон слайдера

    // // Додаємо підписи вручну через QLabel
    // int min = -30;
    // int max = 30;
    // int step = 10;

    // // Зачекаємо, поки слайдер буде повністю відображений, щоб отримати коректну ширину
    // QTimer::singleShot(0, [=]() {
    //     int sliderWidth = ui->horizontalSlider->width();
    //     QFontMetrics fm(this->font()); // Отримуємо метрики шрифту для обчислення ширини тексту

    //     for (int i = min; i <= max; i += step) {
    //         QLabel *label = new QLabel(QString::number(i), this);
    //         label->setAlignment(Qt::AlignCenter);

    //         // Обчислюємо бажану позицію центру лейбла
    //         double ratio = static_cast<double>(i - min) / (max - min);
    //         int centerPos = static_cast<int>(ratio * sliderWidth);

    //         // Отримуємо ширину тексту лейбла
    //         int textWidth = fm.horizontalAdvance(label->text());
    //         int labelHalfWidth = textWidth / 2;

    //         // Встановлюємо позицію лівого краю лейбла, щоб його центр був на потрібному місці
    //         int xPos = ui->horizontalSlider->x() + centerPos - labelHalfWidth;
    //         int yPos = ui->horizontalSlider->y() + ui->horizontalSlider->height();

    //         label->move(xPos, yPos);
    //         label->show();
    //     }
    // });



    // Ініціалізація CanBus
    canBus = new CanBus(this);

    connect(canBus, &CanBus::packetReceived, this, [this](const QByteArray &packetData) {
        // Перетворення отриманого пакету в hex і виведення в консоль
        QString hexString = canBus->toHexString(packetData);
        qDebug() << "Received CAN packet:" << hexString;

        try {
            // обробка пакета канелоні
            CannelloniFrame frame(packetData);

            QMutexLocker locker(&queueMutex); // Блокуємо доступ до черги

            activeRx = 50;

            // Отримуємо тимчасову чергу з кадру
            std::queue<std::vector<uint8_t>> frameQueue = frame.GetMessageQueue();

            // Додаємо всі повідомлення в спільну чергу
            while (!frameQueue.empty()) {
                localMessageQueue.push(frameQueue.front());
                frameQueue.pop();
            }
        } catch (const std::exception &e) {
            qWarning() << "Error parsing CannelloniFrame:" << e.what();
        }
    });

    parserWorker = new CANParserWorker();

    parserThread = new QThread();
    parserWorker->moveToThread(parserThread);

    connect(parserThread, &QThread::started, parserWorker, &CANParserWorker::process);
    // connect(parserWorker, &CANParserWorker::messageParsed, this, []() {
    //     qDebug() << "Message parsed in worker.";
    // });
    // connect(parserWorker, &CANParserWorker::parseError, this, [](const QString &err) {
    //     qWarning() << err;
    // });

    parserThread->start();

    // Ініціалізація CanThread
    //canThread = new CANThread(&queueMutex, &localMessageQueue);

    QTimer *queueTransferTimer = new QTimer(this);
    connect(queueTransferTimer, &QTimer::timeout, this, [this]() {
        QMutexLocker locker(&queueMutex);

        std::vector<uint8_t> msg;
        int maxMsgs = 100; // optional cap per cycle

        for (int i = 0; i < maxMsgs && localMessageQueue.pop(msg); ++i) {
            parserWorker->enqueueMessage(msg);
        }



        // while (!localMessageQueue.empty()) {
        //     //parserWorker->enqueueMessage(localMessageQueue.front());
        //     localMessageQueue.pop();
        // }
    });
    queueTransferTimer->start(10); // Кожні 10 мс перевіряє чергу

    // Стартуємо прийом пакету
    canBus->startReceiving();
    //canThread->start();

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateLpsParametersUI);
    updateTimer->start(100);


}

MainWindow::~MainWindow()
{
    // Зупинка відео потоків
    on_stop_b_2_clicked();

    // Зупинка CanBus
    if (canBus) {
        canBus->stopReceiving();
        delete canBus;
    }
    if (canThread) {
        canThread->stop();
        delete canThread;
    }



    parserThread->quit();
    parserThread->wait();
    parserWorker->deleteLater();
    parserThread->deleteLater();

    delete ui;
}

QString MainWindow::circleHtml(bool active, const QString& label) {
    QString color = active ? "green" : "red";
    return QString("<span style='color:%1;font-size:14pt;'>●</span> %2")
        .arg(color).arg(label);
}

void MainWindow::setRxActive(bool active) {
    ui->rxLabel->setText(circleHtml(active, "RX"));
}

void MainWindow::setTxActive(bool active) {
    ui->txLabel->setText(circleHtml(active, "TX"));
}

void MainWindow::onLabelClicked(QPoint pos)
{
    //qDebug() << "Клік у QLabel на позиції:" << pos;
    //PixelToAngleConverter converter(videoLabel->width(), videoLabel->height(), 8.0, 6.0);
}

void MainWindow::onFrequencyModeChanged(int index)
{
    float frequency[8] = {1, 2, 5, 10, 20, 25, 0.5, 0.1};
    uint periodInMicrosec = static_cast<uint>(std::round((1.0 / frequency[index]) * 1e6));

    std::vector<uint8_t> byteArray(sizeof(periodInMicrosec));
    for (int i = 0; i < sizeof(periodInMicrosec); ++i) {
        byteArray[i] = (periodInMicrosec >> (i * 8)) & 0xFF;
    }

    std::reverse(byteArray.begin(), byteArray.end());

    std::vector<uint8_t> pld = {0x00, 0x02, 0x04, 0x00};
    pld.insert(pld.end(), byteArray.begin(), byteArray.end());
    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x248, 0x08, pld);
    SendDataFrame::getInstance().Send(0x248, 0x08, pld);
}

void MainWindow::on_step_input_currentTextChanged(const QString &arg1)
{
    bool ok;
    float value = arg1.toFloat(&ok);
    if (ok) {
        LpsParameters::GetInstance().SetVoltageX(value);
        LpsParameters::GetInstance().SetVoltageY(value);
    }
}

// void MainWindow::on_first_STANAG_Changed(int index)
// {
//     int first_stanag_input[8] = {1,2,3,4,5,6,7,8};
// }

void MainWindow::onMeasureModeChanged(int index)
{
    switch (index) {
    case 0:
        code = "0x01";
        break;
    case 1:
        code = "0x02";
        break;
    case 2:
        code = "0x03";
        break;
    case 3:
        code = "0x04";
        break;
    case 4:
        code = "0x05";
        break;
    case 5:
        code = "0x06";
        break;
    case 6:
        code = "0x07";
        break;
    case 7:
        code = "0x08";
        break;
    case 8:
        code = "0x09";
        break;

    default:
        code = "0x01";
        break;
    }
}

void MainWindow::displayFrame1(const QImage &image)
{
    if (!image.isNull()) {
        QPixmap rotatedPixmap = QPixmap::fromImage(image).transformed(QTransform().rotate(
                                                                          rotationAngle),
                                                                      Qt::SmoothTransformation);
        //ui->videoLabel->setPixmap(rotatedPixmap.scaled(ui->videoLabel->size(), Qt::KeepAspectRatio));

         ui->videoLabel->setPixmap(
             QPixmap::fromImage(image)
                 .transformed(QTransform().rotate(rotationAngle), Qt::SmoothTransformation)
                 .scaled(ui->videoLabel->size(), Qt::KeepAspectRatio , Qt::SmoothTransformation)
             );
    }
}

void MainWindow::displayFrame2(const QImage &image)
{
    if (!image.isNull()) {
        ui->videoLabel2->setPixmap(
            QPixmap::fromImage(image).scaled(ui->videoLabel2->size(), Qt::KeepAspectRatio));
    }
}

/**
 * @brief Заповнює елементи вікна значеннями, отриманими від ЛПС
 *
 */
void MainWindow::updateLpsParametersUI()
{
    LpsParameters &manager = LpsParameters::GetInstance();

    float angleX = manager.GetAngleX();
    float angleY = manager.GetAngleY();

    float omegaX = manager.GetSpeedX();
    float omegaY = manager.GetSpeedY();

    float range = manager.GetRange();
    float temp = manager.GetTemperature();

    uint32_t freq = manager.GetLaserFrequency();

    uint32_t time_remaining = manager.GetTimeRemaining();
    uint8_t laser_error_code = manager.GetLaserError();
    QString laser_error_str[4] = {"Error: NONE",
                                  "Error: INPUT",
                                  "Error: OVERTEMPERATURE",
                                  "Error: OVERVOLTAGE"};
    //uint32_t stanag = manager.GetLaserStanag();

    // Display values in UI QLineEdit widgets

    ui->range_out->setText(QString::number(range, 'f', 4));
    ui->temp_out->setText(QString::number(temp, 'f', 4));

    ui->frequency_out->setText(QString::number(freq) + " us");
    ui->time_remaining_out->setText(QString::number(time_remaining / 1000));

    ui->error_label->setText(laser_error_str[laser_error_code]);

    scaleHorizontal.setOmegaValues(omegaX, omegaY);

    // Режим роботи MODE

    ScriptCommands::GetInstance().GetMode();

    switch (manager.GetModePlatform()) {
    case BODY:
        ui->status_label->setText("Mode: BODY");
        break;
    case INERT:
        ui->status_label->setText("Mode: INERT");
        break;
    case EARTH:
        ui->status_label->setText("Mode: EARTH");
        break;
    case TRACKING:
        ui->status_label->setText("Mode: TRACKING");
        break;
    default:
        ui->status_label->setText("Mode: UNDEF");
        break;
    }

    // Рядок зі значеннями кутів і швидкостей

    // auto formatVal = [](double val) {
    //     return QString("%1").arg(val, 9, 'f', 5, QChar(' '));
    // };

    // QString cellStyle = "style='"
    //                     "background-color:#ddd;"         // м'яко-жовтий
    //                     "color:#333;"                        // темний текст
    //                     "border-radius:10px;"               // округлість
    //                     "padding:0 5px;"                // відступи
    //                     "font-family:monospace;"            // моноширинний
    //                     "font-size:14pt;"                   // великий шрифт
    //                     "box-shadow:2px 2px 6px rgba(0,0,0,0.2);" // легка тінь
    //                     "text-align:center;"
    //                     "white-space:pre;'";                // зберігає пробіли

    // QString html = QString(
    //                    "<table cellspacing='15' cellpadding='0'>"
    //                    "  <tr>"
    //                    "    <td %1>H:   %2°</td>"
    //                    "    <td %1>V:   %3°</td>"
    //                    "    <td %1>wH:  %4°/s</td>"
    //                    "    <td %1>wV:  %5°/s</td>"
    //                    "  </tr>"
    //                    "</table>"
    //                    )
    //                    .arg(cellStyle)
    //                    .arg(formatVal(angleX))
    //                    .arg(formatVal(angleY))
    //                    .arg(formatVal(omegaX))
    //                    .arg(formatVal(omegaY));

    // ui->status_label_2->setTextFormat(Qt::RichText);
    // ui->status_label_2->setText(html);
     onHorizontMarkerChanged(angleX);
     onVerticalMarkerChanged(angleY);
     showSpeed(omegaX, omegaY);

     if(activeRx>0)
     {
         setRxActive(true);
         activeRx--;
     }
     else setRxActive(false);


     if(activeTx>0)
     {
        setTxActive(true);
        activeTx--;
     }
     else setTxActive(false);


    // Відправка пакету по CAN
    if (SendDataFrame::getInstance().GetDataFrameLen() != 0) {
        SendDataFrame::getInstance().SendAllFrames();
        activeTx = 30;
    }


    // QString msg = QString("frame: w = %3, h = %4; label: w = %5, h = %6")
    //                   .arg(videoFrameWidth)
    //                   .arg(videoFrameHeight)
    //                   .arg(videoLabel->width())
    //                   .arg(videoLabel->height());
    // ui->labelOutput->setText(msg);
}

/**
 * @brief Встановлює значення кута енкодера по горизонталі.
 *
 * Ця функція оновлює значення кута по горизонту і виводить маркер на горизонтальній шкалі.
 *
 * @param value Значення кута енкодера по горизонту.
 */
void MainWindow::onHorizontMarkerChanged(const float value)
{
    ui->horizontalSlider->setValue(static_cast<int>(-value * 10)); // Встановлення маркера на шкалі

    // Вивід значення кута енкодера зверху (форматований)
    int intPart = static_cast<int>(value);
    int fracPart = static_cast<int>(qAbs(value - intPart) * 100 + 0.5); // округлення

    QString text = QString("<span style='font-size:18pt;'>%1</span><span style='font-size:14pt;'>.%2</span>")
                       .arg(intPart)
                       .arg(fracPart, 2, 10, QLatin1Char('0'));

    ui->hor_out->setText(text);

    // Значення в квадратику

    // Форматування значення з фіксованою шириною
    auto formatVal = [](double val) {
        return QString("%1").arg(val, 9, 'f', 5, QChar(' '));
    };

    // HTML-стиль для прямокутника
    QString cellStyle = "style='"
                        "background:#ddd;"             // світло-сірий фон
                        "color:#000;"                  // чорний текст
                        "border-radius:6px;"           // округлені кути
                        "padding:4px 8px;"             // внутрішні відступи
                        "font-family:monospace;"       // моноширинний шрифт
                        "font-size:14pt;"              // розмір шрифту
                        "text-align:center;"
                        "white-space:pre;'";           // збереження пробілів

    // HTML вивід
    QString html = QString("<div %1>H: %2°</div>")
                       .arg(cellStyle)
                       .arg(formatVal(value));

    // Встановити в QLabel
    ui->H_label->setTextFormat(Qt::RichText);
    ui->H_label->setText(html);


    // Update marker values for both video threads
    if (videoThread1)
        videoThread1->setHorizontMarkerValue(value);
    if (videoThread2)
        videoThread2->setHorizontMarkerValue(value);

}

/**
 * @brief Встановлює значення кута енкодера по вертикалі.
 *
 * Ця функція оновлює значення кута по вертикалі і виводить маркер на вертикальній шкалі.
 *
 * @param value Значення кута енкодера по вертикалі.
 */
void MainWindow::onVerticalMarkerChanged(const float value)
{
    ui->verticalSlider->setValue(static_cast<int>(value * 10)); // Встановлення маркера на шкалі

    // Розділяємо на цілу і дробову частини
    int intPart = static_cast<int>(value);
    int fracPart = static_cast<int>(qAbs(value - intPart) * 100 + 0.5);

    // Створюємо HTML-рядок з переносом
    QString text = QString(
                       "<div align='center'>"
                       "<span style='font-size:18pt;'>%1.</span><br>"
                       "<span style='font-size:14pt;'>%2</span>"
                       "</div>"
                       ).arg(intPart)
                       .arg(fracPart, 2, 10, QLatin1Char('0'));
    ui->vert_out->setText(text);

    // Значення в квадратику

    // Форматування значення з фіксованою шириною
    auto formatVal = [](double val) {
        return QString("%1").arg(val, 9, 'f', 5, QChar(' '));
    };

    // HTML-стиль для прямокутника
    QString cellStyle = "style='"
                        "background:#ddd;"             // світло-сірий фон
                        "color:#000;"                  // чорний текст
                        "border-radius:6px;"           // округлені кути
                        "padding:4px 8px;"             // внутрішні відступи
                        "font-family:monospace;"       // моноширинний шрифт
                        "font-size:14pt;"              // розмір шрифту
                        "text-align:center;"
                        "white-space:pre;'";           // збереження пробілів

    // HTML вивід
    QString html = QString("<div %1>V: %2°</div>")
                       .arg(cellStyle)
                       .arg(formatVal(value));

    // Встановити в QLabel
    ui->V_label->setTextFormat(Qt::RichText);
    ui->V_label->setText(html);


    // Update marker values for both video threads
    if (videoThread1)
        videoThread1->setVerticalMarkerValue(value);
    if (videoThread2)
        videoThread2->setVerticalMarkerValue(value);
}

void MainWindow::showSpeed(const float wH, const float wV)
{
    // Форматування значення з фіксованою шириною
    auto formatVal = [](double val) {
        return QString("%1").arg(val, 9, 'f', 5, QChar(' '));
    };

    // HTML-стиль для прямокутника
    QString cellStyle = "style='"
                        "background:#ddd;"             // світло-сірий фон
                        "color:#000;"                  // чорний текст
                        "border-radius:6px;"           // округлені кути
                        "padding:4px 8px;"             // внутрішні відступи
                        "font-family:monospace;"       // моноширинний шрифт
                        "font-size:14pt;"              // розмір шрифту
                        "text-align:center;"
                        "white-space:pre;'";           // збереження пробілів

    // HTML вивід
    QString html = QString("<div %1>wH: %2°</div>")
                       .arg(cellStyle)
                       .arg(formatVal(wH));

    // Встановити в QLabel
    ui->wH_label->setTextFormat(Qt::RichText);
    ui->wH_label->setText(html);

    html = QString("<div %1>wV: %2°</div>")
               .arg(cellStyle)
               .arg(formatVal(wV));

    // Встановити в QLabel
    ui->wV_label->setTextFormat(Qt::RichText);
    ui->wV_label->setText(html);
}



void MainWindow::on_start_b_clicked()
{
    if (videoThread1)
        videoThread1->stop();
    if (videoThread2)
        videoThread2->stop();

    videoThread1 = new VideoThread(this);
    videoThread1->setPipeline("udpsrc port=5601 ! tsparse ! tsdemux ! h264parse ! avdec_h264 ! "
                              "videoconvert ! video/x-raw, format=BGR ! appsink sync=false");
    connect(videoThread1, &VideoThread::frameReady, this, &MainWindow::displayFrame1);
    videoThread1->start();

    videoThread2 = new VideoThread(this);
    videoThread2->setPipeline("udpsrc port=5600 ! tsparse ! tsdemux ! h264parse ! avdec_h264 ! "
                              "videoconvert ! video/x-raw, format=BGR ! appsink sync=false");
    connect(videoThread2, &VideoThread::frameReady, this, &MainWindow::displayFrame2);
    videoThread2->start();

    videoThread1->isSwitched = false; // малювати мале поле
    videoThread2->isSwitched = true; //не малювати мале поле
}

void MainWindow::on_stop_b_2_clicked()
{
    if (videoThread1) {
        videoThread1->stop();
        videoThread1->deleteLater();
        videoThread1 = nullptr;
    }

    if (videoThread2) {
        videoThread2->stop();
        videoThread2->deleteLater();
        videoThread2 = nullptr;
    }
}

void MainWindow::on_l_vid_turn_clicked()
{
    //VideoThread.isRotated = !isRotated;
    videoThread1->isRotated = !videoThread1->isRotated;
    rotationAngle -= 180;
    if (rotationAngle < 0)
        rotationAngle += 360;
}

void MainWindow::on_switch_vid_clicked()
{
    //static bool isSwitched = false;
    isSwitched = !isSwitched;

    disconnect(videoThread1, &VideoThread::frameReady, this, nullptr);
    disconnect(videoThread2, &VideoThread::frameReady, this, nullptr);

    if (isSwitched) {
        connect(videoThread1, &VideoThread::frameReady, this, &MainWindow::displayFrame2);
        connect(videoThread2, &VideoThread::frameReady, this, &MainWindow::displayFrame1);
    } else {
        connect(videoThread1, &VideoThread::frameReady, this, &MainWindow::displayFrame1);
        connect(videoThread2, &VideoThread::frameReady, this, &MainWindow::displayFrame2);
    }

    // Передаємо в ClickableLabel:
    ui->videoLabel->setFOV(isSwitched, videoThread1->isRotated);
    videoThread1->isSwitched = isSwitched; // флаг для малювання ВПЗ на ШПЗ (переключили - не малюємо)
}

// void MainWindow::on_pointer_b_clicked() {
//     // Приклад payload для CAN кадру
//     std::vector<uint8_t> payload = {0x00, 0x10, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00};

//     // Створення об'єкта для відправки даних
//     SendDataFrame sendDataFrame;
//     sendDataFrame.Send(0x210, payload);  // Відправка CAN повідомлення з ID 0x210
// }

void MainWindow::on_pointer_b_clicked()
{
    statePointer = !statePointer;

    // Встановлюємо байт відповідно до стану
    uint8_t statePointerByte = static_cast<uint8_t>(statePointer ? 1 : 0);

    // Формуємо payload
    std::vector<uint8_t> payload = {0x00, 0x02, 0x13, 0x00, 0x00, 0x00, statePointerByte, 0x04};

    // Відправка повідомлення
    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x238,0x08, payload);
    SendDataFrame::getInstance().Send(0x238, 0x08, payload);
}

// void MainWindow::on_start_range_b_clicked()
// {
//     // Формуємо payload
//     std::vector<uint8_t> payload = {0x00, 0x01, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x02};

//     // Відправка повідомлення
//     SendDataFrame sendDataFrame;
//     sendDataFrame.Send(0x238, payload);
// }

void MainWindow::on_start_range_b_clicked()
{
    bool ok;
    uint8_t codeByte = static_cast<uint8_t>(code.toUInt(&ok, 16));

    std::vector<uint8_t> payload = {0x00, 0x01, 0x0A, 0x00, 0x00, 0x00, 0x00, codeByte};

    // Відправка повідомлення
    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x238,0x08, payload);
    SendDataFrame::getInstance().Send(0x238, 0x08, payload);
}

void MainWindow::on_break_range_b_clicked()
{
    // Формуємо payload
    std::vector<uint8_t> payload = {0x00, 0x01, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00};

    // Відправка повідомлення
    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x238,0x08, payload);
    SendDataFrame::getInstance().Send(0x238, 0x08, payload);
}

void MainWindow::on_laser_act_b_clicked()
{
    laserOn = !laserOn;
    uint8_t lastByte = laserOn ? 0x01 : 0x00;

    std::vector<uint8_t> payload = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, lastByte};

    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x248,0x08, payload);
    SendDataFrame::getInstance().Send(0x248, 0x08, payload);
}

void MainWindow::on_pulse_b_clicked()
{
    pulseOn = !pulseOn;
    uint8_t lastByte = pulseOn ? 0x01 : 0x00;

    std::vector<uint8_t> payload = {0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, lastByte};

    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x248,0x08, payload);
    SendDataFrame::getInstance().Send(0x248, 0x08, payload);
}

void MainWindow::on_term_control_b_clicked()
{
    termOn = !termOn;
    uint8_t lastByte = termOn ? 0x01 : 0x00;

    std::vector<uint8_t> payload = {0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, lastByte};

    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x248,0x08, payload);
    SendDataFrame::getInstance().Send(0x248, 0x08, payload);
}

void MainWindow::on_get_frequency_clicked()
{
    std::vector<uint8_t> payload = {0x00, 0x02, 0x04, 0x01};
    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x248,0x04, payload);
    SendDataFrame::getInstance().Send(0x248, 0x04, payload);
}

void MainWindow::on_get_stanag_clicked()
{
    QString octalStr = QString("%1%2%3")
                           .arg(ui->first_STANAG->currentIndex())
                           .arg(ui->second_STANAG->currentIndex())
                           .arg(ui->third_STANAG->currentIndex());
    bool ok = false;
    int octalValue = octalStr.toInt(&ok, 8); // основа 8

    std::vector<uint8_t> octalBytes(4);
    octalBytes[0] = (octalValue >> 24) & 0xFF;
    octalBytes[1] = (octalValue >> 16) & 0xFF;
    octalBytes[2] = (octalValue >> 8) & 0xFF;
    octalBytes[3] = octalValue & 0xFF;

    std::vector<uint8_t> payload = {0x00, 0x03, 0x04, 0x00};
    payload.insert(payload.end(), octalBytes.begin(), octalBytes.end());

    // 5. Відправка через SendDataFrame
    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x248, 0x08, payload);
    SendDataFrame::getInstance().Send(0x248, 0x08, payload);
}

void MainWindow::on_energy_0_clicked()
{
    ScriptCommands::GetInstance().SetLaserEnergy(0);
}
void MainWindow::on_energy_1_clicked()
{
    ScriptCommands::GetInstance().SetLaserEnergy(1);
}
void MainWindow::on_energy_2_clicked()
{
    ScriptCommands::GetInstance().SetLaserEnergy(2);
}
void MainWindow::on_energy_3_clicked()
{
    ScriptCommands::GetInstance().SetLaserEnergy(3);
}
void MainWindow::on_energy_4_clicked()
{
    ScriptCommands::GetInstance().SetLaserEnergy(4);
}
void MainWindow::on_energy_5_clicked()
{
    ScriptCommands::GetInstance().SetLaserEnergy(5);
}

void MainWindow::on_mode_input_currentIndexChanged(int index)
{
    ScriptCommands::GetInstance().SetMode((ModePlatform) index);
}

void MainWindow::on_stop_b_clicked()
{
    ScriptCommands::GetInstance().SetAngleEncoder(0, 0);
}

void MainWindow::on_r_b_clicked()
{
    float voltage_x = -LpsParameters::GetInstance().GetVoltageX();
    if (videoThread1->isRotated)
        voltage_x = -voltage_x;
    ScriptCommands::GetInstance().SetVoltageEncoder(voltage_x, 0);
}

void MainWindow::on_l_l_clicked()
{
    float voltage_x = LpsParameters::GetInstance().GetVoltageX();

    if (videoThread1->isRotated)
        voltage_x = -voltage_x;
    ScriptCommands::GetInstance().SetVoltageEncoder(voltage_x, 0);
}

void MainWindow::on_up_b_clicked()
{
    float voltage_y = LpsParameters::GetInstance().GetVoltageY();
    if (videoThread1->isRotated)
        voltage_y = -voltage_y;
    ScriptCommands::GetInstance().SetVoltageEncoder(0, voltage_y);
}

void MainWindow::on_d_b_clicked()
{
    float voltage_y = -LpsParameters::GetInstance().GetVoltageY();
    if (videoThread1->isRotated)
        voltage_y = -voltage_y;
    ScriptCommands::GetInstance().SetVoltageEncoder(0, voltage_y);
}

void MainWindow::on_actionBias_calibration_triggered()
{
    BiasCalibration *form = new BiasCalibration(this); // створюємо об'єкт вікна
    form->setModal(true);                    // або setModal(false) для не-блокуючого
    form->show();                            // відображаємо вікно
}

void MainWindow::on_actionSet_program_0_triggered()
{
    ScriptCommands::GetInstance().SetProgrammZero();
}

void MainWindow::on_actionZero_set_H_triggered()
{
    ScriptCommands::GetInstance().ZeroSet(0x10, 0x2);
}

void MainWindow::on_actionZero_set_V_triggered()
{
    ScriptCommands::GetInstance().ZeroSet(0x20, 0x2);
}

void MainWindow::on_actionZero_reset_H_triggered()
{
    ScriptCommands::GetInstance().ZeroSet(0x10, 0x3);
}

void MainWindow::on_actionZero_reset_V_triggered()
{
    ScriptCommands::GetInstance().ZeroSet(0x20, 0x3);
}

void MainWindow::onFrameSizeAvailable(int width, int height, VideoConfig videoConfig) {
    videoFrameWidth = width;
    videoFrameHeight = height;

    // Передаємо в ClickableLabel:
    ui->videoLabel->setVideoFrameSize(width, height);
    ui->videoLabel->setVideoConfig(videoConfig);
    ui->videoLabel->setFOV(isSwitched, videoThread1->isRotated);
}
