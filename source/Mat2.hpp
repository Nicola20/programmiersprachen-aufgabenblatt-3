# ifndef MAT2_HPP
# define MAT2_HPP

#include "Vec2.hpp"
#include <cmath>
#include <iostream>

struct Mat2
{
    Mat2& operator*=(Mat2 const& m);

    Mat2 (float a, float b, float c, float d);
    Mat2 ();

    float a_;
    float b_;
    float c_;
    float d_;

    float det () const ;

     //schmeißt aus irgendwelchen Gründen komische Fehler...

};

Mat2 operator *(Mat2 const& m1, Mat2 const& m2);

Vec2 operator *(Mat2 const& m , Vec2 const& v );
Vec2 operator *(Vec2 const& v , Mat2 const& m );
Mat2 inverse (Mat2 const& m );
Mat2 transpose (Mat2 const& m );
Mat2 make_rotation_mat2 (float phi);

# endif // MAT2_HPP