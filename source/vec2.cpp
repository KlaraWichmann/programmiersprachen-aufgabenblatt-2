#include <exception>
#include <iostream>
#include "vec2.hpp"

//member methods

Vec2& Vec2::operator+= (Vec2 const& v) {
    x += v.x;
    y += v.y;
    return *this;
}

Vec2& Vec2::operator-= (Vec2 const& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2& Vec2::operator*= (float s) {
    x *= s;
    y *= s;
    return *this;
}

Vec2& Vec2::operator/= (float s) {
    if (s == 0) {
        throw std::invalid_argument ("Division by 0");
    }
    x /= s;
    y /= s;
    return *this;
}

//free methods

Vec2 operator+ (Vec2 const& u, Vec2 const& v) {
    Vec2 result {u};
    result += v;
    return result;
}

Vec2 operator- (Vec2 const& u, Vec2 const& v) {
    Vec2 result {u};
    result -= v;
    return result;
}

Vec2 operator* (Vec2 const& v, float s) {
    Vec2 result {v};
    result *= s;
    return result;
}

Vec2 operator/ (Vec2 const& v, float s) {
    if (s == 0) {
        throw std::invalid_argument ("Division by 0");
    }
    Vec2 result {v};
    result /= s;
    return result;
}

Vec2 operator* (float s, Vec2 const& v) {
    Vec2 result {v};
    result *= s;
    return result;
}
