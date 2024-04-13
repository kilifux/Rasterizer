#ifndef ALGORYTMY_MESH_H
#define ALGORYTMY_MESH_H

#include "Vertex.h"
#include "Vector.h"

class Triangle;

class Mesh {
public:
    int vSize;
    int tSize;

    std::vector<unsigned int> colors;

    std::vector<Vertex> vertices{};
    std::vector<Vector> indices{};

    Mesh() {}
    virtual ~Mesh() {}

};


#endif //ALGORYTMY_MESH_H
