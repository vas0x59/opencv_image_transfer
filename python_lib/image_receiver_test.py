import cv2
from opencv_image_transfer.ImgReceiver import Receiver

recv = Receiver("tcp://127.0.0.1:1258")

recv.open()

while cv2.waitKey(1) != ord('q'):
    ret, image = recv.read()
    # print(ret)
    cv2.imshow("recv", image)

recv.close()
cv2.destroyAllWindows()