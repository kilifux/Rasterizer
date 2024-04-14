#ifndef ALGORYTMY_SPHERE_H
#define ALGORYTMY_SPHERE_H

#include "Mesh.h"

class Sphere : public Mesh {
public:

    Sphere(float radius, int slices, int stacks);

private:
    Vector calculateSferaPoint(float radius, float theta, float phi);
};

#endif //ALGORYTMY_SPHERE_H
