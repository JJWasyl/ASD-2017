#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

//Wyszukiwanie maksymalnej sumy algorytm Kadane O(n)
int maxSeg(int tab[], int n){

   int current_max, k = 0, total_max = 0, lower;

   while(k != n){
      current_max = 0;
      for(int i = k; i < n; i++){
         lower = tab[i];
         current_max += tab[i];
         if(tab[i + 1] < lower){break;}
      }
      if(total_max < current_max){
         total_max = current_max;
      }
      k++;
   }
   return total_max;
}

int main(int argc, char *argv[]){

   if(argc != 2) {
      std::cerr << "Podaj dlugosc tablicy\n";
      return 1;
   }

   int n = stoi(argv[1]);

   srand(time(nullptr));
   int tab[n];

   cout << "\nZbior:\n";
   tab[0] = rand() % n + 1; cout << tab[0] << ", ";
   for(int i = 1; i < n; i++){
      tab[i] = rand() % n + 1;
      cout << tab[i] << ", ";
   }

   cout << "\nnajwieksza suma = " << maxSeg(tab, n) << "\n";

}
