#ifndef ALGORYTMY_POINTLIGHT_H
#define ALGORYTMY_POINTLIGHT_H


#include "Light.h"

class PointLight : public Light{
public:
    Vector position;

    PointLight() : Light(), position(Vector(23, 23, 23)) {}
};


#endif //ALGORYTMY_POINTLIGHT_H
