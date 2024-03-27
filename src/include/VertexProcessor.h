#ifndef ALGORYTMY_VERTEXPROCESSOR_H
#define ALGORYTMY_VERTEXPROCESSOR_H

#include "Matrix4.h"
#include "Vector.h"

class VertexProcessor {

    Matrix4 obj2world;
    static Matrix4 world2view;
    static Matrix4 view2proj;

public:
    static Matrix4 setPerspective(float fovy, float aspect, float near, float far);
    static Matrix4 setLookat(Vector eye, Vector center, Vector up);
};


#endif //ALGORYTMY_VERTEXPROCESSOR_H
