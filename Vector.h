#ifndef ALGORYTMY_VECTOR_H
#define ALGORYTMY_VECTOR_H


class Vector {
public:
    float x, y, z;

    Vector(){}
    Vector(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector operator+(Vector &vector) const { return Vector(x + vector.x, y + vector.y, z + vector.z);}
    Vector operator-(Vector &vector) const { return Vector(x - vector.x, y - vector.y, z - vector.z);}

};


#endif //ALGORYTMY_VECTOR_H
