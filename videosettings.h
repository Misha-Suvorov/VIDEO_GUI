// VideoSettings.h
#pragma once
#include "pixeltoangleconverter.h"
#include "qwidget.h"
#include "structs.h"

class VideoSettings
{
public:
    explicit VideoSettings(QObject *parent = nullptr);
    //VideoSettings();
    void update(const VideoConfig& config, bool isSwitched, bool isRotated);
    PixelToAngleConverter& getConverter() { return converter; }
    QPointF mapToVideoCoordinates(const QPoint &clickPos, QSize labelSize, const VideoConfig *config);
    const VideoConfig& getConfig() const { return videoConfig; }
    bool isSwitched = false;
    bool isRotated = false;

private:
    VideoConfig videoConfig;
    cv::Size2f roiSize, fov;
    cv::Point opticalCenter;
    float FOVWidth, FOVHeight;
    float nonlinearFactor;

    PixelToAngleConverter converter;

    QWidget *QWidget;
};


