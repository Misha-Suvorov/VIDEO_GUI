// ClickableLabel.cpp
#include "clickable.h"
#include "lpsparameters.h"
#include "pixeltoangleconverter.h"
#include "scriptcommands.h"

ClickableLabel::ClickableLabel(QWidget *parent)
    : QLabel(parent)
{}

void ClickableLabel::setVideoFrameSize(int width, int height)
{
    videoFrameWidth = width;
    videoFrameHeight = height;
}

void ClickableLabel::setFOV(bool isSwitched)
{
    this->isSwitched = isSwitched;
    if(isSwitched)
    {
        FOVWidth = 0.56f; //34`
        FOVHeight = 0.416f; //25`
    }
    else
    {
        FOVWidth = 8;
        FOVHeight = 6;
    }
}

void ClickableLabel::setDebugLabel(QLabel *label)
{
    labelDebug = label;
}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    int xInVideo, yInVideo;

    if (event->button() == Qt::LeftButton) {
        //emit clickedAt(event->pos());

        QPointF deltaAngle = mapClickToAngle(event->pos());
        if (deltaAngle.isNull())
        {
            qDebug() << "Click outside video area";
            return;
        }
        //PixelToAngleConverter converter(videoFrameWidth, videoFrameHeight, FOVWidth, FOVHeight);
        //deltaAngle = converter.pixelToAngle(QPoint(event->pos()));

        // if (videoFrameWidth > 0 && videoFrameHeight > 0) {
        //     int labelWidth = this->width();
        //     int labelHeight = this->height();

        //     // Масштаб із системи QLabel у зображення
        //     //double scaleX = static_cast<double>(videoFrameWidth) / labelWidth;
        //     //double scaleY = static_cast<double>(videoFrameHeight) / labelHeight;

        //     double labelAspect = static_cast<double>(labelWidth) / labelHeight;
        //     double frameAspect = static_cast<double>(videoFrameWidth) / videoFrameHeight;


        //     if (labelAspect > frameAspect) {
        //         // QLabel ширший — відео розтягується по висоті
        //         double scale = static_cast<double>(labelHeight) / videoFrameHeight;

        //         int videoWidthOnLabel = static_cast<int>(videoFrameWidth * scale);
        //         int offsetX = (labelWidth - videoWidthOnLabel) / 2;

        //         // Перевірка чи клік всередині відео
        //         if (event->pos().x() < offsetX || event->pos().x() > offsetX + videoWidthOnLabel) {
        //             qDebug() << "Click outside video area (horizontal)";
        //             return;
        //         }


        //     // Маштабування позиції кліку
        //         xInVideo = static_cast<int>((event->pos().x() - offsetX) / scale);
        //         yInVideo = static_cast<int>(event->pos().y() / scale);

        //     }
        //     else
        //     {
        //         // QLabel вищий — відео розтягується по ширині
        //         double scale = static_cast<double>(labelWidth) / videoFrameWidth;
        //         int videoHeightOnLabel = static_cast<int>(videoFrameHeight * scale);
        //         int offsetY = (labelHeight - videoHeightOnLabel) / 2;

        //         if (event->pos().y() < offsetY || event->pos().y() > offsetY + videoHeightOnLabel) {
        //             qDebug() << "Click outside video area (vertical)";
        //             return;
        //         }

        //         xInVideo = static_cast<int>(event->pos().x() / scale);
        //         yInVideo = static_cast<int>((event->pos().y() - offsetY) / scale);
        //     }


        //     if (labelDebug) {
        //         //QString msg = QString("X = %1, Y = %2").arg(xInVideo).arg(yInVideo);
        //         QString msg = QString("X = %1, Y = %2; frame: w = %3, h = %4; label: w = %5, h = %6")
        //                           .arg(event->pos().x())
        //                           .arg(event->pos().y())
        //                           .arg(videoFrameWidth)
        //                           .arg(videoFrameHeight)
        //                           .arg(labelWidth)
        //                           .arg(labelHeight);
        //         labelDebug->setText(msg);
        //     }

        //     // Конвертер з фактичними розмірами кадру та FOV
        //     PixelToAngleConverter converter(videoFrameWidth, videoFrameHeight, FOVWidth, FOVHeight);

        //     QPointF deltaAngle = converter.pixelToAngle(QPoint(xInVideo, yInVideo));  //(event->pos());
        //     qDebug() << " Вивід пікселів через Angle:" << deltaAngle;



            float currentAngleX = LpsParameters::GetInstance().GetAngleX();
            float newAngleX = currentAngleX + deltaAngle.x();

            float currentAngleY = LpsParameters::GetInstance().GetAngleY();
            float newAngleY = currentAngleY - deltaAngle.y();

            ScriptCommands::GetInstance().SetAngleEncoder(newAngleX, newAngleY);
        //}
    }
}


