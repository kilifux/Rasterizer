#ifndef ALGORYTMY_MESH_H
#define ALGORYTMY_MESH_H

#include "Vertex.h"

class Mesh {
public:
    int vSize;
    int tSize;

    unsigned int colors[3];

    Vertex* vertices;
    Vector* indices;

    Mesh() {};
};


#endif //ALGORYTMY_MESH_H
