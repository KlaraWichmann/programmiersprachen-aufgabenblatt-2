#include "mat2.hpp"

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

Mat2 operator * (Mat2 const& m1, Mat2 const& m2) {
    Mat2 result {m1};
    result *= m2;
    return result;
}



