#include "mat2.hpp"
#include <math.h>

Mat2& Mat2::operator *= (Mat2 const& m) {
    float zero = e_00 * m.e_00 + e_10 * m.e_01;
    float ten = e_00 * m.e_10 + e_10 * m.e_11;
    float one = e_01 * m.e_00 + e_11 * m.e_01;
    float eleven = e_01 * m.e_10 + e_11 * m.e_11;
    e_00 = zero;
    e_10 = ten;
    e_01 = one;
    e_11 = eleven;
    return *this;
    
}

float Mat2::det() const {
    float determinant = 0.0f;
    determinant = e_00 * e_11 - e_01 * e_10;
    return determinant;
}

Mat2 operator* (Mat2 const& m1, Mat2 const& m2) {
    Mat2 result {m1};
    result *= m2;
    return result;
}

Vec2 operator* (Mat2 const& m, Vec2 const& v) {
    Vec2 result;
    result.x = m.e_00 * v.x + m.e_10 * v.y;
    result.y = m.e_01 * v.x + m.e_11 * v.y;
    return result;
}

Vec2 operator* (Vec2 const& v, Mat2 const& m) {
    Vec2 result;
    result.x = m.e_00 * v.x + m.e_01 * v.y;
    result.y = m.e_10 * v.x + m.e_11 * v.y;
    return result;
}

Mat2 inverse (Mat2 const& m) {
    Mat2 result;
    result.e_00 = m.e_11 * 1 / m.det();
    result.e_10 = -m.e_10 * 1 / m.det();
    result.e_01 = -m.e_01 * 1 / m.det();
    result.e_11 = m.e_00 * 1 / m.det();
    return result;
}

Mat2 transpose (Mat2 const& m) {
    Mat2 result;
    result.e_00 = m.e_00;
    result.e_10 = m.e_01;
    result.e_01 = m.e_10;
    result.e_11 = m.e_11;
    return result;
}

Mat2 make_rotation_mat2 (float phi) {
    Mat2 rotation_matrix;
    float degree = phi / M_PI * 180;
    rotation_matrix.e_00 = cos (degree);
    rotation_matrix.e_10 = -sin (degree);
    rotation_matrix.e_01 = sin (degree);
    rotation_matrix.e_11 = cos (degree);
    return rotation_matrix;
}


