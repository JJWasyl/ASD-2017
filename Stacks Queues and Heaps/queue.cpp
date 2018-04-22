#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Maksymalny rozmiar kolejki
#define MAX 300

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


int main(int argc, char* argv[]){

   //Deklaracja zmiennych i obiektow
   string cin_input;
   stringstream stream;
   int count;
   char x;
   int n;
   int z;
   cin >> count;
   Queue kolejka;

   cout << endl << "Ilosc instrukcji = " << count << "\n\n";

   //Wyrzucenie niepotrzebnych znakow
   getline(cin, cin_input); 
   stream << cin_input; 
   stream.clear(); 
   
 
   //Ladowanie strumienia i interpretacja znakow
   while(getline(cin, cin_input)){  
      try{
      stream << cin_input;
      stream >> x;
      stream >> n;
      stream.clear();
      if(cin_input.empty()) break;

      if(x == 'A'){
         kolejka.enqueue(n);
         cout << x << " " << n << "   Dodane na koniec kolejki\n";


      } else if(x == 'D'){
         cout << x << "    ";
         z = kolejka.dequeue();
         cout << "    Usunieto = " << z << "\n";

      } else if(x == 'S'){
         cout << x << "        Rozmiar = " << kolejka.size() << "\n";
      } else {break;}    
      }
      catch (exception& e){
         cout << e.what() << "\n";
      }
   }

   cout << "\n\n\nKolejka:\nFront\n";
   for(int i = kolejka.front; i <= kolejka.back; i++){ 
      if (i == -1) { cout << "Empty" << endl; break;}
      cout << kolejka.tab[i] << "\n"; 
   }
}

