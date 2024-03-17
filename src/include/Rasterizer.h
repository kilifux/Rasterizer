#ifndef ALGORYTMY_RASTERIZER_H
#define ALGORYTMY_RASTERIZER_H

class TGABuffer;
class Vector;

class Rasterizer {
    TGABuffer* tgaBuffer;

public:
    Rasterizer(TGABuffer* buffer);

    void Rasterize(const Vector &vector1, const Vector &vector2, const Vector &vector3);
};


#endif //ALGORYTMY_RASTERIZER_H
