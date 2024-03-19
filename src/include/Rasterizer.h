#ifndef ALGORYTMY_RASTERIZER_H
#define ALGORYTMY_RASTERIZER_H

class TGABuffer;
class Vector;
class Triangle;

class Rasterizer {
    TGABuffer* tgaBuffer;

public:
    Rasterizer(TGABuffer* buffer);

    void Rasterize(Triangle &triangle);
};


#endif //ALGORYTMY_RASTERIZER_H
