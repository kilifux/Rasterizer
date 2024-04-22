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

        float norm = std::sqrt(point.x * point.x + point.y * point.y);

        normal.x = point.x / norm;
        normal.y = point.y / norm;
        normal.z = point.z / minorRadius;

        normal.Normalize();

        return normal;
    }

    Vector2 CalculateTextureCoordinates(float majorAngle, float minorAngle, int textureWidth, int textureHeight) {
        float u = majorAngle / (2 * M_PI);
        float v = minorAngle / (2 * M_PI);

        u /= textureWidth;
        v /= textureHeight;

        return Vector2(u, v);
    }
};


#endif
