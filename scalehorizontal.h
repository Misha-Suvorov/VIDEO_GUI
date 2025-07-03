#ifndef SCALEHORIZONTAL_H
#define SCALEHORIZONTAL_H
#pragma once
#include "base.h"
#include <opencv2/opencv.hpp>

class ScaleHorizontal : public baseElement
{
private:
    int countStepsForHorizontalScale = 4;
    float lineLengthForHorizontalScale = 20;
    int markerPosition = 0; // Marker position for the horizontal

    float omegaX = 0.0f;
    float omegaY = 0.0f;

    std::string convertValueToText(float value);

public:
    ScaleHorizontal()
        : baseElement(0.5)
        , countStepsForHorizontalScale(4)
        , lineLengthForHorizontalScale(20)
    {}

    void setCountStepsForHorizontalScale(int value)
    {
        if (value > 0)
            countStepsForHorizontalScale = value;
    }
    void setLineLengthForHorizontalScale(int value)
    {
        if (value > 0)
            lineLengthForHorizontalScale = value;
    }

    void setMarkerPosition(int position)
    {
        markerPosition = position;
    } // Set horizontal marker position
    void drawScale(cv::InputOutputArray img,
                   const cv::Scalar &color,
                   int thickness,
                   int lineType,
                   float value);
    void drawScaleReversed(cv::InputOutputArray img,
                           const cv::Scalar &color,
                           int thickness,
                           int lineType,
                           float value);

    void setOmegaValues(float omegaX, float omegaY); // Метод для отримання значень
};

#endif // SCALEHORIZONTAL_H
