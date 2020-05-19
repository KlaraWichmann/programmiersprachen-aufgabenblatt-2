#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <math.h>
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
    public:
        Circle (float r, float centr, Color const& clr);
        float circumference() const;
        void draw (Window const& win) const;
        void draw (Window const& win, bool highlight) const;
    private:
        float radius_ = 0.0f;
        float center_ = 0.0f;
        Color color_;
        Color highlight_color_ {1.0f, 1.0f, 0.0f};
};

class Rectangle {
    public:
        Rectangle () = default;
        Rectangle (Vec2 const& minimum, Vec2 const& maximum, Color const& clr);
        float circumference() const;
        void draw (Window const& win) const;
    private:
        Vec2 min_;
        Vec2 max_;
        Color color_;
        Color highlight_color_ {1.0f, 1.0f, 0.0f};
};


#endif // SHAPES_HPP
