#include <vector>
#include <algorithm>
#include <iterator>

TEST_CASE("alle Elemente gleich zehn","[sum]")
{

std::vector<int> v_1{1,2,3,4,5,6,7,8,9};
std::vector<int> v_2{9,8,7,65,4,3,2,1};
std::vector<int> v_3(9);
  
REQUIRE (std::all_of(v3_3.begin(), v3_3.end(), is_even)); //Test

}

int main (int argc, char* argv[])
{
   return Catch::Session().run (argc,argv);
}