#include "Triangle.h"

Triangle::Triangle(const Vector &vertex1, const Vector &vertex2, const Vector &vertex3) {
    vertices[0].position = vertex1;
    vertices[1].position = vertex2;
    vertices[2].position = vertex3;
}

Triangle::Triangle(const Vector &vertex1, const Vector &vertex2, const Vector &vertex3, unsigned int color1,
                   unsigned int color2, unsigned int color3) {

    vertices = new Vertex[3];

    vertices[0].position = vertex1;
    vertices[1].position = vertex2;
    vertices[2].position = vertex3;

    colors[0] = color1;
    colors[1] = color2;
    colors[2] = color3;
}

Triangle::Triangle() {

    vSize = 3;
    tSize = 1;

    vertices = new Vertex[3];
    indices = new Vector[1];

    vertices[0].position = Vector(-.5f, 0.f, 0.f);
    vertices[1].position = Vector(0.f, .5f, 0.f);
    vertices[2].position = Vector(.5f, 0.f, 0.f);

    colors[0] = 0xFFAAFFAA;
    colors[1] = 0xFFAAFFAA;
    colors[2] = 0xFFAAFFAA;

    indices[0] = Vector(0, 1 , 2);
}
