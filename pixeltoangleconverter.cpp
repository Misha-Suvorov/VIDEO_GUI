#include "PixelToAngleConverter.h"

PixelToAngleConverter::PixelToAngleConverter(cv::Size2f roiSize, cv::Size2f fov, cv::Point opticalCenter)
    : roiSize(roiSize)
    , fov(fov)
    , opticalCenter(opticalCenter)
{
    roi.x = 0; roi.y = 0; roi.width = roiSize.width; roi.height = roiSize.height;
    updateScaling();
}

void PixelToAngleConverter::updateScaling()
{
    if (roi.width > 0)  degPerPixelX = fov.width / static_cast<double>(roi.width);
    if (roi.height > 0)  degPerPixelY = fov.height / static_cast<double>(roi.height);
}

QPointF PixelToAngleConverter::pixelToAngle(QPoint p) const
{
    // Центр активної зони
    const double cx = opticalCenter.x; //roiX + roiW / 2.0;
    const double cy = opticalCenter.y; //roiY + roiH / 2.0;

    const double dx = p.x() - cx;
    const double dy = p.y() - cy;

    const double angleX = dx * degPerPixelX;
    const double angleY = -dy * degPerPixelY; // вісь Y вниз

    return { angleX, angleY };
}

