#include "shapes.hpp"

Circle::Circle (float r, Color const& clr):
    radius_ {r},
    color_ {clr}
{}


Rectangle::Rectangle (Vec2 const& minimum, Vec2 const& maximum, Color const& clr):
    min_ {minimum},
    max_ {maximum},
    color_ {clr}
{}

float Rectangle::circumference() const {
    float result = 0.0f;
    float width = max_.x - min_.x;
    float height = max_.y - min_.y;
    result = 2 * width + 2 * height;
    return result;
}

float Circle::circumference() const {
    float result = 0.0f;
    result = 2 * M_PI * radius_;
    return result;
}
