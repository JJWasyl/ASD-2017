#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;


void countingSort(vector<int> &vec){
   
   int max = *max_element(vec.begin(), vec.end());

   //Deklaracja wektorow pomocniczych o rozmiarze vec i inicjalizacja do 0
   vector<int> temp(max);

   //Timer
   auto start = std::chrono::high_resolution_clock::now();

   for(auto& i:vec){
      temp[i]++;
   }  

   vec.clear();

   for(int j = 0; j < temp.size(); j++){
      for(int i = 0; i < temp[j]; i++){
         vec.push_back(j);
      }
   }

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = end - start;
   std::cerr << "Elapsed time[s] = " << elapsed.count() << endl;

}

//Funkcja ladujaca do std::cout kolejne wartosci posortowanego wczesniej wektora
void printVector(vector<int> vec){
   for(size_t i = 0; i < vec.size(); i++){
      cout << vec[i] << "\n";
   }
}


int main(int argc, char *argv[]){

   int x;
   vector<int> v;
   
   //While zapycha wektor danymi z wejscia (jak w stosie)
   while(cin >> x)
   v.push_back(x);

   //Wykonujemy sortowanie i drukowanie
   countingSort(v);
   printVector(v);

   return 0;
}

