#include "scalingfactor.h"

//scalingFactor::scalingFactor() {}
void scalingFactor::calculateScalingFactors(const cv::InputArray &img, cv::Rect2d rect)
{
    // Scaled rectangle size
    scaledWidth = getScaledWidth(img, rect.width);
    scaledHeight = getScaledHeight(img, rect.height);

    // Scaled rectangle position
    calculateScalingFactors(img, cv::Point(rect.x, rect.y));
}

void scalingFactor::calculateScalingFactors(const cv::InputArray &img, cv::Point point)
{
    // Scaled position
    cv::Point pt = getScaledPoint(img, point);
    posX = pt.x;
    posY = pt.y;
}

double scalingFactor::getScaledWidth(const cv::InputArray &img, int width)
{
    double w;
    w = width * getScaleX(img);
    w = std::max(0.0, std::min(w, static_cast<double>(img.cols())));
    return w;
}

double scalingFactor::getScaledHeight(const cv::InputArray &img, int height)
{
    double h;
    h = height * getScaleY(img);
    h = std::max(0.0, std::min(h, static_cast<double>(img.rows())));
    return h;
}

cv::Point scalingFactor::getScaledPoint(const cv::InputArray &img, cv::Point pt)
{
    cv::Point ptScaled;
    cv::Size size;

    ptScaled.x = pt.x * getScaleX(img);
    ptScaled.y = pt.y * getScaleY(img);

    ptScaled.x = std::max(0.0,
                          std::min(static_cast<double>(
                                       ptScaled.x), //static_cast<double>(img.cols() - scaledWidth)));
                                   static_cast<double>(img.cols())));
    ptScaled.y = std::max(0.0,
                          std::min(static_cast<double>(
                                       ptScaled.y), //static_cast<double>(img.rows() - scaledHeight)));
                                   static_cast<double>(img.rows())));
    return ptScaled;
}

cv::Rect2d scalingFactor::getScaledRect(const cv::InputArray &img, cv::Rect2d rect)
{
    cv::Rect2d rectScaled;
    cv::Point pt;

    pt = getScaledPoint(img, cv::Point(rect.x, rect.y));
    rectScaled.x = pt.x;
    rectScaled.y = pt.y;
    rectScaled.width = getScaledWidth(img, rect.width);
    rectScaled.height = getScaledHeight(img, rect.height);

    return rectScaled;
}
