
#pragma once

#include "opencv2/opencv.hpp"
#include "opencv2/ximgproc.hpp"

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "zmq.h"

using namespace std;
namespace opencv_image_transfer
{
class ImgSender
{
public:
    // ImgSender();
    bool load_config(string config_path);
    // void wait_sub();
    bool open();
    void close();
    void send_img(cv::Mat image);

private:
    cv::Size image_size = cv::Size(320, 240);
    string sub_url = "tcp://*:1258";
    bool mode = 0;
    int bind;
    void *publisher;
    void *context;
    // int wait_url  =  "";
};
} // namespace opencv_image_transfer