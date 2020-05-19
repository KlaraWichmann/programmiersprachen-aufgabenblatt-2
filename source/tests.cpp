#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "shapes.hpp"


TEST_CASE ("describe_vec2", "[vec2]") {
    Vec2 a; //requires that 0.0f == a.x and 0.0f == a.y
    REQUIRE (a.x == 0.0f);
    Vec2 b {5.1f, -9.3f}; /* requires that 5.1f == Approx(b.x) and -9.3f == Approx(b.y)*/
    REQUIRE (Approx(b.x) == 5.1f);
    REQUIRE (Approx(b.y) == -9.3f);
}

TEST_CASE ("describe_vec2_operation_add", "[vec2_operation_add]") {
    //Vector (1, 0) + (0, 0)
    Vec2 a {1.0f, 0.0f};
    Vec2 b {0.0f, 0.0f};
    Vec2 c {1.0f, 0.0f};
    a += b;
    REQUIRE(Approx(a.x) == c.x);
    REQUIRE(Approx(a.y) == c.y);
    //Vector (5.1, -9.3) + (-5.1, 9.3)
    a = {5.1f, -9.3f};
    b = {-5.1f, 9.3f};
    c = {0.0f, 0.0f};
    a += b;
    REQUIRE(Approx(a.x) == c.x);
    REQUIRE(Approx(a.y) == c.y);
    //Vector (1.1, 2.2) + (3.3, 4.4)
     a = {1.1f, 2.2f};
     b = {3.3f, 4.4f};
     c = {4.4f, 6.6f};
     a += b;
     REQUIRE(Approx(a.x) == c.x);
     REQUIRE(Approx(a.y) == c.y);
}

TEST_CASE ("describe_vec2_operation_sub", "[vec2_operation_sub]") {
    //Vector (1, 0) - (0, 0)
    Vec2 a {1.0f, 0.0f};
    Vec2 b {0.0f, 0.0f};
    Vec2 c {1.0f, 0.0f};
    a -= b;
    REQUIRE(Approx(a.x) == c.x);
    REQUIRE(Approx(a.y) == c.y);
    //Vector (5.1, -9.3) - (-5.1, 9.3)
    a = {5.1f, -9.3f};
    b = {-5.1f, 9.3f};
    c = {10.2f, -18.6f};
    a -= b;
    REQUIRE(Approx(a.x) == c.x);
    REQUIRE(Approx(a.y) == c.y);
    //Vector (1.1, 2.2) - (3.3, 4.4)
     a = {1.1f, 2.2f};
     b = {3.3f, 4.4f};
     c = {-2.2f, -2.2f};
     a -= b;
     REQUIRE(Approx(a.x) == c.x);
     REQUIRE(Approx(a.y) == c.y);
}

TEST_CASE ("describe_vec2_operation_multiply", "[vec2_operation_multiply]") {
    //Vector (1, 0) * 0
    Vec2 a {1.0f, 0.0f};
    float s = 0.0f;
    Vec2 c {0.0f, 0.0f};
    a *= s;
    REQUIRE(Approx(a.x) == c.x);
    REQUIRE(Approx(a.y) == c.y);
    //Vector (5.1, -9.3) * -9.3
    a = {5.1f, -9.3f};
    s = -9.3f;
    c = {-47.43f, 86.49f};
    a *= s;
    REQUIRE(Approx(a.x) == c.x);
    REQUIRE(Approx(a.y) == c.y);
    //Vector (1.1, 2.2) * 4.0
     a = {1.1f, 2.2f};
     s = 4.0f;
     c = {4.4f, 8.8f};
     a *= s;
     REQUIRE(Approx(a.x) == c.x);
     REQUIRE(Approx(a.y) == c.y);
}

