#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "mat2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <math.h>

//circle object containing a radius, center, color and highlight color
class Circle {
    public:
        Circle (float r, Vec2 centr, Color const& clr, Color const& highlight_clr);
        float circumference() const;
        void draw (Window const& win, bool highlight = false) const;
        bool is_inside (Vec2 const& v);
    private:
        float radius_ = 0.0f;
        Vec2 center_;
        Color color_;
        Color highlight_color_;
};

//rectangle object containing a minimum vector (bottom left), a maximum vector (top right), color and highlight color
class Rectangle {
    public:
        Rectangle () = default;
        Rectangle (Vec2 const& minimum, Vec2 const& maximum, Color const& clr, Color const& highlight_clr);
        float circumference() const;
        void draw (Window const& win, bool highlight = false) const;
        bool is_inside (Vec2 const& v);
    private:
        Vec2 min_;
        Vec2 max_;
        Color color_;
        Color highlight_color_;
};


#endif // SHAPES_HPP
