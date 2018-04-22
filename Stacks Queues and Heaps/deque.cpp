#include <iostream>

using namespace std;

//Maksymalny rozmiar kolejki
#define MAX 100


class Deque {
private:
   int tab[MAX];
   int front;
   int back;
   int rozmiar;

public:

   //Budujemy bufor na tablicy o sztywnej dlugosci, ale size recznie ja zmniejsza
   Deque(int size){
      front = -1;
      back = 0;
      this->rozmiar = size;
   }

   //Check na przepelnienie
   bool isFull(){
      return ((front == 0 && back == size-1) || front == back+1);
   }

   bool isEmpty(){
      return (front == -1);
   }

   void push_front(int x){

      //Sprawdzamy czy kolejka pelna
      if(isFull()){
         throw out_of_range("FULL");
      }

      //Sprawdzamy czy kolejka jest pusta
      if(front == -1){
         front = 0;
         back = 0;

      } else if(front == 0){ 
         front = rozmiar-1;

      } else {
         front--;
      }
   
      //Wstawianie elementu
      tab[front] = x;
   }

   void push_back(int x){

      //Sprawdzamy czy kolejka pelna
      if(isFull()){
         throw out_of_range("FULL");
      }

      //Sprawdzamy czy kolejka jest pusta
      if(front == -1){
         front = 0;
         back = 0;

      } else if(back == rozmiar-1){ //Ostatnie miejsce w kolejce
         back = 0;

      } else {
         back++;
      }
   
      //Wstawianie elementu
      tab[back] = x;
   }


   int pop_front(){

      int temp = tab[front];
      if(front == -1){
         throw out_of_range("EMPTY");
      }

      //Tylko jeden element
      if(front == back){
         front = -1;
         back = -1;

      } else {
         //Bufor cukliczny wykonal obrot
         if(front == rozmiar - 1){
            front = 0;
         } else {
            front++;
         }
      }
      return temp;
   }

   int pop_back(){

      int temp = tab[back];

      if(front == -1){
         throw out_of_range("EMPTY");
      }

      //Tylko jeden element
      if(front == back){
         front = -1;
         back = -1;
      } else if(back == 0){
         back = rozmiar -1;
      } else {
         back--;
      }
   }

   int& first(){

      if(front == -1){
         throw out_of_range("EMPTY");
      }

      return tab[front];
   }

          
   int& last(){

      if(front == -1){
         throw out_of_range("EMPTY");
      }

      return tab[back];
   }


   int size(){
      return (front - back);
   }

};

int main(int argc, char* argv[]){
return 0;
}
