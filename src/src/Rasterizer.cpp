#include "Rasterizer.h"
#include "Vector.h"
#include "TGABuffer.h"
#include <algorithm>
#include "Triangle.h"
#include <iostream>
#include "VertexProcessor.h"
#include "Cylinder.h"

Rasterizer::Rasterizer(TGABuffer *buffer) {
    tgaBuffer = buffer;
}

void Rasterizer::Rasterize(Mesh &mesh, Matrix4 &model) {

    for (auto &triangle : mesh.triangles)
    {
        RenderTriangle(triangle, model);
    }
}

void Rasterizer::RenderTriangle(Triangle &triangle, Matrix4 &model) {

    int width = tgaBuffer->GetWidth();
    int height = tgaBuffer->GetHeight();

    Matrix4 viewMatrix = VertexProcessor::setLookAt({0, 1, 2}, {0, 2, 0}, {0, 1, 0});

    Matrix4 projectionMatrix = VertexProcessor::setPerspective(120.f, 1.f, 0.01f, 100.f);

    Matrix4 camera =  Matrix4::Identity();

    camera = camera * projectionMatrix * viewMatrix;

    Vector4 transformedVertex1 =  model * camera * Vector4(triangle.vertices[0].position.x, triangle.vertices[0].position.y, triangle.vertices[0].position.z, 1.0f);
    int x1 = (transformedVertex1.x + 1.0f) * width * 0.5f;
    int y1 = (transformedVertex1.y + 1.0f) * height * 0.5f;

    Vector4 transformedVertex2 = model * camera * Vector4(triangle.vertices[1].position.x, triangle.vertices[1].position.y, triangle.vertices[1].position.z, 1.0f);
    int x2 = (transformedVertex2.x + 1.0f) * width * 0.5f;
    int y2 = (transformedVertex2.y + 1.0f) * height * 0.5f;

    Vector4 transformedVertex3 = model * camera * Vector4(triangle.vertices[2].position.x, triangle.vertices[2].position.y, triangle.vertices[2].position.z, 1.0f);
    int x3 = (transformedVertex3.x + 1.0f) * width * 0.5f;
    int y3 = (transformedVertex3.y + 1.0f) * height * 0.5f;

    int z1 = triangle.vertices[0].position.z, z2 = triangle.vertices[1].position.z, z3 = triangle.vertices[2].position.z;

    int minx = std::min({x1, x2, x3});
    int maxx = std::max({x1, x2, x3});
    int miny = std::min({y1, y2, y3});
    int maxy = std::max({y1, y2, y3});

    minx = std::max(minx, 0);
    maxx = std::min(maxx, width - 1);
    miny = std::max(miny, 0);
    maxy = std::min(maxy, height - 1);

    float dx12 = x1 - x2;
    float dx13 = x1 - x3;
    float dx23 = x2 - x3;
    float dx31 = x3 - x1;
    float dx32 = x3 - x2;
    float dy12 = y1 - y2;
    float dy13 = y1 - y3;
    float dy23 = y2 - y3;
    float dy31 = y3 - y1;

    bool tl1 = (dy12 < 0 || (dy12 == 0 && dx12 > 0));
    bool tl2 = (dy23 < 0 || (dy23 == 0 && dx23 > 0));
    bool tl3 = (dy31 < 0 || (dy31 == 0 && dx31 > 0));

    for (int x = minx; x < maxx; ++x) {
        for (int y = miny; y < maxy; ++y) {

            float edge1 = (dx12) * (y - y1) - (dy12) * (x - x1);
            float edge2 = (dx23) * (y - y2) - (dy23) * (x - x2);
            float edge3 =  (dx31) * (y - y3) - (dy31) * (x - x3);

            if (   (edge1 > 0 || (edge1 >= 0 && tl1))
                   && (edge2 > 0 || (edge2 >= 0 && tl2))
                   && (edge3 > 0 || (edge3 >= 0 && tl3))) {

                float bar1 = ((dy23) * (x - x3) + (dx32) * (y - y3)) / ((dy23) * (dx13) + (dx32) * (dy13));
                float bar2 = ((dy31) * (x - x3) + (dx13) * (y - y3)) / ((dy31) * (dx23) + (dx13) * (dy23));
                float bar3 = 1.f - bar1 - bar2;

                Vector color1 = Vector::ToVector(triangle.colors[0]);
                Vector color2 = Vector::ToVector(triangle.colors[1]);
                Vector color3 = Vector::ToVector(triangle.colors[2]);

                Vector color =  color1 * bar1 + color2 * bar2 + color3 * bar3;
                float depth = bar1 * z1 + bar2 * z2 + bar3 * z3;
                if (depth    < tgaBuffer->GetDepth()[y * width + x])
                {
                    tgaBuffer->GetColorBuffer()[y * width + x] = Vector::ToColor(color);
                    tgaBuffer->GetDepth()[y * width + x] = depth;
                }


            }
        }
    }
}




