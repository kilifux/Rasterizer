#include "Vertex.h"

Vertex::Vertex(const Vector &position, const Vector &normal) : position(position), normal(normal) {}

Vertex::Vertex(const Vector &position, const Vector &normal, const unsigned int &color) : position(position), normal(normal), color(color){}
