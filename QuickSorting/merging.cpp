#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int swap_count = 0;
int compares = 0;

//Algorytm sortowanie przez scalanie
//Wersja rekurencyjna
void sort(vector<int> &left, vector<int> &right, vector<int> &vec){

   //Deklaracje i definicje zmiennych
   int i, j, k;
   int n1 = left.size();
   int n2 = right.size();


   //Algorytm scalania
   i = 0; j = 0; k = 0;
   while(i < n1 && j < n2){
      compares++;
      if(left[i] <= right[j]){
         vec[k] = left[i];
         i++;
         swap_count++;
      } else {
         vec[k] = right[j];
         j++;
         swap_count++;
      }
      k++;
   }
   
   //Wypelnienie vec tym co zostalo z left
   while(i < n1){
      vec[k] = left[i];
      i++; k++;
   }
   //Wypelnienie vec tym co zostalo z right
   while(j < n2){
      vec[k] = right[j];
      j++; k++;
   }
}

//Rekurencyjna funkcja dzielenia wektora
void merge_sort(vector<int> &vec){
   
   if(vec.size() <= 1) return;
   int m = vec.size()/2;

   vector<int> left;
   vector<int> right;

   //Dzielimy na dwa podwektory
   for(int j = 0; j < m; j++){
      left.push_back(vec[j]);
   }
   for(int i = 0; i < vec.size() - m; i++){
      right.push_back(vec[m + i]);
   }

   //Rekurencja w dzieleniu wektorow na pol
   merge_sort(left);
   merge_sort(right);

   sort(left, right, vec);
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
   merge_sort(v);

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = end - start;
   std::cerr << "Elapsed time[s] = " << elapsed.count() << endl;

   printVector(v);
   cerr << "Porownania = " << compares << ", Zamiany = " << swap_count << endl;
   return 0;
}
