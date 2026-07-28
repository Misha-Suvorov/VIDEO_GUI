// ClickableLabel.h
#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>
#include "structs.h"
#include "trackingworker.h"
#include "videosettings.h"

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(QWidget *parent = nullptr);
    void setDebugLabel(QLabel *label);

    //void setVideoConfig(VideoConfig videoConfig);
    void setStepSize(float step) { stepSize = step; }
    float getStepSize() const { return stepSize; }
    void setVideoSettings(VideoSettings* settings)
    {
        this->settings = settings;
        isSwitched = settings->isSwitched;
        isRotated = settings->isRotated;
    }
    void setTrackingWorker(TrackingWorker* tw) {trackingWorker = tw;}

    void setTrackingRoiSize(uint16_t roiSize);
    uint16_t trackingRoiSize() const;

signals:
    void clickedAt(QPoint pos);
    void held(QPointF deltaAngle);
    void clicked(QPointF deltaAngle);
    void pressed();  // простий сигнал "натиснули", без параметрів
    void voltageChanged(float voltageH, float voltageV);

private slots:
    void mouseHeld();
    void processClick();


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:

    QPointF mapClickToAngle(const QPoint &clickPos);

    VideoConfig videoConfig {};
    VideoSettings* settings = nullptr;
    //int videoFrameWidth = 0;
    //int videoFrameHeight = 0;

    //float FOVWidth = 8;
    //float FOVHeight = 6;


    bool isSwitched = false;
    bool isRotated = false;

    QLabel *labelDebug = nullptr;
    QTimer *holdTimer;
    bool mousePressed = false;
    QPointF lastDeltaAngle;

    QTimer *repeatTimer;
    QPoint lastClickPos; // позиція кліка при утримування мишки
    QPointF videoPos; // координати кліку масштабовані згідно з лейблом
    float maxVoltage = 15.0f;
    float stepSize = 1;   // значення за замовчуванням для руху по крокам в режимі Інерт


    TrackingWorker *trackingWorker;
    QPointF lastRoiCenter = QPointF(-1, -1);
    int roiTrackingSize = 30;
    uint16_t m_trackingRoiSize = 80;
    void startRepeating();
    //QPointF scaleClick(const QPoint &clickPos);

};
