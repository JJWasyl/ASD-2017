#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Maksymalny rozmiar kolejki
#define MAX 160000

class Queue {

public:

   int tab[MAX];
   int front;
   int back;

   Queue(){
      front = -1;
      back = -1;
   }

   //Check na przepelnienie
   bool isFull(){
      return (back == MAX);
   }

   bool isEmpty(){
      return (front == -1 || back == -1);
   }

   void enqueue(int x){

      //Sprawdzamy czy kolejka pelna
      if(isFull()){
         throw out_of_range("FULL");
      }

      //Sprawdzamy czy kolejka jest pusta
      if(front == -1){
         front = 0;
         back = 0;

      } else { 
         back++;
      }

      tab[back] = x;
   }


   int dequeue(){
      //Zlozonosc O(1), czyli bez przesuwania kolejki w tablicy
      int temp = tab[front];

      if(isEmpty()){
         throw out_of_range("EMPTY");
      }

      //Tylko jeden element
      if(front == back){
         front = -1;
         back = -1;
      } else {
         front++;
      }
      return temp;
   }

   int& peek(){

      if(front == -1){
         throw out_of_range("EMPTY");
      }

      return tab[front];
   }

   int size(){
      if(back == front) {return 0;}
      return (back+1 - front);
   }

};
