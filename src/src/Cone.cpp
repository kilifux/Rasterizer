#include "Cone.h"

constexpr float piOver180 = 0.017453292519943f;
constexpr float twoPi = 6.283185307179586f;

Cone::Cone(float radius, float height, int sectors) {
    float step = (360.f / static_cast<float>(sectors)) * piOver180;

    for (float angle = 0.0f; angle < twoPi; angle += step)
    {
        Vector p0 = pOnCircle(angle, radius);
        Vector p1 = pOnCircle(angle + step, radius);

        Vertex vertex1(p1, Vector(0, 1, 0));
        Vertex vertex2(Vector(0.0f, height, 0.0f), Vector(0, 1, 0));
        Vertex vertex3(p0, Vector(0, 1, 0));

        Vertex vertex4(p0, Vector(0, 1, 0));
        Vertex vertex5(Vector(0.0f, 0.0f, 0.0f), Vector(0, 1, 0));
        Vertex vertex6(p1, Vector(0, 1, 0));

        triangles.emplace_back(vertex1, vertex2, vertex3);
        triangles.emplace_back(vertex4, vertex5, vertex6);
    }

}


