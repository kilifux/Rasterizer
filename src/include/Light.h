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

    Light() : ambient(0.4f, 0.2f, 0.8f), diffuse(0.4f, 0.4f, 0.4f), specular(0.2f, 0.2f, 0.2f) {}

    virtual ~Light() = default;
};


#endif //ALGORYTMY_LIGHT_H
