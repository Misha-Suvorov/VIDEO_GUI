#pragma once

#include "structs.h"
#include <opencv2/core.hpp>

// Default resolution for size and position recalculation for symbols
const int defaultScreenWidth = 1600;
const int defaultScreenHeight = 900;

namespace cv {

void drawGuidanceMarker(InputOutputArray img,
                        Rect2d rect,
                        const Scalar &color,
                        int thickness = 1,
                        int lineLength = 50,
                        int lineType = 1);

void putTextStroked(InputOutputArray img,
                    const String &text,
                    Point point,
                    int fontFace,
                    double fontScale,
                    const Scalar &color,
                    int thickness = 1,
                    int lineType = UNSTROKED);

void putTextStrokedRotated(InputOutputArray img,
                           const std::string &text,
                           cv::Point org,
                           int fontFace,
                           double fontScale,
                           const cv::Scalar &color,
                           int thickness,
                           int lineType);

void drawLineStroked(InputOutputArray img,
                     Point pt1,
                     Point pt2,
                     const Scalar &color,
                     int thickness = 1,
                     int lineType = UNSTROKED);
void drawPolylinesStroked(InputOutputArray img,
                          std::vector<Point> pts,
                          bool isClosed,
                          const Scalar &color,
                          int thickness = 1,
                          int lineType = UNSTROKED);
void drawRectStroked(InputOutputArray img,
                     Rect2d rect,
                     const Scalar &color,
                     int thickness = 1,
                     int lineType = UNSTROKED);
} // namespace cv
