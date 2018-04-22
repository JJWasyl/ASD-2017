
#include <iostream>

using namespace std;

class SortedArrayList{

public:

   static const int staly_rozmiar = 50000;
   int tab[staly_rozmiar];
   int free;
   int maxval;

   SortedArrayList(){
      free = 0;
      maxval = 0;
   }

   void push(int x){
      int i = free - 1;
      if(free == 0){
         tab[free] = x;
         maxval = x;
         free++;
      } else if(x >= maxval){
         tab[free] = x;
         maxval = x;
         free++;
      } else {
         while(i >= 0 && tab[i] > x){
            tab[i+1] = tab[i];
            if(i == 0){
               tab[i] = x;
               free++;
               break;
            }
            i--;
            if(tab[i] <= x){
               tab[i+1] = x;
               free++;
               break;
            }
         }
      }
   }


   int pop(){
      int min = tab[0];
      for(int j = 0; j < free; j++){
         tab[j] = tab[j+1];
      }
      free--;
      return min;
   }


   int erase(int i){
      int temp = tab[i];
      if(i >= free){
         return 0;
      }
      for(int j = i; j < free; j++){
         tab[j] = tab[j+1];
      }
      free--;
      return temp;
   }


   void remove(int x){
      for(int i = 0; i < free; i++){
         if(tab[i] == x){
            for(int j = i; j < free; j++){
               tab[j] = tab[j+1];
            }
            free--;
         }
      }
   }


   int find(int x){
      int f;
      for(int j = 0; j < free; j++){
         if(tab[j] == x){
            f = j;
             return f;
         } else {
            return -1;
         }
      }
   }


   int size(){
      int j = 0;
      while(j != free){
         j++;
      }
   return j;
   }


   void unique(){
      for(int j = 1; j < free; j++){
         if(tab[j] == tab[j+1] || tab[j] == tab[j-1]){
            for(int i = j; i < free; i++){
               tab[i] = tab[i+1];
            }
         free--;
         }
      }
   }


   void print(){
      for(int j = 0; j < free; j++){
         cout << tab[j] << ", ";
      }
      cout << "\n";
   }

//Ponizsze wywalic jesli nowa wersja dziala.
/*
   static SortedArrayList merge(const SortedArrayList& a, const SortedArrayList& b){
      int tab[staly_rozmiar];
      for(int i = 0; i < a.free; i++){
         tab[i] = a.tab[i];
      }
      int it;
      int val;
      int tempsize = 1;

      //Petla insertion sort
      for(int z = b.free-1; z >= 0; z--){  
         it = a.free + tempsize; 
         val = b.tab[z]; 
         while(it > 0 && val < tab[it-1]){
            tab[it] = tab[it-1];  
            it--;
         }
         tab[it] = val;
         tempsize++; 
      }
      return SortedArrayList;    
   }

*/

   static SortedArrayList merge(const SortedArrayList& a, const SortedArrayList& b){
      SortedArrayList temp;
      temp = a;
      for(int i = 0; i < b.free; i++){
         temp.push(b.tab[i]);
      }

      return temp;    
   }

   void killMe(){
      delete this;
   }
};

