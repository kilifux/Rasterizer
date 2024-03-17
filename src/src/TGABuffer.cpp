#include "TGABuffer.h"
#include <cstdio>


TGABuffer::TGABuffer(unsigned int width, unsigned int height) : width(width), height(height) {
    colorBuffer = new unsigned int[width * height];
}

TGABuffer::~TGABuffer() {
    delete[] colorBuffer;
}

void TGABuffer::ClearColor(unsigned int color) {
    for (unsigned int i = 0; i < width * height; ++i) {
        colorBuffer[i] = color;
    }
}

bool TGABuffer::WriteTGA(const char* fileName) {
    unsigned short header[9] = {
            0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0100, 0x0100, 0x0820
    };

    FILE *file = fopen(fileName, "wb+");

    if (!file)
        return false;

    header[6] = width;
    header[7] = height;

    fwrite(header, 2, 9, file);
    fwrite(colorBuffer, sizeof(unsigned int), width * height, file);


    fclose(file);

    return true;
}


