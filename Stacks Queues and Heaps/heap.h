#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Aby wykluczyc tab[0] z indeksu, maks rozmiar jest wiekszy o 2
#define MAX 100002

class Heap {
   
private:
   void heapify(int i){
      int max = i;
      if(2*i <= rozmiar && heap[2*i] > heap[max]){
         max = 2*i;
      }
      if(2*i + 1 <= rozmiar && heap[2*i + 1] > heap[max]){
         max = 2*i + 1;
      }
      if(max != i){
         int temp = heap[max];
         heap[max] = heap[i];
         heap[i] = temp;
         heapify(max);
      }
   }

   int child;

public:
   
   //Front oznacza tutaj "najmlodsze" child (najnizej, po prawej)
   int heap[MAX];
   int rozmiar;

   Heap(){ 
      rozmiar = 0;
   }

   bool isEmpty(){
      return (rozmiar == 0);
   }

   bool check(){
      for(int i = 1; i <= rozmiar/2; i++){
         if(heap[2*i] > heap[i]){
            return false;
         } else if(heap[2*i + 1] > heap[i]){
            return false;
         }
      }
      return true;
   }

   void build(int a[], int n){
      for(int i = 0; i < sizeof(&a); i++){
         heap[i] = a[i];
         rozmiar = sizeof(&a);
      }
      for(int j = rozmiar-1; j >= 0; j--){
         heapify(j);
      }
   }

   void push(int x){
      if(rozmiar == MAX){
         throw out_of_range("FULL");
      } else {
         rozmiar++;
         child = rozmiar;
         heap[rozmiar] = x;
         while(child > 1 && heap[child] > heap[(child/2)]){
            int temp = heap[child];
            heap[child] = heap[(child/2)];
            heap[(child/2)] = temp;
            child = (child/2);
         }
      }
   }

   //Usuniecie najbardziej prawego child z kopca
   int pop(){
      if(rozmiar == 0){
         throw out_of_range("EMPTY");
      }
      int temp = heap[rozmiar];
      rozmiar--;
      return temp;
   }


   int& top(){
      return heap[1];
   }

   int size(){
      return rozmiar;
   }
};

