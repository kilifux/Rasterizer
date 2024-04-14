#ifndef ALGORYTMY_LIGHT_H
#define ALGORYTMY_LIGHT_H

#include "Vector.h"

class Light {
public:
    Vector ambient;
    Vector diffuse;
    Vector specular;
    float shininess;

    static std::vector<Light> sceneLights;

    Light() : ambient(0.45f, 0.3f, 0.8f), diffuse(0.6f, 0.6f, 0.6f), specular(0.1, 0.1f, 0.1f) {}

    virtual ~Light() = default;
};


#endif //ALGORYTMY_LIGHT_H
