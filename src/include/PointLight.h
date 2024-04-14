#ifndef ALGORYTMY_POINTLIGHT_H
#define ALGORYTMY_POINTLIGHT_H


#include "Light.h"

class PointLight : public Light{
public:
    Vector position;

    PointLight() : Light(), position(Vector(0, 0, 0)) {}
};


#endif //ALGORYTMY_POINTLIGHT_H
