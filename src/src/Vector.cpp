#include "Vector.h"

#include <cmath>

Vector::Vector(const Vector& vector) {
    x = vector.x;
    y = vector.y;
    z = vector.z;
}

Vector Vector::operator-() const
{
    return { -this->x, -this->y, -this->z };
}

Vector Vector::operator+(const Vector& v) const {
    return { x + v.x, y + v.y, z + v.z };
}

Vector Vector::operator-(const Vector& v) const {
    return { x - v.x, y - v.y, z - v.z };
}

Vector Vector::operator*(float f) const {
    return { x * f, y * f, z * f };
}

Vector Vector::operator/(float f) const {
    return { x / f, y / f, z / f };
}

float Vector::getAngle(const Vector& vector)
{
    return acos(dotProduct(vector) / (this->GetLength() * vector.GetLength()));
}

float Vector::GetLength() const {
    return (float)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector Vector::Normalize() {
    float len = GetLength();

    if (len < 0 )
        return Vector(0, 0, 0);

    return *this/len;
}

float Vector::dotProduct(Vector v) {
    Vector result;
    result.x = x * v.x;
    result.y = y * v.y;
    result.z = z * v.z;

    return result.x + result.y + result.z;
}

Vector Vector::cross(Vector a, Vector b) {
    return Vector(a.y * b.z - a.z * b.y,
                  a.z * b.x - a.x * b.z,
                  a.x * b.y - a.y * b.x);

}

Vector Vector::cross(Vector v) {
    return Vector(y * v.z - z * v.y,
                  z * v.x - x * v.z,
                  x * v.y - y * v.x);
}


std::ostream& operator<<(std::ostream& Os, const Vector& vector3)
{
    Os << "[" << vector3.x << "," << vector3.y << "," << vector3.z << "]";
    return Os;
}

Vector Vector::ToVector(unsigned int color)  {
    float red = ((color >> 16) & 0xFF) / 255.0f;
    float green = ((color >> 8) & 0xFF) / 255.0f;
    float blue = (color & 0xFF) / 255.0f;

    return Vector(red, green, blue);
}

unsigned int Vector::ToColor(Vector vector) {
    int red = static_cast<int>(vector.x * 255);
    int green = static_cast<int>(vector.y * 255);
    int blue = static_cast<int>(vector.z * 255);
    unsigned int alpha = static_cast<int>(255);
    return (alpha << 24) |(red << 16) | (green << 8) | blue;
}

Vector Vector::operator*(Vector o) {
    Vector result;
    result.x = x * o.x;
    result.y = y * o.y;
    result.z = z * o.z;
    return result;
}

