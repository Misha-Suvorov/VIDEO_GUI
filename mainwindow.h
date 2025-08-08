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
#include "scalehorizontal.h"
#include "senddataframe.h"
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

signals:
    void frameReady(const QImage &image);
    void horizontMarkerValueChanged(int value);
    void verticalMarkerValueChanged(int value);
    void frameSizeAvailable(int width, int height);


private:
    bool running;
    cv::VideoCapture cap;
    std::string gstPipeline;
    float horizontMarkerValue = 0;
    float verticalMarkerValue = 0;
    int rotationAngle = 0;
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

private slots:
    void displayFrame1(const QImage &image);
    void displayFrame2(const QImage &image);
    void onLabelClicked(QPoint pos);

    void on_l_vid_turn_clicked();
    void on_switch_vid_clicked();
    void on_start_b_clicked();
    void on_stop_b_2_clicked();

    // Slot to update the horizontal marker position
    void onHorizontMarkerChanged(const float); // const QString &text);
    void onVerticalMarkerChanged(const float);
    void showSpeed(const float, const float);

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


    void onFrameSizeAvailable(int width, int height);

};

#endif // MAINWINDOW_H
