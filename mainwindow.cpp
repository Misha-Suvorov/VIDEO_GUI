#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include "scalevertical.h"
#include "scalehorizontal.h"
#include "canbus.h"  // Підключаємо CanBus
#include "cannelloniframe.h"
#include "canthread.h"
#include "structs.h"
#include "scriptcommands.h"

VideoThread::VideoThread(QObject *parent)
    : QThread(parent), running(false), horizontMarkerValue(0), verticalMarkerValue(0) {}

VideoThread::~VideoThread() {
    stop();
}




void VideoThread::setPipeline(const std::string &pipeline) {
    gstPipeline = pipeline;
}

void VideoThread::setHorizontMarkerValue(float value) {
    if (value > 30) {
        horizontMarkerValue = 30;
    } else if (value < -30) {
        horizontMarkerValue = -30;
    } else {
        horizontMarkerValue = value;
    }
    emit horizontMarkerValueChanged(static_cast<int>(horizontMarkerValue));

}

void VideoThread::setVerticalMarkerValue(float value){
    if (value > 30) {
        verticalMarkerValue = 30;
    } else if (value < -30) {
        verticalMarkerValue = -30;
    } else {
        verticalMarkerValue = value;
    }
    emit verticalMarkerValueChanged(static_cast<int>(verticalMarkerValue));


}

void VideoThread::run() {
    running = true;
    cap.open(gstPipeline, cv::CAP_GSTREAMER);

    if (!cap.isOpened()) {
        qDebug() << "Cannot open the stream";
        emit frameReady(QImage());
        return;
    }

    ScaleVertical scaleVertical;
    ScaleHorizontal scaleHorizontal;
    double angle = 0; // Кут обертання у градусах

    cv::Mat frame;
    while (running) {
        cap >> frame;
        if (frame.empty()) continue;

        // Draw crosshair in the center
        cv::Point center(frame.cols / 2, frame.rows / 2);
        cv::Scalar crossColor(255, 255, 0);  // Червоний колір
        int thickness = 1;
        int length = 15;

        // Horizontal line
        cv::line(frame,
                 cv::Point(center.x - length, center.y),
                 cv::Point(center.x + length, center.y),
                 crossColor, thickness);

        // Vertical line
        cv::line(frame,
                 cv::Point(center.x, center.y - length),
                 cv::Point(center.x, center.y + length),
                 crossColor, thickness);


        // Draw the scale and markers

        // if(isRotated){
        //     scaleVertical.drawScaleRotated(frame, cv::Scalar(0, 0, 0), 2, STROKED, verticalMarkerValue);
        //     scaleHorizontal.drawScale(frame, cv::Scalar(0, 0, 0), 2, STROKED, horizontMarkerValue);

        // }
        // else{
        //     scaleVertical.drawScale(frame, cv::Scalar(0, 0, 0), 2, STROKED, verticalMarkerValue);
        //     scaleHorizontal.drawScale(frame, cv::Scalar(0, 0, 0), 2, STROKED, horizontMarkerValue);
        // }



        cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
        QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
        emit frameReady(image.copy());


    }

    cap.release();
}



void VideoThread::stop() {
    running = false;
    wait();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), videoThread1(nullptr), videoThread2(nullptr), rotationAngle(0), canBus(nullptr),
    /*messageQueue(localMessageQueue),*/localMessageQueue(1000){
    ui->setupUi(this);

    connect(ui->measure_mode, &QComboBox::currentIndexChanged,
            this, &MainWindow::onMeasureModeChanged);
    onMeasureModeChanged(ui->measure_mode->currentIndex());

    connect(ui->frequency_mode, &QComboBox::currentIndexChanged,
            this, &MainWindow::onFrequencyModeChanged);
    onFrequencyModeChanged(ui->frequency_mode->currentIndex());


    connect(ui->videoLabel, &ClickableLabel::clickedAt,
            this, &MainWindow::onLabelClicked);




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






    // Connect QLineEdit to slots for marker changes
    connect(ui->horizont_marker_input, &QLineEdit::textChanged, this, &MainWindow::onHorizontMarkerChanged);
    connect(ui->vertical_marker_input, &QLineEdit::textChanged, this, &MainWindow::onVerticalMarkerChanged);

    on_start_b_clicked();  // Start video on launch

    // Ініціалізація CanBus
    canBus = new CanBus(this);

    connect(canBus, &CanBus::packetReceived, this, [this](const QByteArray &packetData) {
        // Перетворення отриманого пакету в hex і виведення в консоль
        QString hexString = canBus->toHexString(packetData);
        qDebug() << "Received CAN packet:" << hexString;

        try {
            // обробка пакета канелоні
            CannelloniFrame frame(packetData);

            QMutexLocker locker(&queueMutex);  // Блокуємо доступ до черги

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
        int maxMsgs = 100;  // optional cap per cycle

        for (int i = 0; i < maxMsgs && localMessageQueue.pop(msg); ++i) {
            parserWorker->enqueueMessage(msg);
        }

        // while (!localMessageQueue.empty()) {
        //     //parserWorker->enqueueMessage(localMessageQueue.front());
        //     localMessageQueue.pop();
        // }
    });
    queueTransferTimer->start(10);  // Кожні 10 мс перевіряє чергу


    // Стартуємо прийом пакету
    canBus->startReceiving();
    //canThread->start();

    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateLpsParametersUI);
    updateTimer->start(100);



}





