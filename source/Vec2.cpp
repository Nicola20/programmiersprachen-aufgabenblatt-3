#include "Vec2.hpp"


// TODO Constructors
  Vec2::Vec2 ():
   x_{0.0f}, 
   y_{0.0f}
   {}

  Vec2::Vec2 (float x, float y):
    x_{x},
    y_{y} 
    {}

  Vec2& Vec2::operator+=(Vec2 const& v)
  {
     x_ += v.x_;
	   y_ += v.y_;

    return *this;
  }

  Vec2& Vec2::operator-=(Vec2 const& v)
  {
     x_ -= v.x_;
     y_ -= v.y_;

     return *this;
  }

Vec2& Vec2::operator*=(float s)
{
     x_ *= s;
     y_ *= s;

     return *this;
}

Vec2& Vec2::operator/=(float s)
{
    if(s==0){
        std::cout<<"Division by zero ist not possible!";
        return *this;
    } else {
     x_ /= s;
     y_ /= s;

     return *this;
    }
}

  Vec2 operator + (Vec2 const& u, Vec2 const& v)
  {
    Vec2 result {};
    result.x_ = u.x_ + v.x_;
    result.y_ = u.y_ + v.y_;

    return result;
  }


  Vec2 operator - (Vec2 const& u, Vec2 const& v)
  {
    Vec2 result {};
    result.x_ = u.x_ - v.x_;
    result.y_ = u.y_ - v.y_;

    return result;
  }


  Vec2 operator * (Vec2 const& v, float s)
  { 
    Vec2 result {};
    result.x_ = v.x_ *s;
    result.y_ = v.y_ *s;

    return result;
  }

  Vec2 operator *(float s, Vec2 const & v )
  {
    Vec2 result {};
    result.x_ = v.x_ *s;
    result.y_ = v.y_ *s;

    return result;
  }

  Vec2 operator / (Vec2 const& v, float s)
  {
    if(s==0) {
      std::cout<<"Division by zero is not possible.";
    } else {
       Vec2 result {};
       result.x_ = v.x_ /s;
       result.y_ = v.y_ /s;

       return result;
    }
  }

