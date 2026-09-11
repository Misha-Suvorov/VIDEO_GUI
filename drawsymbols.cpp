#include "drawsymbols.h"
#include <opencv2/opencv.hpp>

namespace cv {
void drawGuidanceMarker(InputOutputArray img,
                        Rect2d rect,
                        const Scalar &color,
                        int thickness,
                        int lineLength,
                        int lineType)
{
    //Up Left corner
    int lineLengthPx = (lineLength / 100.0f) * rect.width;
    Point ptLeftUp = Point(rect.x, rect.y);
    cv::line(img, ptLeftUp, Point(ptLeftUp.x + lineLengthPx, ptLeftUp.y), color, thickness, lineType);
    cv::line(img, ptLeftUp, Point(ptLeftUp.x, ptLeftUp.y + lineLengthPx), color, thickness, lineType);

    //Up Right corner
    Point ptRightUp = Point(rect.x + rect.width, rect.y);
    cv::line(img,
             ptRightUp,
             Point(ptRightUp.x - lineLengthPx, ptRightUp.y),
             color,
             thickness,
             lineType);
    cv::line(img,
             ptRightUp,
             Point(ptRightUp.x, ptRightUp.y + lineLengthPx),
             color,
             thickness,
             lineType);

    //Down Right corner
    Point ptRightDown = Point(rect.x + rect.width, rect.y + rect.height);
    cv::line(img,
             ptRightDown,
             Point(ptRightDown.x - lineLengthPx, ptRightDown.y),
             color,
             thickness,
             lineType);
    cv::line(img,
             ptRightDown,
             Point(ptRightDown.x, ptRightDown.y - lineLengthPx),
             color,
             thickness,
             lineType);

    //Down Left corner
    Point ptLeftDown = Point(rect.x, rect.y + rect.height);
    cv::line(img,
             ptLeftDown,
             Point(ptLeftDown.x + lineLengthPx, ptLeftDown.y),
             color,
             thickness,
             lineType);
    cv::line(img,
             ptLeftDown,
             Point(ptLeftDown.x, ptLeftDown.y - lineLengthPx),
             color,
             thickness,
             lineType);
}

void putTextStroked(InputOutputArray img,
                    const String &text,
                    Point point,
                    int fontFace,
                    double fontScale,
                    const Scalar &color,
                    int thickness,
                    int lineType)
{
    thickness = std::max(thickness, 0); //protection against entering a negative value of thickness
    if (lineType == STROKED)
        putText(img, text, point, fontFace, fontScale, Scalar(0, 0, 0), thickness * 2, LINE_AA);
    putText(img, text, point, fontFace, fontScale, color, thickness, LINE_AA);
}
void putTextStrokedRotated(InputOutputArray img,
                           const std::string &text,
                           cv::Point org,
                           int fontFace,
                           double fontScale,
                           const cv::Scalar &color,
                           int thickness,
                           int lineType)
{
    thickness = std::max(thickness, 0);

    int baseline = 0;
    cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);

    // Створюємо прозору картинку з альфа-каналом (BGR, без альфи, як у звичайному putText)
    cv::Mat textImg(textSize.height + baseline, textSize.width, CV_8UC3, cv::Scalar(0, 0, 0));

    // Якщо треба обводку — малюємо чорний текст потовщено
    if (lineType == STROKED)
        cv::putText(textImg,
                    text,
                    cv::Point(0, textSize.height),
                    fontFace,
                    fontScale,
                    cv::Scalar(0, 0, 0),
                    thickness * 2,
                    cv::LINE_AA);

    // Малюємо основний кольоровий текст
    cv::putText(textImg,
                text,
                cv::Point(0, textSize.height),
                fontFace,
                fontScale,
                color,
                thickness,
                cv::LINE_AA);

    // Повертаємо на 180°
    cv::Mat rotated;
    cv::rotate(textImg, rotated, cv::ROTATE_180);

    // Розраховуємо позицію так само, як і OpenCV це робить
    int x = org.x - rotated.cols + 1;
    int y = org.y - rotated.rows + baseline;

    // Доступ до зображення
    cv::Mat &dst = img.getMatRef();