TEST_CASE ("describe_vec2_operation_devide", "[vec2_operation_devide]") {
    //Vector (1, 0) / 1
    Vec2 a {1.0f, 0.0f};
    float s = 1.0f;
    Vec2 c {1.0f, 0.0f};
    a /= s;
    REQUIRE(Approx(a.x) == c.x);
    REQUIRE(Approx(a.y) == c.y);
    //Vector (5.1, -5.1) / -5.1
    a = {5.1f, -5.1f};
    s = -5.1f;
    c = {-1.0f, 1.0f};
    a /= s;
    REQUIRE(Approx(a.x) == c.x);
    REQUIRE(Approx(a.y) == c.y);
    //Vector (1.1, 2.2) /= 4.0
     a = {1.1f, 2.2f};
     s = 4.0f;
     c = {0.275f, 0.55f};
     a /= s;
     REQUIRE(Approx(a.x) == c.x);
     REQUIRE(Approx(a.y) == c.y);
    //Vector (1.1, 2.2) /= 0.0
     a = {1.1f, 2.2f};
     s = 0.0f;
    try {
        a /= s;
    }
    catch (const std::invalid_argument& e) {
        REQUIRE(true);
    }
}

TEST_CASE ("describe_add_two_Vec2", "[vec2_add_two_Vec2]") {
    //Vector (1, 0) + (0, 0)
    Vec2 a {1.0f, 0.0f};
    Vec2 b {0.0f, 0.0f};
    Vec2 c;
    Vec2 d {1.0f, 0.0f};
    c = a + b;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
    //Vector (-1.5, 5.5) + (1.5, -1.0)
    a = {-1.5f, 5.5f};
    b = {1.5f, -1.0f};
    d = {0.0f, 4.5f};
    c = a + b;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
    //Vector (-1.5, 5.5) + (-1.5, 1.0)
    a = {-1.5f, 5.5f};
    b = {-1.5f, 1.0f};
    d = {-3.0f, 6.5f};
    c = a + b;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
}

TEST_CASE ("describe_subtract_two_Vec2", "[vec2_subtract_two_Vec2]") {
    //Vector (1, 0) - (0, 0)
    Vec2 a {1.0f, 0.0f};
    Vec2 b {0.0f, 0.0f};
    Vec2 c;
    Vec2 d {1.0f, 0.0f};
    c = a - b;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
    //Vector (-1.5, 5.5) - (1.5, -1.0)
    a = {-1.5f, 5.5f};
    b = {1.5f, -1.0f};
    d = {-3.0f, 6.5f};
    c = a - b;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
    //Vector (-1.5, 5.5) - (-1.5, 1.0)
    a = {-1.5f, 5.5f};
    b = {-1.5f, 1.0f};
    d = {0.0f, 4.5f};
    c = a - b;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
}

TEST_CASE ("describe_multiply_two_Vec2", "[vec2_multiply_two_Vec2]") {
    //Vector (1, 0) * 0.0
    Vec2 a {1.0f, 0.0f};
    float s = 0.0f;
    Vec2 c;
    Vec2 d {0.0f, 0.0f};
    c = a * s;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
    //Vector (-1.5, 5.5) * 1.5
    a = {-1.5f, 5.5f};
    s = 1.5f;
    d = {-2.25f, 8.25f};
    c = a * s;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
    //Vector (-1.5, 5.5) * -1.5
    a = {-1.5f, 5.5f};
    s = -1.5f;
    d = {2.25f, -8.25f};
    c = a * s;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
}

TEST_CASE ("describe_multiply_two_Vec2_direction_change", "[vec2_multiply_two_Vec2_direction_change]") {
    //Vector 0.0 * (1, 0)
    Vec2 a {1.0f, 0.0f};
    float s = 0.0f;
    Vec2 c;
    Vec2 d {0.0f, 0.0f};
    c = s * a;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
    //Vector 1.5 * (-1.5, 5.5)
    a = {-1.5f, 5.5f};
    s = 1.5f;
    d = {-2.25f, 8.25f};
    c = s * a;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
    //Vector -1.5 * (-1.5, 5.5)
    a = {-1.5f, 5.5f};
    s = -1.5f;
    d = {2.25f, -8.25f};
    c = s * a;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
}

