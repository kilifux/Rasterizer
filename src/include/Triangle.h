#ifndef ALGORYTMY_TRIANGLE_H
#define ALGORYTMY_TRIANGLE_H

#include "Vector.h"
#include "Mesh.h"

class Triangle : public Mesh {
public:

    Triangle(const Vertex &vertex1, const Vertex &vertex2, const Vertex &vertex3);
    Triangle(const Vertex &vertex1, const Vertex &vertex2, const Vertex &vertex3, unsigned int color1, unsigned int color2, unsigned int color3);

    Triangle();
};


#endif //ALGORYTMY_TRIANGLE_H