    // Просто копіюємо пікселі, без прозорості — як `putText`
    for (int i = 0; i < rotated.rows; ++i) {
        for (int j = 0; j < rotated.cols; ++j) {
            int dstY = y + i;
            int dstX = x + j;
            if (dstX >= 0 && dstX < dst.cols && dstY >= 0 && dstY < dst.rows) {
                cv::Vec3b px = rotated.at<cv::Vec3b>(i, j);
                if (px != cv::Vec3b(0, 0, 0)) // пропускаємо чорне тло
                    dst.at<cv::Vec3b>(dstY, dstX) = px;
            }
        }
    }
}

// void putTextStrokedRotated(cv::InputOutputArray img, const std::string& text, cv::Point org,
//                               int fontFace, double fontScale, const cv::Scalar& color,
//                               int thickness, int lineType)
// {
//     thickness = std::max(thickness, 0);

//     int baseline = 0;
//     cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);

//     cv::Mat textImg(textSize.height + baseline, textSize.width, CV_8UC4, cv::Scalar(0, 0, 0, 0));

//     if (lineType == STROKED)
//         cv::putText(textImg, text, cv::Point(0, textSize.height), fontFace, fontScale,
//                     cv::Scalar(0, 0, 0, 255), thickness * 2, cv::LINE_AA);

//     cv::putText(textImg, text, cv::Point(0, textSize.height), fontFace, fontScale,
//                 cv::Scalar(color[0], color[1], color[2], 255), thickness, cv::LINE_AA);

//     cv::Mat rotated;
//     cv::rotate(textImg, rotated, cv::ROTATE_180);

//     int x = org.x - rotated.cols + 1;
//     int y = org.y - rotated.rows + baseline;

//     // ОТРИМУЄМО Мат для прямого доступу до пікселів
//     cv::Mat& dst = img.getMatRef();

//     for (int i = 0; i < rotated.rows; ++i)
//     {
//         for (int j = 0; j < rotated.cols; ++j)
//         {
//             cv::Vec4b &px = rotated.at<cv::Vec4b>(i, j);
//             if (px[3] > 0)
//             {
//                 int dstY = y + i;
//                 int dstX = x + j;
//                 if (dstX >= 0 && dstX < dst.cols && dstY >= 0 && dstY < dst.rows)
//                 {
//                     dst.at<cv::Vec3b>(dstY, dstX) = cv::Vec3b(px[0], px[1], px[2]);
//                 }
//             }
//         }
//     }
// }

void drawRectStroked(
    InputOutputArray img, Rect2d rect, const Scalar &color, int thickness, int lineType)
{
    thickness = std::max(thickness, 0); //protection against entering a negative value of thickness
    if (lineType == STROKED)
        rectangle(img, rect, Scalar(0, 0, 0), thickness * 2, LINE_AA);
    rectangle(img, rect, color, thickness, LINE_AA);
}

void drawLineStroked(
    InputOutputArray img, Point pt1, Point pt2, const Scalar &color, int thickness, int lineType)
{
    thickness = std::max(thickness, 0); //protection against entering a negative value of thickness
    if (lineType == STROKED)
        line(img, pt1, pt2, Scalar(0, 0, 0), thickness * 2, LINE_8);
    line(img, pt1, pt2, color, thickness, LINE_8);
}

void drawPolylinesStroked(InputOutputArray img,
                          std::vector<Point> pts,
                          bool isClosed,
                          const Scalar &color,
                          int thickness,
                          int lineType)
{
    thickness = std::max(thickness, 0); //protection against entering a negative value of thickness
    if (lineType == STROKED) {
        polylines(img, pts, true, Scalar(0, 0, 0), thickness * 2, LINE_AA);
        //redraw the beak outline because it is not visible and it should be thicker
        //line(img, pts[1], pts[2], Scalar(0, 0, 0), thickness * 3, LINE_AA);
        //line(img, pts[2], pts[3], Scalar(0, 0, 0), thickness * 3, LINE_AA);
    }
    polylines(img, pts, true, color, thickness, LINE_AA);
}

} // namespace cv
