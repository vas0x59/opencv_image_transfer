#!/bin/bash

if [ "$1" = "arm" ]
then
    echo "arm"
    if [ "$2" = "1" ]
    then
        rm -rf build_arm
        mkdir build_arm
        (cd build_arm && cmake -D DEP2_BUILD_DIR=build_arm -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_TOOLCHAIN_FILE=$HOME/rpi/toolchain_rpi.cmake .. )
    fi
    (cd build_arm && make)
else
    echo $(arch)
    if  [ "$2" = "1" ]
    then
        rm -rf build
        mkdir build
        (cd build && cmake -D DEP2_BUILD_DIR=build -D CMAKE_BUILD_TYPE=DEBUG ..)
    fi
    (cd build && make)
fi