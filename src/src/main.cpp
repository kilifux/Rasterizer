#include "TGABuffer.h"
#include "Vector.h"
#include "Rasterizer.h"
#include "Triangle.h"
#include "Matrix4.h"
#include "VertexProcessor.h"
#include "Cone.h"


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


    Vertex vertex1(Vector(0.9f, -0.5f, -1.0f), Vector(0, 1, 0));
    Vertex vertex2(Vector(0.0f, -0.5f, -1.0f), Vector(0, 1, 0));
    Vertex vertex3(Vector(0.0f, 0.5f, 0.0f), Vector(0, 1, 0));

    //Glebokosc depth (tym bardziej na minusie tym bliżej kamery)
    Triangle triangle(vertex1, vertex2, vertex3);    //zielony
    Triangle triangle2(vertex1, vertex2, vertex3, 0xFFBBBBBB, 0xFFDDAAFF, 0xFFDDAAFF);    //różowy

   // rasterizer.Rasterize(triangle, model);
  //  rasterizer.Rasterize(triangle2, model2);


    Cone cone(2, 2, 8, 0xFFbbbbbb);
    rasterizer.Rasterize(cone, model2);


    if (!tgaImg.WriteTGA("test.tga"))
        return -1;

    return 0;
}


















