#include "shapes.hpp"

//circle methods

//initializing circle constructor with list
Circle::Circle (float r, Vec2 centr, Color const& clr, Color const& highlight_clr):
    radius_ {r},
    center_ {centr},
    color_ {clr},
    highlight_color_ {highlight_clr}
{}

//determines the circumference of the rectangle
float Circle::circumference() const {
    return (2 * M_PI * radius_);
}

//draws a circle in a given window and if highlight is true in the highlighted color
void Circle::draw (Window const& win, bool highlight) const {
    Color clr;
    if (highlight) {
        clr = highlight_color_;
    } else {
        clr = color_;
    }
    
    float count_segments = 70.0f;
    float phi = ((360 / count_segments) * (M_PI / 180));
    Vec2 start {0.0f, radius_};
    Vec2 end;
    for (int i = 0; i <= count_segments; i++) {
        end = start;
        end = end * make_rotation_mat2(phi);
        win.draw_line (start.x + center_.x, start.y + center_.y,
                       end.x + center_.x, end.y + center_.y,
                       clr.r, clr.g, clr.b,
                       1.0f);
       start = end;
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
Rectangle::Rectangle (Vec2 const& minimum, Vec2 const& maximum, Color const& clr, Color const& highlight_clr):
    min_ {minimum},
    max_ {maximum},
    color_ {clr},
    highlight_color_ {highlight_clr}
{}

//determines the circumference of the rectangle
float Rectangle::circumference() const {
    float width = max_.x - min_.x;
    float height = max_.y - min_.y;
    return (2 * width + 2 * height);
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
