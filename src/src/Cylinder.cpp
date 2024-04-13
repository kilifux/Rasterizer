#include "Cylinder.h"

constexpr float twoPi = 6.283185307179586f;
constexpr float piOver180 = 0.017453292519943f;

Cylinder::Cylinder(float radius, float height, int sectors, int cuts) {

    float step = (360.0f / static_cast<float>(sectors)) * piOver180;
    float rise = height / static_cast<float>(cuts);

    for (float angle = 0; angle < twoPi; angle += step)
    {
        for (int i = 0; i < cuts; ++i)
        {
            Vertex vertex1(pOnCircle(angle, radius, Vector(0.0f, rise * i, 0.0f)), Vector(0, 1, 0));
            Vertex vertex2(pOnCircle(angle + step, radius, Vector(0.0f, rise * i, 0.0f)), Vector(0, 1, 0));
            Vertex vertex3(pOnCircle(angle, radius, Vector(0.0f, rise * (i + 1), 0.0f)), Vector(0, 1, 0));

            Vertex vertex4(pOnCircle(angle, radius, Vector(0.0f, rise * (i + 1), 0.0f)), Vector(0, 1, 0));
            Vertex vertex5(pOnCircle(angle + step, radius, Vector(0.0f, rise * i, 0.0f)), Vector(0, 1, 0));
            Vertex vertex6(pOnCircle(angle + step, radius, Vector(0.0f, rise * (i + 1), 0.0f)), Vector(0, 1, 0));

            triangles.emplace_back(
                    vertex1,
                    vertex2,
                    vertex3,
                    0xFFFF0000, 0xFF00FF00, 0xFF0000FF
            );

            triangles.emplace_back(
                    vertex4,
                    vertex5,
                    vertex6,
                    0xFFFF0000, 0xFF00FF00, 0xFF0000FF
            );
        }


        Vertex vertex7(pOnCircle(angle, radius), Vector(0, 1, 0));
        Vertex vertex8(Vector(0.0f, 0.0f, 0.0f), Vector(0, 1, 0));
        Vertex vertex9(pOnCircle(angle + step, radius), Vector(0, 1, 0));

        Vertex vertex10(pOnCircle(angle, radius), Vector(0, 1, 0));
        Vertex vertex11(Vector(0.0f, height, 0.0f), Vector(0, 1, 0));
        Vertex vertex12(pOnCircle(angle + step, radius), Vector(0, 1, 0));

        triangles.emplace_back(vertex7, vertex8, vertex9, 0xFFFF0000, 0xFF00FF00, 0xFF0000FF);
        triangles.emplace_back(vertex10, vertex11, vertex12, 0xFFFF0000, 0xFF00FF00, 0xFF0000FF);
    }

}

