#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <chrono>

class Queue;

#include "queue.h"

using namespace std;

const int max_size = 160000;
const int max_digits = 6;

void radix_sort(vector<int> &vec){
   Queue kosze[10];
   int current_digit = 0;

   while(current_digit < max_digits){
      for(int i = 0; i < vec.size(); i++){
         int dzielnik = pow(10, current_digit);
         int liczba = vec[i];
         //trik na wyciagniecie cyfry, trzeba rzutowac z double (a moze float) na int
         int digitval = static_cast<int>((liczba/dzielnik)%10);
         kosze[digitval].enqueue(liczba);
      }
      //Zerujemy kosz do wektora
      int i = 0;
      for(int j = 0; j < 10; j++){
         while(!kosze[j].isEmpty()){
            vec[i] = kosze[j].dequeue();
            i++;
         }
      }
      current_digit++;
   }
}

//Funkcja ladujaca do std::cout kolejne wartosci posortowanego wczesniej wektora
void printVector(vector<int> &vec){
   for(size_t i = 0; i < vec.size(); i++){
      cout << vec[i] << "\n";
   }
}

int main(int argc, char *argv[]){

   int x;
   vector<int> v;
   
   //While zapycha wektor danymi z wejscia
   while(cin >> x)
   v.push_back(x);

   //Timer
   auto start = std::chrono::high_resolution_clock::now();

   radix_sort(v);

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = end - start;
   std::cerr << "Elapsed time[s] = " << elapsed.count() << endl;
   printVector(v);
}
