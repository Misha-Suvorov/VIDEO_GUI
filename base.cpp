#include "base.h"

//base::base(){}

void base::setRect(cv::InputOutputArray img, cv::Rect2d rect)
{
    //rect = ScalingFactor::getScaledRect(img, rect);

    // Get the size of the window
    cv::Size windowSize = { img.cols(), img.rows() };

    // Limit the rectangle coordinates to ensure it stays within the window bounds
    rect.x = std::max(0.0, std::min(rect.x, windowSize.width - rect.width));
    rect.y = std::max(0.0, std::min(rect.y, windowSize.height - rect.height));

    // Limit the rectangle dimensions to ensure it fits within the window bounds
    rect.width = std::min(rect.width, windowSize.width - rect.x);
    rect.height = std::min(rect.height, windowSize.height - rect.y);

    this->rect = rect;
}
