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
class Heap;

#include "sortedLinkedList.h"
#include "sortedArrayList.h"
#include "heap.h"

using namespace std;

int main(int argc, char* argv[]){

   //Deklaracja zmiennych i obiektow
   string cin_input;
   stringstream stream1, stream2;
   int count, z, n, erased1, erased2;
   char x;
   SortedArrayList al1;
   SortedLinkedList ll1;
   Heap h1;
   list<int> sl1;
   vector<int> vec(100000);
   srand(time(nullptr));

   //Wczytanie dlugosci l1
   getline(cin, cin_input);
   stream1 << cin_input;
   stream1 >> count;
   stream1.clear();

   /*
   //Timer1
   auto start = std::chrono::high_resolution_clock::now();

   //Wczytanie al1
   while(getline(cin, cin_input)){
      stream1 << cin_input;
      stream1 >> z;
      al1.push(z);
      stream1.clear();
   }
   stream1.clear();


   for(int j = 0; j < count; j++){
      z = count - j;
      n = rand() % z; 
      erased1 = al1.erase(n);
   }

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = end - start;
   std::cerr << "Array List: Elapsed time[s] = " << elapsed.count() << endl;
   */

   //Timer2
   auto start = std::chrono::high_resolution_clock::now();

   //Wczytanie al1
   while(getline(cin, cin_input)){

      stream1 << cin_input;
      stream1 >> z;
      ll1.push(z);
      stream1.clear();
   }

   for(int j = 0; j < count; j++){
      z = count - j;
      n = rand() % z; 
      erased1 = ll1.erase(n);
   }

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = end - start;
   std::cerr << "Linked List: Elapsed time[s] = " << elapsed.count() << endl;


   /*
   //Timer3
   auto start = std::chrono::high_resolution_clock::now();

   //Wczytanie h1
   while(getline(cin, cin_input)){
      stream1 << cin_input;
      stream1 >> z;
      h1.push(z);
      stream1.clear();
   }

   cerr << h1.check() << endl;

   for(int j = 0; j < count; j++){
      int temp = h1.pop();
      cout << temp << endl;
   }

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = end - start;
   std::cerr << "Heap: Elapsed time[s] = " << elapsed.count() << endl;
   */
   cout << "\nProcess complete" << endl;
}
