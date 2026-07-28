#include "mainwindow.h"
#include <QButtonGroup>
#include <QDebug>
#include <QPainter>
#include <QSettings>
#include <QTimer>
#include <scriptCommands.h>
#include "canbus.h" // Підключаємо CanBus
#include "cannelloniframe.h"
#include "canthread.h"
#include "scalehorizontal.h"
#include "scalevertical.h"
#include "structs.h"
#include "ui_mainwindow.h"
#include "biascalibration.h"
#include "platformmotioncontroller.h"
#include <opencv2/opencv.hpp>

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
void VideoThread::cross(cv::Mat frame, cv::Scalar crossColor, int x, int y,
                        int thickness, int length)
{
    //Малювання перехрестя
    // Horizontal line
    cv::line(frame,
             cv::Point(x - length, y),
             cv::Point(x + length, y),
             crossColor,
             thickness);

    // Vertical line
    cv::line(frame,
             cv::Point(x, y - length),
             cv::Point(x, y + length),
             crossColor,
             thickness);
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

        //Заповнення конфігурації з файла config.ini
        if (!roiSet)
        {
            videoConfig = loadVideoConfig();
        }

        //Малювання перехрестя
        cv::Scalar crossColor(0, 255, 255);
        int thickness = 1;
        int length = 25;
        cv::Point center; // = videoConfig.opticalCenter;
        //center.x = frame.cols/2-15;
        //center.y = frame.rows/2;
        center.x = frame.cols/2+1;
        center.y = frame.rows/2;

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

/*
        //Центр Лазера
        cv::Scalar crossLaser(255, 0, 0);
        cv::Point centerLaser; // = videoConfig.opticalCenter;
        centerLaser.x = frame.cols/2-3; //12 px*0.00077 = 0.56`=33.6"
        centerLaser.y = frame.rows/2-15; //15 px *0.00072=38.88"
        cross(frame, crossLaser, centerLaser.x, centerLaser.y, 1, 20);

        //Центр далекоміра
        cv::Scalar crossLRF(0, 0, 255);
        cv::Point centerLRF; // = videoConfig.opticalCenter;
        centerLRF.x = frame.cols/2+4; //19px*0.00077=52.5"
        centerLRF.y = frame.rows/2+15; //15px = 38.88"
        cross(frame, crossLRF, centerLRF.x, centerLRF.y, 1, 15);
*/

        // Малювання ВПЗ
/*
        if(!isSwitched)
        {
            cv::Rect rectV2 = getVideo2RectInVideo1(videoConfig);
            cv::rectangle(frame, rectV2, cv::Scalar(0, 0, 255), 1);

        }

        // малювання прямокутника трекінгу
        //QMutexLocker locker(&roiMutex);
        if (!currentRoi.empty()) {
            cv::rectangle(frame, currentRoi, cv::Scalar(0, 0, 255), 2);
        }
*/
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
        //QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        emit frameReady(matToQImage(frame));

        emit frameSizeAvailable(frame.cols, frame.rows, videoConfig); // передаємо розміри кадра для кліка мішкою

        emit frameReadyForTracking(frame);
        //emit frameProcessed(matToQImage(frame));





    }

    cap.release();
}




/*
cv::Mat VideoThread::processVideoWithConfig(cv::Mat frame)
{
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
    int length = 25;

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
*/
//}


// QImage VideoThread::matToQImage(const cv::Mat &mat)
// {
//     cv::Mat temp;
//     temp = mat;
//     //cv::cvtColor(mat, temp, cv::COLOR_BGR2RGB);
//     QImage image((uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
//     return image.copy();
// }

QImage VideoThread::matToQImage(const cv::Mat &mat)
{
    if (mat.empty())
        return QImage();

    cv::Mat rgb;

    if (mat.channels() == 3) {
        // OpenCV/GStreamer дає BGR, а Qt QImage хоче RGB
        cv::cvtColor(mat, rgb, cv::COLOR_BGR2RGB);

        QImage image(rgb.data,
                     rgb.cols,
                     rgb.rows,
                     static_cast<int>(rgb.step),
                     QImage::Format_RGB888);

        return image.copy();
    }

    if (mat.channels() == 1) {
        QImage image(mat.data,
                     mat.cols,
                     mat.rows,
                     static_cast<int>(mat.step),
                     QImage::Format_Grayscale8);

        return image.copy();
    }

    return QImage();
}

void VideoThread::stop()
{
    running = false;
    wait();
}


