import cv2
import threading
import time


class Receiver:
    def __init__(self, url, image_size = (240, 320, 3), timeout = 0.5):
        self.running = False
        self.image_size = image_size
        self.timeout = timeout
        self.image = np.zeros(self.image_size, np.uint8)
        self.timeouted = False
        self.url = url
    def open(self):
        self.running = True
    def close(self):
        self.running = False
    def read(self):
        # return 
        return (self.running and (not self.timeouted)), self.image
