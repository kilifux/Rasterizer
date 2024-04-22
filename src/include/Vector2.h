#ifndef ALGORYTMY_VECTOR2_H
#define ALGORYTMY_VECTOR2_H

#include <ostream>

class Vector2 {
public:
    float x;
    float y;

    Vector2() : x(0.f), y(0.f){}
    Vector2(float x, float y): x(x), y(y) {}

    friend std::ostream& operator<<(std::ostream& Os, const Vector2& vector);

    Vector2 operator*(float o)
    {
        return Vector2(x * o, y * o);
    }
    Vector2 operator+(Vector2 o)
    {
        return Vector2(x + o.x, y + o.y);
    }


};


#endif //ALGORYTMY_VECTOR2_H
