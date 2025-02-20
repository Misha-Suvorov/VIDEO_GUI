#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <opencv2/opencv.hpp>

// Function to draw a crosshair on the frame
void DrawCrosshair(cv::InputOutputArray frame, cv::Point center, const cv::Scalar& color, int thickness) {
    int size = 20;  // Length of the crosshair lines
    cv::line(frame, cv::Point(center.x - size, center.y), cv::Point(center.x + size, center.y), color, thickness);
    cv::line(frame, cv::Point(center.x, center.y - size), cv::Point(center.x, center.y + size), color, thickness);
}

// VideoThread constructor
VideoThread::VideoThread(QObject *parent) : QThread(parent), running(false) {}

// VideoThread destructor
VideoThread::~VideoThread() {
    stop();
}



// Set GStreamer pipeline
void VideoThread::setPipeline(const std::string &pipeline) {
    gstPipeline = pipeline;
}

// Video processing loop
void VideoThread::run() {
    running = true;

    cap.open(gstPipeline, cv::CAP_GSTREAMER);
    if (!cap.isOpened()) {
        qDebug() << "Cannot open the stream";
        emit frameReady(QImage());
        return;
    }

    cv::Mat frame;
    while (running) {
        cap >> frame; // Capture a frame
        if (frame.empty()) continue;

        // Calculate the center of the video frame
        int centerX = frame.cols / 2;
        int centerY = frame.rows / 2;
        cv::Point center = cv::Point(centerX, centerY);

        // Draw a crosshair
        DrawCrosshair(frame, center, cv::Scalar(255, 255, 0), 2);  // Yellow crosshair with thickness 2

        // Convert frame to RGB for Qt
        cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);

        // Convert the frame to QImage
        QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

        // Emit the frameReady signal with the updated frame
        emit frameReady(image.copy());
    }

    cap.release();
}

// Stop the video thread
void VideoThread::stop() {
    running = false;
    wait();
}

// MainWindow constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), videoThread1(nullptr), videoThread2(nullptr) {
    ui->setupUi(this);

    // Automatically start video streams
    startBothVideos();
}

// MainWindow destructor
MainWindow::~MainWindow() {
    stopBothVideos();
    delete ui;
}

// Start both video streams
void MainWindow::startBothVideos() {
    // Stop any running video threads before starting new ones
    stopBothVideos();

    // Set up the first video stream for the first QLabel
    videoThread1 = new VideoThread(this);
    videoThread1->setPipeline("udpsrc port=5601 ! tsparse ! tsdemux ! h264parse ! avdec_h264 ! videoconvert ! video/x-raw, format=BGR ! appsink sync=false");
    connect(videoThread1, &VideoThread::frameReady, this, &MainWindow::displayFrame1);
    videoThread1->start();

    // Set up the second video stream for the second QLabel
    videoThread2 = new VideoThread(this);
    videoThread2->setPipeline("udpsrc port=5600 ! tsparse ! tsdemux ! h264parse ! avdec_h264 ! videoconvert ! video/x-raw, format=BGR ! appsink sync=false");
    connect(videoThread2, &VideoThread::frameReady, this, &MainWindow::displayFrame2);
    videoThread2->start();
}

// Stop both video streams
void MainWindow::stopBothVideos() {
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
int rotationAngle = 0;

// Display the first video stream
//void MainWindow::displayFrame1(const QImage &image) {
//    if (!image.isNull()) {
//        ui->videoLabel->setPixmap(QPixmap::fromImage(image).scaled(ui->videoLabel->size(), Qt::KeepAspectRatio));
//    }
//}


void MainWindow::displayFrame1(const QImage &image) {
    if (!image.isNull()) {
        QTransform transform;
        transform.rotate(rotationAngle);

        QPixmap rotatedPixmap = QPixmap::fromImage(image).transformed(transform, Qt::SmoothTransformation);
        ui->videoLabel->setPixmap(rotatedPixmap.scaled(ui->videoLabel->size(), Qt::KeepAspectRatio));
    }
}




// Display the second video stream
void MainWindow::displayFrame2(const QImage &image) {
    if (!image.isNull()) {
        ui->videoLabel2->setPixmap(QPixmap::fromImage(image).scaled(ui->videoLabel2->size(), Qt::KeepAspectRatio));
    }
}


void MainWindow::on_up_2_b_clicked()
{

}



void MainWindow::on_l_vid_turn_clicked()
{
    rotationAngle -= 90;  // Rotate left by 90 degrees
    if (rotationAngle < 0) rotationAngle += 360;  // Keep within 0-360 degrees
}


void MainWindow::on_r_vid_turn_clicked()
{
    rotationAngle += 90;  // Rotate right by 90 degrees
    if (rotationAngle >= 360) rotationAngle -= 360;  // Keep within 0-360 degrees
}

