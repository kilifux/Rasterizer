#include "TGABuffer.h"
#include "Vector.h"
#include "Rasterizer.h"
#include "Triangle.h"
#include "Matrix4.h"
#include "VertexProcessor.h"


int main() {
    unsigned int width = 800;
    unsigned int height = 600;

    TGABuffer tgaImg(width, height);

    tgaImg.ClearColor(0xFF8888FF); // ARGB
    tgaImg.ClearDepth(std::numeric_limits<float>::max());

    Rasterizer rasterizer(&tgaImg);

    Matrix4 camera = Matrix4::Identity();
    camera = VertexProcessor::setLookat({2.f, 2.f, 2.f}, {0.f, 0.f, 0.f}, {0.f, 0.f, 1.f}) * camera;



    //Glebokosc depth (tym bardziej na minusie tym bliżej kamery)
    Triangle triangle(Vector(0.9f, -0.5f, -1.0f), Vector(0.0f, -0.5f, -1.0f), Vector(0.0f, 0.5f, 0.0f), 0xFFAAFFAA, 0xFFAAFFAA, 0xFFAAFFAA);    //zielony
    Triangle triangle2(Vector(0.9f, -0.5f, 0.0f), Vector(0.0f, -0.5f, -1.0f), Vector(0.0f, 0.5f, 0.0f), 0xFFDDAAFF, 0xFFDDAAFF, 0xFFDDAAFF);    //różowy

    rasterizer.Rasterize(triangle);
    rasterizer.Rasterize(triangle2);

    if (!tgaImg.WriteTGA("test.tga"))
        return -1;

    return 0;
}


















