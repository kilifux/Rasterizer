#ifndef ALGORYTMY_VERTEX_H
#define ALGORYTMY_VERTEX_H

#include "Vector.h"

class Vertex {
public:
    Vertex(const Vector &position, const Vector &normal);
    Vertex(const Vector &position, const Vector &normal, const unsigned int &color);
    Vertex(){}
public:
    Vector position;
    Vector normal;
    unsigned int color;
};


#endif //ALGORYTMY_VERTEX_H
