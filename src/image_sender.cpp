#include "image_sender.h"

using namespace cv;
namespace opencv_image_transfer
{
bool ImgSender::load_config(string config_path)
{
    FileStorage fs2;
    
    fs2.open(String(config_path.c_str()), FileStorage::READ);
    // FileStorage()
    
    fs2["sub_url"] >> sub_url;
    int img_w, img_h;

    fs2["img_w"] >> img_w;
    fs2["img_h"] >> img_h;

    image_size = Size(img_w, img_h);
    fs2.release();
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
    // std::cout << image.data;
    // image.resize()
    Mat img_b;
    // image.copyTo(img_b);
    resize(image,img_b,image_size);
    img_b = (img_b.reshape(0,1)); // to make it continuous
    // std::cout << img_b.total() << "\n";
    int  imgSize = img_b.total()*img_b.elemSize();
    zmq_send(publisher, img_b.data, imgSize, ZMQ_NOBLOCK);
}
void ImgSender::close(){
    zmq_close(publisher);
	zmq_ctx_destroy(context);
}
} // namespace opencv_image_transfer