#include "shapes.hpp"

#include <iostream>

//circle methods

//initializing circle constructor with list
Circle::Circle (float r, Vec2 centr, Color const& clr):
    radius_ {r},
    center_ {centr},
    color_ {clr}
{}

//determines the circumference of the rectangle
float Circle::circumference() const {
    float result = 0.0f;
    result = 2 * M_PI * radius_;
    return result;
}

//draws a circle in a given window
void Circle::draw (Window const& win) const {
    float temp_x = center_.x + cos(1 * (M_PI/180)) * radius_;
    float temp_y = center_.x + sin(1 * (M_PI/180)) * radius_;
    for (int i = 2; i <= 360; i++) {
         win.draw_line (temp_x, temp_y,
                        center_.x + cos(i * (M_PI/180)) * radius_, center_.x + sin(i * (M_PI/180)) * radius_,
                        color_.r, color_.g, color_.b,
                        1.0f);
        temp_x = center_.x + cos(i * (M_PI/180)) * radius_;
        temp_y = center_.x + sin(i * (M_PI/180)) * radius_;
    }
}

//draws a circle in a given window and if highlight is true in the highlighted color
void Circle::draw (Window const& win, bool highlight) const {
    Color clr;
    if (highlight) {
        clr = highlight_color_;
    } else {
        clr = color_;
    }
    float temp_x = center_.x + cos(1 * (M_PI/180)) * radius_;
    float temp_y = center_.x + sin(1 * (M_PI/180)) * radius_;
    for (int i = 2; i <= 360; i++) {
         win.draw_line (temp_x, temp_y,
                        center_.x + cos(i * (M_PI/180)) * radius_, center_.x + sin(i * (M_PI/180)) * radius_,
                        clr.r, clr.g, clr.b,
                        1.0f);
        temp_x = center_.x + cos(i * (M_PI/180)) * radius_;
        temp_y = center_.x + sin(i * (M_PI/180)) * radius_;
    }
}

//checks if given vector is in circle
bool Circle::is_inside (Vec2 const& v) {
    Vec2 min {center_.x - radius_, center_.y - radius_};
    Vec2 max {center_.x + radius_, center_.y + radius_};
    if (v.x >= min.x && v.x <= max.x && v.y >= min.y && v.y <= max.y) {
        return true;
    }
    return false;
}

//rectangle methods

//initializes rectangle constructor with list
Rectangle::Rectangle (Vec2 const& minimum, Vec2 const& maximum, Color const& clr):
    min_ {minimum},
    max_ {maximum},
    color_ {clr}
{}

//determines the circumference of the rectangle
float Rectangle::circumference() const {
    float result = 0.0f;
    float width = max_.x - min_.x;
    float height = max_.y - min_.y;
    result = 2 * width + 2 * height;
    return result;
}

//draws the rectangle in a given window
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

//draws a rectangle in a given window and if highlight is true in the highlighted color
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

//checks if given vector is in rectangle
bool Rectangle::is_inside (Vec2 const& v) {
    if (v.x >= min_.x && v.x <= max_.x && v.y >= min_.y && v.y <= max_.y) {
        return true;
    }
    return false;
}
