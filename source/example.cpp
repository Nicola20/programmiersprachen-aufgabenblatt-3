#include "window.hpp"
#include "Circle.hpp"
//#include "Rectangle.hpp"
//#include "Vec2.hpp"

#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <set>
#include <iostream>
#include <vector>
#include <string>



int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

    std::cout<<"Please enter a name of the circle you are searching for. \n";
    string input;
    std::cin >> input;

    double first_timestamp = win.get_time();

    Circle c1{200.0f, Vec2{300.0f,100.0f}, Color{0.0f}, "karl"};
    Circle c2{100.0f, Vec2{250.0f,150.0f}, Color{0.0f}, "judith"};

    std::vector<Circle> vec;
    vec.push_back(c1);
    vec.push_back(c2);

  while (!win.should_close()) {

    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
    
  
    auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f); 

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }


    /*Ergänzungen zu Aufgabe 3.4*/
    for (int i = 0; i < vec.size(); ++i) {
        if(vec[i].getName() == input) {
            double second_timestamp = win.get_time();
            //std::cout << second_timestamp - first_timestamp << std::endl;

            if ((second_timestamp - first_timestamp) < 11) {
              vec[i].setColor(Color{1.0f, 0.0f, 0.0f});
            }
        }
        vec[i].draw(win, vec[i].getColor());
    }



    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);

    win.update();
  }

  return 0;
}
