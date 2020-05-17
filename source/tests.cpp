#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

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
}

TEST_CASE ("describe_mat2_operation_multiply", "[_mat2_operation_multiply]") {
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



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
