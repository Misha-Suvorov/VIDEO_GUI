#include "scalehorizontal.h""
#include "drawsymbols.h"
#include "scalingfactor.h"
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
        textValue.insert(i, " ");
    }
    return textValue;
}

// void ScaleHorizontal::drawScale(cv::InputOutputArray img, const Scalar& color, int thickness, int lineType, float value)
// {
//     int startX = 650;
//     int startY = 440;
//     int endX = 650;
//     int endY = 100;

//     // Фіолетовий колір
//     Scalar purple(255, 0, 255);

//     // Малюємо головну горизонтальну лінію
//     line(img, Point(startX, startY), Point(endX, endY), purple, thickness, lineType);

//     // Параметри шкали
//     const int startTick = -30;
//     const int endTick = 30;
//     const int tickStep = 10;
//     const int smallTickStep = 5;

//     int lineLength = endX - startX;
//     int numTicks = (endTick - startTick) / tickStep + 1;
//     float tickSpacing = static_cast<float>(lineLength) / (numTicks - 1);
//     float smallTickSpacing = tickSpacing / 2; // Маленькі поділки кожні 5 одиниць

//     // Малюємо основні позначки та цифри
//     for (int i = 0; i < numTicks; i++)
//     {
//         int tickPosX = startX + static_cast<int>(i * tickSpacing);

//         // Основні поділки
//         line(img, Point(tickPosX, startY), Point(tickPosX, startY - 10), purple, thickness, lineType);

//         // Текст для основних міток
//         int tickValue = startTick + (i * tickStep);
//         std::string text = std::to_string(tickValue);
//         Size textSize = getTextSize(text, FONT_HERSHEY_SIMPLEX, 0.5, 2, nullptr);
//         Point ptText = Point(tickPosX - textSize.width / 2, startY - 15);
//         putText(img, text, ptText, FONT_HERSHEY_SIMPLEX, 0.5, purple, 2, lineType);
//     }

//     // Малюємо маленькі поділки між десятками
//     for (int i = 0; i < numTicks - 1; i++)
//     {
//         int smallTickPosX = startX + static_cast<int>(i * tickSpacing + smallTickSpacing);
//         line(img, Point(smallTickPosX, startY), Point(smallTickPosX, startY - 5), purple, thickness, lineType);
//     }
// }



void ScaleHorizontal::drawScale(cv::InputOutputArray img, const Scalar& color, int thickness, int lineType, float value)
{
    int startX = 650;   // Початкова точка по X
    int startY = 440;    // Початкова точка по Y
    int endX = 650;     // Кінцева точка по X (залишаємо той самий)
    int endY = 100;     // Кінцева точка по Y (міняємо, щоб лінія була вертикальною)

    // Фіолетовий колір
    Scalar purple(255, 0, 255);

    // Малюємо головну вертикальну лінію
    line(img, Point(startX, startY), Point(endX, endY), purple, thickness, lineType);

    // Параметри шкали
    const int startTick = -30;
    const int endTick = 30;
    const int tickStep = 10;
    const int smallTickStep = 5;

    int lineLength = endY - startY;  // Для вертикальної шкали
    int numTicks = (endTick - startTick) / tickStep + 1;
    float tickSpacing = static_cast<float>(lineLength) / (numTicks - 1);
    float smallTickSpacing = tickSpacing / 2; // Кожні 5 одиниць

    // Малюємо основні поділки та цифри
    for (int i = 0; i < numTicks; i++)
    {
        int tickPosY = startY + static_cast<int>(i * tickSpacing);

        // Малюємо основні поділки
        line(img, Point(startX, tickPosY), Point(startX + 10, tickPosY), purple, thickness, lineType);

        // Текст для основних міток
        int tickValue = startTick + (i * tickStep);
        std::string text = std::to_string(tickValue);
        Size textSize = getTextSize(text, FONT_HERSHEY_SIMPLEX, 0.5, 3, nullptr);
        Point ptText = Point(startX + 10, tickPosY + textSize.height / 2);  // Текст розташовуємо праворуч
        putText(img, text, ptText, FONT_HERSHEY_SIMPLEX, 0.5, purple, 1, lineType);
    }

    // Малюємо маленькі поділки між десятками (кожні 5 одиниць)
    for (int i = 0; i < numTicks - 1; i++)
    {
        int smallTickPosY = startY + static_cast<int>(i * tickSpacing + smallTickSpacing);
        line(img, Point(startX, smallTickPosY), Point(startX + 5, smallTickPosY), purple, thickness, lineType);
    }
}

