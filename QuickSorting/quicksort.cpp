#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int swap_count = 0;
int compares = 0;

//Funkcja pomocnicza swap
void swap(int *a, int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
   swap_count++;
}

//Funkcja odpowiedzialna za podzial wektora przy pivocie
int partycja(vector<int> &vec, int l, int n){

   int x = vec[n];
   int i = (l -1);

   for(int j = l; j <= n - 1; j++){
      if(vec[j] <= x){
         i++;
         swap(&vec[i], &vec[j]);
         compares++;
      }
   }
   swap(&vec[i + 1], &vec[n]);
   return (i + 1);
}


//Iteracyjna wersja quicksort z wykorzystaniem elementu pivot do zamiany
void quick_sort(vector<int> &vec){

   int n = vec.size() - 1;
   int l = 0;

   //Szybki stos przechowujacy indeksy do porownan
   int stos[n+1];
   int top = -1;
   stos[++top] = l;
   stos[++top] = n;

   //Wyjmujemy ze stosu dopoki sie nie oprozni
   while(top >= 0){
      
      n = stos[top--];
      l = stos[top--];

      //Umieszczamy pivot w poprawnym miejscu w posortowanym wektorze
      int pivot = partycja(vec, l, n);

      if(pivot - 1 > l){
         stos[++top] = l;
         stos[++top] = pivot - 1;
      }
      if(pivot + 1 < n){
         stos[++top] = pivot + 1;
         stos[++top] = n;
      }
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

   //Wykonujemy sortowanie i drukowanie
   quick_sort(v);

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = end - start;
   std::cerr << "Elapsed time[s] = " << elapsed.count() << endl;

   printVector(v);
   cerr << "Porownania = " << compares << ", Zamiany = " << swap_count << endl;
   return 0;
}
