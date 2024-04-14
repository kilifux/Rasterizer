#ifndef ALGORYTMY_DIRECTIONALLIGHT_H
#define ALGORYTMY_DIRECTIONALLIGHT_H


#include "Light.h"

class DirectionalLight : public Light {
public:
    Vector direction;

    DirectionalLight() : Light(), direction(Vector(-0.1f, -1.f, 1.f).Normalize()) {}
};


#endif //ALGORYTMY_DIRECTIONALLIGHT_H
