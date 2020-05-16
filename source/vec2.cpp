#include "vec2.hpp"

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
    x /= s;
    y /= s;
    return *this;
}

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
