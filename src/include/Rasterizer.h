#ifndef ALGORYTMY_RASTERIZER_H
#define ALGORYTMY_RASTERIZER_H

#include "Mesh.h"
#include "Cone.h"

class TGABuffer;
class Vector;
class Triangle;
class Matrix4;

class Rasterizer {
    TGABuffer* tgaBuffer;

public:
    Rasterizer(TGABuffer* buffer);

    void Rasterize(Mesh &mesh, Matrix4 &model);
    void RenderTriangle(Triangle &triangle, Matrix4 &model);
    void RenderCone(Cone &cone, Matrix4 &model);
};


#endif //ALGORYTMY_RASTERIZER_H
