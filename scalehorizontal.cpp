#include "scalehorizontal.h"
#include "drawsymbols.h"
#include "scalingfactor.h"
#include "LpsParameters.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

std::string ScaleHorizontal::convertValueToText(float value)
{
    std::string textValue = std::to_string(static_cast<int>(std::round(value)));
    int width = (value < 10) ? 3 : (value < 100) ? 2 : (value < 1000) ? 1 : 0;
    for (int i = 0; i < width; i++)
    {
        textValue.insert(0, " "); // Insert spaces at the beginning
    }
    return textValue;
}

void ScaleHorizontal::setOmegaValues(float omegaX, float omegaY)
{
    this->omegaX = omegaX;
    this->omegaY = omegaY;
}



void ScaleHorizontal::drawScale(cv::InputOutputArray img, const Scalar& color, int thickness, int lineType, float value)
{
    int startX = 100;
    int startY = 60;
    int endX = 620;
    int endY = 60;
    int centerX = (startX + endX) / 2;  // Center of the entire scale
    float coefX = ((endX - startX) / 2) / 30.0;

    // Draw the main line (horizontal in this case)
    cv::drawLineStroked(img, Point(startX, startY), Point(endX, endY), cv::Scalar(255, 255, 255), thickness, lineType);

    const int startTick = -30;
    const int endTick = 30;
    const int tickStep = 10;
    const int smallTickStep = 5;

    int lineLength = endX - startX;
    int numTicks = (endTick - startTick) / tickStep + 1;
    float tickSpacing = static_cast<float>(lineLength) / (numTicks - 1);
    float smallTickSpacing = tickSpacing / 2;

    // Draw the ticks and their labels
    for (int i = 0; i < numTicks; i++)
    {
        int tickPosX = startX + static_cast<int>(i * tickSpacing);
        cv::drawLineStroked(img, Point(tickPosX, startY), Point(tickPosX, startY - 10), cv::Scalar(255, 255, 255), thickness, lineType);

        int tickValue = startTick + (i * tickStep);
        std::string text = std::to_string(tickValue);
        Size textSize = getTextSize(text, FONT_HERSHEY_SIMPLEX, 0.5, 3, nullptr);
        Point ptText = Point(tickPosX - textSize.width / 2, startY - 15);
        cv::putTextStroked(img, text, ptText, FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1, lineType);
    }

    // Draw small ticks between the main ticks
    for (int i = 0; i < numTicks - 1; i++)
    {
        int smallTickPosX = startX + static_cast<int>(i * tickSpacing + smallTickSpacing);
        cv::drawLineStroked(img, Point(smallTickPosX, startY), Point(smallTickPosX, startY - 5), cv::Scalar(255, 255, 255), thickness, lineType);
    }

    // Calculate the static position for the text
    std::string textValue = convertValueToText(value);
    Size textSize = getTextSize(textValue, FONT_HERSHEY_SIMPLEX, 0.5, 3, nullptr);
    Point textPosition = Point(centerX - textSize.width / 2, startY - 30);  // Center-aligned text, static position

    // Draw the text at the calculated static position
    cv::putTextStroked(img, textValue, textPosition, FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1, lineType);

    // Draw the marker based on the value
    float markerPosX = value * coefX + centerX;
    Point pt1 = Point(markerPosX, startY);
    Point pt2 = Point(markerPosX, startY - 10);
    cv::drawLineStroked(img, pt1, pt2, cv::Scalar(0, 0, 255), thickness + 1, lineType);

    // Draw omega values in the top-left corner
    std::string omegaTextX = "w horizontal = " + std::to_string(omegaX);
    std::string omegaTextY = "w vertical = " + std::to_string(omegaY);
    cv::putText(img, omegaTextX, Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 255, 255), 2);
    cv::putText(img, omegaTextY, Point(10, 60), FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(255, 255, 255), 2);
}
