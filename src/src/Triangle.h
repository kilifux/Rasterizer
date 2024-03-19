#ifndef ALGORYTMY_TRIANGLE_H
#define ALGORYTMY_TRIANGLE_H

#include "Vector.h"

class Triangle {


public:
    Vector vertices[3];
    unsigned int colors[3];

    Triangle(const Vector &vertex1, const Vector &vertex2, const Vector &vertex3);
    Triangle(const Vector &vertex1, const Vector &vertex2, const Vector &vertex3, unsigned int color1, unsigned int color2, unsigned int color3);
};


#endif //ALGORYTMY_TRIANGLE_H
