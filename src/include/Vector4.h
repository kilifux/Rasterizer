#ifndef RASTERIZER_VECTOR4_H
#define RASTERIZER_VECTOR4_H

#include <iostream>
#include <array>
#include <cmath>

class Vector4 {
public:
    mutable float x, y, z, w;

    Vector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f)
            : x(x), y(y), z(z), w(w) {}

    float& operator[](int index) const {
        switch (index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            case 3: return w;
            default:
                throw std::out_of_range("Index out of range");
        }
    }

    Vector4 operator+(const Vector4& other) const {
        return {x + other.x, y + other.y, z + other.z, w + other.w};
    }

    Vector4 operator-(const Vector4& other) const {
        return {x - other.x, y - other.y, z - other.z, w - other.w};
    }

    Vector4 operator*(float scalar) const {
        return {x * scalar, y * scalar, z * scalar, w * scalar};
    }

    Vector4 operator/(float scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return {x / scalar, y / scalar, z / scalar, w / scalar};
    }

    float Dot(const Vector4& other) const {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

    Vector4 Normalize() {
        float length = Length();
        if (length < 0.0001) {
            return {0, 0, 0, 0};
        }

        return *this / length;
    }

    float Length() const {
        return sqrt(x * x + y * y + z * z + w * w);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector4& vector4) {
        os << "[" << vector4.x << "," << vector4.y << "," << vector4.z << "," << vector4.w << "]";
        return os;
    }
};


#endif //RASTERIZER_VECTOR4_H
