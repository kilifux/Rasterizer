#ifndef ALGORYTMY_TORUS_H
#define ALGORYTMY_TORUS_H

#include "Mesh.h"
#include "Triangle.h"

class Torus : public Mesh {
public:
    Torus(float majorRadius, float minorRadius, int majorSegments, int minorSegments);

    Vector calculateTorusPoint(float majorRadius, float minorRadius, float majorAngle, float minorAngle) {
        Vector point;
        point.x = (majorRadius + minorRadius * std::cos(minorAngle)) * std::cos(majorAngle);
        point.y = (majorRadius + minorRadius * std::cos(minorAngle)) * std::sin(majorAngle);
        point.z = minorRadius * std::sin(minorAngle);
        return point;
    }

    Vector calculateNormal(const Vector &point, float majorRadius, float minorRadius) {
        Vector normal;

        // Obliczamy odległość punktu od środka torusa
        float norm = std::sqrt(point.x * point.x + point.y * point.y);

        // Obliczamy składowe normalnej
        normal.x = point.x / norm;
        normal.y = point.y / norm;
        normal.z = point.z / minorRadius;

        // Normalizujemy wektor normalny
        normal.Normalize();

        return normal;
    }

};


#endif
