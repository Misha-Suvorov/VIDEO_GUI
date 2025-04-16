#pragma once
#include <QSize>
#include <QPointF>
#include <utility>

class PixelToAngleConverter
{
public:
    // Constructor: image width and height, FOV in degrees
    PixelToAngleConverter(int width, int height, double fovX_deg, double fovY_deg);

    // Convert pixel (x, y) to angle (xAngle, yAngle)
    //std::pair<double, double> pixelToAngle(int x, int y) const;
    QPointF pixelToAngle(QPoint pixelPoint) const;

    // Optional: setters if image size changes
    void setImageSize(int width, int height);
    void setFOV(double fovX_deg, double fovY_deg);

private:
    //QSize imageSize;
    int imageWidth;
    int imageHeight;
    double fovX; // degrees
    double fovY;
    double degPerPixelX;
    double degPerPixelY;

    void updateScaling();
};
