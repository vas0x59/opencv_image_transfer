
#pragma once

#include "opencv2/opencv.hpp"
#include "opencv2/ximgproc.hpp"

namespace opencv_image_transfer
{
class ImgSender
{
public:
    ImgSender();
    ImgSender(cv::Size image_size_);
    bool open();
    void close();
    void send_img(cv::Mat image);

private:
    cv::Size image_size = cv::Size(320, 240);
};
} // namespace opencv_image_transfer