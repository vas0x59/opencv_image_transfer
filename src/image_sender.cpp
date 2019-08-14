#include "image_sender.h"

using namespace cv;
namespace opencv_image_transfer
{
bool ImgSender::load_config(string config_path)
{
    FileStorage fs2(config_path, FileStorage::READ);
    fs2["sub_url"] >> sub_url;
    int img_w, img_h;

    fs2["img_w"] >> img_w;
    fs2["img_h"] >> img_h;

    image_size = Size(img_w, img_h);

    return true;
}
bool ImgSender::open()
{
    context = zmq_ctx_new();
    publisher = zmq_socket(context, ZMQ_PUB);
    bind = zmq_bind(publisher, sub_url.c_str());
    return true;
}
void ImgSender::send_img(cv::Mat image)
{
    zmq_send(publisher, image.data, (image.rows*image.cols*image.channels()*sizeof(CV_8U)), ZMQ_NOBLOCK);
}
void ImgSender::close(){
    zmq_close(publisher);
	zmq_ctx_destroy(context);
}
} // namespace opencv_image_transfer