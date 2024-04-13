cmake_minimum_required(VERSION 3.25)
project(algorytmy)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/include)

add_executable(algorytmy src/src/main.cpp
        src/include/TGABuffer.h
        src/src/TGABuffer.cpp
        src/include/Rasterizer.h
        src/src/Rasterizer.cpp
        src/src/Vector.cpp
        src/include/Vector.h
        src/src/Triangle.cpp
        src/include/Triangle.h
        src/src/Vector4.cpp
        src/include/Vector4.h
        src/src/Matrix4.cpp
        src/include/Matrix4.h
        src/src/VertexProcessor.cpp
        src/include/VertexProcessor.h src/src/Mesh.cpp src/include/Mesh.h src/src/Vertex.cpp src/include/Vertex.h
        src/src/Cone.cpp
        src/include/Cone.h)
