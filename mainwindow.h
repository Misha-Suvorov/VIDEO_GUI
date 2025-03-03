#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QImage>
#include <opencv2/opencv.hpp>
//#include "clickable.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class VideoThread : public QThread {
    Q_OBJECT

public:
    explicit VideoThread(QObject *parent = nullptr);
    ~VideoThread();

    void setPipeline(const std::string &pipeline);
    void run() override;
    void stop();

signals:
    void frameReady(const QImage &image);

private:
    bool running;
    cv::VideoCapture cap;
    std::string gstPipeline;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void startBothVideos();
    //void stopBothVideos();
    void displayFrame1(const QImage &image);
    void displayFrame2(const QImage &image);
    //void LabelClick();

    void on_up_2_b_clicked();

    void on_l_vid_turn_clicked();

    void on_r_vid_turn_clicked();

    void on_switch_vid_clicked();

    void on_start_b_clicked();

    void on_stop_b_2_clicked();

private:
    Ui::MainWindow *ui;
    VideoThread *videoThread1;
    VideoThread *videoThread2;
    int rotationAngle = 0;
    bool isSwitched = false;  // Track which video is displayed where

    void startBothVideos();
    void stopBothVideos();
};

#endif // MAINWINDOW_H
