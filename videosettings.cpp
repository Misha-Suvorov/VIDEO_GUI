#include "videosettings.h"



VideoSettings::VideoSettings(QObject *parent)
    : converter(cv::Size2f(1,1), cv::Size2f(1,1), cv::Point(0,0), 1.0f)
{

}

void VideoSettings::update(const VideoConfig& config, bool isSwitched, bool isRotated) {
    this->videoConfig = config;
    this->isSwitched = isSwitched;
    this->isRotated = isRotated;

    // Визначаємо FOV
    if (isSwitched) {
        FOVWidth  = config.fovVideo2.width;
        FOVHeight = config.fovVideo2.height;
        nonlinearFactor = config.nonlinearFactor2;
    } else {
        FOVWidth  = config.fovVideo1.width;
        FOVHeight = config.fovVideo1.height;
        nonlinearFactor = config.nonlinearFactor1;
    }

    roiSize = cv::Size2f(config.roi.width, config.roi.height);
    fov = cv::Size2f(FOVWidth, FOVHeight);

    opticalCenter = cv::Point(roiSize.width/2, roiSize.height/2);
    if (!isRotated) opticalCenter = config.opticalCenter;
    else {
        float cx = roiSize.width  / 2.0;
        float cy = roiSize.height / 2.0;
        opticalCenter.x = 2*cx - config.opticalCenter.x;
        opticalCenter.y = 2*cy - config.opticalCenter.y;
    }

    converter = PixelToAngleConverter(roiSize, fov, opticalCenter, nonlinearFactor);
}

// QPointF VideoSettings::scaleClick(const QPoint &clickPos)
// {
//     double frameW = videoConfig.roi.width;   // 702
//     double frameH = videoConfig.roi.height;  // 566

//     int labelW = this->width();
//     int labelH = this->height();

//     double labelAspect = static_cast<double>(labelW) / labelH;
//     double frameAspect = frameW / frameH;

//     double scale;

//     if (labelAspect > frameAspect)
//     {
//         // QLabel ширший — зображення вписане по висоті
//         scale = static_cast<double>(labelH) / frameH;
//         //double displayedW = frameW * scale;
//     }
//     else
//     {
//         // QLabel вищий — зображення вписане по ширині
//         scale = static_cast<double>(labelW) / frameW;
//         //double displayedH = frameH * scale;
//     }

//     // Конвертація у координати відео
//     double videoX = (clickPos.x()) / scale;
//     double videoY = (clickPos.y()) / scale;
//     return { videoX, videoY };
// }

QPointF VideoSettings::mapToVideoCoordinates(const QPoint &clickPos, QSize labelSize, const VideoConfig *config)
{
    if(config == nullptr) return { 0, 0 };
    double frameW = config->roi.width;
    double frameH = config->roi.height;

    double labelW = labelSize.width();
    double labelH = labelSize.height();

    double labelAspect = labelW / labelH;
    double frameAspect = frameW / frameH;

    int scaledImageW = labelW;
    int scaledImageH = labelH;

    //Так було без вираховування offset
    double scale = (labelAspect > frameAspect)
                       ? labelH / frameH
                       : labelW / frameW;


    double videoX = clickPos.x() / scale;
    double videoY = clickPos.y() / scale;


    /*

    if(labelAspect > frameAspect){
        scaledImageH = (int)(labelW / frameAspect);
    }
    else {
        scaledImageW = (int)(labelH * frameAspect);
    }

    // Вирахування відступів (якщо кадр не заповнює весь QLabel, ми маємо відступи ("рамку"))
    int offsetX = (labelW - scaledImageW) / 2;
    int offsetY = (labelH - scaledImageH) / 2;

    double videoX = (int)((clickPos.x() - offsetX) * frameW / scaledImageW);
    double videoY = (int)((clickPos.y() - offsetY) * frameH / scaledImageH) ;

*/
    return { videoX, videoY };
}

