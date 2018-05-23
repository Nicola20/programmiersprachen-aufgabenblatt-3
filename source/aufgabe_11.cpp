#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>

bool is_multiple_of_3 (int i) {
     return (i%3) == 0;
}

bool dividable_by_3 (int i){
    return (i % 3) != 0;  
}



TEST_CASE("filter alle vielfache von drei","[erase]")
{

std::vector<unsigned int> v(100);
for (auto& it : v) {                        //wann genau macht man auto& ?
    it = std::rand() % 101;                       //Fügt von 0-100 random positive zahlen ein
}

    v.erase(std::remove_if(v.begin(), v.end(), dividable_by_3), v.end());       //Nicht durch 3 teilbare entfernen
  
REQUIRE (std::all_of(v.begin(), v.end(), is_multiple_of_3 )); //Test
}


int main (int argc, char* argv[])
{
   return Catch::Session().run (argc,argv);
}