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
    int startX = 100;
    int startY = 60;
    int endX = 620;
    int endY = 60;

    cv::drawLineStroked(img, Point(startX, startY), Point(endX, endY), cv::Scalar(255, 255, 255), thickness, lineType);

    const int startTick = -30;
    const int endTick = 30;
    const int tickStep = 10;
    const int smallTickStep = 5;

    int lineLength = endX - startX;
    int numTicks = (endTick - startTick) / tickStep + 1;
    float tickSpacing = static_cast<float>(lineLength) / (numTicks - 1);
    float smallTickSpacing = tickSpacing / 2;

    for (int i = 0; i < numTicks; i++)
    {
        int tickPosX = startX + static_cast<int>(i * tickSpacing);
        cv::drawLineStroked(img, Point(tickPosX, startY), Point(tickPosX, startY - 10), cv::Scalar(255, 255, 255), thickness, lineType);

        int tickValue = startTick + (i * tickStep);
        std::string text = std::to_string(tickValue);
        Size textSize = getTextSize(text, FONT_HERSHEY_SIMPLEX, 0.5 , 3, nullptr);
        Point ptText = Point(tickPosX - textSize.width / 2, startY - 15);
        cv::putTextStroked(img, text, ptText, FONT_HERSHEY_SIMPLEX, 0.5 , cv::Scalar(255, 255, 255), 1, lineType);
    }

    for (int i = 0; i < numTicks - 1; i++)
    {
        int smallTickPosX = startX + static_cast<int>(i * tickSpacing + smallTickSpacing);
        cv::drawLineStroked(img, Point(smallTickPosX, startY), Point(smallTickPosX, startY - 5), cv::Scalar(255, 255, 255), thickness, lineType);
    }

    // Задаємо позицію червоного маркера як вертикальну лінію
    int centerPosX = startX + lineLength / 2;
    int markerHeight = 10; // Висота маркера
    cv::drawLineStroked(img, Point(centerPosX, startY), Point(centerPosX, startY - markerHeight), cv::Scalar(0, 0, 255), thickness + 1, lineType);
}
