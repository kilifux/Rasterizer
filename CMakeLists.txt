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
        src/include/Cone.h
        src/src/Cylinder.cpp
        src/include/Cylinder.h
        src/src/Torus.cpp
        src/include/Torus.h
        src/src/Light.cpp
        src/include/Light.h
        src/src/DirectionalLight.cpp
        src/include/DirectionalLight.h
        src/src/PointLight.cpp
        src/include/PointLight.h
        src/src/Sphere.cpp
        src/include/Sphere.h
        src/src/SpotLight.cpp
        src/include/SpotLight.h
        src/src/Vector2.cpp
        src/include/Vector2.h)
