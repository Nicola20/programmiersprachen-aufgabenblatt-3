#include "Mat2.hpp"


//User-Konstruktor
Mat2::Mat2 (float a, float b, float c, float d):
   a_{a},
   b_{b},
   c_{c},
   d_{d} {}

Mat2::Mat2 ():
   a_{1.0f},
   b_{0.0f},
   c_{0.0f},
   d_{1.0f} {}


Mat2& Mat2::operator*=(Mat2 const& m)
{   
    float tmp_a = a_;
    float tmp_b = b_;
    float tmp_c = c_;
    float tmp_d = d_;

    a_ = tmp_a* m.a_ + tmp_b *m.c_;
	b_ = tmp_a * m.b_ + tmp_b * m.d_;

	c_ = tmp_c * m.a_ + tmp_d* m.c_;
	d_ = tmp_c * m.b_ + tmp_d * m.d_;

    return *this;
 
}

Mat2 operator *(Mat2 const& m1, Mat2 const& m2)
{
    Mat2 result{};

	result.a_ = m1.a_ * m2.a_ + m1.b_ * m2.c_;
	result.b_ = m1.a_ * m2.b_ + m1.b_ * m2.d_;

	result.c_ = m1.c_ * m2.a_ + m1.d_ * m2.c_;
	result.d_ = m1.c_ * m2.b_ + m1.d_ * m2.d_;

return result;
}

float Mat2::det() const
{
    return ((a_*d_) - (b_*c_));
}

Vec2 operator *(Mat2 const& m , Vec2 const& v )
{
    Vec2 result{};
    result.x_ =m.a_*v.x_ + m.b_*v.y_;
    result.y_ =m.c_*v.x_ + m.d_*v.y_;

    return result;
}

Vec2 operator *(Vec2 const& v , Mat2 const& m )
{
    Vec2 result{};
    result.x_ = m.a_*v.x_ + m.b_*v.y_;
    result.y_ = m.c_*v.x_ + m.d_*v.y_;

    return result;
}

Mat2 inverse (Mat2 const& m )
{   
    if(m.det() == 0) {
        std::cout<<"Da die Determinante gleich 0 ist, gibt es keine Inverse.\n";
    } else {
    
      float a = ((1 / m.det()) * m.d_);
      float b = ((1 / m.det()) * (-m.b_));
      float c = ((1 / m.det()) *(-m.c_));
      float d = ((1 / m.det()) * m.a_);

       return Mat2 {a,b,c,d};
    }
}

Mat2 transpose (Mat2 const& m )
{
    Mat2 transpose = m;
    transpose.b_ = m.c_;
    transpose.c_ = m.b_;

    return transpose;

}

Mat2 make_rotation_mat2 (float phi)
{
    return Mat2 {(float)cos(phi), -1.0f*(float)sin(phi),(float)sin(phi), (float)cos(phi)};
}

