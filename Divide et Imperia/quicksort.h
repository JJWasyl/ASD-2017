#include <iostream>

using namespace std;

//Funkcja pomocnicza swap
template<class T>
T swap(T *a, T *b){
   T temp = *a;
   *a = *b;
   *b = temp;
}

//Funkcja odpowiedzialna za podzial wektora przy pivocie
template<class T>
int partycja(T &arr, int l, int n, bool flag){
   int i = (l -1);
   if(flag == true){
      auto x = arr.tab[n].x;
      for(int j = l; j <= n - 1; j++){
         if(arr.tab[j].x <= x){
            i++;
            swap(&arr.tab[i], &arr.tab[j]);
         }
      }
   } else {
      auto x = arr.tab[n].y;
      for(int j = l; j <= n - 1; j++){
         if(arr.tab[j].y <= x){
            i++;
            swap(&arr.tab[i], &arr.tab[j]);
         }
      }
   }
   swap(&arr.tab[i + 1], &arr.tab[n]);
   return (i + 1);
}


//Iteracyjna wersja quicksort z wykorzystaniem elementu pivot do zamiany
template<class T>
void quick_sort(T &arr, bool flag){

   int n = arr.size() - 1;
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
      auto pivot = partycja(arr, l, n, flag);

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
