#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <list>

class SortedLinkedList;
class SortedArrayList;

#include "sortedLinkedList.h"
#include "sortedArrayList.h"

using namespace std;

int main(int argc, char* argv[]){

   //Deklaracja zmiennych i obiektow
   string cin_input;
   stringstream stream1, stream2;
   int l1_count, l2_count, z, n;
   char x;
   SortedArrayList al1, al2;
   SortedLinkedList ll1, ll2;
   list<int> sl1, sl2;

   //Wczytanie dlugosci l1
   getline(cin, cin_input);
   stream1 << cin_input;
   stream1 >> l1_count;
   stream1.clear();

   //Wczytanie l1
   getline(cin, cin_input);
   for(int i = 0; i < l1_count; i++){
      stream1 << cin_input;
      stream1 >> z;
      al1.push(z);
      ll1.push(z);
      sl1.push_front(z);
      //stream1 >> x; //Mozna ignorowac spacje
   }
   stream1.clear();
   sl1.sort();

   //Wczytanie dlugosci l2
   getline(cin, cin_input);
   stream2 << cin_input;
   stream2 >> l2_count;
   stream2.clear();

   //Wczytanie l1
   getline(cin, cin_input);
   for(int i = 0; i < l2_count; i++){
      stream2 << cin_input;
      stream2 >> z;
      al2.push(z);
      ll2.push(z);
      sl2.push_front(z);
      //stream2 >> x; //Mozna ignorowac spacje
   }
   stream2.clear();
   sl2.sort();

   /** Do testow dzialania list
   cout << "\nLista Array1\n";
   al1.print();
   cout << "\nLista Linked1:\n";
   ll1.print();
   cout << "\nLista Array2:\n";
   al2.print();
   cout << "\nLista Linked2:\n";
   ll2.print();
   cout << "\n";
   */
   auto a = SortedArrayList::merge(al1, al2);
   cout<< "\nal1 and al2 merged:\n";
   a.print();

   auto b = SortedLinkedList::merge(ll1, ll2);
   cout << "\nll1 and ll2 merged:\n";
   b.print();

   sl1.merge(sl2);
   cout << "\nsl1 and sl2 merged:\n";
   for(auto v : sl1){
      cout << v << ", ";
   }
}
