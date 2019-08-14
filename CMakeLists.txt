cmake_minimum_required (VERSION 2.6)
project (opencv_image_transfer)

include_directories("./src")
include_directories("./examples")

add_library(opencv_image_transfer  SHARED
    ./src/image_sender.cpp
)

find_package( OpenCV REQUIRED )


add_executable(opencv_image_transfer_test example/opencv_image_transfer_test.cpp)

target_link_libraries(opencv_image_transfer_test
    #mavlink_indoor_sdk
    ${PROJECT_SOURCE_DIR}/src/libopencv_image_transfer.so
    pthread
    ${OpenCV_LIBS}
)