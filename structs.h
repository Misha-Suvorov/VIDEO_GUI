#ifndef STRUCTS_H
#define STRUCTS_H
#include <opencv2/opencv.hpp>
enum LineTypeSymbols { UNSTROKED = 1, STROKED };
enum ModePlatform { INERT, BODY, EARTH, TRACKING };
enum Result {S_OK, S_FAIL, S_FAIL_OFFSET};

struct Voltage
{
    float x = 1.0f;
    float y = 1.0f;
};

struct VideoConfig {
    cv::Rect roi; // x, y, width, height
    cv::Rect fullFrame;
    cv::Size2f fovVideo1;    // width, height в градусах ШПЗ
    cv::Size2f fovVideo2;    // width, height в градусах ВПЗ

    float nonlinearFactor1; // коефіцієнт нелінійності для плавного руху біля центру ШПЗ
    float nonlinearFactor2; // коефіцієнт нелінійності для плавного руху біля центру ВПЗ

    cv::Point opticalCenter;
};


#endif // STRUCTS_H
