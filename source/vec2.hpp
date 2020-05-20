#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 data type definition
struct Vec2 {
    float x = 0.0f;
    float y = 0.0f;

    //xVec2 (Vec2 const& v);
    
    //member methods overwriting += operator for a vector
    Vec2& operator+= (Vec2 const& v);
    //member methods overwriting -= operator for a vector
    Vec2& operator-= (Vec2 const& v);
    //member methods overwriting *= operator for a vector
    Vec2& operator*= (float s);
    //member methods overwriting /= operator for a vector
    Vec2& operator/= (float s);
};

//overwrites the + operation for two vectors
Vec2 operator+ (Vec2 const& u, Vec2 const& v);

//overwrites the - operation for two vectors - ensuring commutativity
Vec2 operator- (Vec2 const& u, Vec2 const& v);

//overwrites the * operation for a vector and a float value
Vec2 operator* (Vec2 const& v, float s);

//overwrites the / operation for a vector and a float value
Vec2 operator/ (Vec2 const& v, float s);

//overwrites the * operation for a float value and a vector - ensuring commutativity
Vec2 operator* (float s, Vec2 const& v);

#endif // VEC2_HPP
