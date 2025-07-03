#ifndef BASE_H
#define BASE_H
#include <opencv2/opencv.hpp>>
class baseElement
{
protected:
    cv::Rect2d rect;
    int fontFace = cv::FONT_HERSHEY_SIMPLEX;
    double fontScale = 1;

public:
    baseElement(double fontScale)
        : fontScale(fontScale) {};
    void setRect(cv::InputOutputArray img, cv::Rect2d rect);
    void setFontFace(int fontFace) { this->fontFace = fontFace; }
    void setFontScale(cv::InputOutputArray img, double fontScale);
};

#endif // BASE_H
