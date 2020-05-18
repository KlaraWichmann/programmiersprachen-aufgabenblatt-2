#include "shapes.hpp"

Circle::Circle (float r, Color const& clr):
    radius_ {r},
    color_ {clr}
{}


Rectangle::Rectangle (Vec2 const& minimum, Vec2 const& maximum, float width, float height, Color const& clr):
    min_ {minimum},
    max_ {maximum},
    width_ {width},
    height_ {height},
    color_ {clr}
{}

float Rectangle::circumference() const {
    float result = 0.0f;
    result = 2 * width_ + 2 * height_;
    return result;
}

float Circle::circumference() const {
    float result = 0.0f;
    result = 2 * M_PI * radius_;
    return result;
}
