#ifndef SCALINGFACTOR_H
#define SCALINGFACTOR_H
#pragma once
#include <opencv2/opencv.hpp>
class scalingFactor
{
public:
    double scaleX = 1;
    double scaleY = 1;
    double posX = 0;
    double posY = 0;
    double scaledWidth = 0;
    double scaledHeight = 0;
    static const int baseWidth = 1600;
    static const int baseHeight = 900;
    //scalingFactor();
public:
    scalingFactor() : scaleX(1), scaleY(1), posX(0), posY(0),
        scaledWidth(baseWidth), scaledHeight(baseHeight) {}
    static double getScaleX(const cv::InputArray& img) {
        return static_cast<double>(img.cols()) / baseWidth;
    }
    static double getScaleY(const cv::InputArray& img) {
        return static_cast<double>(img.rows()) / baseHeight;
    }
    double getScaledPosX() const { return posX; }
    double getScaledPosY() const { return posY; }
    double getScaledWidth() const { return scaledWidth; }
    double getScaledHeight() const { return scaledHeight; }
    void calculateScalingFactors(const cv::InputArray& img, cv::Rect2d rect);
    void calculateScalingFactors(const cv::InputArray& img, cv::Point point);
    static double getScaledWidth(const cv::InputArray& img, int width);
    static double getScaledHeight(const cv::InputArray& img, int height);
    static cv::Point getScaledPoint(const cv::InputArray& img, cv::Point);
    static cv::Rect2d getScaledRect(const cv::InputArray& img, cv::Rect2d rect);
};

#endif // SCALINGFACTOR_H
