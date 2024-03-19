#include "Rasterizer.h"
#include "Vector.h"
#include "TGABuffer.h"
#include <algorithm>
#include "Triangle.h"
#include <iostream>

Rasterizer::Rasterizer(TGABuffer *buffer) {
    tgaBuffer = buffer;
}

void Rasterizer::Rasterize(Triangle &triangle) {

    int width = tgaBuffer->GetWidth();
    int height = tgaBuffer->GetHeight();

    int x1 = (triangle.vertices[0].x + 1.f) * width * 0.5f, x2 = (triangle.vertices[1].x + 1.f) * width * 0.5f, x3 = (triangle.vertices[2].x + 1.f) * width * 0.5f;
    int y1 = (triangle.vertices[0].y + 1.f) * height * 0.5f, y2 = (triangle.vertices[1].y + 1.f) * height * 0.5f, y3 = (triangle.vertices[2].y + 1.f) * height * 0.5f;

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

    for (int x = minx; x < maxx; ++x) {
        for (int y = miny; y < maxy; ++y) {

            if (    (dx12) * (y - y1) - (dy12) * (x - x1) > 0.0f &&
                    (dx23) * (y - y2) - (dy23) * (x - x2) > 0.0f &&
                    (dx31) * (y - y3) - (dy31) * (x - x3) > 0.0f )
            {
                float bar1 = ((dy23) * (x - x3) + (dx32) * (y - y3)) / ((dy23) * (dx13) + (dx32) * (dy13));
                float bar2 = ((dy31) * (x - x3) + (dx13) * (y - y3)) / ((dy31) * (dx23) + (dx13) * (dy23));
                float bar3 = 1.f - bar1 - bar2;

                Vector color1 = Vector::ToVector(triangle.colors[0]);
                Vector color2 = Vector::ToVector(triangle.colors[1]);
                Vector color3 = Vector::ToVector(triangle.colors[2]);

                Vector color =  color1 * bar1 + color2 * bar2 + color3 * bar3;
                tgaBuffer->GetColorBuffer()[y * width + x] = Vector::ToColor(color);
            }
        }
    }
}
