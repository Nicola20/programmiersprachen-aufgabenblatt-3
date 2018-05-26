
#include <list>
#include <vector>
#include <set>
# include <cstdlib>
# include <iostream> // std :: cout
# include <iterator> // std :: ostream_iterator <>
# include <algorithm> // std :: reverse , std :: generate
#include <map>

int main() {

    std::list <unsigned int> l1 (100);           //int kann nicht neg. werden
    for (auto& l : l1) {
		  l = std::rand() % 101;                       //Fügt von 0-100 random positive zahlen ein
    }

    /* Aufgabe 3.10 */
    std::vector<unsigned int > v1 (l1.size());               
    std::copy(std::begin(l1), std::end(l1), std::begin(v1));  //Kopieren von list l1 in vector v1


    std::set <unsigned int> s1;

    for(auto& s : l1){                            //Jede Zahl kommt nur einmal vor, da Dublikate von set ignoriert werden 
      s1.insert(s);
    }

    std::cout<< "Insgesamt befinden sich " << l1.size() << " Zahlen in der Liste. Davon sind "<< s1.size() << " verschieden. \n";

    std::set <unsigned int> s2;

    for(int i = 0; i <= 100; ++i ){       //Elemente die die list nicht enthält
      auto j = s1.find(i);
      if(j == s1.end()){            //Wenn Element nicht vorhanden verweis auf end()
        s2.insert(i);
      }
    }

  /* merkwürdig, da 62 verschiedene Werte in der Liste sind aber 39 nicht vorhanden sind =101? */
  std::cout << "Die Liste enthält nicht: \n";
  for (std::set<unsigned int>::iterator it = s2.begin(); it!=s2.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';    


    /*Aufgabe 3.4 */

    std::map<int,int> count;
    for (auto i = l1.begin(); i != l1.end(); ++i) {
         count.insert(std::make_pair(*i, 0));
         if (count.count(*i) > 0) { //count(key) schaut, ob der besagte key bereits vorhanden ist
           ++count[*i];
         }

    }

    std::cout << "Zahlen und ihre Häufigkeit: \n";

    for(auto it = count.begin(); it != count.end(); ++it){      //map printen
      std::cout << it->first << ":" << it->second << "\n";
    }

  /*

    //map bietet sich an weil der Key(Zahl) unveränderlich ist und nur einmal vorkommt aber die Value(Anzahl) verändert werden kann 
//Also wenn Key mehr als einmal vorkommt  */
    
}