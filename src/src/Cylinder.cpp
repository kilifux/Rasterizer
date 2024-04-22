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
            // Obliczamy wektory normalne dla wierzchołków bocznych walca
            Vector normal_side1 = (pOnCircle(angle, radius, Vector(0.0f, rise * i, 0.0f)) - pOnCircle(angle + step, radius, Vector(0.0f, rise * i, 0.0f))).cross(Vector(0, -1, 0)).Normalize();
            Vector normal_side2 = (pOnCircle(angle, radius, Vector(0.0f, rise * (i + 1), 0.0f)) - pOnCircle(angle, radius, Vector(0.0f, rise * i, 0.0f))).cross(Vector(0, -1, 0)).Normalize();
            Vector normal_side3 = (pOnCircle(angle, radius, Vector(0.0f, rise * (i + 1), 0.0f)) - pOnCircle(angle + step, radius, Vector(0.0f, rise * (i + 1), 0.0f))).cross(Vector(0, -1, 0)).Normalize();

            Vertex vertex1(pOnCircle(angle, radius, Vector(0.0f, rise * i, 0.0f)), normal_side1, 0xFFFF0000);
            Vertex vertex2(pOnCircle(angle + step, radius, Vector(0.0f, rise * i, 0.0f)), normal_side1, 0xFF00FF00);
            Vertex vertex3(pOnCircle(angle, radius, Vector(0.0f, rise * (i + 1), 0.0f)), normal_side2, 0xFF0000FF);

            Vertex vertex4(pOnCircle(angle, radius, Vector(0.0f, rise * (i + 1), 0.0f)), normal_side2, 0xFFFF0000);
            Vertex vertex5(pOnCircle(angle + step, radius, Vector(0.0f, rise * i, 0.0f)), normal_side3, 0xFF00FF00);
            Vertex vertex6(pOnCircle(angle + step, radius, Vector(0.0f, rise * (i + 1), 0.0f)), normal_side3, 0xFF0000FF);

            // Boczne ściany walca
   /*         triangles.emplace_back(vertex1, vertex2, vertex3);
            triangles.emplace_back(vertex4, vertex5, vertex6);*/
        }


        // Wierzchołki na podstawie walca
        Vertex vertex7(pOnCircle(angle, radius), Vector(0, -1, 0), 0xFFFF0000);
        Vertex vertex8(Vector(0.0f, 0.0f, 0.0f), Vector(0, -1, 0), 0xFF00FF00);
        Vertex vertex9(pOnCircle(angle + step, radius), Vector(0, -1, 0), 0xFF0000FF);

        Vertex vertex10(pOnCircle(angle, radius, Vector(0.0f, height, 0.0f)), Vector(0, 1, 0), 0xFFFF0000);
        Vertex vertex11(Vector(0.0f, height, 0.0f), Vector(0, 1, 0), 0xFF00FF00);
        Vertex vertex12(pOnCircle(angle + step, radius, Vector(0.0f, height, 0.0f)), Vector(0, 1, 0), 0xFF0000FF);

        // Górna i dolna powierzchnia walca
      /*  triangles.emplace_back(vertex7, vertex8, vertex9);
        triangles.emplace_back(vertex10, vertex11, vertex12);*/
    }
}

