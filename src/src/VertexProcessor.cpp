#include "VertexProcessor.h"

Matrix4 VertexProcessor::setPerspective(float fovy, float aspect, float near, float far) {
    fovy *= M_PI / 360;
    float f = cos(fovy) / sin(fovy);
    view2proj[0] = Vector4(f/aspect, 0, 0, 0);
    view2proj[1] = Vector4(0, f, 0 ,0);
    view2proj[2] = Vector4(0, 0, (far + near) / (near - far), -1);
    view2proj[2] = Vector4(0, 0, 2 * far * near / (near - far), 0);

    return view2proj;
}

Matrix4 VertexProcessor::setLookat(Vector eye, Vector center, Vector up) {
    Vector f = center - eye;
    f = f.Normalize();
    up = up.Normalize();
    Vector s = s.cross(up);
    Vector u = s.cross(f);

    world2view[0] = Vector4(s.x, u.x, -f.x, 0);
    world2view[1] = Vector4(s.y, u.y, -f.y, 0);
    world2view[2] = Vector4(s.z, u.z, -f.z, 0);
    world2view[3] = Vector4(0, 0, 0, 1);

    Matrix4 m;
    m[3] = Vector4(-eye.x, -eye.y, -eye.z,  1);
    world2view = world2view * m;

    return world2view;

}
















