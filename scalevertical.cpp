#include "scalevertical.h"
#include "drawsymbols.h"
#include "scalingfactor.h"

using namespace cv;

//ScaleVertical::ScaleVertical(){}
std::string ScaleVertical::convertValueToText(float value)
{
    int width;
    std::string textValue = std::to_string(static_cast<int>(std::round(value)));

    // Set the width of the text alignment based on the number of characters
    width = (value < 10) ? 3 : (value < 100) ? 2 : (value < 1000) ? 1 : 0;

    // Insert spaces
    for (int i = 0; i < width; i++)
    {
        textValue.insert(i, " ");
    }

    return textValue;
}


void ScaleVertical::drawScale(cv::InputOutputArray img, const cv::Scalar& color, int thickness, int lineType, float value)
{
    double intpart, fractpart;
    float fractPx; //fraction in pixels

    int dash;
    std::string text;

    fractpart = modf(value / 10, &intpart);

    //Count of big dishes in the rect area
    const int countSteps = countStepsForVerticalScale;
    const float stepSize = rect.height / countSteps;

    //Length of big and small dashes
    //const float lineLength = lineLengthForVerticalScale * scalingFactor::getScaleX(img);
    //const int lineLengthSmall = lineLength / 2;
    //const float offsetTextPositionFromDash = 5 * scalingFactor::getScaleX(img);


    fractPx = fractpart * stepSize;

    Point topLeft = Point(rect.x, rect.y);
    Point center = Point(rect.x, rect.y + rect.height / 2);
    float offsetFromCenter = center.y + fractPx;

    // Convert InputOutputArray to Mat
    Mat inputImage = img.getMat();

    // Extract region of interest from input image
    Mat roi = inputImage(rect);

    Point center1 = Point(2, rect.height / 2);
    float offsetFromCenter1 = center1.y + fractPx;

    /*for (int i = 0; i < 4; i++)
    {
        dash = (int)((intpart + i) * 10);
        if (dash >= 0)
        {
            Point ptDash = Point(center1.x, offsetFromCenter1 - i * stepSize);
            cv::drawLineStroked(roi, ptDash, Point(ptDash.x + lineLength, ptDash.y), color, thickness, lineType);

            ptDash = Point(ptDash.x, offsetFromCenter1 - stepSize / 2 - i * stepSize);
            cv::drawLineStroked(roi, ptDash, Point(ptDash.x + lineLengthSmall, ptDash.y), color, thickness, lineType);

            text = std::to_string(dash);
            cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness, nullptr);
            int textHalfHeight = textSize.height / 2;

            Point ptText = Point(center1.x + lineLength + offsetTextPositionFromDash,
                                 offsetFromCenter1 - i * stepSize + textHalfHeight);
            cv::putTextStroked(roi, text, ptText, fontFace, fontScale, color, thickness, lineType);

        }
    }
    for (int i = 0; i < 3; i++)
    {
        dash = (int)((intpart - i) * 10);
        if (dash >= 0)
        {
            Point ptDash = Point(center1.x, offsetFromCenter1 + i * stepSize);
            cv::drawLineStroked(roi, ptDash, Point(ptDash.x + lineLength, ptDash.y), color, thickness, lineType);

            ptDash = Point(ptDash.x, offsetFromCenter1 - stepSize / 2 + i * stepSize);
            cv::drawLineStroked(roi, ptDash, Point(ptDash.x + lineLengthSmall, ptDash.y), color, thickness, lineType);

            text = std::to_string(dash);
            cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness, nullptr);
            int textHalfHeight = textSize.height / 2;

            Point ptText = Point(center1.x + lineLength + offsetTextPositionFromDash,
                                 offsetFromCenter1 + i * stepSize + textHalfHeight);
            cv::putTextStroked(roi, text, ptText, fontFace, fontScale, color, thickness, lineType);

        }
    }*/
    //cv::rectangle(img, rect, cv::Scalar(255, 0, 0));
    //cv::line(roi, center1, Point(center1.x + 100, center1.y), cv::Scalar(255, 0, 0));
    cv::line(img, Point(100,60), Point(620,60), cv::Scalar(255, 0, 0),2);




    // Main line coordinates
    int startX = 100;  // Start X coordinate of the main line
    int startY = 60;   // Y coordinate of the main line
    int endX = 620;    // End X coordinate of the main line
    int endY = 60;     // Y coordinate of the main line (same as startY for horizontal line)

    // Constants for the scale
    const int startTick = -30; // Starting from -30
    const int endTick = 30;    // Going up to +30
    const int tickStep = 10;   // Tick step is 10

    // Length of the line
    int lineLength = endX - startX;

    // Number of ticks we need based on the range and the tick step
    int numTicks = (endTick - startTick) / tickStep + 1;
    float tickSpacing = static_cast<float>(lineLength) / (numTicks - 1);  // Spacing between ticks

    // Loop through the range from -30 to +30
    for (int i = startTick; i <= endTick; i += tickStep)
    {
        // Calculate the position for each tick along the horizontal line
        int tickPosX = startX + (i - startTick) * tickSpacing;

        // Draw the vertical tick (perpendicular to the main line)
        Point ptStart = Point(tickPosX, startY);
        Point ptEnd = Point(tickPosX, startY - 10); // Length of the small tick (can be adjusted)
        cv::line(img, ptStart, ptEnd, color, thickness, lineType);

        // Draw the text for the tick
        std::string text = std::to_string(i);
        cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness, nullptr);
        int textHalfHeight = textSize.height / 2;

        // Position the text below the tick
        Point ptText = Point(tickPosX - textSize.width / 2, ptEnd.y - 5);
        cv::putText(img, text, ptText, fontFace, fontScale, color, thickness, lineType);
    }

}



