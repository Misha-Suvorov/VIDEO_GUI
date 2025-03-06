#include "drawsymbols.h"
#include <opencv2/opencv.hpp>

namespace cv
{
void drawGuidanceMarker(InputOutputArray img, Rect2d rect, const Scalar& color,
                        int thickness, int lineLength, int lineType)
{
    //Up Left corner
    int lineLengthPx = (lineLength/100.0f)*rect.width;
    Point ptLeftUp = Point(rect.x, rect.y);
    cv::line(img, ptLeftUp, Point(ptLeftUp.x + lineLengthPx, ptLeftUp.y), color, thickness, lineType);
    cv::line(img, ptLeftUp, Point(ptLeftUp.x , ptLeftUp.y + lineLengthPx), color, thickness, lineType);

    //Up Right corner
    Point ptRightUp = Point(rect.x + rect.width, rect.y);
    cv::line(img, ptRightUp, Point(ptRightUp.x - lineLengthPx, ptRightUp.y), color, thickness, lineType);
    cv::line(img, ptRightUp, Point(ptRightUp.x , ptRightUp.y + lineLengthPx), color, thickness, lineType);

    //Down Right corner
    Point ptRightDown = Point(rect.x + rect.width, rect.y + rect.height);
    cv::line(img, ptRightDown, Point(ptRightDown.x - lineLengthPx, ptRightDown.y), color, thickness, lineType);
    cv::line(img, ptRightDown, Point(ptRightDown.x , ptRightDown.y - lineLengthPx), color, thickness, lineType);

    //Down Left corner
    Point ptLeftDown = Point(rect.x, rect.y + rect.height);
    cv::line(img, ptLeftDown, Point(ptLeftDown.x + lineLengthPx, ptLeftDown.y), color, thickness, lineType);
    cv::line(img, ptLeftDown, Point(ptLeftDown.x , ptLeftDown.y - lineLengthPx), color, thickness, lineType);

}




void putTextStroked(InputOutputArray img, const String& text, Point point, int fontFace, double fontScale, const Scalar& color,
                    int thickness, int lineType)
{
    thickness = std::max(thickness, 0); //protection against entering a negative value of thickness
    if (lineType == STROKED) putText(img, text, point, fontFace, fontScale, Scalar(0, 0, 0), thickness * 2, LINE_AA);
    putText(img, text, point, fontFace, fontScale, color, thickness, LINE_AA);
}


void drawRectStroked(InputOutputArray img, Rect2d rect, const Scalar& color,
                     int thickness, int lineType)
{
    thickness = std::max(thickness, 0); //protection against entering a negative value of thickness
    if (lineType == STROKED) rectangle(img, rect, Scalar(0,0,0), thickness * 2, LINE_AA);
    rectangle(img, rect, color, thickness, LINE_AA);
}


void drawLineStroked(InputOutputArray img, Point pt1, Point pt2, const Scalar& color,
                     int thickness, int lineType)
{
    thickness = std::max(thickness, 0); //protection against entering a negative value of thickness
    if (lineType == STROKED) line(img, pt1, pt2, Scalar(0,0,0), thickness * 2, LINE_8);
    line(img, pt1, pt2, color, thickness, LINE_8);
}

void drawPolylinesStroked(InputOutputArray img, std::vector<Point> pts,
                          bool isClosed, const Scalar& color, int thickness, int lineType)
{
    thickness = std::max(thickness, 0); //protection against entering a negative value of thickness
    if (lineType == STROKED)
    {
        polylines(img, pts, true, Scalar(0, 0, 0), thickness * 2, LINE_AA);
        //redraw the beak outline because it is not visible and it should be thicker
        //line(img, pts[1], pts[2], Scalar(0, 0, 0), thickness * 3, LINE_AA);
        //line(img, pts[2], pts[3], Scalar(0, 0, 0), thickness * 3, LINE_AA);
    }
    polylines(img, pts, true, color, thickness, LINE_AA);
}


}
