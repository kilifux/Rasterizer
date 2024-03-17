cmake_minimum_required(VERSION 3.27)
project(algorytmy)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorytmy main.cpp
        TGABuffer.h
        TGABuffer.cpp
        Rasterizer.h
        Rasterizer.cpp
        Vector.cpp
        Vector.h)
