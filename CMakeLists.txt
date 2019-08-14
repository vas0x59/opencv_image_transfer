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
    ${PROJECT_SOURCE_DIR}/libopencv_image_transfer.so
    pthread
    ${OpenCV_LIBS}
)

#zmq


# pkg_check_modules(PC_ZeroMQ QUIET zmq)
find_path(ZeroMQ_INCLUDE_DIR
    NAMES zmq.hpp
    PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
)

## use the hint from about to find the location of libzmq
find_library(ZeroMQ_LIBRARY
    NAMES zmq
    PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
)
# add_executable(zmq_copter zmq_copter.cpp)

include_directories(opencv_image_transfer_test ${ZeroMQ_INCLUDE_DIR})
## at the 0mq library to our link directive
target_link_libraries(opencv_image_transfer_test ${ZeroMQ_LIBRARY})