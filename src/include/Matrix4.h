#ifndef ALGORYTMY_MATRIX4_H
#define ALGORYTMY_MATRIX4_H

#include <iostream>
#include <array>
#include <cmath>
#include "Vector4.h"


class Matrix4 {
public:
    std::array<Vector4, 4> rows;

    Matrix4() {
        rows.fill(Vector4());
    }


    Matrix4(const Vector4& row1, const Vector4& row2, const Vector4& row3, const Vector4& row4) {
        rows[0] = row1;
        rows[1] = row2;
        rows[2] = row3;
        rows[3] = row4;
    }


    static Matrix4 Identity() {
        return Matrix4(Vector4(1.0f, 0.0f, 0.0f, 0.0f),
                       Vector4(0.0f, 1.0f, 0.0f, 0.0f),
                       Vector4(0.0f, 0.0f, 1.0f, 0.0f),
                       Vector4(0.0f, 0.0f, 0.0f, 1.0f));
    }

    Vector4& operator[](int index) {
        if (index < 0 || index >= 4) {
            throw std::out_of_range("Index out of range");
        }
        return rows[index];
    }

    Matrix4 Transpose()  {
        Matrix4 result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result[i][j] = rows[j][i];
            }
        }
        return result;
    }

    float Determinant() const {
        return 0.0f;
    }

    Matrix4 Inverse() const {
        return Matrix4();
    }

    Matrix4 operator+(const Matrix4& other) const {
        Matrix4 result;
        for (int i = 0; i < 4; ++i) {
            result[i] = rows[i] + other.rows[i];
        }
        return result;
    }

    Matrix4 operator-(const Matrix4& other) const {
        Matrix4 result;
        for (int i = 0; i < 4; ++i) {
            result[i] = rows[i] - other.rows[i];
        }
        return result;
    }

    Matrix4 operator*(const Matrix4& other) const {
        Matrix4 result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                float sum = 0.0f;
                for (int k = 0; k < 4; ++k) {
                    sum += rows[i][k] * other.rows[k][j];
                }
                result.rows[i][j] = sum;
            }
        }
        return result;
    }

    Matrix4 operator*(float scalar) const {
        Matrix4 result;
        for (int i = 0; i < 4; ++i) {
            result[i] = rows[i] * scalar;
        }
        return result;
    }

    Matrix4 &operator*=(Matrix4& other) {
        *this = *this * other;
        return *this;
    }

    Vector4 operator*(const Vector4& vector) const {
        Vector4 result;
        for (int i = 0; i < 4; ++i) {
            result[i] = rows[i].Dot(vector);
        }
        return result;
    }
};


#endif //ALGORYTMY_MATRIX4_H
