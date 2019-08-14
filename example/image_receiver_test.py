import cv2
from ImgReceiver import Receiver

recv = Receiver("udp://127.0.0.1:1853")

recv.open()

while cv2.waitKey(1) != ord('q'):
    ret, image = recv.read()
    if ret == True:
        cv2.imshow("recv", image)
recv.close()
cv2.destroyAllWindows()