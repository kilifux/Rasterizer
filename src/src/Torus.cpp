#include "Torus.h"

Torus::Torus(float majorRadius, float minorRadius, int majorSegments, int minorSegments) {
    float majorStep = 2 * M_PI / majorSegments;
    float minorStep = 2 * M_PI / minorSegments;

    for (int i = 0; i < majorSegments; ++i) {
        for (int j = 0; j < minorSegments; ++j) {
            float majorAngle1 = i * majorStep;
            float majorAngle2 = (i + 1) * majorStep;
            float minorAngle1 = j * minorStep;
            float minorAngle2 = (j + 1) * minorStep;

            Vector p1 = calculateTorusPoint(majorRadius, minorRadius, majorAngle1, minorAngle1);
            Vector p2 = calculateTorusPoint(majorRadius, minorRadius, majorAngle1, minorAngle2);
            Vector p3 = calculateTorusPoint(majorRadius, minorRadius, majorAngle2, minorAngle2);
            Vector p4 = calculateTorusPoint(majorRadius, minorRadius, majorAngle2, minorAngle1);

            Vertex v1 = {p1, calculateNormal(p1, majorRadius, minorRadius),0xFFFF0000};
            Vertex v2 = {p2, calculateNormal(p2, majorRadius, minorRadius), 0xFF00FF00};
            Vertex v3 = {p3, calculateNormal(p3, majorRadius, minorRadius), 0xFF0000FF};
            Vertex v4 = {p4, calculateNormal(p4, majorRadius, minorRadius), 0xFF00FF00};

            triangles.emplace_back(v1, v2, v3);
            triangles.emplace_back(v1, v3, v4);
        }
    }
}
