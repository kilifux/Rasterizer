#ifndef ALGORYTMY_CYLINDER_H
#define ALGORYTMY_CYLINDER_H

#include "Mesh.h"
#include "Triangle.h"

class Cylinder : public Mesh{
public:
    Cylinder(float radius, float height, int sectors, int cuts);
};


#endif
