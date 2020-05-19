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
    float temp_x = center_ + cos(1 * (M_PI/180)) * radius_;
    float temp_y = center_ + sin(1 * (M_PI/180)) * radius_;
    for (int i = 2; i <= 360; i++) {
         win.draw_line (temp_x, temp_y,
         center_ + cos(i * (M_PI/180)) * radius_, center_ + sin(i * (M_PI/180)) * radius_,
         color_.r, color_.g, color_.b,
         1.0f);
        temp_x = center_ + cos(i * (M_PI/180)) * radius_;
        temp_y = center_ + sin(i * (M_PI/180)) * radius_;
    }
}

void Circle::draw (Window const& win, bool highlight) const {
    Color clr;
    if (highlight) {
        clr = highlight_color_;
    } else {
        clr = color_;
    }
    float temp_x = center_ + cos(1 * (M_PI/180)) * radius_;
    float temp_y = center_ + sin(1 * (M_PI/180)) * radius_;
    for (int i = 2; i <= 360; i++) {
         win.draw_line (temp_x, temp_y,
         center_ + cos(i * (M_PI/180)) * radius_, center_ + sin(i * (M_PI/180)) * radius_,
         clr.r, clr.g, clr.b,
         1.0f);
        temp_x = center_ + cos(i * (M_PI/180)) * radius_;
        temp_y = center_ + sin(i * (M_PI/180)) * radius_;
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

void Rectangle::draw (Window const& win, bool highlight) const {
    Color clr;
    if (highlight) {
        clr = highlight_color_;
    } else {
        clr = color_;
    }
    
    win.draw_line (min_.x, min_.y,
                      max_.x, min_.y,
                      clr.r, clr.g, clr.b,
                      1.0f);
    win.draw_line (max_.x, min_.y,
                      max_.x, max_.y,
                      clr.r, clr.g, clr.b,
                      1.0f);
    win.draw_line (max_.x, max_.y,
                      min_.x, max_.y,
                      clr.r, clr.g, clr.b,
                      1.0f);
    win.draw_line (min_.x, max_.y,
                      min_.x, min_.y,
                      clr.r, clr.g, clr.b,
                      1.0f);
}

bool Rectangle::is_inside (Vec2 const& v) {
    if (v.x >= min_.x && v.x <= max_.x && v.y >= min_.y && v.y <= max_.y) {
        return true;
    }
    return false;
}
