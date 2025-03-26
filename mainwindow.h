#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QImage>
#include <QLineEdit>
#include <opencv2/opencv.hpp>
#include "canbus.h"
#include "canthread.h"


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

    void setHorizontMarkerValue(float value);
    void setVerticalMarkerValue(float value);
    void setRotationAngle(int angle);

signals:
    void frameReady(const QImage &image);

private:
    bool running;
    cv::VideoCapture cap;
    std::string gstPipeline;
    float horizontMarkerValue = 0;
    float verticalMarkerValue = 0;
    int rotationAngle = 0;

};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void displayFrame1(const QImage &image);
    void displayFrame2(const QImage &image);

    void on_l_vid_turn_clicked();
    void on_r_vid_turn_clicked();
    void on_switch_vid_clicked();
    void on_start_b_clicked();
    void on_stop_b_2_clicked();

    // Slot to update the horizontal marker position
    void onHorizontMarkerChanged(const QString &text);
    void onVerticalMarkerChanged(const QString &text);

private:
    Ui::MainWindow *ui;
    VideoThread *videoThread1;
    VideoThread *videoThread2;
    CANThread *canThread;
    int rotationAngle = 0;
    bool isSwitched = false;

    // New variables for marker values
    float horizontMarkerValue = 0;
    float verticalMarkerValue = 0;

    void startBothVideos();
    void stopBothVideos();
    CanBus *canBus;
    void PrintMessageQueue(const std::queue<std::vector<uint8_t>>& messageQueue);



};

#endif // MAINWINDOW_H
