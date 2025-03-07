#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include "drawsymbols.h"
#include "scalevertical.h"
#include "scalehorizontal.h"

VideoThread::VideoThread(QObject *parent)
    : QThread(parent), running(false), horizontMarkerValue(0) {}

VideoThread::~VideoThread() {
    stop();
}

void VideoThread::setPipeline(const std::string &pipeline) {
    gstPipeline = pipeline;
}

void VideoThread::setHorizontMarkerValue(float value) {
    horizontMarkerValue = value;}

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

        scaleVertical.drawScale(frame, cv::Scalar(0, 0, 0), 2, STROKED, horizontMarkerValue);
        scaleHorizontal.drawScale(frame, cv::Scalar(0, 0, 0), 2, STROKED, 1);

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
    : QMainWindow(parent), ui(new Ui::MainWindow), videoThread1(nullptr), videoThread2(nullptr), rotationAngle(0) {
    ui->setupUi(this);

    // Connect QLineEdit to slot
    connect(ui->horizont_marker_input, &QLineEdit::textChanged, this, &MainWindow::onHorizontMarkerChanged);

    on_start_b_clicked();  // Start video on launch
}

MainWindow::~MainWindow() {
    on_stop_b_2_clicked();
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

void MainWindow::onHorizontMarkerChanged(const QString &text) {
    bool ok;
    float value = text.toFloat(&ok);

    // Validate input range
    if (ok && value >= -30 && value <= 30) {
        ui->horizont_marker_input->setStyleSheet("");  // Reset border if valid
        if (videoThread1) videoThread1->setHorizontMarkerValue(value);
    } else {
        ui->horizont_marker_input->setStyleSheet("border: 2px solid red;");  // Highlight invalid input
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
