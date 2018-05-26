#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "Circle.hpp"
#include <vector>


TEST_CASE ("sorted_circles", "[sort]"){
   std::vector<Circle> sorted_circles;

    Circle c1 {4.0f,Vec2{3.7f, 6.3f}, Color{1.0f, 1.0f,1.0f}};
    Circle c2 {4.7f,Vec2{3.7f, 6.3f}, Color{1.0f, 1.0f,1.0f}};
    Circle c3 {6.9f,Vec2{3.7f, 6.3f}, Color{1.0f, 1.0f,1.0f}};
    Circle c4 {1.9f,Vec2{3.7f, 6.3f}, Color{1.0f, 1.0f,1.0f}};
    Circle c5 {5.9f,Vec2{3.7f, 6.3f}, Color{1.0f, 1.0f,1.0f}};

    sorted_circles.push_back(c1);
    sorted_circles.push_back(c2);
    sorted_circles.push_back(c3);
    sorted_circles.push_back(c4);
    sorted_circles.push_back(c5);

    std::sort(sorted_circles.begin(), sorted_circles.end(),[](Circle circ1, Circle circ2) {return circ1 < circ2;}), sorted_circles.end();          //mit lambda sortieren 
    REQUIRE(std::is_sorted(sorted_circles.begin(),sorted_circles.end()));
}

int main(int argc, char* argv[]){

    return Catch::Session().run(argc, argv); 
}