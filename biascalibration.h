#ifndef BIASCALIBRATION_H
#define BIASCALIBRATION_H

#include "qelapsedtimer.h"
#include "structs.h"
#include <QDialog>

namespace Ui {
class BiasCalibration;
}

class BiasCalibration : public QDialog
{
    Q_OBJECT

public:
    explicit BiasCalibration(QWidget *parent = nullptr);
    ~BiasCalibration();

private slots:

    void on_startButton_clicked();

    void on_saveButton_clicked();

    void on_setBiasButton_clicked();

    void on_checkButton_clicked();

private:
    Ui::BiasCalibration *ui;

    struct MonitorResult {
        QVector<float> valuesH;
        QVector<float> valuesV;
    };
    QTimer* monitorTimer;
    QElapsedTimer elapsed;
    MonitorResult result;


    void startCalibration(int timeSec, int offset1, int offset2);
    void waitAndProgress(int msec);
    void sendCommandCalibration(int dx, int dy, unsigned char cmd);
    void monitorStep();
    MonitorResult startMonitoring(int durationMs);
    //int computeDelta(QVector<float> A1, QVector<float> A2, int offset1, int offset2);
    Result computeDelta(int & bias, QVector<float> A1, QVector<float> A2, int offset1, int offset2);
    float computeCoefficientB(QVector<float> A);
    void compareMonitorValues(int durationInMsec);
};

#endif // BIASCALIBRATION_H
