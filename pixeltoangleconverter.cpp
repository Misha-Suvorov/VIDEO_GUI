#include "PixelToAngleConverter.h"

PixelToAngleConverter::PixelToAngleConverter(int width, int height, double fovX_deg, double fovY_deg)
    : imageWidth(width)
    , imageHeight(height)
    , fovX(fovX_deg)
    , fovY(fovY_deg)
{
    // За замовчуванням ROI = весь кадр (якщо ще не знаємо смуг)
    roiX = 0; roiY = 0; roiW = width; roiH = height;
    updateScaling();
}

void PixelToAngleConverter::setROI(int x, int y, int w, int h) {
    roiX = x; roiY = y; roiW = w; roiH = h;
    updateScaling();
}

void PixelToAngleConverter::updateScaling()
{
    // if (imageWidth > 0) {
    //     degPerPixelX = fovX / static_cast<double>(imageWidth);
    // }

    // if (imageHeight > 0) {
    //     degPerPixelY = fovY / static_cast<double>(imageHeight);
    // }

    if (roiW > 0)  degPerPixelX = fovX / static_cast<double>(roiW);
    if (roiH > 0)  degPerPixelY = fovY / static_cast<double>(roiH);
}

QPointF PixelToAngleConverter::pixelToAngle(QPoint p) const
{
    // double centerX = imageWidth / 2.0;
    // double centerY = imageHeight / 2.0;

    // double deltaX = pixelPoint.x() - centerX;
    // double deltaY = pixelPoint.y() - centerY;

    // double angleX = deltaX * degPerPixelX;
    // double angleY = -deltaY * degPerPixelY; // minus because Y grows down

    // return {angleX, angleY};


    // Центр активної зони
    const double cx = roiX + roiW / 2.0;
    const double cy = roiY + roiH / 2.0;

    const double dx = p.x() - cx;
    const double dy = p.y() - cy;

    const double angleX = dx * degPerPixelX;
    const double angleY = -dy * degPerPixelY; // вісь Y вниз

    return { angleX, angleY };
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
