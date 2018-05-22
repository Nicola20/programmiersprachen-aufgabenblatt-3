#include "Rectangle.hpp"

Rectangle::Rectangle (Vec2 const& min, Vec2 const& max, Color const& color):
   min_{min},
   max_{max},
   color_{color} 
   {}


Vec2 Rectangle::getMin() const {
    return this -> min_;
}

Vec2 Rectangle::getMax() const{
    return this -> max_;
}

Color Rectangle::getColor() const {
    return this -> color_;
}


float Rectangle::circumference() const{

    float a = max_.x_ - min_.x_;                //Länge
    float b = max_.y_ - min_.y_;                //Breite
    return 2*a+2*b;
}

  void Rectangle::draw (Window const& w) {
      w.draw_line(min_.x_, min_.y_, max_.x_, min_.y_,0.0f,0.0f,0.0f); //min nach rechts
      w.draw_line(min_.x_, min_.y_, min_.x_, max_.y_,0.0f,0.0f,0.0f); //min nach oben
      w.draw_line(max_.x_, min_.y_, max_.x_, max_.y_,0.0f,0.0f,0.0f); //unten rechts nach max
      w.draw_line(max_.x_, max_.y_, min_.x_, max_.y_,0.0f,0.0f,0.0f); //max nach links
  }

  void Rectangle::draw(Window const& w, Color const& c) {
      w.draw_line(min_.x_, min_.y_, max_.x_, min_.y_,c.r_, c.g_, c.b_); //min nach rechts
      w.draw_line(min_.x_, min_.y_, min_.x_, max_.y_,c.r_, c.g_, c.b_); //min nach oben
      w.draw_line(max_.x_, min_.y_, max_.x_, max_.y_,c.r_, c.g_, c.b_); //unten rechts nach max
      w.draw_line(max_.x_, max_.y_, min_.x_, max_.y_,c.r_, c.g_, c.b_); //max nach links
  }

  bool Rectangle::is_inside(Vec2 const& v){
      if (min_.x_ < v.x_ && v.x_ < max_.x_){
        if (min_.y_ < v.y_ && v.y_ < max_.y_){
            return true;
        }
        return false;
      }
      return false;
  }
   

