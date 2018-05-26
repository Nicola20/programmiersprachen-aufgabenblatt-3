#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Circle.hpp"

#include <vector>


TEST_CASE ("equals_10", "[transform]"){
    std::vector <int> v1 {1,2,3,4,5,6,7,8,9};
    std::vector <int> v2 {9,8,7,6,5,4,3,2,1};
    std::vector <int> v3 (9);

    std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), [](int i, int j) {return i+j;});       //in v3, v2 + v1 einfügen durch lambda (Funktion) und transform (wendet Funktion auf alle Elemente an)
    //anstatt v3.begin ist alternativ auch std::back_inserter(v3) möglich, wenn die größe von v3 noch nicht festgelegt ist

    //std::copy(std::begin(v3), std::end(v3), std::ostream_iterator <int>(std::cout, "\n"));              //v3 ausgeben
    
    REQUIRE(std::all_of(v3.begin(),v3.end(), [](int n) { return n == 10; } ));
}

int main(int argc, char* argv[]){

    return Catch::Session().run(argc, argv); 

}