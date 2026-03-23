#pragma once

#include <QObject>

class QComboBox;
class QTimer;
class QPushButton;

enum class PlatformMoveDirection
{
    None,
    Left,
    Right,
    Up,
    Down
};

class PlatformMotionController : public QObject
{
    Q_OBJECT

public:
    explicit PlatformMotionController(QObject *parent = nullptr);

    void setStepCombo(QComboBox *combo);
    void setRotated(bool rotated);

    void setHoldButtons(QPushButton *left,
                        QPushButton *right,
                        QPushButton *up,
                        QPushButton *down,
                        QPushButton *stop);

    void moveSingleStep(PlatformMoveDirection direction);

    void startContinuousMove(PlatformMoveDirection direction);
    void stopMotion();

    PlatformMoveDirection activeDirection() const;

private slots:
    void onMoveTimerTimeout();

private:
    float currentStepValue() const;
    void sendStep(float x, float y);
    void buildStepForDirection(PlatformMoveDirection direction, float &x, float &y) const;

    QPushButton *buttonForDirection(PlatformMoveDirection direction) const;
    void updateButtonHighlight();
    void setButtonActiveStyle(QPushButton *button, bool active);

private:
    QComboBox *m_stepCombo = nullptr;
    bool m_isRotated = false;

    QTimer *m_moveTimer = nullptr;
    PlatformMoveDirection m_activeDirection = PlatformMoveDirection::None;

    QPushButton *m_leftButton = nullptr;
    QPushButton *m_rightButton = nullptr;
    QPushButton *m_upButton = nullptr;
    QPushButton *m_downButton = nullptr;
    QPushButton *m_stopButton = nullptr;
};
