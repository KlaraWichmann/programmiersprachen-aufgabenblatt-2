#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <math.h>
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

//circle object containing a radius, center and color
class Circle {
    public:
        Circle (float r, Vec2 centr, Color const& clr);
        float circumference() const;
        void draw (Window const& win) const;
        void draw (Window const& win, bool highlight) const;
        bool is_inside (Vec2 const& v);
    private:
        float radius_ = 0.0f;
        Vec2 center_;
        Color color_;
        Color highlight_color_ {1.0f, 1.0f, 0.0f};
};

//rectangle object containing a minimum vector (bottom left), a maximum vector (top right) and a color
class Rectangle {
    public:
        Rectangle () = default;
        Rectangle (Vec2 const& minimum, Vec2 const& maximum, Color const& clr);
        float circumference() const;
        void draw (Window const& win) const;
        void draw (Window const& win, bool highlight) const;
        bool is_inside (Vec2 const& v);
    private:
        Vec2 min_;
        Vec2 max_;
        Color color_;
        Color highlight_color_ {1.0f, 1.0f, 0.0f};
};


#endif // SHAPES_HPP
