#include "Rasterizer.h"
#include "Vector.h"
#include "TGABuffer.h"

Rasterizer::Rasterizer(TGABuffer *buffer) {
    tgaBuffer = buffer;
}

void Rasterizer::Rasterize(const Vector &vector1, const Vector &vector2, const Vector &vector3) {

    int width = tgaBuffer->GetWidth();
    int height = tgaBuffer->GetHeight();

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {

            float scaledX = ((float)x / (width - 1)) * 2.0f - 1.0f;
            float scaledY = ((float)y / (height - 1)) * 2.0f - 1.0f;

            if (    (vector1.x - vector2.x) * (scaledY - vector1.y) - (vector1.y - vector2.y) * (scaledX - vector1.x) > 0.0f &&
                    (vector2.x - vector3.x) * (scaledY - vector2.y) - (vector2.y - vector3.y) * (scaledX - vector2.x) > 0.0f &&
                    (vector3.x - vector1.x) * (scaledY - vector3.y) - (vector3.y - vector1.y) * (scaledX - vector3.x) > 0.0f )
            {
                tgaBuffer->GetColorBuffer()[y * tgaBuffer->GetWidth() + x] = 0xFFFFFFFF;
            }
        }
    }
}
