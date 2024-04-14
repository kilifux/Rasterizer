#include "Cone.h"

constexpr float piOver180 = 0.017453292519943f;
constexpr float twoPi = 6.283185307179586f;

Cone::Cone(float radius, float height, int sectors) {
    float step = (360.f / static_cast<float>(sectors)) * piOver180;

    for (float angle = 0.0f; angle < twoPi; angle += step)
    {
        Vector p0 = pOnCircle(angle, radius);
        Vector p1 = pOnCircle(angle + step, radius);

        // Obliczamy wektory normalne dla wierzchołków bocznych stożka
        Vector normal_base = Vector(0, 1, 0); // Normalna dla wierzchołka na podstawie
        Vector normal_side = (p1 - p0).cross(Vector(0, -height, 0)).Normalize(); // Normalna dla wierzchołków na powierzchni bocznej

        // Dodajemy wierzchołki do stożka z odpowiednimi wektorami normalnymi
        Vertex vertex1(p1, normal_side, 0xFFFF0000);
        Vertex vertex2(Vector(0.0f, height, 0.0f), normal_base, 0xFF00FF00);
        Vertex vertex3(p0, normal_side, 0xFF0000FF);

        Vertex vertex4(p0, normal_side, 0xFFFF0000);
        Vertex vertex5(Vector(0.0f, 0.0f, 0.0f), Vector(0, -1, 0), 0xFF00FF00); // Normalna dla wierzchołka na szczycie
        Vertex vertex6(p1, normal_side, 0xFF0000FF);

        triangles.emplace_back(vertex1, vertex2, vertex3);
        triangles.emplace_back(vertex4, vertex5, vertex6);
    }

    // Obliczamy wektor normalny dla wierzchołka na podstawie stożka
    Vector normal_top = Vector(0, -1, 0);
    // Dodajemy wierzchołek na szczycie stożka z odpowiednim wektorem normalnym
    Vertex top_vertex(Vector(0.0f, height, 0.0f), normal_top, 0xFFFFFFFF);
    vertices.push_back(top_vertex);
}