TEST_CASE ("describe_devide_two_Vec2", "[vec2_devide_two_Vec2]") {
    //Vector (1, 0) / 1.0
    Vec2 a {1.0f, 0.0f};
    float s = 1.0f;
    Vec2 c;
    Vec2 d {1.0f, 0.0f};
    c = a / s;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
    //Vector (-1.5, 5.7) / 1.5
    a = {-1.5f, 5.7f};
    s = 1.5f;
    d = {-1.0f, 3.8f};
    c = a / s;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
    //Vector (-1.5, 5.7) / -1.5
    a = {-1.5f, 5.7f};
    s = -1.5f;
    d = {1.0f, -3.8f};
    c = a / s;
    REQUIRE(Approx(c.x) == d.x);
    REQUIRE(Approx(c.y) == d.y);
    //Vector (1.1, 2.2) /= 0.0
     a = {1.1f, 2.2f};
     s = 0.0f;
    try {
        c = a / s;
    }
    catch (const std::invalid_argument& e) {
        REQUIRE(true);
    }
}

TEST_CASE ("describe_mat2_operation_multiply", "[mat2_operation_multiply]") {
    //Matrix (2, 3, 4, 5) * (6, 7, 8, 9)
    Mat2 a {2.0f, 3.0f, 4.0f, 5.0f};
    Mat2 b {6.0f, 7.0f, 8.0f, 9.0f};
    Mat2 c {36.0f, 41.0f, 64.0f, 73.0f};
    a *= b;
    REQUIRE(Approx(a.e_00) == c.e_00);
    REQUIRE(Approx(a.e_10) == c.e_10);
    REQUIRE(Approx(a.e_01) == c.e_01);
    REQUIRE(Approx(a.e_11) == c.e_11);
    //Matrix (-2, 3.7, 4.2, -5) * (6.3, -7.5, 8.8, -9.2)
    a = {-2.0f, 3.7f, 4.2f, -5.0f};
    b = {6.3f, -7.5f, 8.8f, -9.2f};
    c = {19.96f, -19.04f, -17.54f, 14.5f};
    a *= b;
    REQUIRE(Approx(a.e_00) == c.e_00);
    REQUIRE(Approx(a.e_10) == c.e_10);
    REQUIRE(Approx(a.e_01) == c.e_01);
    REQUIRE(Approx(a.e_11) == c.e_11);
}

TEST_CASE ("describe_mat2_multiply_two_matrices", "[mat2_multiply_two_matrices]") {
    //Matrix (2, 3, 4, 5) * (6, 7, 8, 9)
    Mat2 a {2.0f, 3.0f, 4.0f, 5.0f};
    Mat2 b {6.0f, 7.0f, 8.0f, 9.0f};
    Mat2 c;
    Mat2 d {36.0f, 41.0f, 64.0f, 73.0f};
    c = a * b;
    REQUIRE(Approx(c.e_00) == d.e_00);
    REQUIRE(Approx(c.e_10) == d.e_10);
    REQUIRE(Approx(c.e_01) == d.e_01);
    REQUIRE(Approx(c.e_11) == d.e_11);
    //Matrix (-2, 3.7, 4.2, -5) * (6.3, -7.5, 8.8, -9.2)
    a = {-2.0f, 3.7f, 4.2f, -5.0f};
    b = {6.3f, -7.5f, 8.8f, -9.2f};
    d = {19.96f, -19.04f, -17.54f, 14.5f};
    c = a * b;
    REQUIRE(Approx(c.e_00) == d.e_00);
    REQUIRE(Approx(c.e_10) == d.e_10);
    REQUIRE(Approx(c.e_01) == d.e_01);
    REQUIRE(Approx(c.e_11) == d.e_11);
}

TEST_CASE ("describe_mat2_determinant", "[mat2_determinant]") {
    //Matrix (-2, -3.7, 4.2, -5)
    Mat2 a {-2.0f, -3.7f, 4.2f, -5.0f};
    REQUIRE(Approx(a.det()) == 25.54f);
}

