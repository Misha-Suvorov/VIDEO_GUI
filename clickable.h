// ClickableLabel.h
#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>
#include "pixeltoangleconverter.h"
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
    void setStepSize(float step) { stepSize = step; }
    float getStepSize() const { return stepSize; }

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

    PixelToAngleConverter converter;

    QLabel *labelDebug = nullptr;
    QTimer *holdTimer;
    bool mousePressed = false;
    QPointF lastDeltaAngle;

    QTimer *repeatTimer;
    QPoint lastClickPos; // позиція кліка при утримування мишки
    float maxVoltage = 15.0f;
    float stepSize = 1;   // значення за замовчуванням для руху по крокам в режимі Інерт

    //std::pair<float, float> calculateVoltage(QPoint pos);
    void startRepeating();
    QPointF scaleClick(const QPoint &clickPos);
};
