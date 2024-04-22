#ifndef ALGORYTMY_DIRECTIONALLIGHT_H
#define ALGORYTMY_DIRECTIONALLIGHT_H


#include "Light.h"

class DirectionalLight : public Light {
public:
    Vector direction;

    DirectionalLight() : Light(), direction(Vector(2.0f, -1.f, 0.f).Normalize()) {}
};


#endif //ALGORYTMY_DIRECTIONALLIGHT_H
