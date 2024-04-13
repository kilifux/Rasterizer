#ifndef ALGORYTMY_CONE_H
#define ALGORYTMY_CONE_H

#include "Mesh.h"
#include "Triangle.h"

class Cone : public Mesh {
public:
    std::vector<Triangle> triangles;

    Cone( float radius, float height, int sectors, unsigned int color);
    static Vector pOnCircle(float angle, float radius, Vector center = {0.0f, 0.0f, 0.0f});

};


#endif //ALGORYTMY_CONE_H
