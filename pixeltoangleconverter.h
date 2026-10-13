#pragma once
#include <QPointF>
#include <QSize>
#include <opencv2/opencv.hpp>

class PixelToAngleConverter
{
public:
    // Constructor: image width and height, FOV in degrees, opticalCenter
    PixelToAngleConverter(cv::Size2f roiSize, cv::Size2f fov, cv::Point opticalCenter, float);
    QPointF pixelToAngle(QPointF p) const;
    QPointF calculateVoltage(QPointF p, float maxVoltage, bool isRotated) const;
    QPointF calculateVoltageNonlinear(QPointF p, float maxVoltage, bool isRotated) const;

    QPointF movePlatformInInertModeByStep(QPointF p, bool isRotated, float step) const;

    void setRoiSize(const cv::Size2f& s);
    void setFov(const cv::Size2f& f);
    void setOpticalCenter(const cv::Point& c);
    void setNonlinearFactor(float k);

    // одним викликом оновити все
    void setParams(const cv::Size2f& s,
                   const cv::Size2f& f,
                   const cv::Point&  c,
                   float             k);

private:
    cv::Size2f roiSize;

    cv::Size2f  fov; // degrees

    double degPerPixelX, degPerPixelY;

    cv::Rect roi;

    // OpticalCenter
    cv::Point opticalCenter;

    float nonlinearFactor; // коефіцієнт чутливості (більший = рух плавніший біля центру)

    void updateScaling();


};
