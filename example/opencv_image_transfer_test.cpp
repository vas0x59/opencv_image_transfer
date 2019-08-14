#include "opencv2/opencv.hpp"
#include "opencv2/ximgproc.hpp"

#include "image_sender.h"

#include <iostream>
#include <unistd.h>
#include <sys/time.h>

#define INTERVAL 100

using namespace cv;
using namespace opencv_image_transfer;

uint64_t get_time_msec()
{
    static struct timeval _time_stamp;
    gettimeofday(&_time_stamp, NULL);
    return _time_stamp.tv_sec * 1000 + _time_stamp.tv_usec / 1000;
}

int main()
{
    VideoCapture cap(0);
    ImgSender sender;
    sender.load_config("config/config.yml");
    sender.open();
    uint64_t prev_t = get_time_msec();
    while (true == true)
    {
        Mat frame;
        cap >> frame;
        if ((get_time_msec() - prev_t) >= INTERVAL)
        {
            prev_t = get_time_msec();
            sender.send_img(frame);
        }
    }
}