#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>

class SortedLinkedList;
class SortedArrayList;

#include "sortedLinkedList.h"
#include "sortedArrayList.h"

using namespace std;

int main(int argc, char* argv[]){

   //Deklaracja zmiennych i obiektow
   string cin_input;
   stringstream stream1, stream2;
   int l1_count, z, n, erased1, erased2;
   char x;
   SortedArrayList al1;
   SortedLinkedList ll1;
   list<int> sl1;
   vector<int> vec(50000);
   srand(time(nullptr));

   //Wczytanie dlugosci l1
   getline(cin, cin_input);
   stream1 << cin_input;
   stream1 >> l1_count;
   stream1.clear();


   //Timer
   auto start = std::chrono::high_resolution_clock::now();

   //Wczytanie l1
   getline(cin, cin_input);
   for(int i = 0; i < l1_count; i++){
      stream1 << cin_input;
      stream1 >> z;
      //al1.push(z);
      ll1.push(z);
   }
   stream1.clear();

   cout << "\nLista Array1\n";
   //al1.print();
   cout << "\nLista Linked1:\n";
   ll1.print();
   cout << "\n";

   for(int j = 0; j < l1_count; j++){
      z = l1_count - j;
      n = rand() % z; 
      //erased1 = al1.erase(n);
      erased2 = ll1.erase(n);
   }

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = end - start;
   std::cerr << "Elapsed time[s] = " << elapsed.count() << endl;

   cout << "\nLista Array1 i Linked1 czysta:\n";
   //al1.print();
   cout << "\n----------------------\n";
   ll1.print();
}
