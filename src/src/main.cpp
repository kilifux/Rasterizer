#include "TGABuffer.h"
#include "Vector.h"
#include "Rasterizer.h"
#include "Triangle.h"


int main() {
    unsigned int width = 800;
    unsigned int height = 600;

    TGABuffer tgaImg(width, height);

    tgaImg.ClearColor(0xFF8888FF); // ARGB
    tgaImg.ClearDepth(std::numeric_limits<float>::max());

    Rasterizer rasterizer(&tgaImg);

    //Wypelnienie
/*    Triangle triangle(Vector(0.5f, -0.5f, 0.0f), Vector(-0.5f, -0.5f, 0.0f), Vector(0.0f, 0.5f, 0.0f), 0xFFFF0000, 0xFF00FF00, 0xFF0000FF);
    Triangle triangle2(Vector(0.9f, -0.5f, 0.0f), Vector(0.5f, -0.5f, 0.0f), Vector(0.0f, 0.5f, 0.0f), 0xFFFF0000, 0xFF00FF00, 0xFF0000FF);

    rasterizer.Rasterize(triangle);
    rasterizer.Rasterize(triangle2);*/

    //Glebokosc
    Triangle triangle(Vector(0.5f, -0.5f, -1.0f), Vector(-0.5f, -0.5f, 0.0f), Vector(0.0f, 0.5f, 0.0f), 0xFFAAFFAA, 0xFFAAFFAA, 0xFFAAFFAA);
    Triangle triangle2(Vector(0.9f, -0.5f, 0.0f), Vector(0.0f, -0.5f, -1.0f), Vector(0.0f, 0.5f, 0.0f), 0xFFDDAAFF, 0xFFDDAAFF, 0xFFDDAAFF);

    rasterizer.Rasterize(triangle);
    rasterizer.Rasterize(triangle2);

    if (!tgaImg.WriteTGA("test.tga"))
        return -1;

    return 0;
}
