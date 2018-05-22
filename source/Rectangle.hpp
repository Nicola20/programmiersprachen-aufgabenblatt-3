# ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

#include "Vec2.hpp"
#include "color.hpp"
#include "window.hpp"


class Rectangle
{

    public:
    Rectangle (Vec2 const& min, Vec2 const& max, Color const& color);

    Vec2 getMin() const;
    Vec2 getMax() const;
    float circumference() const;
    Color getColor() const;
    void draw (Window const& w);
    void draw(Window const& w, Color const& c);
    bool is_inside(Vec2 const& v);

    private:
    Vec2 min_;
    Vec2 max_;
    Color color_;

    
    
};

# endif // RECTANGLE_HPP