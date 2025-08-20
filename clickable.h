// ClickableLabel.h
#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>
#include "structs.h"

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(QWidget *parent = nullptr);
    void setVideoFrameSize(int width, int height);
    void setFOV(bool isSwitched, bool isRotated);
    void setDebugLabel(QLabel *label);

    void setVideoConfig(VideoConfig videoConfig);

signals:
    void clickedAt(QPoint pos);
    void held(QPointF deltaAngle);
    void clicked(QPointF deltaAngle);
    void voltageChanged(float voltageH, float voltageV);

private slots:
    void mouseHeld();
    void processClick();


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:

    QPointF mapClickToAngle(const QPoint &clickPos);

    VideoConfig videoConfig {};
    int videoFrameWidth = 0;
    int videoFrameHeight = 0;

    float FOVWidth = 8;
    float FOVHeight = 6;

    cv::Size2f roiSize;
    cv::Size2f fov;
    cv::Point opticalCenter;
    float nonlinearFactor;

    bool isSwitched = false;
    bool isRotated = false;

    QLabel *labelDebug = nullptr;
    QTimer *holdTimer;
    bool mousePressed = false;
    QPointF lastDeltaAngle;

    QTimer *repeatTimer;
    QPoint lastClickPos; // позиція кліка при утримування мишки
    float maxVoltage = 15.0f;

    //std::pair<float, float> calculateVoltage(QPoint pos);
    void startRepeating();
    QPointF scaleClick(const QPoint &clickPos);
};
