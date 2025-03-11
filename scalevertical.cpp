#include "scalevertical.h"
#include "drawsymbols.h"
#include "scalingfactor.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

std::string ScaleVertical::convertValueToText(float value)
{
    std::string textValue = std::to_string(static_cast<int>(std::round(value)));
    int width = (value < 10) ? 3 : (value < 100) ? 2 : (value < 1000) ? 1 : 0;
    for (int i = 0; i < width; i++)
    {
        textValue.insert(i, " ");
    }
    return textValue;
}



void ScaleVertical::drawScale(cv::InputOutputArray img, const Scalar& color, int thickness, int lineType, float value)
{
    int startX = 650;
    int startY = 440;
    int endX = 650;
    int endY = 100;
    int centerY = (startY + endY) / 2;
    float coefY = ((startY - endY) / 2) / 30.0;
    cv::drawLineStroked(img, Point(startX, startY), Point(endX, endY), cv::Scalar(255, 255, 255), thickness, lineType);

    const int startTick = -30;
    const int endTick = 30;
    const int tickStep = 10;
    const int smallTickStep = 5;

    int lineLength = startY - endY;
    int numTicks = (endTick - startTick) / tickStep + 1;
    float tickSpacing = static_cast<float>(lineLength) / (numTicks - 1);
    float smallTickSpacing = tickSpacing / 2;

    for (int i = 0; i < numTicks; i++)
    {
        int tickPosY = startY - static_cast<int>(i * tickSpacing);
        cv::drawLineStroked(img, Point(startX, tickPosY), Point(startX + 10, tickPosY), cv::Scalar(255, 255, 255), thickness, lineType);

        int tickValue = startTick + (i * tickStep);
        std::string text = std::to_string(tickValue);
        Size textSize = getTextSize(text, FONT_HERSHEY_SIMPLEX, 0.5, 3, nullptr);
        Point ptText = Point(startX + 15, tickPosY + textSize.height / 2);
        cv::putTextStroked(img, text, ptText, FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1, lineType);
    }

    for (int i = 0; i < numTicks - 1; i++)
    {
        int smallTickPosY = startY - static_cast<int>(i * tickSpacing + smallTickSpacing);
        cv::drawLineStroked(img, Point(startX, smallTickPosY), Point(startX + 5, smallTickPosY), cv::Scalar(255, 255, 255), thickness, lineType);
    }
    std::string textValue = convertValueToText(-value);
    Size textSize = getTextSize(textValue, FONT_HERSHEY_SIMPLEX, 0.5, 3, nullptr);
    Point textPosition = Point(startX + 20, centerY);  // Center-aligned text, static position

    // Draw the text at the calculated static position
    cv::putTextStroked(img, textValue, textPosition, FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1, lineType);


    float markerPosY = value * coefY + centerY;

    Point pt1 =  Point(startX, markerPosY);
    Point pt2 = Point(startX + 10, markerPosY);
    cv::drawLineStroked(img, pt1, pt2, cv::Scalar(0, 0, 255), thickness + 1, lineType);
}
