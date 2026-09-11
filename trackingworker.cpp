#include "trackingworker.h"
#include <QDebug>
#include "pixeltoangleconverter.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/tracking.hpp>

TrackingWorker::TrackingWorker(QObject *parent)
    : QObject(parent)
    , converter(cv::Size2f(1,1), cv::Size2f(1,1), cv::Point(0,0), 1.0f)
{
    tracker = cv::TrackerCSRT::create();
}

TrackingWorker::~TrackingWorker()
{
    // Clean up resources if needed
}

void TrackingWorker::processFrame(const cv::Mat &frame)
{
    QMutexLocker locker(&mutex);
    if (frame.empty()) {
        return;
    }

    //converter.setImageSize(frame.cols, frame.rows);
    //converter.setFOV(120.0f, 90.0f);

    if (roiNeedsInit) {
        tracker = cv::TrackerCSRT::create();
        tracker->init(frame, opencvRoi);
        isTracking = true;
        roiNeedsInit = false;
        qDebug() << "Tracker re-initialized with new ROI.";
    }

    if (isTracking) {
        if (tracker->update(frame, opencvRoi)) {
            float centerX = opencvRoi.x + opencvRoi.width / 2.0f;
            float centerY = opencvRoi.y + opencvRoi.height / 2.0f;


            //auto[videoX, videoY] = scaleClick(clickPos);

            QPointF angles = converter.pixelToAngle(QPoint(centerX, centerY));
            //std::pair<float, float> angles = converter.pixelToAngle(static_cast<int>(centerX),
            //                                                        static_cast<int>(centerY));
            emit anglesCalculated(angles.x(), angles.y());
            emit roiUpdated(opencvRoi); // Відправляємо оновлений ROI
        } else {
            isTracking = false;
            qDebug() << "Tracking lost.";
        }
    }
}

void TrackingWorker::setTrackingROI(const cv::Rect &roi)
{
    QMutexLocker locker(&mutex);
    opencvRoi = roi;
    roiNeedsInit = true;
}

void TrackingWorker::stopProcessing()
{
    // Clean up if necessary
}


