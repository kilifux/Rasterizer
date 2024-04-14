#include "Sphere.h"

Sphere::Sphere(float radius, int slices, int stacks) {
    for (int i = 0; i < slices; ++i) {
        for (int j = 0; j < stacks; ++j) {
            float theta1 = static_cast<float>(i) * M_PI / slices;
            float theta2 = static_cast<float>(i + 1) * M_PI / slices;
            float phi1 = static_cast<float>(j) * 2 * M_PI / stacks;
            float phi2 = static_cast<float>(j + 1) * 2 * M_PI / stacks;

            Vector p1 = calculateSferaPoint(radius, theta1, phi1);
            Vector p2 = calculateSferaPoint(radius, theta2, phi1);
            Vector p3 = calculateSferaPoint(radius, theta2, phi2);
            Vector p4 = calculateSferaPoint(radius, theta1, phi2);

            Vertex v1(p1, p1.Normalize());
            Vertex v2(p2, p2.Normalize());
            Vertex v3(p3, p3.Normalize());
            Vertex v4(p4, p4.Normalize());

            triangles.emplace_back(v1, v2, v3);
            triangles.emplace_back(v1, v3, v4);
        }
    }
}

Vector Sphere::calculateSferaPoint(float radius, float theta, float phi) {
    float x = radius * std::sin(theta) * std::cos(phi);
    float y = radius * std::sin(theta) * std::sin(phi);
    float z = radius * std::cos(theta);
    return Vector(x, y, z);
}
