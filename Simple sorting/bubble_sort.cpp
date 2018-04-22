#include <iostream>
#include <vector>
#include <chrono>

using namespace std;


//Funkcja sortowania babelkowego pobierajaca dane z wektora
//Wektor podany przez referencje gdyz chcemy sortowac oryginal a nie kopie
void bubbleSort(vector<int>& vec){

   //Flaga swap odchacza sie zawsze gdy dokonano zmiany
   //Gdy dokonano ostatniej zmiany, warunek if nie spelnia sie i flaga blokuje petle while 
   bool swap = true;

   //Timer
   auto start = std::chrono::high_resolution_clock::now();
 
   while(swap){
      swap = false;
      for(size_t i = 0; i < vec.size()-1; i++){
         if(vec[i] > vec[i+1]){
            vec[i] += vec[i+1];
            vec[i+1] = vec[i] - vec[i+1];
            vec[i] -= vec[i+1];
            swap = true;
         }
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
   cout << endl;
}


int main(int argc, char *argv[]){

   int x;
   vector<int> v;
   
   //While zapycha wektor danymi z wejscia (jak w stosie)
   while(cin >> x)
   v.push_back(x);

   //Wykonujemy sortowanie i drukowanie
   bubbleSort(v);
   printVector(v);

   return 0;
}
