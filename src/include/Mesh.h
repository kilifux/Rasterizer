#ifndef ALGORYTMY_MESH_H
#define ALGORYTMY_MESH_H

#include "Triangle.h"
#include "Vertex.h"
#include "Vector.h"


class Mesh {
public:
    std::vector<unsigned int> colors;

    std::vector<Triangle> triangles;
    std::vector<Vertex> vertices;
    std::vector<Vector> indices;

    static Vector pOnCircle(float angle, float radius, Vector center = {0.0f, 0.0f, 0.0f});

    virtual ~Mesh() = default;
};


#endif //ALGORYTMY_MESH_H
