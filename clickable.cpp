// ClickableLabel.cpp
#include "clickable.h"
#include "lpsparameters.h"
#include "pixeltoangleconverter.h"
#include "scriptcommands.h"

ClickableLabel::ClickableLabel(QWidget *parent)
    : QLabel(parent)
{}

void ClickableLabel::setVideoConfig(VideoConfig videoConfig)
{
    this->videoConfig = videoConfig;
}

void ClickableLabel::setVideoFrameSize(int width, int height)
{
    videoFrameWidth = width;
    videoFrameHeight = height;
}

void ClickableLabel::setFOV(bool isSwitched, bool isRotated)
{
    this->isSwitched = isSwitched;
    this->isRotated = isRotated;
    if(isSwitched)
    {
        FOVWidth = videoConfig.fovVideo2.width; //0.56f; //34`
        FOVHeight = videoConfig.fovVideo2.height; // 0.416f; //25`
    }
    else
    {
        FOVWidth = videoConfig.fovVideo1.width; // 8;
        FOVHeight = videoConfig.fovVideo1.height; //6;
    }
}

void ClickableLabel::setDebugLabel(QLabel *label)
{
    labelDebug = label;
}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {

        QPointF deltaAngle = mapClickToAngle(event->pos());
        if (deltaAngle.isNull())
        {
            qDebug() << "Click outside video area";
            return;
        }

        float currentAngleX = LpsParameters::GetInstance().GetAngleX();
        float newAngleX = (isRotated)? currentAngleX + deltaAngle.x() : currentAngleX - deltaAngle.x();

        float currentAngleY = LpsParameters::GetInstance().GetAngleY();
        float newAngleY = (isRotated)? currentAngleY - deltaAngle.y() : currentAngleY + deltaAngle.y();

        ScriptCommands::GetInstance().SetAngleEncoder(newAngleX, newAngleY);
    }
}

QPointF ClickableLabel::mapClickToAngle(const QPoint &clickPos)
{
    if (videoFrameWidth <= 0 || videoFrameHeight <= 0)
        return QPointF();

    //int labelWidth = this->width();
    //int labelHeight = this->height();

    //double labelAspect = static_cast<double>(labelWidth) / labelHeight;
    //double frameAspect = static_cast<double>(videoConfig.roi.width) / videoConfig.roi.height; //   videoFrameWidth) / videoFrameHeight;

    // int xInVideo = -1;
    // int yInVideo = -1;

    // if (labelAspect > frameAspect)
    // {
    //     // QLabel ширший — зображення вписане по висоті
    //     double scale = static_cast<double>(labelHeight) / videoFrameHeight;
    // }
    // else
    // {
    //     // QLabel вищий — зображення вписане по ширині
    //     double scale = static_cast<double>(labelWidth) / videoFrameWidth;
    // }

    // Перетворення у кути
    cv::Size2f roiSize (videoConfig.roi.width, videoConfig.roi.height);
    cv::Size2f fov (FOVWidth, FOVHeight);

    cv::Point opticalCenter;

    if(!isRotated) opticalCenter = videoConfig.opticalCenter;
    else { //Перевертаєсо центр якщо зображення перевернуто
        float cx = roiSize.width  / 2.0;
        float cy = roiSize.height / 2.0;
        opticalCenter.x = 2*cx - videoConfig.opticalCenter.x;
        opticalCenter.y = 2*cy - videoConfig.opticalCenter.y;
    }

    PixelToAngleConverter converter(roiSize, fov, opticalCenter);

    QPointF deltaAngle = converter.pixelToAngle(clickPos);


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


