#include "Triangle.h"

Triangle::Triangle(const Vector &vertex1, const Vector &vertex2, const Vector &vertex3) {
    vertices[0] = vertex1;
    vertices[1] = vertex2;
    vertices[2] = vertex3;
}

Triangle::Triangle(const Vector &vertex1, const Vector &vertex2, const Vector &vertex3, unsigned int color1,
                   unsigned int color2, unsigned int color3) {

    vertices[0] = vertex1;
    vertices[1] = vertex2;
    vertices[2] = vertex3;

    colors[0] = color1;
    colors[1] = color2;
    colors[2] = color3;
}
