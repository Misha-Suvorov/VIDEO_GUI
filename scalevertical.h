#ifndef SCALEVERTICAL_H
#define SCALEVERTICAL_H
#pragma once
#include <opencv2/opencv.hpp>
#include "base.h"

class ScaleVertical : public baseElement
{
private:
    int countStepsForVerticalScale = 4;
    int countStepsForHorizontalScale = 4;
    float lineLengthForVerticalScale = 20;
    float lineLengthForHorizontalScale = 20;
    std::string convertValueToText(float value);
public:
    //ScaleVertical();
    ScaleVertical() : baseElement(0.5),
        countStepsForVerticalScale(4), countStepsForHorizontalScale(4),
        lineLengthForVerticalScale(20), lineLengthForHorizontalScale(20) {}
    void setCountStepsForVerticalScale(int value) { if(value>0) countStepsForVerticalScale = value; }
    void setCountStepsForHorizontalScale(int value) { if(value>0) countStepsForHorizontalScale = value; }
    void setLineLengthForVerticalScale(int value) { if(value>0) lineLengthForVerticalScale = value; }
    void setLineLengthForHorizontalScale(int value) { if(value>0) lineLengthForHorizontalScale = value; }
    void drawScale(cv::InputOutputArray img, const cv::Scalar& color, int thickness, int lineType, float value);
    //void drawScaleVerticalLeft(cv::InputOutputArray img, const cv::Scalar& color, int thickness, int lineType, float value);
    //void drawScaleHorizontal(cv::InputOutputArray img, const cv::Scalar& color, int thickness, int lineType, float value);

};

#endif // SCALEVERTICAL_H