TEST_CASE ("describe_mat2_matrix_multiply_vector", "[mat2_matrix_multiply_vector]") {
    //Matrix (-2, -3.7, 4.2, -5) * (-2.4, 3.6)
    Mat2 a {-2.0f, -3.7f, 4.2f, -5.0f};
    Vec2 v {-2.4f, 3.6f};
    Vec2 result;
    Vec2 expected {-8.52f, -28.08f};
    result = a * v;
    REQUIRE(Approx(result.x) == expected.x);
    REQUIRE(Approx(result.y) == expected.y);
}

TEST_CASE ("describe_mat2_vector_multiply_matrix", "[mat2_vector_multiply_matrix]") {
    //Matrix (-2.4, 3.6) * (-2, -3.7, 4.2, -5)
    Mat2 a {-2.0f, -3.7f, 4.2f, -5.0f};
    Vec2 v {-2.4f, 3.6f};
    Vec2 result;
    Vec2 expected {19.92f, -9.12f};
    result = v * a;
    REQUIRE(Approx(result.x) == expected.x);
    REQUIRE(Approx(result.y) == expected.y);
}

TEST_CASE ("describe_mat2_inverse", "[mat2_inverse]") {
    //Matrix (-2, -3.7, 4.2, -5)
    Mat2 a {-2.0f, -3.7f, 4.2f, -5.0f};
    Mat2 expected {-0.19577f, 0.14487f, -0.16444f, -0.07830f};
    a = inverse (a);
    REQUIRE(Approx(a.e_00) == expected.e_00);
    REQUIRE(Approx(a.e_10) == expected.e_10);
    REQUIRE(Approx(a.e_01) == expected.e_01);
    REQUIRE(Approx(a.e_11) == expected.e_11);
}

TEST_CASE ("describe_mat2_transpose", "[mat2_transpose]") {
    //Matrix (-2, -3.7, 4.2, -5)
    Mat2 a {-2.0f, -3.7f, 4.2f, -5.0f};
    Mat2 expected {-2.0f, 4.2f, -3.7f, -5.0f};
    a = transpose (a);
    REQUIRE(Approx(a.e_00) == expected.e_00);
    REQUIRE(Approx(a.e_10) == expected.e_10);
    REQUIRE(Approx(a.e_01) == expected.e_01);
    REQUIRE(Approx(a.e_11) == expected.e_11);
}

TEST_CASE ("describe_mat2_rotation", "[mat2_rotation]") {
    //phi 2* PI = 360 degrees
    float phi = 2 * M_PI;
    Mat2 result;
    Mat2 expected {-0.28369f, -0.95891f, 0.95891f, -0.28369f};
    result = make_rotation_mat2 (phi);
    REQUIRE(Approx(result.e_00) == expected.e_00);
    REQUIRE(Approx(result.e_10) == expected.e_10);
    REQUIRE(Approx(result.e_01) == expected.e_01);
    REQUIRE(Approx(result.e_11) == expected.e_11);
    //phi PI = 180 degrees
    phi = M_PI;
    expected = {-0.59846f, 0.80115f, -0.80115f, -0.59846f};
    result = make_rotation_mat2 (phi);
    REQUIRE(Approx(result.e_00) == expected.e_00);
    REQUIRE(Approx(result.e_10) == expected.e_10);
    REQUIRE(Approx(result.e_01) == expected.e_01);
    REQUIRE(Approx(result.e_11) == expected.e_11);
}

TEST_CASE ("describe_color", "[color]") {
    Color a; //requires that 0.5 == a.r and 0.5 == a.g and 0.5 == a.b
    REQUIRE (a.r == 0.5f);
    REQUIRE (a.g == 0.5f);
    REQUIRE (a.b == 0.5f);
    Color b {0.69f, 0.4f, 0.2f}; //requires that 0.69 == a.r and 0.4 == a.g and 0.2 == a.b
    REQUIRE (Approx(b.r) == 0.69f);
    REQUIRE (Approx(b.g) == 0.4f);
    REQUIRE (Approx(b.b) == 0.2f);
}

