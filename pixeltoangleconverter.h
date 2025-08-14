#pragma once
#include <QPointF>
#include <QSize>
#include <utility>

class PixelToAngleConverter
{
public:
    // Constructor: image width and height, FOV in degrees
    PixelToAngleConverter(int width, int height, double fovX_deg, double fovY_deg);

    // Convert pixel (x, y) to angle (xAngle, yAngle)
    //std::pair<double, double> pixelToAngle(int x, int y) const;
    QPointF pixelToAngle(QPoint p) const;

    // Optional: setters if image size changes
    void setImageSize(int width, int height);
    void setFOV(double fovX_deg, double fovY_deg);

    // Встановити активну область (без чорних полів)
    void setROI(int x, int y, int w, int h); // L, T, roiW, roiH

private:
    //QSize imageSize;

    int imageWidth, imageHeight;

    double fovX, fovY; // degrees

    double degPerPixelX, degPerPixelY;

    // ROI
    int roiX = 0, roiY = 0, roiW = 0, roiH = 0;

    void updateScaling();
};
