#ifndef ALGORYTMY_CONE_H
#define ALGORYTMY_CONE_H

#include "Mesh.h"
#include "Triangle.h"

class Cone : public Mesh {
public:

    Cone( float radius, float height, int sectors);

    Vector2 CalculateTextureCoordinates(float x, float y, float z, float height);
};


#endif //ALGORYTMY_CONE_H
