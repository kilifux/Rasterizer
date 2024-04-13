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
        float norm = std::sqrt(point.x * point.x + point.y * point.y);
        Vector normal;
        normal.x = (point.x * majorRadius) / norm;
        normal.y = (point.y * majorRadius) / norm;
        normal.z = (point.z * minorRadius) / norm;
        return normal;
    }

};


#endif