MainWindow::~MainWindow() {
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

void MainWindow::onLabelClicked(QPoint pos) {
    //qDebug() << "Клік у QLabel на позиції:" << pos;
    //PixelToAngleConverter converter(videoLabel->width(), videoLabel->height(), 8.0, 6.0);

}


void MainWindow::onFrequencyModeChanged(int index){
    float frequency[8] = {1,2,5,10,20,25,0.5,0.1};
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


// void MainWindow::on_first_STANAG_Changed(int index)
// {
//     int first_stanag_input[8] = {1,2,3,4,5,6,7,8};
// }


void MainWindow::onMeasureModeChanged(int index)
{
    switch (index) {
    case 0: code = "0x01"; break;
    case 1: code = "0x02"; break;
    case 2: code = "0x03"; break;
    case 3: code = "0x04"; break;
    case 4: code = "0x05"; break;
    case 5: code = "0x06"; break;
    case 6: code = "0x07"; break;
    case 7: code = "0x08"; break;
    case 8: code = "0x09"; break;

    default: code = "0x01"; break;
    }

}


void MainWindow::displayFrame1(const QImage &image) {
    if (!image.isNull()) {
        QPixmap rotatedPixmap = QPixmap::fromImage(image).transformed(QTransform().rotate(rotationAngle), Qt::SmoothTransformation);
        ui->videoLabel->setPixmap(rotatedPixmap.scaled(ui->videoLabel->size(), Qt::KeepAspectRatio));
    }
}

void MainWindow::displayFrame2(const QImage &image) {
    if (!image.isNull()) {
        ui->videoLabel2->setPixmap(QPixmap::fromImage(image).scaled(ui->videoLabel2->size(), Qt::KeepAspectRatio));
    }
}



void MainWindow::updateLpsParametersUI() {
    LpsParameters& manager = LpsParameters::GetInstance();

    float angleX = manager.GetAngleX();
    float angleY = manager.GetAngleY();

    float omegaX = manager.GetSpeedX();
    float omegaY = manager.GetSpeedY();

    float range = manager.GetRange();
    float temp = manager.GetTemperature();

    uint32_t freq = manager.GetLaserFrequency();

    uint32_t time_remaining = manager.GetTimeRemaining();
    uint8_t laser_error_code = manager.GetLaserError();
    QString laser_error_str[4] = {"Error: NONE","Error: INPUT","Error: OVERTEMPERATURE", "Error: OVERVOLTAGE"};
    //uint32_t stanag = manager.GetLaserStanag();

    // Display values in UI QLineEdit widgets
    ui->horizont_marker_input->setText(QString::number(angleX, 'f', 2));
    ui->vertical_marker_input->setText(QString::number(angleY, 'f', 2));

    ui->omega_vertical_input->setText(QString::number(omegaX, 'f', 4));
    ui->omega_horizontal_input->setText(QString::number(omegaY, 'f', 4));

    ui->range_out->setText(QString::number(range, 'f', 4));
    ui->temp_out->setText(QString::number(temp, 'f',4));

    ui->frequency_out->setText(QString::number(freq) + " us");
    ui->time_remaining_out->setText(QString::number(time_remaining/1000));

    ui->error_label->setText(laser_error_str[laser_error_code]);

    scaleHorizontal.setOmegaValues(omegaX, omegaY);

    //ScriptCommands::GetInstance().GetMode();

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
    default:
        break;
    }
    if(SendDataFrame::getInstance().GetDataFrameLen() != 0){
        SendDataFrame::getInstance().SendAllFrames();

    }

}


void MainWindow::onHorizontMarkerChanged(const QString &text) {
    bool ok;
    //float value = LpsParameters::GetInstance().GetAngleX();
    float value = text.toFloat(&ok);

    if (text.isEmpty()) {
        value = 0;
        ok = true;
    }

    if (ok) {
        ui->horizont_marker_input->setStyleSheet("");
        horizontMarkerValue = value;
        ui->horizontalSlider->setValue(static_cast<int>(-value*10));
        ui->hor_out->setText(QString::number(value, 'f', 1));



        // Update marker values for both video threads
        if (videoThread1) videoThread1->setHorizontMarkerValue(value);
        if (videoThread2) videoThread2->setHorizontMarkerValue(value);
    } else {
        ui->horizont_marker_input->setStyleSheet("border: 2px solid red;");
    }
}

void MainWindow::onVerticalMarkerChanged(const QString &text) {
    bool ok;
    //float value = LpsParameters::GetInstance().GetAngleY();
    float value = text.toFloat(&ok);
    //ui->horizont_marker_input->setText(QString::number(value, 'f', 2));

    if (text.isEmpty()) {
        value = 0;
        ok = true;
    }

    if (ok) {
        ui->vertical_marker_input->setStyleSheet("");
        //value = value;

        verticalMarkerValue = value;
        ui->verticalSlider->setValue(static_cast<int>(value*10));
        ui->vert_out->setText(QString::number(value, 'f', 1));




        // Update marker values for both video threads
        if (videoThread1) videoThread1->setVerticalMarkerValue(value);
        if (videoThread2) videoThread2->setVerticalMarkerValue(value);
    } else {
        ui->vertical_marker_input->setStyleSheet("border: 2px solid red;");
    }
}

void MainWindow::on_start_b_clicked() {
    if (videoThread1) videoThread1->stop();
    if (videoThread2) videoThread2->stop();

    videoThread1 = new VideoThread(this);
    videoThread1->setPipeline("udpsrc port=5601 ! tsparse ! tsdemux ! h264parse ! avdec_h264 ! videoconvert ! video/x-raw, format=BGR ! appsink sync=false");
    connect(videoThread1, &VideoThread::frameReady, this, &MainWindow::displayFrame1);
    videoThread1->start();

    videoThread2 = new VideoThread(this);
    videoThread2->setPipeline("udpsrc port=5600 ! tsparse ! tsdemux ! h264parse ! avdec_h264 ! videoconvert ! video/x-raw, format=BGR ! appsink sync=false");
    connect(videoThread2, &VideoThread::frameReady, this, &MainWindow::displayFrame2);
    videoThread2->start();
}

void MainWindow::on_stop_b_2_clicked() {
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

void MainWindow::on_l_vid_turn_clicked() {
    //VideoThread.isRotated = !isRotated;
    videoThread1->isRotated = !videoThread1->isRotated;
    rotationAngle -= 180;
    if (rotationAngle < 0) rotationAngle += 360;
}



void MainWindow::on_switch_vid_clicked() {
    static bool isSwitched = false;
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
}


// void MainWindow::on_pointer_b_clicked() {
//     // Приклад payload для CAN кадру
//     std::vector<uint8_t> payload = {0x00, 0x10, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00};

//     // Створення об'єкта для відправки даних
//     SendDataFrame sendDataFrame;
//     sendDataFrame.Send(0x210, payload);  // Відправка CAN повідомлення з ID 0x210
// }


void MainWindow::on_pointer_b_clicked() {
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

    std::vector<uint8_t> payload = {
        0x00, 0x01, 0x0A, 0x00, 0x00, 0x00, 0x00, codeByte
    };

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

    std::vector<uint8_t> payload = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, lastByte
    };

    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x248,0x08, payload);
    SendDataFrame::getInstance().Send(0x248, 0x08, payload);


}



void MainWindow::on_pulse_b_clicked()
{
    pulseOn = !pulseOn;
    uint8_t lastByte = pulseOn ? 0x01 : 0x00;

    std::vector<uint8_t> payload = {
        0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, lastByte
    };

    // SendDataFrame sendDataFrame;
    // sendDataFrame.Send(0x248,0x08, payload);
    SendDataFrame::getInstance().Send(0x248, 0x08, payload);


}


void MainWindow::on_term_control_b_clicked()
{
    termOn = !termOn;
    uint8_t lastByte = termOn ? 0x01 : 0x00;

    std::vector<uint8_t> payload = {
        0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, lastByte
    };

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
    QString octalStr = QString("%1%2%3").arg(ui->first_STANAG->currentIndex()).arg(ui->second_STANAG->currentIndex()).arg(ui->third_STANAG->currentIndex());
    bool ok = false;
    int octalValue = octalStr.toInt(&ok, 8);  // основа 8

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
    ScriptCommands::GetInstance().SetMode((ModePlatform)index);
}

void MainWindow::on_stop_b_clicked()
{
    ScriptCommands::GetInstance().SetAngleEncoder(0, 0);

}

