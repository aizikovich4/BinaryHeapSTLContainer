#!/bin/sh
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .
./BinaryHeapSTLContainer