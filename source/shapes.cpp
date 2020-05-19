#include "shapes.hpp"

#include <iostream>

Circle::Circle (float r, float centr, Color const& clr):
    radius_ {r},
    center_ {centr},
    color_ {clr}
{}

float Circle::circumference() const {
    float result = 0.0f;
    result = 2 * M_PI * radius_;
    return result;
}

void Circle::draw (Window const& win) const {
    float temp_x = cos(0) * radius_;
    float temp_y = sin(0) * radius_;
     for (int i = 1; i <= 24; i++) {
         win.draw_line (temp_x, temp_y,
         cos(i) * radius_, sin(i) * radius_,
         color_.r, color_.g, color_.b,
         1.0f);
        temp_x = cos(i) * radius_;
        temp_y = sin(i) * radius_;
    }
}


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

void Rectangle::draw (Window const& win) const {
    win.draw_line (min_.x, min_.y,
                      max_.x, min_.y,
                      color_.r, color_.g, color_.b,
                      1.0f);
    win.draw_line (max_.x, min_.y,
                      max_.x, max_.y,
                      color_.r, color_.g, color_.b,
                      1.0f);
    win.draw_line (max_.x, max_.y,
                      min_.x, max_.y,
                      color_.r, color_.g, color_.b,
                      1.0f);
    win.draw_line (min_.x, max_.y,
                      min_.x, min_.y,
                      color_.r, color_.g, color_.b,
                      1.0f);
}
