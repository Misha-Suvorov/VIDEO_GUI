#include "PixelToAngleConverter.h"
#include "qdebug.h"

PixelToAngleConverter::PixelToAngleConverter(cv::Size2f roiSize, cv::Size2f fov, cv::Point opticalCenter, float nonlinearFactor)
    : roiSize(roiSize)
    , fov(fov)
    , opticalCenter(opticalCenter)
    , nonlinearFactor(nonlinearFactor)
{
    roi.x = 0; roi.y = 0; roi.width = roiSize.width; roi.height = roiSize.height;
    updateScaling();
}

void PixelToAngleConverter::updateScaling()
{
    if (roi.width > 0)  degPerPixelX = fov.width / static_cast<double>(roi.width);
    if (roi.height > 0)  degPerPixelY = fov.height / static_cast<double>(roi.height);
}

QPointF PixelToAngleConverter::pixelToAngle(QPoint p) const
{
    // Центр активної зони
    const double cx = opticalCenter.x; //roiX + roiW / 2.0;
    const double cy = opticalCenter.y; //roiY + roiH / 2.0;

    const double dx = p.x() - cx;
    const double dy = p.y() - cy;

    const double angleX = dx * degPerPixelX;
    const double angleY = -dy * degPerPixelY; // вісь Y вниз

    return { angleX, angleY };
}

QPointF PixelToAngleConverter::calculateVoltage(QPointF p, float maxVoltage, bool isRotated) const
{
    float scaleH = maxVoltage / static_cast<double>(roi.width);
    float scaleV = maxVoltage / static_cast<double>(roi.height);

    const double cx = opticalCenter.x;
    const double cy = opticalCenter.y;

    const double dx = p.x() - cx;
    const double dy = p.y() - cy;

    float vH = dx * scaleH;
    //vH -= maxVoltage/2;

    float vV = dy * scaleV;
    //vV -= maxVoltage/2;

    vH = std::clamp((isRotated)? vH:-vH, -maxVoltage/2, maxVoltage/2); // Х перевертаємо
    vV = std::clamp((isRotated)? vV:-vV, -maxVoltage/2, maxVoltage/2); // Y перевертаємо
    qDebug() << "Held movement: vH=" << vH << " vV=" << vV;

    return { vH, vV };
}

QPointF PixelToAngleConverter::calculateVoltageNonlinear(QPointF p, float maxVoltage, bool isRotated) const
{
    float scaleH = maxVoltage / static_cast<double>(roi.width);
    float scaleV = maxVoltage / static_cast<double>(roi.height);

    const double cx = opticalCenter.x;
    const double cy = opticalCenter.y;

    const double dx = p.x() - cx;
    const double dy = p.y() - cy;


    // Кубічна
    auto nonlinear = [](float value, float max, float koef) {
        float norm = value / (max/2); // нормалізуємо [-1..1]
        norm = std::clamp(norm, -1.0f, 1.0f);
        // кубічна залежність
        float shaped = norm * norm * norm;
        return shaped * (max/koef);
    };

    // S-подібна крива
    // auto nonlinear = [](float value, float max) {
    //     float norm = value / (max/2);
    //     norm = std::clamp(norm, -1.0f, 1.0f);
    //     float shaped = std::tanh(norm * 2.0f); // коефіцієнт 2.0 = "крутість" кривої
    //     return shaped * (max/2);
    // };

    float vH = nonlinear(dx * scaleH, maxVoltage, nonlinearFactor);
    float vV = nonlinear(dy * scaleV, maxVoltage, nonlinearFactor);

    vH = std::clamp((isRotated)? vH:-vH, -maxVoltage/2, maxVoltage/2); // Х перевертаємо
    vV = std::clamp((isRotated)? vV:-vV, -maxVoltage/2, maxVoltage/2); // Y перевертаємо
    qDebug() << "Held movement: vH=" << vH << " vV=" << vV;

    return { vH, vV };
}
