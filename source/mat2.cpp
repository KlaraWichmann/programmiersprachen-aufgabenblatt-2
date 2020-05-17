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
