#ifndef ALGORYTMY_RASTERIZER_H
#define ALGORYTMY_RASTERIZER_H

#include "Mesh.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Torus.h"
#include "Light.h"

class TGABuffer;
class Vector;
class Triangle;
class Matrix4;

class Rasterizer {
    TGABuffer* tgaBuffer;

public:
    std::vector<Light*> sceneLights;
    Rasterizer(TGABuffer* buffer);

    void Rasterize(Mesh &mesh, Matrix4 &model);
    void RenderTriangle(Triangle &triangle, Matrix4 &model);

    void CalculateLighting(Vertex &vertex);
};


#endif //ALGORYTMY_RASTERIZER_H
