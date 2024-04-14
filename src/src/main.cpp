#include "TGABuffer.h"
#include "Vector.h"
#include "Rasterizer.h"
#include "Matrix4.h"
#include "VertexProcessor.h"
#include "Cone.h"
#include "PointLight.h"
#include "DirectionalLight.h"
#include "Sphere.h"


int main() {
    unsigned int width = 800;
    unsigned int height = 600;

    TGABuffer tgaImg(width, height);

    tgaImg.ClearColor(0xFF8888FF); // ARGB
    tgaImg.ClearDepth(std::numeric_limits<float>::max());

    Rasterizer rasterizer(&tgaImg);

    DirectionalLight directionalLight;
    rasterizer.sceneLights.push_back(&directionalLight);

    PointLight pointLight;
    //rasterizer.sceneLights.push_back(&pointLight);

    Matrix4 modelCylinder = Matrix4::Identity();
    modelCylinder = modelCylinder * VertexProcessor::multByScale(Vector(0.3, 0.3, 0.3));
    modelCylinder = modelCylinder * VertexProcessor::multByRotation(-60.f, Vector(1, 0, 0));
    modelCylinder = modelCylinder * VertexProcessor::multByTranslation(Vector(1, 1, 0));

    Matrix4 modelCone = Matrix4::Identity();
    modelCone = modelCone * VertexProcessor::multByScale(Vector(0.4, 0.4, 0.4));
    modelCone = modelCone * VertexProcessor::multByRotation(45.f, Vector(1, 0, 0));
    modelCone = modelCone * VertexProcessor::multByTranslation(Vector(-1.f, -1.5, 0));

    Matrix4 modelTorus = Matrix4::Identity();
    modelTorus = modelTorus * VertexProcessor::multByScale(Vector(0.2, 0.2, 0.2));
    modelTorus = modelTorus * VertexProcessor::multByRotation(-120.f, Vector(1, 1, 0));
    modelTorus = modelTorus * VertexProcessor::multByTranslation(Vector(-1.f, .7, 0));

    Torus torus(2, 1, 10, 5);
    rasterizer.Rasterize(torus, modelTorus, true);

    Sphere sphere(2, 6, 6);
    rasterizer.Rasterize(sphere, modelCylinder, false);
    //Cylinder cylinder(2, 3, 12, 5);
    //rasterizer.Rasterize(cylinder, modelCylinder, true);

    Cone cone(2, 2, 14);
    rasterizer.Rasterize(cone, modelCone, true);

    if (!tgaImg.WriteTGA("test.tga"))
        return -1;

    return 0;
}


















