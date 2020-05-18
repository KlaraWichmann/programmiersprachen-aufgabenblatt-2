#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <math.h>
#include "vec2.hpp"
#include "color.hpp"

class Circle {
    public:
        Circle (float r, Color const& clr);
        float circumference() const;
    private:
        float radius_;
        Color color_;
};

class Rectangle {
    public:
        Rectangle () = default;
        Rectangle (Vec2 const& minimum, Vec2 const& maximum, float width, float height, Color const& clr);
        float circumference() const;
    private:
        Vec2 min_ {1.0f, 1.0f};
        Vec2 max_{1.0f, 1.0f};
        float width_ = 1.0f;
        float height_ = 1.0f;
        Color color_ {2, 2, 2};
};


#endif // SHAPES_HPP
