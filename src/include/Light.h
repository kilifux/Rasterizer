#ifndef ALGORYTMY_LIGHT_H
#define ALGORYTMY_LIGHT_H

#include "Vector.h"

class Light {
public:
    Vector position;
    Vector ambient;
    Vector diffuse;
    Vector specular;
    float shininess;

    Vector calculate();



};


#endif //ALGORYTMY_LIGHT_H
