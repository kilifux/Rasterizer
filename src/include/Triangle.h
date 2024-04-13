#ifndef ALGORYTMY_TRIANGLE_H
#define ALGORYTMY_TRIANGLE_H

#include "Vector.h"
#include "Vertex.h"

class Triangle {
public:
    std::vector<unsigned int> colors;

    std::vector<Vertex> vertices;
    std::vector<Vector> indices;

    Triangle(const Vertex &vertex1, const Vertex &vertex2, const Vertex &vertex3);
    Triangle(const Vertex &vertex1, const Vertex &vertex2, const Vertex &vertex3, unsigned int color1, unsigned int color2, unsigned int color3);

    Triangle();
};


#endif //ALGORYTMY_TRIANGLE_H
