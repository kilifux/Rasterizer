#ifndef ALGORYTMY_SPOTLIGHT_H
#define ALGORYTMY_SPOTLIGHT_H

#include "Light.h"

class SpotLight : public Light {
public:
    Vector position;
    Vector direction;
    float cutoff; // kąt odcięcia w stopniach

    SpotLight() : Light(), position(Vector(0.0f, 0.0f, 0.0f)), direction(Vector(0.0f, -1.0f, 0.0f)), cutoff(45.0f) {}
};


#endif //ALGORYTMY_SPOTLIGHT_H
