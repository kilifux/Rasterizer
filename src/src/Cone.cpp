#include "Cone.h"

constexpr float piOver180 = 0.017453292519943f;
constexpr float twoPi = 6.283185307179586f;

Cone::Cone(float radius, float height, int sectors) {
    float step = (360.f / static_cast<float>(sectors)) * piOver180;

    for (float angle = 0.0f; angle < twoPi; angle += step)
    {
        Vector p0 = pOnCircle(angle, radius);
        Vector p1 = pOnCircle(angle + step, radius);

        Vector normal_base = Vector(0, 1, 0);
        Vector normal_side = (p1 - p0).cross(Vector(0, -height, 0)).Normalize();

        Vertex vertex1(p1, normal_side, 0xFFFF0000);
        Vertex vertex2(Vector(0.0f, height, 0.0f), normal_base, 0xFF00FF00);
        Vertex vertex3(p0, normal_side, 0xFF0000FF);

        Vertex vertex4(p0, normal_side, 0xFFFF0000);
        Vertex vertex5(Vector(0.0f, 0.0f, 0.0f), Vector(0, -1, 0), 0xFF00FF00);
        Vertex vertex6(p1, normal_side, 0xFF0000FF);

        triangles.emplace_back(vertex1, vertex2, vertex3, CalculateTextureCoordinates(vertex1.position.x, vertex1.position.y, vertex1.position.z, height), CalculateTextureCoordinates(vertex2.position.x, vertex2.position.y, vertex2.position.z, height), CalculateTextureCoordinates(vertex3.position.x, vertex3.position.y, vertex3.position.z, height));
        triangles.emplace_back(vertex4, vertex5, vertex6, CalculateTextureCoordinates(vertex4.position.x, vertex4.position.y, vertex4.position.z, height), CalculateTextureCoordinates(vertex5.position.x, vertex5.position.y, vertex5.position.z, height), CalculateTextureCoordinates(vertex6.position.x, vertex6.position.y, vertex6.position.z, height));
    }


    Vector normal_top = Vector(0, -1, 0);

    Vertex top_vertex(Vector(0.0f, height, 0.0f), normal_top, 0xFFFFFFFF);
    vertices.push_back(top_vertex);

}

Vector2 Cone::CalculateTextureCoordinates(float x, float y, float z, float height) {
    float phi = atan2f(z, x);
    float theta = acosf(y / sqrt(x * x + y * y + z * z));

    float u = phi / (2 * M_PI) + 0.5f;
    float v = theta / M_PI;

    return Vector2(u, v);
}



