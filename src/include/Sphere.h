#ifndef ALGORYTMY_SPHERE_H
#define ALGORYTMY_SPHERE_H

#include "Mesh.h"

class Sphere : public Mesh {
public:

    Sphere(float radius, int slices, int stacks);
    float radius;

private:
    Vector calculateSferaPoint(float radius, float theta, float phi);
    void CalculateTextures();
    Vector2 CalculateTextureCoordinates(float theta, float phi, int textureWidth, int textureHeight);
};

#endif //ALGORYTMY_SPHERE_H
