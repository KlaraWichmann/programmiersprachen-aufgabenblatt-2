#include "vec2.hpp"

Vec2& Vec2::operator+= (Vec2 const& v) {
    x += v.x;
    y += v.y;
    return *this;
}
