#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <math.h>
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
    public:
        Circle (float r, /*float centr,*/ Color const& clr);
        float circumference() const;
        void draw (Window const& win) const;
    private:
    float radius_;// = 0.0f;
        //float center_ = 0.0f;
        Color color_;
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
};


#endif // SHAPES_HPP
