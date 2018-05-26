#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
//#include <algorithm>
#include <vector>

bool is_even (int n) {
     return (n%2) == 0;
}

bool is_uneven (int n) {
    return (n%2) != 0;
}

template<typename container, typename praedikat> //verwende keine sonderzeichen, wirft sonst fehler
    container filter (container c, praedikat p) {
       container c2;
       for (auto i=c.begin(); i !=c.end(); ++i) {
           if (p(*i) == true) {
              c2.push_back(*i);
           }
       }
       return c2;
   }



TEST_CASE("filter alle vielfache von drei","[erase]")
{

std::vector<int> v{1,2,3,4,5,6};
std::vector<int> all_even = filter(v, is_even);
std::vector<int> not_even = filter(v, is_uneven);
  
REQUIRE (std::all_of(all_even.begin(), all_even.end(), is_even)); //Test
REQUIRE (std::all_of(not_even.begin(), not_even.end(), is_uneven)); //Test


}


int main (int argc, char* argv[])
{
   return Catch::Session().run (argc,argv);
}