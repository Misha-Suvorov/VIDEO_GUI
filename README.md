videoThread1->setPipeline("udpsrc port=5601 ! tsparse ! tsdemux ! h264parse ! avdec_h264 ! "
                              "videoconvert ! video/x-raw, format=BGR ! appsink sync=false");


void VideoThread::setPipeline(const std::string &pipeline)
{
    gstPipeline = pipeline;
}
