#pragma once
#include <QPointF>
#include <QSize>
#include <opencv2/opencv.hpp>

class PixelToAngleConverter
{
public:
    // Constructor: image width and height, FOV in degrees, opticalCenter
    PixelToAngleConverter(cv::Size2f roiSize, cv::Size2f fov, cv::Point opticalCenter);
    QPointF pixelToAngle(QPoint p) const;


private:
    cv::Size2f roiSize;

    cv::Size2f  fov; // degrees

    double degPerPixelX, degPerPixelY;

    cv::Rect roi;

    // OpticalCenter
    cv::Point opticalCenter;

    void updateScaling();
};
