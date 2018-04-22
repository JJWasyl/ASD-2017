#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void selectionSort(vector<int>& vec){
   
   int min;

   //Timer
   auto start = std::chrono::high_resolution_clock::now();

   //Algorytm wylapuje wartosc minimalna i przeszukuje wektor w poszukiwaniu mniejszych wartosci   
   for(int j = 0; j < vec.size() - 1; j++){
      min = j;
      for(int i = j + 1; i < vec.size(); i++){
         if(vec.at(min) > vec.at(i)){
            min = i;
         }
      }
      if(min != j)
         swap(vec.at(j), vec.at(min));
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
   selectionSort(v);
   printVector(v);

   return 0;
}

