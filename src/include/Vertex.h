#ifndef ALGORYTMY_VERTEX_H
#define ALGORYTMY_VERTEX_H

#include "Vector.h"

class Vertex {
public:
    Vertex(const Vector &position, const Vector &normal);
    Vertex(){}
public:
    Vector position;
    Vector normal;
};


#endif //ALGORYTMY_VERTEX_H
