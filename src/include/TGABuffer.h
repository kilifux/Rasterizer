#ifndef ALGORYTMY_TGABUFFER_H
#define ALGORYTMY_TGABUFFER_H

class TGABuffer {
    unsigned int* colorBuffer;
    unsigned int width;
    unsigned int height;

public:
    TGABuffer(unsigned int width, unsigned int height);
    ~TGABuffer();

    bool WriteTGA(const char* fileName);
    void ClearColor(unsigned int color);

    unsigned int* GetColorBuffer() {return colorBuffer;}
    unsigned int GetWidth() const { return width; }
    unsigned int GetHeight() const {return height; }
};


#endif //ALGORYTMY_TGABUFFER_H
