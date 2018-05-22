# include <cstdlib>  //std::rand ()
# include <vector>   //std::vector <>
# include <list>     //std::list <>
# include <iostream>  //std::cout
# include <iterator>   //std::ostream_iterator <>
# include <algorithm>  //std::reverse, std::generate

int main () {
   std::vector <int> v_0 (10);  //erstellt vektor mit 10 stellen
   for ( auto & v : v_0 ) {
       v = std :: rand (); //füllt den vector mit Zufallszahlen
   }

   std::copy(std::cbegin (v_0), std::cend (v_0), // kopiert begin(v_0) bis end(v_0) die werte in den ostream operator
   std::ostream_iterator <int>(std::cout,"\n"));//printet die kopierten werte aus (v_0)

   std::list <int> l_0 (std::cbegin (v_0), std::cend (v_0)); //erstellt liste l_0 mit den werten von v_0
   std::list <int> l_1 (std::cbegin (l_0), std::cend (l_0));  //erstellt l_1 aus l_0 (kopieren der werte)
   std::reverse (std::begin(l_1), std::end (l_1)); //dreht l_1 um
   std::copy (std::cbegin (l_1), std::cend (l_1), //gibt l_1 aus
   std::ostream_iterator <int>(std::cout,"\n"));

   l_1.sort();        //sortiert l_1 nach größe
   std::copy (l_1.cbegin(), l_1.cend(),  //gibt die veränderte l_1 aus  
   std::ostream_iterator <int>(std::cout,"\n"));

   std::generate (std::begin (v_0), std::end (v_0), std::rand); //füllt v_0 mit neuen Zufallszahlen
   std::copy (v_0.crbegin(), v_0.crend(),    //gibt veränderten v_0 aus
   std::ostream_iterator <int>(std::cout,"\n"));

   return 0;
}