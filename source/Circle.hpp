# ifndef CIRCLE_HPP
# define CIRCLE_HPP

#include "Vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <string>
using namespace std;


class Circle
{

    public:
    Circle (float r, float d, Vec2 const& c, Color const& color);
    Circle (float r, Vec2 const& c, Color const& color);
    /*Erweiterung für Aufgabe 3.4*/
    Circle (float r, Vec2 const& c, Color const& color, std::string name);

    float getRadius() const;
    float getDiameter() const;
    Vec2 getCenter() const;
    Color getColor() const;
    float circumference() const;
    void draw (Window const& w);
    void draw (Window const& w, Color const& c);
    bool is_inside(Vec2 const& v);

    /*Erweiterungen für Aufgabe 3.6*/
     bool operator< (Circle const& c);
     bool operator> (Circle const& c);
     bool operator== (Circle const& c);
     std::string getName() const;
     void setColor(Color const& c);

    private:
    float radius_;
    Vec2 center_;
    float diameter_;
    Color color_;
    /*Erweiterung für Aufgabe 3.4*/
    std::string name_; 
    
    
};
# endif // CIRCLE_HPP