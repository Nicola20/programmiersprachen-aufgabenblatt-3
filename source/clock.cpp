#include "Vec2.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "window.hpp"

#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

 //auto t = win.get_time();
 double t= 3*3600;

     Circle c1 {300.0f, Vec2{400.0f,400.0f},Color{0.0f}};
     c1.draw(win);

     Vec2 middle (c1.getCenter().x_,c1.getCenter().y_);

        win.draw_line(400.0f,400.0f,-(c1.getRadius()-20)*cos(t*0.0000727f + (M_PI/2))+ middle.x_, -(c1.getRadius()-20)*sin(t*0.0000727f + (M_PI/2))+ middle.y_,0.0,0.0,0.0);  //Stunde

        win.draw_line(400.0f,400.0f,-(c1.getRadius()-20)*cos(t*0.0000727f + (M_PI/2))+ middle.x_, -(c1.getRadius()-20)*sin(t*0.0000727f + (M_PI/2))+ middle.y_,0.0,0.0,0.0);
            
        win.draw_line(400.0f,400.0f,-(c1.getRadius()-150.0f)*cos(t*0.0017f + (M_PI/2))+ middle.x_, -(c1.getRadius()-150.0f)*sin(t*0.0017f + (M_PI/2))+ middle.y_,0.0,0.0,0.0);  //Minute

        win.draw_line(400.0f,400.0f,-(c1.getRadius()-150.0f)*cos(t*0.0017f + (M_PI/2))+ middle.x_, -(c1.getRadius()-150.0f)*sin(t*0.0017f + (M_PI/2))+ middle.y_,0.0,0.0,0.0);

        win.draw_line(400.0f,400.0f,-(c1.getRadius()-100.0f)*cos(t*0.1f + (M_PI/2))+ middle.x_, -(c1.getRadius()-100.0f)*sin(t*0.1f + (M_PI/2))+ middle.y_,0.0,0.0,0.0);  //Sekunde

        win.update();

    }

    return 0;






  }