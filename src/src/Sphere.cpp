#include "Sphere.h"

Sphere::Sphere(float r, int slices, int stacks) {
    radius = r;

    for (int i = 0; i < slices; ++i) {
        for (int j = 0; j < stacks; ++j) {
            float theta1 = static_cast<float>(i) * M_PI / slices;
            float theta2 = static_cast<float>(i + 1) * M_PI / slices;
            float phi1 = static_cast<float>(j) * 2 * M_PI / stacks;
            float phi2 = static_cast<float>(j + 1) * 2 * M_PI / stacks;

            Vector p1 = calculateSferaPoint(r, theta1, phi1);
            Vector p2 = calculateSferaPoint(r, theta2, phi1);
            Vector p3 = calculateSferaPoint(r, theta2, phi2);
            Vector p4 = calculateSferaPoint(r, theta1, phi2);

            Vertex v1(p1, p1.Normalize());
            Vertex v2(p2, p2.Normalize());
            Vertex v3(p3, p3.Normalize());
            Vertex v4(p4, p4.Normalize());

            int textureWidth = 1;
            int textureHeight = 1;

            Vector2 t1 = CalculateTextureCoordinates(theta1, phi1, textureWidth, textureHeight);
            Vector2 t2 = CalculateTextureCoordinates(theta2, phi1, textureWidth, textureHeight);
            Vector2 t3 = CalculateTextureCoordinates(theta2, phi2, textureWidth, textureHeight);
            Vector2 t4 = CalculateTextureCoordinates(theta1, phi2, textureWidth, textureHeight);

            vertices.push_back(v1);
            vertices.push_back(v2);
            vertices.push_back(v3);
            vertices.push_back(v4);
            //CalculateTextures();

            triangles.emplace_back(v1, v2, v3, t1, t2, t3);
            triangles.emplace_back(v1, v3, v4, t1, t3, t4);
        }
    }
}

Vector Sphere::calculateSferaPoint(float radius, float theta, float phi) {
    float x = radius * std::sin(theta) * std::cos(phi);
    float y = radius * std::sin(theta) * std::sin(phi);
    float z = radius * std::cos(theta);
    return Vector(x, y, z);
}

void Sphere::CalculateTextures() {

    for (int i = 0; i < vertices.size(); i++) {
        // Obliczanie współrzędnych sferycznych (theta, phi) dla danego wierzchołka
        float theta = std::acos(vertices[i].position.y / radius); // kąt theta
        float phi = std::atan2(vertices[i].position.z, vertices[i].position.x); // kąt phi

        // Normalizacja wartości phi do przedziału [0, 2*pi]
        if (phi < 0)
            phi += 2 * M_PI;

        // Normalizacja wartości theta do przedziału [0, pi]
        theta /= M_PI;

        // Obliczanie współrzędnych tekstury (u, v) na podstawie współrzędnych sferycznych
        float u = phi / (2 * M_PI);
        float v = 1 - theta;

        // Dodanie obliczonych współrzędnych tekstury do listy tekstur dla wierzchołka
        textures.push_back(Vector2(u, v));
    }

}

Vector2 Sphere::CalculateTextureCoordinates(float theta, float phi, int textureWidth, int textureHeight) {
    // Mapowanie sferyczne polega na przypisaniu współrzędnych tekstury w sposób zależny od kątów sferycznych (theta, phi)
    float u = phi / (2 * M_PI); // Współrzędna u zależy od kąta phi
    float v = theta / M_PI; // Współrzędna v zależy od kąta theta

    // Aby uzyskać wartości tekstury w zakresie [0, 1], należy podzielić uzyskane wartości przez szerokość i wysokość tekstury
    u /= textureWidth;
    v /= textureHeight;

    return Vector2(u, v);
}
