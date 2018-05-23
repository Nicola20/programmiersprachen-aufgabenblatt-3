#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "Circle.hpp"
#include <algorithm>
#include <vector>
#include <iostream>


TEST_CASE ("test_if_sorted","[sorting]")
 {
   std::vector<Circle> sorted_circles;

 Circle c1 {4.0f,Vec2{3.7f, 6.3f}, Color{1.0f, 1.0f,1.0f}};
 Circle c2 {4.7f,Vec2{3.7f, 6.3f}, Color{1.0f, 1.0f,1.0f}};
 Circle c3 {6.9f,Vec2{3.7f, 6.3f}, Color{1.0f, 1.0f,1.0f}};

 sorted_circles.push_back(c1);
 sorted_circles.push_back(c2);
 sorted_circles.push_back(c3);

 std::sort(sorted_circles.begin(), sorted_circles.end());
 
   REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
 } 

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
	//return 0;
}