VideoConfig VideoThread::loadVideoConfig() {
    VideoConfig cfg{};
    QString path = QCoreApplication::applicationDirPath() + "/config.ini";
    QSettings settings(path, QSettings::IniFormat);

    qDebug() << "Config path =" << path;
    qDebug() << "App dir =" << QCoreApplication::applicationDirPath();


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
    cfg.nonlinearFactor1 = settings.value("nonlinearFactor", 0.0).toFloat();
    settings.endGroup();

    // Video2
    settings.beginGroup("Video2");
    cfg.fovVideo2.width  = settings.value("w", 0.0).toFloat();
    cfg.fovVideo2.height = settings.value("h", 0.0).toFloat();
    cfg.nonlinearFactor2 = settings.value("nonlinearFactor", 0.0).toFloat();
    settings.endGroup();

    cfg.opticalCenter.x = cfg.roi.width/2;
    cfg.opticalCenter.y = cfg.roi.height/2;


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

    // Важливо для коректного перерахунку кліку у координати відео.
    // QLabel НЕ повинен сам розтягувати pixmap.
    ui->videoLabel->setScaledContents(false); // заборона розтягувати відео
    ui->videoLabel->setAlignment(Qt::AlignCenter);
    ui->videoLabel->setStyleSheet("background-color: black;"); // для поля

    ui->videoLabel2->setScaledContents(false);
    ui->videoLabel2->setAlignment(Qt::AlignCenter);
    ui->videoLabel2->setStyleSheet("background-color: black;");

    // Рух платформи кнопками
    setupPlatformControlUi();

    ui->laserAdvancedFrame->setVisible(false);

    modeButtonGroup = new QButtonGroup(this);

    modeButtonGroup->addButton(ui->radioModeInert, static_cast<int>(ModePlatform::INERT));
    modeButtonGroup->addButton(ui->radioModeBody, static_cast<int>(ModePlatform::BODY));
    modeButtonGroup->addButton(ui->radioModeTracking, static_cast<int>(ModePlatform::TRACKING));

    ui->comboRoiSize->clear();

    ui->comboRoiSize->addItem("40", 40);
    ui->comboRoiSize->addItem("60", 60);
    ui->comboRoiSize->addItem("80", 80);
    ui->comboRoiSize->addItem("100", 100);
    ui->comboRoiSize->addItem("120", 120);
    ui->comboRoiSize->addItem("160", 160);
    ui->comboRoiSize->addItem("200", 200);
    ui->comboRoiSize->addItem("240", 240);

    ui->comboRoiSize->setCurrentText("80");
    ui->videoLabel->setTrackingRoiSize(80);

    connect(modeButtonGroup, QOverload<int>::of(&QButtonGroup::idClicked),
            this, &MainWindow::onModeSelected);

    connect(ui->comboMeasurementMode,
            &QComboBox::currentIndexChanged,
            this,
            &MainWindow::onMeasureModeChanged);
    onMeasureModeChanged(ui->comboMeasurementMode->currentIndex());

    connect(ui->frequency_mode,
            &QComboBox::currentIndexChanged,
            this,
            &MainWindow::onFrequencyModeChanged);
    onFrequencyModeChanged(ui->frequency_mode->currentIndex());

    on_start_b_clicked(); // Start video on launch

    connect(videoThread1, &VideoThread::frameSizeAvailable, this, &MainWindow::onFrameSizeAvailable);
    connect(videoThread2, &VideoThread::frameSizeAvailable, this, &MainWindow::onFrameSizeAvailable);

    videoLabel = qobject_cast<ClickableLabel*>(ui->videoLabel);
    //videoLabel->setDebugLabel(ui->labelOutput);

    connect(ui->videoLabel, &ClickableLabel::clickedAt, this, &MainWindow::onLabelClicked);

    // якщо клікнути по Video2, то йде перемикання відео (Switch video)
    connect(ui->videoLabel2, &ClickableLabel::pressed,
            this, &MainWindow::on_switch_vid_clicked);




    // connect(ui->step_input, QOverload<int>::of(&QComboBox::currentIndexChanged),
    //         [this](int index){
    //             int step = ui->step_input->itemText(index).toInt();
    //             ui->videoLabel->setStepSize(step);
    //         });

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

    trackingThread = new QThread(this);
    trackingThread->start();
    trackingWorker = new TrackingWorker();
    trackingWorker->moveToThread(trackingThread);

    connect(videoThread1, &VideoThread::frameProcessed, this, &MainWindow::displayFrame);

    connect(videoThread1,
            &VideoThread::frameReadyForTracking,
            trackingWorker,
            &TrackingWorker::processFrame);
    connect(videoThread1,
            &VideoThread::processingError,
            this,
            &MainWindow::handleProcessingError);

    //Connect TrackingWorker signals
    //connect(trackingWorker, &TrackingWorker::anglesCalculated, this, &MainWindow::handleAngles);
    connect(trackingWorker, &TrackingWorker::roiUpdated, this, &MainWindow::handleRoiUpdate);

    //Вибір roiSize
    connect(ui->comboRoiSize,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,
            [this](int index)
            {
                bool ok = false;

                uint16_t roiSize =
                    static_cast<uint16_t>(ui->comboRoiSize->itemData(index).toUInt(&ok));

                // Якщо itemData не заданий у Designer, беремо текст ComboBox
                if (!ok || roiSize == 0) {
                    roiSize =
                        static_cast<uint16_t>(ui->comboRoiSize->itemText(index).toUInt(&ok));
                }

                if (!ok || roiSize < 10 || roiSize > 1000) {
                    qDebug() << "[PC ROI SIZE] invalid"
                             << "index =" << index
                             << "text =" << ui->comboRoiSize->itemText(index)
                             << "data =" << ui->comboRoiSize->itemData(index);
                    return;
                }

                // 1. Зберегти для наступного кліку
                ui->videoLabel->setTrackingRoiSize(roiSize);

                // 2. Одразу передати на плату, щоб активний квадратик змінився
                ScriptCommands::GetInstance().SetTrackingRoiSize(roiSize);

                qDebug() << "[PC ROI SIZE] selected and sent =" << roiSize;
            });

    // Ініціалізація CanBus
    canBus = new CanBus(this);

    connect(canBus, &CanBus::packetReceived, this, [this](const QByteArray &packetData) {
        // Перетворення отриманого пакету в hex і виведення в консоль
        QString hexString = canBus->toHexString(packetData);
       // qDebug() << "Received CAN packet:" << hexString;

        try {
            // обробка пакета канелоні
            CannelloniFrame frame(packetData);

            QMutexLocker locker(&queueMutex); // Блокуємо доступ до черги

            activeRx = 20;

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



    connect(trackingWorker, &TrackingWorker::roiUpdated,
            videoThread1, &VideoThread::setCurrentRoi);



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


void MainWindow::onModeSelected(int id)
{
    ScriptCommands::GetInstance().SetMode(static_cast<ModePlatform>(id));
    if(id==0) ui->label_step->setText("Step (Volts)");
    else ui->label_step->setText("Step (°/s)");
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

/**
 * @brief Вибір режиму вимірювання далекоміра
 *
 */
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
    LaserParameters &laser = LaserParameters::GetInstance();


    float angleX = manager.GetAngleX();
    float angleY = manager.GetAngleY();

    float omegaX = manager.GetSpeedX();
    float omegaY = manager.GetSpeedY();

    float range = manager.GetRange();
    float temp = laser.GetTemperature();

    float voltageX = manager.GetVoltageX();
    float voltageY = manager.GetVoltageY();

    //Laser
    uint32_t period_us = laser.GetLaserFrequency(); // період в мікросекундах
    float period_s = (float)period_us/1000000.0; // перевела в секунди
    float freq = (period_s!=0) ? (1/period_s):0;

    uint32_t time_remaining = laser.GetTimeRemaining();
    uint8_t laser_error_code = laser.GetLaserError();

    bool isLaserActive = laser.GetLaserActive();
    bool isTermocontrolOn = laser.GetThermocontrolOn();
    bool isBlindOn = laser.GetBlindOn();
    bool isPulseOn = laser.GetPulseOn();


    // Display values in UI QLineEdit widgets

    ui->range_out->setText(QString::number(range, 'f', 4));
    //ui->labelLaserTempValue->setText(QString::number(temp, 'f', 2));
    updateLaserTemperatureUI(temp);

    ui->period_out->setText(QString::number(period_s) + " s");
    ui->frequency_out->setText(QString::number(freq,  'f', 2) + " Hz");
    ui->labelPulseTimerValue->setText(QString::number(time_remaining / 1000) + " s");

    //ui->labelLaserErrorValue->setText(laser_error_str[laser_error_code]);
    updateLaserErrorUI(laser_error_code);

    // Робота лазера
    updateLaserIndicators(isLaserActive,
                          isPulseOn,
                          isTermocontrolOn,
                          isBlindOn);


    scaleHorizontal.setOmegaValues(omegaX, omegaY);

    // Режим роботи MODE

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

     onHorizontMarkerChanged(angleX);
     onVerticalMarkerChanged(angleY);
     showSpeed(omegaX, omegaY);
     showDacValues(voltageX, voltageY);

     setStatusRowState();

     static int counterTicks = 0;
     // Запроси значень платформи
     switch (counterTicks)
     {
     case 0:
         ScriptCommands::GetInstance().AskValueDACHoriz();
         counterTicks = 1;
         break;
     case 1:
         ScriptCommands::GetInstance().AskValueDACVert();
         counterTicks = 2;
         break;
     case 2:
         ScriptCommands::GetInstance().GetMode();
         counterTicks = 0;
         break;
     }




    // Відправка пакету по CAN
    if (SendDataFrame::getInstance().GetDataFrameLen() != 0) {
        SendDataFrame::getInstance().SendAllFrames();
        activeTx = 20;
    }

    ui->videoLabel->setTrackingWorker(trackingWorker);

}




/**
 * @brief Показує чи активний лазер
 */
void MainWindow::updateLaserActiveState(bool isLaserActive)
{
   applyStateStyle(ui->laser_act_b, isLaserActive ? UiState::On : UiState::Off);
}

/**
 * @brief Показує чи лазер пульсує
 */
void MainWindow::updatePulseOnState(bool isPulseOn)
{
    applyStateStyle(ui->pulse_b, isPulseOn ? UiState::On : UiState::Off);
}

/**
 * @brief Показує чи увімкнено термоконтроль
 */
void MainWindow::updateThermalControlState(bool isThermocontrolOn)
{
    applyStateStyle(ui->term_control_b, isThermocontrolOn ? UiState::On : UiState::Off);
}

/**
 * @brief Показує чи увімкнено затвор
 */
void MainWindow::updateExternalRadiationState(bool isExternalRadiationOn)
{
    applyStateStyle(ui->ext_radiation_b, isExternalRadiationOn ? UiState::On : UiState::Off);
}

/**
 * @brief Оновити стани кнопок для ІЛВ
 */
void MainWindow::updateLaserIndicators(bool isLaserActive,
                                       bool isPulseOn,
                                       bool isThermocontrolOn,
                                       bool isBlindOn)
{
    applyIndicatorStyle(
        ui->laser_act_b,
        isLaserActive ? IndicatorVisual::LaserEnabled : IndicatorVisual::Inactive,
        isLaserActive
            ? "Laser activation enabled. Thermal control is enabled automatically."
            : "Laser activation is off."
        );

    applyIndicatorStyle(
        ui->term_control_b,
        isThermocontrolOn ? IndicatorVisual::ThermalActive : IndicatorVisual::Inactive,
        isThermocontrolOn
            ? "Thermal control active."
            : "Thermal control inactive."
        );

    applyIndicatorStyle(
        ui->pulse_b,
        isPulseOn ? IndicatorVisual::RadiationActive : IndicatorVisual::Inactive,
        isPulseOn
            ? "Pulse ON. Radiation active. Use caution."
            : "Pulse OFF."
        );

    applyIndicatorStyle(
        ui->ext_radiation_b,
        isBlindOn ? IndicatorVisual::ShutterClosed : IndicatorVisual::Inactive,
        isBlindOn
            ? "Shutter closed. Radiation does not exit outside."
            : "Shutter open."
        );
}

/**
 * @brief Стилі для кнопок ІЛВ
 */
void MainWindow::applyIndicatorStyle(QWidget *widget,
                                     IndicatorVisual visual,
                                     const QString &tooltip)
{
    QString style;

    switch (visual)
    {
    case IndicatorVisual::Inactive:
        style =
            "QPushButton {"
            "background-color: transparent;"
            "border: 1px solid #8a8a8a;"
            "color: black;"
            "}";
        break;

    case IndicatorVisual::LaserEnabled:
        style =
            "QPushButton {"
            "background-color: #2ecc71;"
            "border: 1px solid #1e8449;"
            "color: black;"
            "font-weight: 600;"
            "}";
        break;

    case IndicatorVisual::RadiationActive:
        style =
            "QPushButton {"
            "background-color: #e74c3c;"
            "border: 1px solid #922b21;"
            "color: white;"
            "font-weight: 600;"
            "}";
        break;

    case IndicatorVisual::ThermalActive:
        style =
            "QPushButton {"
            "background-color: #d6eaf8;"
            "border: 1px solid #7fb3d5;"
            "color: black;"
            "font-weight: 400;"
            "}";
        break;

    case IndicatorVisual::ShutterClosed:
        style =
            "QPushButton {"
            "background-color: #fcf3cf;"
            "border: 1px solid #d4ac0d;"
            "color: black;"
            "font-weight: 400;"
            "}";
        break;
    }

    widget->setStyleSheet(style);

    if (!tooltip.isEmpty())
        widget->setToolTip(tooltip);
}




/**
 * @brief Стилі для рядка статуса
 */
QString MainWindow::statusTextHtml(const QString &name, bool active) const
{
    const QString stateText  = active ? "ON" : "OFF";
    const QString stateColor = active ? "#2ecc71" : "#808080";

    return QString("%1: <span style='color:%2; font-weight:600;'>%3</span>")
        .arg(name)
        .arg(stateColor)
        .arg(stateText);
}

/**
 * @brief Встановити стани для рядка статуса
 */
void MainWindow::setStatusRowState()
{
    LaserParameters &laser = LaserParameters::GetInstance();
    LpsParameters &lps = LpsParameters::GetInstance();
    activeLaserStatus = laser.GetHeartbeat();
    activePlatformStatus = lps.GetPlatformHeartbeat();

    ui->labelLaserStatus->setText(statusTextHtml("LASER", activeLaserStatus > 0 ));
    ui->rxLabel->setText(statusTextHtml("RX", activeRx > 0));
    ui->txLabel->setText(statusTextHtml("TX", activeTx > 0));
    ui->labelPlatformStatus->setText(statusTextHtml("PLT", activePlatformStatus  > 0));

    if(activeLaserStatus>0) activeLaserStatus--;
    if(activeRx>0) activeRx--;
    if(activeTx>0) activeTx--;
    if(activePlatformStatus>0) activePlatformStatus--;
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


    QString html = QString("H:%1°")
                       .arg(formatVal(value));

    // // Встановити в QLabel
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

    // Форматування значення з фіксованою шириною
    auto formatVal = [](double val) {
        return QString("%1").arg(val, 9, 'f', 5, QChar(' '));
    };

    // HTML вивід
    QString html = QString("V:%1°")
                       .arg(formatVal(value));

    ui->V_label->setText(html);


    // Update marker values for both video threads
    if (videoThread1)
        videoThread1->setVerticalMarkerValue(value);
    if (videoThread2)
        videoThread2->setVerticalMarkerValue(value);
}

/**
 * @brief Виводить значення кутових швидкостей енкодерів
 *
 * Ця функція виводить форматовані значення швидкостей у віконця виводу
 *
 * @param wH значення кутовой швидкості по горизонталі (в градусах/сек)
 * @param wV значення кутовой швидкості по вертикалі (в градусах/сек)
 *
 */
void MainWindow::showSpeed(const float wH, const float wV)
{
    // Форматування значення з фіксованою шириною
    auto formatVal = [](double val) {
        return QString("%1").arg(val, 9, 'f', 5, QChar(' '));
    };

    // HTML вивід значення по горизонталі
    QString html = QString("wH:%1°/s").arg(formatVal(wH));
    // Встановити в QLabel значення по горизонталі
    ui->wH_label->setText(html);

    // HTML вивід значення по вертикалі
    html = QString("wV:%1°/s").arg(formatVal(wV));

    // Встановити в QLabel значення по вертикалі
    ui->wV_label->setText(html);
}


/**
 * @brief Виводить значення напруги енкодерів
 *
 * Ця функція виводить форматовані значення напруги енкодерів
 *
 * @param vH значення напруги по горизонталі (в Вольтах)
 * @param vV значення напруги по вертикалі (в Вольтах)
 *
 */
void MainWindow::showDacValues(const float vH, const float vV)
{
    // Форматування значення з фіксованою шириною
    auto formatVal = [](double val) {
        return QString("%1").arg(val, 7, 'f', 4, QChar(' '));
    };

    // HTML вивід значення по горизонталі
    QString html = QString("DacH:%1V").arg(formatVal(vH));
    // Встановити в QLabel значення по горизонталі
    ui->valueDacH_label->setText(html);

    // HTML вивід значення по вертикалі
    html = QString("DacV:%1V").arg(formatVal(vV));
    // Встановити в QLabel значення по вертикалі
    ui->valueDacV_label->setText(html);
}


/**
 * @brief Стартує потоки відтворення відео з камер 1 і 2.
 *
 * Функція зупиняє вже існуючі потоки відео, створює нові екземпляри
 * класу VideoThread для двох відеопотоків, налаштовує для них GStreamer-пайплайни,
 * підключає сигнали до слотів відображення кадрів і запускає потоки.
 *
 * Додатково виставляє прапорці isSwitched:
 *  - videoThread1 -> isSwitched = false (малювати мале поле);
 *  - videoThread2 -> isSwitched = true (не малювати мале поле).
 *
 */
void MainWindow::on_start_b_clicked()
{
    if (videoThread1)
        videoThread1->stop();
    if (videoThread2)
        videoThread2->stop();

    videoThread1 = new VideoThread(this);

    /*
    // For Lichee camera
    videoThread1->setPipeline(
        "udpsrc port=5000 "
        "caps=\"application/x-rtp, media=(string)video, "
        "clock-rate=(int)90000, encoding-name=(string)H264, payload=(int)96\" ! "
        "rtpjitterbuffer latency=0 drop-on-latency=true ! "
        "rtph264depay ! "
        "h264parse ! "
        "avdec_h264 ! "
        "videoconvert ! "
        "video/x-raw, format=BGR ! "
        "appsink sync=false drop=true max-buffers=1"
        );
 */
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

/**
 * @brief Зупиняє потоки відтворення відео з камер 1 і 2.
 *
 * Функція зупиняє вже існуючі потоки відео
 *
 */
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

/**
 * @brief Поворот відео. Виставляє флаг для екземпляру класу videoThread1 і глобальний кут повороту
 *
 */
void MainWindow::on_l_vid_turn_clicked()
{
    //VideoThread.isRotated = !isRotated;
    videoThread1->isRotated = !videoThread1->isRotated;
    rotationAngle -= 180;
    if (rotationAngle < 0)
        rotationAngle += 360;
}

/**
 * @brief Переключення відео. Виставляє флаг isSwitched
 *
 */
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
    //ui->videoLabel->setFOV(isSwitched, videoThread1->isRotated);
    videoThread1->isSwitched = isSwitched; // флаг для малювання ВПЗ на ШПЗ (переключили - не малюємо)
}

/**
 * @brief Включення лазерного вказівникеа далекоміра
 *
 */
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

/**
 * @brief Виконати замір дальності
 *
 */
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

/**
 * @brief Зупинити замір дальності
 *
 */
void MainWindow::on_break_range_b_clicked()
{
    // Формуємо payload
    std::vector<uint8_t> payload = {0x00, 0x01, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00};

    // Відправка повідомлення
    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x238,0x08, payload);
    SendDataFrame::getInstance().Send(0x238, 0x08, payload);
}

/**
 * @brief Активувати лазер
 *
 */
void MainWindow::on_laser_act_b_clicked()
{
    laserOn = !laserOn;
    uint8_t lastByte = laserOn ? 0x01 : 0x00;

    std::vector<uint8_t> payload = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, lastByte};
    SendDataFrame::getInstance().Send(0x248, 0x08, payload);

    //Одночастно включаємо термоконтроль
    on_term_control_b_clicked();

    // перевіряємо потужність лазера і виставляємо відповідний radiobutton
    uint8_t energy = LaserParameters::GetInstance().GetEnergy();
    switch (energy)
    {
    case 0: ui->energy_0->setChecked(true); break;
    case 1: ui->energy_1->setChecked(true); break;
    case 2: ui->energy_2->setChecked(true); break;
    case 3: ui->energy_3->setChecked(true); break;
    case 4: ui->energy_4->setChecked(true); break;
    case 5: ui->energy_5->setChecked(true); break;
    default: break;
    }
}


/**
 * @brief Включити пульс лазера
 *
 */
void MainWindow::on_pulse_b_clicked()
{
    pulseOn = !pulseOn;
    uint8_t lastByte = pulseOn ? 0x01 : 0x00;

    std::vector<uint8_t> payload = {0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, lastByte};
    SendDataFrame::getInstance().Send(0x248, 0x08, payload);
}

/**
 * @brief ВУвімкнути термальний контроль
 *
 */
void MainWindow::on_term_control_b_clicked()
{
    termOn = !termOn;
    uint8_t lastByte = termOn ? 0x01 : 0x00;

    std::vector<uint8_t> payload = {0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, lastByte};
    SendDataFrame::getInstance().Send(0x248, 0x08, payload);
}

/**
 * @brief Отримати частоту лазера
 *
 */
void MainWindow::on_get_frequency_clicked()
{
    std::vector<uint8_t> payload = {0x00, 0x02, 0x04, 0x01};
    SendDataFrame::getInstance().Send(0x248, 0x04, payload);
}

/**
 * @brief Отримати станаг код
 *
 */
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


/**
 * @brief Задати потужність лазера 0 - 5
 *
 */
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

/**
 * @brief Вибрати режим платформи
 *
 */
void MainWindow::on_mode_input_currentIndexChanged(int index)
{
    ScriptCommands::GetInstance().SetMode((ModePlatform) index);
}


/**
 * @brief Калібровка біас
 *
 */
void MainWindow::on_actionBias_calibration_triggered()
{
    BiasCalibration *form = new BiasCalibration(this); // створюємо об'єкт вікна
    form->setModal(true);                    // або setModal(false) для не-блокуючого
    form->show();                            // відображаємо вікно
}

/**
 * @brief Встановити програмний ноль
 *
 */
void MainWindow::on_actionSet_program_0_triggered()
{
    ScriptCommands::GetInstance().SetProgrammZero();
}

/**
 * @brief Zero set/reset
 *
 */
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

/**
 * @brief Заповнити структуру налаштувань відео
 *
 * @param width Ширина кадру
 * @param height висота кадру
 * @param videoConfig Конфігурація відео (з файлу config.ini)
 *
 */
void MainWindow::onFrameSizeAvailable(int width, int height, VideoConfig videoConfig) {
    videoFrameWidth = width;
    videoFrameHeight = height;

    // Беремо FOV та інші параметри з config.ini,
    // але геометрію кадру - з реального потоку
    videoConfig.roi.x = 0;
    videoConfig.roi.y = 0;
    videoConfig.roi.width  = width;
    videoConfig.roi.height = height;

    // optical center теж перерахувати від реального кадру
    videoConfig.opticalCenter.x = width / 2;
    videoConfig.opticalCenter.y = height / 2;

    qDebug() << "[PC stream size]"
             << "actual =" << width << height
             << "cfg roi replaced to =" << videoConfig.roi.width << videoConfig.roi.height;

    videoSettings.update(videoConfig, isSwitched, videoThread1->isRotated);

    ui->videoLabel->setVideoSettings(&videoSettings);
    trackingWorker->setVideoSettings(&videoSettings);

    QString text = ui->step_input->currentText();
    float step = text.toFloat();
    ui->videoLabel->setStepSize(step);
}

void MainWindow::handleProcessingError(const QString &errorMessage)
{
    qWarning() << "Video processing error:" << errorMessage;
}


void MainWindow::handleRoiUpdate(const cv::Rect &roi)
{
    currentRoi = roi;
}

void MainWindow::displayFrame(const QImage &image)
{

    lastFrameSize = image.size();
    QImage displayImage = image.copy();

    if (!currentRoi.empty()) {
        QPainter painter(&displayImage);
        painter.setPen(QPen(Qt::red, 2));
        painter.drawRect(currentRoi.x, currentRoi.y, currentRoi.width, currentRoi.height);
    }

    // videoLabel->setPixmap(
    //     QPixmap::fromImage(displayImage)
    //         .scaled(videoLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


 void MainWindow::keyPressEvent(QKeyEvent *keyEvent) {
//     if (lastFrameSize.isEmpty()) {
//         qDebug() << "No frame size available yet!";
//         return;
//     }

    if (keyEvent->key() == Qt::Key_Up) {
        roiSize = std::min(roiSize + 10, 200);
        qDebug() << "ROI size increased to" << roiSize;
    }
    else if (keyEvent->key() == Qt::Key_Down) {
        roiSize = std::max(roiSize - 10, 20);
        qDebug() << "ROI size decreased to" << roiSize;
    }

 }

 void MainWindow::on_pushButton_clicked()
 {

 }

 QString MainWindow::uiStateToString(UiState state) const
 {
     switch (state) {
     case UiState::Off:     return "off";
     case UiState::On:      return "on";
     case UiState::Warning: return "warn";
     case UiState::Error:   return "error";
     }
     return "off";
 }

 void MainWindow::applyStateStyle(QWidget *widget, UiState state)
 {
     const QString stateStr = uiStateToString(state);

     if (stateStr == "on") {
         widget->setStyleSheet(
             "QPushButton {"
             "background-color: #2ecc71;"
             "border: 1px solid #1e8449;"
             "}");
     }
     else if (stateStr == "warn") {
         widget->setStyleSheet(
             "QPushButton {"
             "background-color: #f1c40f;"
             "border: 1px solid #b7950b;"
             "}");
     }
     else if (stateStr == "error") {
         widget->setStyleSheet(
             "QPushButton {"
             "background-color: #e74c3c;"
             "border: 1px solid #922b21;"
             "color: white;"
             "}");
     }
     else {
         widget->setStyleSheet(
             "QPushButton {"
             "background-color: transparent;"
             "border: 1px solid gray;"
             "}");
     }
 }


 void MainWindow::on_ext_radiation_b_clicked()
 {
     blindOn = !blindOn;
     uint8_t lastByte = blindOn ? 0x01 : 0x00;

     std::vector<uint8_t> payload = {0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, lastByte};
     SendDataFrame::getInstance().Send(0x248, 0x08, payload);
 }


 void MainWindow::on_trackingButton_clicked()
 {

 }

 void MainWindow::on_btnLaserAdvanced_clicked()
 {
     const bool showAdvanced = !ui->laserAdvancedFrame->isVisible();

     ui->laserAdvancedFrame->setVisible(showAdvanced);
     ui->btnLaserAdvanced->setText(showAdvanced ? "Advanced ▾" : "Advanced ▸");
 }

 /**
 * @brief Вивід температури червоним кольором, якщо вийшла за межі робочого діапазону
 */
 void MainWindow::updateLaserTemperatureUI(float temperature)
 {
     const bool inRange = (temperature >= 25.0f && temperature <= 35.0f);

     ui->labelLaserTempValue->setText(QString::number(temperature, 'f', 2));

     if (inRange)
     {
         ui->labelLaserTempValue->setStyleSheet(
             "QLabel {"
             "color: #1e8449;"
             "font-weight: 600;"
             "}");
         ui->labelLaserTempValue->setToolTip("Temperature in operating range");
     }
     else
     {
         ui->labelLaserTempValue->setStyleSheet(
             "QLabel {"
             "color: #c0392b;"
             "font-weight: 600;"
             "}");
         ui->labelLaserTempValue->setToolTip("Temperature out of operating range (25-35 °C)");
     }
 }

 /**
 * @brief Вивід помилки червоним кольором
 */
 void MainWindow::updateLaserErrorUI(uint8_t errorCode)
 {
     static const QString laser_error_str[4] = {
         "NONE",
         "INPUT",
         "OVERTEMPERATURE",
         "OVERVOLTAGE"
     };

     QString errorText = "UNKNOWN";
     if (errorCode < 4)
         errorText = laser_error_str[errorCode];

     ui->labelLaserErrorValue->setText(errorText);

     const bool noError = (errorCode == 0);

     if (noError)
     {
         ui->labelLaserErrorValue->setStyleSheet(
             "QLabel {"
             "color: black;"
             "font-weight: normal;"
             "}");
         ui->labelLaserErrorValue->setToolTip("No error");
     }
     else
     {
         ui->labelLaserErrorValue->setStyleSheet(
             "QLabel {"
             "color: #c0392b;"
             "font-weight: 600;"
             "}");
         ui->labelLaserErrorValue->setToolTip("Laser error active");
     }
 }

 /**
 * @brief Налаштовує кнопки керування платформою.
 */
 void MainWindow::setupPlatformControlUi()
 {
     platformMotionController = new PlatformMotionController(this);
     platformMotionController->setStepCombo(ui->step_input);

     platformMotionController->setHoldButtons(
         ui->l_2_b,
         ui->r_2_b,
         ui->up_2_b,
         ui->d_2_b,
         ui->stop_b
         );

     // Безперервний рух
     bindHoldMoveButton(ui->l_2_b, PlatformMoveDirection::Left);
     bindHoldMoveButton(ui->r_2_b, PlatformMoveDirection::Right);
     bindHoldMoveButton(ui->up_2_b, PlatformMoveDirection::Up);
     bindHoldMoveButton(ui->d_2_b, PlatformMoveDirection::Down);

     // Одиночний крок
     bindSingleStepMoveButton(ui->l_l, PlatformMoveDirection::Left);
     bindSingleStepMoveButton(ui->r_b, PlatformMoveDirection::Right);
     bindSingleStepMoveButton(ui->up_b, PlatformMoveDirection::Up);
     bindSingleStepMoveButton(ui->d_b, PlatformMoveDirection::Down);

     // Службові кнопки
     bindStopButton(ui->stop_b);
     bindZeroButton(ui->zero_b);
 }

 /**
 * @brief Прив'язує кнопку безперервного руху до заданого напрямку.
 */
 void MainWindow::bindHoldMoveButton(QPushButton *button, PlatformMoveDirection direction)
 {
     connect(button, &QPushButton::pressed, this, [this, direction]() {
         platformMotionController->setRotated(videoThread1->isRotated);
         platformMotionController->startContinuousMove(direction);
     });
 }

 /**
 * @brief Прив'язує кнопку одиночного руху до заданого напрямку.
 */
 void MainWindow::bindSingleStepMoveButton(QPushButton *button, PlatformMoveDirection direction)
 {
     connect(button, &QPushButton::clicked, this, [this, direction]() {
         platformMotionController->setRotated(videoThread1->isRotated);
         platformMotionController->moveSingleStep(direction);
     });
 }

 /**
 * @brief Прив'язує кнопку зупинки безперервного руху.
 */
 void MainWindow::bindStopButton(QPushButton *button)
 {
     connect(button, &QPushButton::clicked, this, [this]() {
         platformMotionController->stopMotion();
     });
 }

 /**
 * @brief Прив'язує кнопку переходу в нульове положення.
 */
 void MainWindow::bindZeroButton(QPushButton *button)
 {
     connect(button, &QPushButton::clicked, this, [this]() {
         ScriptCommands::GetInstance().SetPlatformZero();
     });
 }

 /**
 * @brief Скидання захоплення
 */
 void MainWindow::on_stop_track_clicked()
 {
     ScriptCommands::GetInstance().ResetTracking();
 }

 /**
 * @brief Нормалізація координат кліку для передачі на плату
 */
 bool MainWindow::normalizedPointFromClick(const QPoint &pos, const cv::Mat &frame, float &nx, float &ny)
 {
     if (frame.empty())
         return false;

     const int frameW = frame.cols;
     const int frameH = frame.rows;

     const int labelW = ui->videoLabel->width();
     const int labelH = ui->videoLabel->height();

     const double scale = std::min(double(labelW) / frameW, double(labelH) / frameH);
     const int displayedW = int(frameW * scale);
     const int displayedH = int(frameH * scale);

     const int offsetX = (labelW - displayedW) / 2;
     const int offsetY = (labelH - displayedH) / 2;

     if (pos.x() < offsetX || pos.x() >= offsetX + displayedW ||
         pos.y() < offsetY || pos.y() >= offsetY + displayedH) {
         return false;
     }

     const double localX = double(pos.x() - offsetX);
     const double localY = double(pos.y() - offsetY);

     nx = static_cast<float>(localX / displayedW);
     ny = static_cast<float>(localY / displayedH);

     nx = std::clamp(nx, 0.0f, 1.0f);
     ny = std::clamp(ny, 0.0f, 1.0f);

     return true;
 }

 /**
 * @brief nx, ny -> координата кадру
 */
 cv::Point MainWindow::framePointFromNormalized(float nx, float ny, const cv::Mat &frame)
 {
     const int frameW = frame.cols;
     const int frameH = frame.rows;

     nx = std::clamp(nx, 0.0f, 1.0f);
     ny = std::clamp(ny, 0.0f, 1.0f);

     int x = static_cast<int>(nx * frameW);
     int y = static_cast<int>(ny * frameH);

     x = std::clamp(x, 0, std::max(0, frameW - 1));
     y = std::clamp(y, 0, std::max(0, frameH - 1));

     return cv::Point(x, y);
 }

 void MainWindow::on_btnLaserAdvanced_triggered(QAction *arg1)
 {

 }

