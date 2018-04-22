#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;


int sepLine(int tab[], int n){

   int length = 0;

   if(n < 2) return 0;

   if(n % 2 == 0){
      for(int i = n-1; i > 0; i--){
         length += tab[i] - tab[i-1]; i--;
      }
   } else {
      if((tab[0] + tab[1]) <= (tab[n-2] + tab[n-1])){
         for(int i = n-1; i > 1; i--){
            length += tab[i] - tab[i-1]; i--;
         }
      } else {
         for(int i = 0; i < n-1; i++){
            length += -tab[i] + tab[i+1]; i--;
         }
      }
   }
   return length;
}

int main(int argc, char *argv[]){

   if(argc != 2) {
      std::cerr << "Podaj ilosc punktow\n";
      return 1;
   }

   int n = stoi(argv[1]);

   srand(time(nullptr));
   int tab[n];

   if(n <= 0){
      std::cerr << "Liczba musi byc > 0\n";
      return 1;
   }

   srand(time(nullptr));

   cout << "\nWspolrzedne na osi X:\n";
   tab[0] = rand() % 10; cout << tab[0] << ", ";
   for(int i = 1; i < n; i++){
      tab[i] = tab[i-1] + rand() % n;
      cout << tab[i] << ", ";
   }
   cout << "\nLaczna dlugosc odcinkow miedzy s. punkatmi = " << sepLine(tab, n) << "\n";

}
