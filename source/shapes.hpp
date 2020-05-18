#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "vec2.hpp"

class Circle {
    public:
        Circle (float r, Color const& clr);
    private:
        float radius_;
        Color color_;
};

class Rectangle {
    public:
        Rectangle (float minimum, float maximum, Color const& clr);
    private:
        Vec2 min_;
        Vec2 max_;
        Color color_;
};


#endif // SHAPES_HPP
