#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

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

TEST_CASE ("describe_add_two_Vec2", "[vec2__add_two_Vec2]") {
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

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
