// ClickableLabel.cpp
#include "clickable.h"
#include "pixeltoangleconverter.h"
#include "scriptcommands.h"
#include "lpsparameters.h"

ClickableLabel::ClickableLabel(QWidget *parent) : QLabel(parent) {}

void ClickableLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit clickedAt(event->pos());
        int labelWidth = this->width();
        int labelHeight = this->height();
        PixelToAngleConverter converter(labelWidth, labelHeight, 8.0, 6.0);

        QPointF deltaAngle = converter.pixelToAngle(event->pos());
        qDebug() << " Вивід пікселів через Angle:" << deltaAngle;

        float currentAngleX =  LpsParameters::GetInstance().GetAngleX();
        ScriptCommands::GetInstance().SetAngleEncoder_H(currentAngleX+deltaAngle.x());

        float currentAngleY = LpsParameters::GetInstance().GetAngleY();
        ScriptCommands::GetInstance().SetAngleEncoder_V(currentAngleY-deltaAngle.y());



    }
}
