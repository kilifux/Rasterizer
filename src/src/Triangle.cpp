#include "Triangle.h"

Triangle::Triangle(const Vertex &vertex1, const Vertex &vertex2, const Vertex &vertex3) {

    vSize = 3;
    tSize = 1;

    vertices.push_back(vertex1);
    vertices.push_back(vertex2);
    vertices.push_back(vertex3);

    indices.push_back(Vector(0, 1 , 2));

    colors.push_back(0xFFAAFFAA);
    colors.push_back(0xFFAAFFAA);
    colors.push_back(0xFFAAFFAA);

}

Triangle::Triangle(const Vertex &vertex1, const Vertex &vertex2, const Vertex &vertex3, unsigned int color1,
                   unsigned int color2, unsigned int color3) {

    vSize = 3;
    tSize = 1;

    vertices.push_back(vertex1);
    vertices.push_back(vertex2);
    vertices.push_back(vertex3);

    colors.push_back(color1);
    colors.push_back(color2);
    colors.push_back(color3);

    indices.push_back(Vector(0, 1 , 2));

}

Triangle::Triangle() {

    vSize = 3;
    tSize = 1;

    vertices[0].position = Vector(-.5f, 0.f, 0.f);
    vertices[1].position = Vector(0.f, .5f, 0.f);
    vertices[2].position = Vector(.5f, 0.f, 0.f);

    colors.push_back(0xFFAAFFAA) ;
    colors.push_back(0xFFAAFFAA) ;
    colors.push_back(0xFFAAFFAA) ;

    indices[0] = Vector(0, 1 , 2);
}
