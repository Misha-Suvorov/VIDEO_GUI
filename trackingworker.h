#ifndef TRACKINGWORKER_H
#define TRACKINGWORKER_H

#include <QMutex>
#include <QObject>

#include "pixeltoangleconverter.h"
#include "structs.h"
#include "videosettings.h"
#include <opencv2/core/mat.hpp>
#include <opencv2/tracking.hpp>

class TrackingWorker : public QObject
{
    Q_OBJECT
public:
    explicit TrackingWorker(QObject *parent = nullptr);
    ~TrackingWorker();
    void setVideoSettings(VideoSettings* settings) { this->settings = settings; }

public slots:
    void processFrame(const cv::Mat &frame);
    void setTrackingROI(const cv::Rect &roi);
    void stopProcessing();

signals:
    void anglesCalculated(float angleX, float angleY);
    void roiUpdated(const cv::Rect &roi);

private:
    cv::Ptr<cv::Tracker> tracker;
    cv::Rect opencvRoi;
    QMutex mutex;
    bool isTracking = false;
    PixelToAngleConverter converter;
    bool roiNeedsInit = false;
    VideoConfig videoConfig;
    VideoSettings* settings = nullptr;

    cv::Size2f roiSize;
    cv::Size2f fov;
    cv::Point opticalCenter;
    float nonlinearFactor;

    bool isSwitched = false;
    bool isRotated = false;
};

#endif // TRACKINGWORKER_H
