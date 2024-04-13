#include "Mesh.h"

Vector Mesh::pOnCircle(float angle, float radius, Vector center) {
    return { radius * std::cos(angle) + center.x,
             center.y,
             radius * std::sin(angle) + center.z };
}

