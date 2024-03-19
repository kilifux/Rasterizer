#include "TGABuffer.h"
#include "Vector.h"
#include "Rasterizer.h"
#include "Triangle.h"


int main() {
    unsigned int width = 800;
    unsigned int height = 600;

    TGABuffer tgaImg(width, height);

    tgaImg.ClearColor(0xFF8888FF); // ARGB

    Rasterizer rasterizer(&tgaImg);

    Triangle triangle(Vector(0.5f, -0.5f, 0.0f), Vector(-0.5f, -0.5f, 0.0f), Vector(0.0f, 0.5f, 0.0f), 0xFFFF0000, 0xFF00FF00, 0xFF0000FF);

    rasterizer.Rasterize(triangle);

    if (!tgaImg.WriteTGA("test.tga"))
        return -1;

    return 0;
}
