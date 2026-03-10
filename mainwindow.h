#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QImage>
#include <QLineEdit>
#include <QMainWindow>
#include <QMutex>
#include <QThread>
#include "CircularBuffer.h"
#include "canbus.h"
#include "canparserworker.h"
#include "canthread.h"
#include "clickable.h"
#include "laserparameters.h"
#include "lpsparameters.h"
#include "pixeltoangleconverter.h"
#include "qabstractbutton.h"
#include "scalehorizontal.h"
#include "senddataframe.h"
#include "trackingworker.h"
#include <opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class VideoThread : public QThread
{
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
    bool isRotated = false;
    bool isSwitched = false;

    VideoConfig videoConfig {};

signals:
    void frameReady(const QImage &image);
    void horizontMarkerValueChanged(int value);
    void verticalMarkerValueChanged(int value);
    void frameSizeAvailable(int width, int height, VideoConfig);

    void frameProcessed(const QImage &image);
    void frameReadyForTracking(const cv::Mat &frame);
    void processingError(const QString &errorMessage);

public slots:
    void setCurrentRoi(const cv::Rect &roi) {
        QMutexLocker locker(&roiMutex);
        currentRoi = roi;
    }


private:
    bool running;
    cv::VideoCapture cap;
    std::string gstPipeline;
    float horizontMarkerValue = 0;
    float verticalMarkerValue = 0;
    int rotationAngle = 0;

    // Встановлюємо roi
    bool roiSet = false;
    //cv::Rect roi;


    std::map<std::string, int> readROIConfig(const std::string& filename);
    void initROIFromConfig();
    cv::Rect initROIAutoDetect(cv::Mat frame);
    void initFOVVideo1();
    void initFOVVideo2();
    VideoConfig loadVideoConfig();
    cv::Rect getVideo2RectInVideo1(const VideoConfig &cfg);
    QImage matToQImage(const cv::Mat &mat);

    cv::Rect currentRoi;
    QMutex roiMutex;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    //std::queue<std::vector<uint8_t>>& messageQueue;

    ~MainWindow();
    void setRxActive(bool active);
    void setTxActive(bool active);

    void onFrameSizeAvailable(int width, int height, VideoConfig videoConfig);

protected:
    void keyPressEvent(QKeyEvent *keyEvent);

private slots:
    void displayFrame1(const QImage &image);
    void displayFrame2(const QImage &image);
    void onLabelClicked(QPoint pos);

    void on_l_vid_turn_clicked();
    void on_switch_vid_clicked();
    void on_start_b_clicked();
    void on_stop_b_2_clicked();

    // Slot to update the horizontal marker position
    void onHorizontMarkerChanged(const float);
    void onVerticalMarkerChanged(const float);
    void showSpeed(const float, const float);
    void showDacValues(const float vH, const float vV);

    void on_pointer_b_clicked();

    void on_start_range_b_clicked();

    void on_break_range_b_clicked();

    void onMeasureModeChanged(int index);
    void onFrequencyModeChanged(int index);

    void on_laser_act_b_clicked();

    void on_pulse_b_clicked();

    void on_term_control_b_clicked();

    void on_get_frequency_clicked();

    void on_get_stanag_clicked();

    //void on_frequency_mode_currentIndexChanged(int index);

    //void on_first_STANAG_Changed(int index);

    void on_energy_1_clicked();

    void on_energy_2_clicked();

    void on_energy_0_clicked();

    void on_energy_3_clicked();

    void on_energy_4_clicked();

    void on_energy_5_clicked();

    void on_mode_input_currentIndexChanged(int index);

    void on_stop_b_clicked();

    void on_r_b_clicked();

    void on_step_input_currentTextChanged(const QString &arg1);

    void on_up_b_clicked();

    void on_l_l_clicked();

    void on_d_b_clicked();

    void on_actionBias_calibration_triggered();
    void on_actionSet_program_0_triggered();
    void on_actionZero_set_H_triggered();
    void on_actionZero_set_V_triggered();
    void on_actionZero_reset_H_triggered();
    void on_actionZero_reset_V_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    VideoThread *videoThread1;
    VideoThread *videoThread2;
    CANThread *canThread;
    CanBus *canBus;
    QTimer *updateTimer;
    SendDataFrame *sendDataFrame; // Об'єкт для відправки даних

    CANParserWorker *parserWorker;
    QThread *parserThread;

    ClickableLabel *videoLabel;
    QButtonGroup *modeButtonGroup = nullptr;

    CircularBuffer<std::vector<uint8_t>> localMessageQueue;
    QMutex queueMutex;

    QString code;

    int rotationAngle = 0;
    bool isSwitched = false;
    bool statePointer = false;
    bool laserOn = false;
    bool pulseOn = false;
    bool termOn = false;
    bool isLittleEndian();

    // New variables for marker values
    float horizontMarkerValue = 0;
    float verticalMarkerValue = 0;

    void startBothVideos();
    void stopBothVideos();
    void updateLpsParametersUI();
    void updateLaserParametersUI();
    //void PrintMessageQueue(const std::queue<std::vector<uint8_t>>& messageQueue);
    ScaleHorizontal scaleHorizontal;

    QString circleHtml(bool active, const QString& label);
    int activeRx = 0;
    int activeTx = 0;

    int videoFrameWidth = 0;
    int videoFrameHeight = 0;

    VideoSettings videoSettings; // Налаштування відео параметрів

    QThread *trackingThread;
    TrackingWorker *trackingWorker;


    void handleProcessingError(const QString &errorMessage);
    void handleRoiUpdate(const cv::Rect &roi);
    cv::Rect currentRoi;
    QSize lastFrameSize;
    int roiSize = 30;
    QPoint lastRoiCenter = QPoint(-1, -1);

    void displayFrame(const QImage &image);
    void onModeSelected(int id);
};

#endif // MAINWINDOW_H
