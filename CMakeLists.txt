cmake_minimum_required(VERSION 3.27)
project(algorytmy)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/include)

add_executable(algorytmy src/src/main.cpp
        src/include/TGABuffer.h
        src/src/TGABuffer.cpp
        src/include/Rasterizer.h
        src/src/Rasterizer.cpp
        src/src/Vector.cpp
        src/include/Vector.h)
