#include "TGABuffer.h"
#include <cstdio>


TGABuffer::TGABuffer(unsigned int width, unsigned int height) : width(width), height(height) {
    colorBuffer = new unsigned int[width * height];
    depth = new float[width * height];
}

TGABuffer::~TGABuffer() {
    delete[] colorBuffer;
}

void TGABuffer::ClearColor(unsigned int color) {
    for (unsigned int i = 0; i < width * height; ++i) {
        colorBuffer[i] = color;
    }
}

void TGABuffer::ClearDepth(float value) {
    for (unsigned int i = 0; i < width * height; ++i) {
        depth[i] = value;
    }
}

unsigned int TGABuffer::GetColor(int index)
{
    return colorBuffer[index];
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


bool TGABuffer::OpenTGA(const char* filename)
{
    unsigned short header[9] = {
            0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000,
            0x0100, 0x0100,
            0x0820 };

    FILE* f = fopen(filename, "rb");
    if (NULL == f) return false;

    fread(header, 2, 9, f);

    width = header[6];
    height = header[7];

    colorBuffer = new unsigned int[width * height];

    fread(colorBuffer, 4, width * height, f);

    return true;
}




