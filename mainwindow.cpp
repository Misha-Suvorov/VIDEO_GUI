#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include "drawsymbols.h"
#include "scalevertical.h"
#include "scalehorizontal.h"
#include "canbus.h"  // Підключаємо CanBus
#include "cannelloniframe.h"
#include "canthread.h"
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
}

void VideoThread::setVerticalMarkerValue(float value){
    if (value > 30) {
        verticalMarkerValue = 30;
    } else if (value < -30) {
        verticalMarkerValue = -30;
    } else {
        verticalMarkerValue = value;
    }
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

    cv::Mat frame;
    while (running) {
        cap >> frame;
        if (frame.empty()) continue;

        // Draw the scale and markers
        scaleVertical.drawScale(frame, cv::Scalar(0, 0, 0), 2, STROKED, verticalMarkerValue);
        scaleHorizontal.drawScale(frame, cv::Scalar(0, 0, 0), 2, STROKED, horizontMarkerValue);

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
    : QMainWindow(parent), ui(new Ui::MainWindow), videoThread1(nullptr), videoThread2(nullptr), rotationAngle(0), canBus(nullptr), messageQueue(localMessageQueue){
    ui->setupUi(this);

    // Connect QLineEdit to slots for marker changes
    connect(ui->horizont_marker_input, &QLineEdit::textChanged, this, &MainWindow::onHorizontMarkerChanged);
    connect(ui->vertical_marker_input, &QLineEdit::textChanged, this, &MainWindow::onVerticalMarkerChanged);

    on_start_b_clicked();  // Start video on launch

    // Ініціалізація CanBus
    canBus = new CanBus(this);

    // Ініціалізація CanThread
    canThread = new CANThread(&queueMutex, &localMessageQueue);

    connect(canBus, &CanBus::packetReceived, this, [this](const QByteArray &packetData){
        // Перетворення отриманого пакету в hex і виведення в консоль
        QString hexString = canBus->toHexString(packetData);
        qDebug() << "Received CAN packet:" << hexString;

        // обробка пакета канелоні
        CannelloniFrame frame(packetData);
        QMutexLocker locker(&queueMutex);
        localMessageQueue = frame.GetMessageQueue();
    });

    // Стартуємо прийом пакету
    canBus->startReceiving();
    canThread->start();

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

    delete ui;
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
    float angleX = LpsParameters::GetInstance().GetAngleX();
    float angleY = LpsParameters::GetInstance().GetAngleY();

    float omegaX = LpsParameters::GetInstance().GetSpeedX();
    float omegaY = LpsParameters::GetInstance().GetSpeedY();

    float range = LpsParameters::GetInstance().GetRange();
    // Display values in UI QLineEdit widgets
    ui->horizont_marker_input->setText(QString::number(angleX, 'f', 2));
    ui->vertical_marker_input->setText(QString::number(angleY, 'f', 2));

    ui->omega_vertical_input->setText(QString::number(omegaX, 'f', 4));
    ui->omega_horizontal_input->setText(QString::number(omegaY, 'f', 4));
    ui->range_out->setText(QString::number(range, 'f', 4));


    scaleHorizontal.setOmegaValues(omegaX, omegaY);



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
        value = -value;

        verticalMarkerValue = value;

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
    rotationAngle -= 90;
    if (rotationAngle < 0) rotationAngle += 360;
}

void MainWindow::on_r_vid_turn_clicked() {
    rotationAngle += 90;
    if (rotationAngle >= 360) rotationAngle -= 360;
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
    SendDataFrame sendDataFrame;
    sendDataFrame.Send(0x238, payload);
}


void MainWindow::on_start_range_b_clicked()
{
    // Формуємо payload
    std::vector<uint8_t> payload = {0x00, 0x01, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x02};

    // Відправка повідомлення
    SendDataFrame sendDataFrame;
    sendDataFrame.Send(0x238, payload);
}


void MainWindow::on_break_range_b_clicked()
{
    // Формуємо payload
    std::vector<uint8_t> payload = {0x00, 0x01, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00};

    // Відправка повідомлення
    SendDataFrame sendDataFrame;
    sendDataFrame.Send(0x238, payload);
}

