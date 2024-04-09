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

    Matrix4 model = Matrix4::Identity();
    model = model * VertexProcessor::multByScale(Vector(1, 1, 1));
    model = model * VertexProcessor::multByRotation(-45.f, Vector(0, 0, 1));
    model = model * VertexProcessor::multByTranslation(Vector(0.5, 1, 0));


    Matrix4 model2 = Matrix4::Identity();
    model2 = model2 * VertexProcessor::multByScale(Vector(0.5, 0.5, 0.5));
    model2 = model2 * VertexProcessor::multByRotation(-45.f, Vector(0, 0, 1));
    model2 = model2 * VertexProcessor::multByTranslation(Vector(-1.f, -0.5, 0));

    //Glebokosc depth (tym bardziej na minusie tym bliżej kamery)
    Triangle triangle(Vector(0.9f, -0.5f, -1.0f), Vector(0.0f, -0.5f, -1.0f), Vector(0.0f, 0.5f, 0.0f), 0xFFAAFFAA, 0xFFAAFFAA, 0xFFAAFFAA);    //zielony
    Triangle triangle2(Vector(0.5f, -0.5f, 0.0f), Vector(0.-0.5f, -0.5f, -1.0f), Vector(0.0f, 0.5f, 0.0f), 0xFFDDAAFF, 0xFFDDAAFF, 0xFFDDAAFF);    //różowy

    rasterizer.Rasterize(triangle, model);
    rasterizer.Rasterize(triangle2, model2);

    if (!tgaImg.WriteTGA("test.tga"))
        return -1;

    return 0;
}


















