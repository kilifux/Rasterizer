#ifndef ALGORYTMY_RASTERIZER_H
#define ALGORYTMY_RASTERIZER_H

class TGABuffer;
class Vector;
class Triangle;
class Matrix4;

class Rasterizer {
    TGABuffer* tgaBuffer;

public:
    Rasterizer(TGABuffer* buffer);

    void Rasterize(Triangle &triangle, Matrix4 &model);
};


#endif //ALGORYTMY_RASTERIZER_H
