#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void insertionSort(vector<int>& vec){
   int x;
   int y;

   //Timer
   auto start = std::chrono::high_resolution_clock::now();

   //Dwie pierwsze pozycje sa "posortowane" wiec zaczynam od i = 2
   for(size_t i = 2; i < vec.size(); i++){  
      y = i; //Zrzucam znacznik na pozycji i
      x = vec[i]; //Zapamietuje liczbe do przeniesienia
      while(y > 0 && x < vec[y-1]){
         vec[y] = vec[y-1];  //Spycham element wiekszy od x jak najdalej w prawo (petla)
         y--;
      }
      vec[y] = x; //Wstawiamy element w pozycji y
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
   cout << endl;
}


int main(int argc, char *argv[]){

   int x;
   vector<int> v;
   
   //While zapycha wektor danymi z wejscia (jak w stosie)
   while(cin >> x)
   v.push_back(x);

   //Wykonujemy sortowanie i drukowanie
   insertionSort(v);
   printVector(v);

   return 0;
}

