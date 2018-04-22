#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <chrono>

using namespace std;

//Funkcja ladujaca do std::cout kolejne wartosci posortowanego wczesniej wektora
void printVector(vector<int> vec){
   for(size_t i = 0; i < vec.size(); i++){
      cout << vec[i] << "\n";
   }
   cout << endl;
}


int main(int argc, char *argv[]){

   int x;
   vector<int> v;
   
   //While zapycha wektor danymi z wejscia (jak w stosie)
   while(cin >> x)
   v.push_back(x);

   //Timer
   auto start = std::chrono::high_resolution_clock::now();

   //Funkcja std::sort
   sort(v.begin(), v.end());

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = end - start;
   std::cerr << "Elapsed time[s] = " << elapsed.count() << endl;

   //Wykonujemy drukowanie
   printVector(v);

   return 0;
}