QPointF ClickableLabel::mapClickToAngle(const QPoint &clickPos)
{
    int videoWidthOnLabel;
    int videoHeightOnLabel;

    if (videoFrameWidth <= 0 || videoFrameHeight <= 0)
        return QPointF();

    int labelWidth = this->width();
    int labelHeight = this->height();

    double labelAspect = static_cast<double>(labelWidth) / labelHeight;
    double frameAspect = static_cast<double>(videoFrameWidth) / videoFrameHeight;

    int xInVideo = -1;
    int yInVideo = -1;

    if (labelAspect > frameAspect)
    {
        // QLabel ширший — зображення вписане по висоті
        double scale = static_cast<double>(labelHeight) / videoFrameHeight;
        videoWidthOnLabel = static_cast<int>(videoFrameWidth * scale);
        videoHeightOnLabel = labelHeight;
        //int offsetX = (labelWidth - videoWidthOnLabel) / 2;

        // if (clickPos.x() < offsetX || clickPos.x() > offsetX + videoWidthOnLabel)
        //     return QPointF(); // Клік у чорну рамку

        //xInVideo = static_cast<int>((clickPos.x() - offsetX) / scale);
        //yInVideo = static_cast<int>(clickPos.y() / scale);
    }
    else
    {
        // QLabel вищий — зображення вписане по ширині
        double scale = static_cast<double>(labelWidth) / videoFrameWidth;
        videoHeightOnLabel = static_cast<int>(videoFrameHeight * scale);
        videoWidthOnLabel = labelWidth;
        //int offsetY = (labelHeight - videoHeightOnLabel) / 2;

        // if (clickPos.y() < offsetY || clickPos.y() > offsetY + videoHeightOnLabel)
        //     return QPointF(); // Клік у чорну рамку

        //xInVideo = static_cast<int>(clickPos.x() / scale);
        //yInVideo = static_cast<int>((clickPos.y() - offsetY) / scale);
    }

    // Перетворення у кути
    PixelToAngleConverter converter(videoFrameWidth, videoFrameHeight, FOVWidth, FOVHeight);
    //QPointF deltaAngle = converter.pixelToAngle(QPoint(xInVideo, yInVideo));
    //PixelToAngleConverter converter(videoWidthOnLabel, videoHeightOnLabel, FOVWidth, FOVHeight);
    QPointF deltaAngle = converter.pixelToAngle(clickPos);

    //if(clickPos.x() <= videoWidthOnLabel/2) offsetX = -14; else offsetX = 14;

    //QPointF deltaAngle = converter.pixelToAngle(QPoint(clickPos.x(), clickPos.y()));

    QString msg = QString("fy = %1, fz = %2; frame: w = %3, h = %4; X = %5 px, Y = %6 px")
                      .arg(deltaAngle.x())
                      .arg(deltaAngle.y())
                      .arg(videoFrameWidth) //videoWidthOnLabel)
                      .arg(videoFrameHeight) //videoHeightOnLabel)
                      .arg(clickPos.x())
                      .arg(clickPos.y())        ;
                labelDebug->setText(msg);

    return deltaAngle;
}