TEST_CASE ("describe_circumference_circle", "[circumference_circle]") {
    // Circle r = 2.5, color = 255, 255, 255
    Color white {0.0f, 0.0f, 0.0f};
    Vec2 ctr;
    Circle a {2.5f, ctr, white};
    float result = 0.0f;
    float expected = 15.70796f;
    result = a.circumference ();
    REQUIRE (Approx(result) == expected);
    // Circle r = -3.7, color = 255, 255, 255
    a = {-3.7f, ctr, white};
    expected = -23.24778f;
    result = a.circumference ();
    REQUIRE (Approx(result) == expected);
    // Circle r = 0, color = 255, 255, 255
    a =  {0.0f, ctr, white};
    expected = 0.0f;
    result = a.circumference ();
    REQUIRE (Approx(result) == expected);
    // Circle r = 1.0, color = 255, 255, 255
    a =  {1.0f, ctr, white};
    expected = 6.28318f;
    result = a.circumference ();
    REQUIRE (Approx(result) == expected);
}


TEST_CASE ("describe_circumference_rectangle", "[circumference_rectangle]") {
    // Rectangle (0, 0) (1, 1), color = 255, 255, 255
    Color white {0.0f, 0.0f, 0.0f};
    Vec2 max {1.0f, 1.0f};
    Vec2 min {0.0f, 0.0f};
    float result = 0.0f;
    float expected = 4.0f;
    Rectangle r {min, max, white};
    result = r.circumference ();
    REQUIRE (Approx(result) == expected);
    // Rectangle (-5.5, 10.5) (5.5, 20.3), color = 255, 255, 255
    min = {-5.5f, 10.5f};
    max = {5.5f, 20.3f};
    expected = 41.6f;
    r = {min, max, white};
    result = r.circumference ();
    REQUIRE (Approx(result) == expected);
    // Rectangle (-5.5, -5.5) (-1.5, -1.5), color = 255, 255, 255
    min = {-5.5f, -5.5f};
    max = {-1.5f, -1.5f};
    expected = 16.0f;
    r = {min, max, white};
    result = r.circumference ();
    REQUIRE (Approx(result) == expected);
}

TEST_CASE ("describe_is_inside_circle", "[is_inside_circle]") {
    Color white {0.0f, 0.0f, 0.0f};
    Circle c {2.5f, Vec2 {0.0f, 0.0f}, white};
    //Vec (20, 20)
    Vec2 v {20.0f, 20.0f};
    REQUIRE (c.is_inside (v) == false);
    //Vec (0, 0)
     v = {0.0f, 0.0f};
     REQUIRE (c.is_inside (v) == true);
    //Vec (-20, -20)
     v = {-20.0f, -20.0f};
     REQUIRE (c.is_inside (v) == false);
    //Vec (2.5, 2.5)
     v = {2.5f, 2.5f};
     REQUIRE (c.is_inside (v) == true);
}

TEST_CASE ("describe_is_inside_rectangle", "[is_inside_rectangle]") {
    Color white {0.0f, 0.0f, 0.0f};
    Vec2 max {10.0f, 10.0f};
    Vec2 min {0.0f, 0.0f};
    Rectangle rec {min, max, white};
    //Vec (20, 20)
    Vec2 v {20.0f, 20.0f};
    REQUIRE (rec.is_inside (v) == false);
    //Vec (0, 0)
     v = {0.0f, 0.0f};
     REQUIRE (rec.is_inside (v) == true);
    //Vec (-20, -20)
     v = {-20.0f, -20.0f};
     REQUIRE (rec.is_inside (v) == false);
    //Vec (2.5, 2.5)
     v = {2.5f, 2.5f};
     REQUIRE (rec.is_inside (v) == true);
}
    
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
