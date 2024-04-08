#include "VertexProcessor.h"

Matrix4 VertexProcessor::setPerspective(float fovy, float aspect, float near, float far) {
    fovy *= M_PI / 360;
    float f = cos(fovy) / sin(fovy);

    Matrix4 view2proj;

    view2proj[0] = Vector4(f/aspect, 0, 0, 0);
    view2proj[1] = Vector4(0, f, 0 ,0);
    view2proj[2] = Vector4(0, 0, (far + near) / (near - far), -1);
    view2proj[3] = Vector4(0, 0, 2 * far * near / (near - far), 0);

    return view2proj;
}

Matrix4 VertexProcessor::setLookAt(Vector eye, Vector center, Vector up) {
    Matrix4 world2view = Matrix4::Identity();

    Vector forward = (center - eye).Normalize();
    Vector right = Vector::cross(forward, up).Normalize();
    Vector Up = Vector::cross(right, forward).Normalize();


    world2view[0] = Vector4(right.x, Up.x, -forward.x, 0);
    world2view[1] = Vector4(right.y, Up.y, -forward.y, 0);
    world2view[2] = Vector4(right.z, Up.z, -forward.z, 0);
    world2view[3] = Vector4(0, 0, 0, 1);

/*    Matrix4 m;
    m[3] = Vector4(-eye.x, -eye.y, -eye.z,  1);
    world2view = world2view * m;*/

    return world2view * multByTranslation(Vector(-eye.x, -eye.y, -eye.z));

}

Matrix4 VertexProcessor::multByTranslation(Vector v) {
    Matrix4 m = Matrix4{Vector4(1, 0, 0, 0),
                        Vector4(0, 1, 0, 0),
                        Vector4(0, 0, 1, 0),
                        Vector4(v.x, v.y, v.z, 1)};

    return m;
}

Matrix4 VertexProcessor::multByScale(Vector v) {

    Matrix4 m = Matrix4{Vector4(v.x, 0, 0, 0),
                        Vector4(0, v.y, 0, 0),
                        Vector4(0, 0, v.z, 0),
                        Vector4(0, 0, 0, 1)};

    return m;
}

Matrix4 VertexProcessor::multByRotation(float a, Vector v) {
    float s = sin(a * M_PI / 180);
    float c = cos(a * M_PI / 180);
    v = v.Normalize();

    Matrix4 m = Matrix4{Vector4(v.x * v.x * (1 - c) + c, v.y * v.x * (1 - c) + v.z * s, v.x * v.z * (1-c) - v.y * s, 0),
                        Vector4(v.x * v.y * (1-c) - v.z * s, v.y * v.y * (1-c) + c, v.y * v.z * (1-c) + v.x * s, 0),
                        Vector4(v.x * v.z * (1-c) + v.y * s, v.y * v.z * (1-c) - v.x * s, v.z * v.z * (1-c) + c, 0),
                        Vector4(0, 0, 0, 1)};

    return m;
}
















