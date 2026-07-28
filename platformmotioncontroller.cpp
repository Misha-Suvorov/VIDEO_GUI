#include "platformmotioncontroller.h"
#include "scriptcommands.h"

#include <QComboBox>
#include <QPushButton>
#include <QTimer>

PlatformMotionController::PlatformMotionController(QObject *parent)
    : QObject(parent)
    , m_moveTimer(new QTimer(this))
{
    m_moveTimer->setInterval(100);
    connect(m_moveTimer, &QTimer::timeout,
            this, &PlatformMotionController::onMoveTimerTimeout);
}

void PlatformMotionController::setStepCombo(QComboBox *combo)
{
    m_stepCombo = combo;
}

void PlatformMotionController::setRotated(bool rotated)
{
    m_isRotated = rotated;
}

void PlatformMotionController::setHoldButtons(QPushButton *left,
                                              QPushButton *right,
                                              QPushButton *up,
                                              QPushButton *down,
                                              QPushButton *stop)
{
    m_leftButton = left;
    m_rightButton = right;
    m_upButton = up;
    m_downButton = down;
    m_stopButton = stop;

    updateButtonHighlight();
}

float PlatformMotionController::currentStepValue() const
{
    if (!m_stepCombo)
        return 0.0f;

    bool ok = false;
    const float value = m_stepCombo->currentText().toFloat(&ok);
    return ok ? value : 0.0f;
}

void PlatformMotionController::sendStep(float x, float y)
{
    ScriptCommands::GetInstance().SetVoltageEncoder(x, y);
}

void PlatformMotionController::buildStepForDirection(PlatformMoveDirection direction, float &x, float &y) const
{
    x = 0.0f;
    y = 0.0f;

    const float step = currentStepValue();
    if (step == 0.0f)
        return;

    switch (direction)
    {
    case PlatformMoveDirection::Left:
        x = step;
        break;

    case PlatformMoveDirection::Right:
        x = -step;
        break;

    case PlatformMoveDirection::Up:
        y = step;
        break;

    case PlatformMoveDirection::Down:
        y = -step;
        break;

    case PlatformMoveDirection::None:
    default:
        return;
    }

    if (m_isRotated)
    {
        x = -x;
        y = -y;
    }
}

void PlatformMotionController::moveSingleStep(PlatformMoveDirection direction)
{
    float x = 0.0f;
    float y = 0.0f;

    buildStepForDirection(direction, x, y);

    if (x == 0.0f && y == 0.0f)
        return;

    sendStep(x, y);
}

void PlatformMotionController::startContinuousMove(PlatformMoveDirection direction)
{
    if (direction == PlatformMoveDirection::None)
        return;

    m_activeDirection = direction;
    updateButtonHighlight();

    moveSingleStep(direction);

    if (!m_moveTimer->isActive())
        m_moveTimer->start();
}

void PlatformMotionController::stopMotion()
{
    m_moveTimer->stop();
    m_activeDirection = PlatformMoveDirection::None;
    updateButtonHighlight();
}

PlatformMoveDirection PlatformMotionController::activeDirection() const
{
    return m_activeDirection;
}

void PlatformMotionController::onMoveTimerTimeout()
{
    if (m_activeDirection == PlatformMoveDirection::None)
        return;

    moveSingleStep(m_activeDirection);
}

QPushButton *PlatformMotionController::buttonForDirection(PlatformMoveDirection direction) const
{
    switch (direction)
    {
    case PlatformMoveDirection::Left:
        return m_leftButton;
    case PlatformMoveDirection::Right:
        return m_rightButton;
    case PlatformMoveDirection::Up:
        return m_upButton;
    case PlatformMoveDirection::Down:
        return m_downButton;
    case PlatformMoveDirection::None:
    default:
        return nullptr;
    }
}

void PlatformMotionController::setButtonActiveStyle(QPushButton *button, bool active)
{
    if (!button)
        return;

    if (active)
    {
        button->setStyleSheet(
            "QPushButton {"
            "background-color: #d6eaf8;"
            "border: 1px solid #5dade2;"
            "font-weight: 600;"
            "}");
    }
    else
    {
        button->setStyleSheet("");
    }
}

void PlatformMotionController::updateButtonHighlight()
{
    setButtonActiveStyle(m_leftButton,  m_activeDirection == PlatformMoveDirection::Left);
    setButtonActiveStyle(m_rightButton, m_activeDirection == PlatformMoveDirection::Right);
    setButtonActiveStyle(m_upButton,    m_activeDirection == PlatformMoveDirection::Up);
    setButtonActiveStyle(m_downButton,  m_activeDirection == PlatformMoveDirection::Down);

    if (m_stopButton)
        m_stopButton->setStyleSheet("");
}
