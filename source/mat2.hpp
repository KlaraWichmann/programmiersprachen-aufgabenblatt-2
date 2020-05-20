#ifndef MAT2_HPP
#define MAT2_HPP

#include "vec2.hpp"
#include <math.h>

// Mat2 definition
#include <array>
struct Mat2 {
    // matrix layout:
    // e_00 e_10
    // e_01 e_11
    float e_00 = 1.0f;
    float e_10 = 0.0f;
    float e_01 = 0.0f;
    float e_11 = 1.0f;
    
    //member function operator *= for a matrix
    Mat2& operator *= (Mat2 const& m);
    
    //member function which determines the determinant of a Matrix
    float det() const;
};

//implements the * operation for two matrices
Mat2 operator* (Mat2 const& m1, Mat2 const& m2);

//implements the * operation for a matrix and a vector
Vec2 operator* (Mat2 const& m, Vec2 const& v);

//implements the * operator for a vector and a matrix
Vec2 operator* (Vec2 const& v, Mat2 const& m);

//determines the inverse of a given matrix
Mat2 inverse (Mat2 const& m);

//determines the transpose matrix of a given matrix
Mat2 transpose (Mat2 const& m);

//determines the rotation matrix using a given float value as the radian
Mat2 make_rotation_mat2 (float phi);


#endif // MAT2_HPP
