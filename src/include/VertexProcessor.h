#ifndef ALGORYTMY_VERTEXPROCESSOR_H
#define ALGORYTMY_VERTEXPROCESSOR_H

#include "Matrix4.h"
#include "Vector.h"

class VertexProcessor {

    Matrix4 obj2world;
    Matrix4 world2view;
    Matrix4 view2proj;

public:
    static Matrix4 setPerspective(float fovy, float aspect, float near, float far);
    static Matrix4 setLookAt(Vector eye, Vector center, Vector up);
    static Matrix4 multByTranslation(Vector v);
    static Matrix4 multByScale(Vector v);
    static Matrix4 multByRotation(float a, Vector v);
};


#endif //ALGORYTMY_VERTEXPROCESSOR_H
