#include "PixelToAngleConverter.h"

PixelToAngleConverter::PixelToAngleConverter(int width, int height, double fovX_deg, double fovY_deg)
    : imageWidth(width)
    , imageHeight(height)
    , fovX(fovX_deg)
    , fovY(fovY_deg)
{
    updateScaling();
}

void PixelToAngleConverter::updateScaling()
{
    if (imageWidth > 0) {
        degPerPixelX = fovX / static_cast<double>(imageWidth);
    }

    if (imageHeight > 0) {
        degPerPixelY = fovY / static_cast<double>(imageHeight);
    }
}

QPointF PixelToAngleConverter::pixelToAngle(QPoint pixelPoint) const
{
    double centerX = imageWidth / 2.0;
    double centerY = imageHeight / 2.0;

    double deltaX = pixelPoint.x() - centerX;
    double deltaY = pixelPoint.y() - centerY;

    double angleX = deltaX * degPerPixelX;
    double angleY = -deltaY * degPerPixelY; // minus because Y grows down

    return {angleX, angleY};
}

void PixelToAngleConverter::setImageSize(int width, int height)
{
    imageWidth = width;
    imageHeight = height;
    updateScaling();
}

void PixelToAngleConverter::setFOV(double fovX_deg, double fovY_deg)
{
    fovX = fovX_deg;
    fovY = fovY_deg;
    updateScaling();
}
