// ClickableLabel.h
#pragma once

#include <QLabel>
#include <QMouseEvent>
#include <QPoint>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(QWidget *parent = nullptr);
    void setVideoFrameSize(int width, int height);
    void setFOV(bool isSwitched);
    void setDebugLabel(QLabel *label);

signals:
    void clickedAt(QPoint pos);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    int videoFrameWidth = 0;
    int videoFrameHeight = 0;
    bool isSwitched = false;
    float FOVWidth = 8;
    float FOVHeight = 6;
    QLabel *labelDebug = nullptr;

    QPointF mapClickToAngle(const QPoint &clickPos);
};
