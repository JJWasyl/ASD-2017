#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Maksymalny rozmiar kolejki
#define MAX 100


class Stack {

public: 

   int tab[MAX];
   int top;

   Stack(){
      top = -1;
   }

   bool isEmpty(){
      return (top == -1);
   }

   bool isFull(){
      return (top == MAX);
   }

   void push(int x){

      if(isFull()){
         throw out_of_range("Stack Overflow");
      }

      top++;
      tab[top] = x;
   }

   int pop(){

      int temp = tab[top];
      if(isEmpty()){
         throw out_of_range("Stack Underflow");
      }

      top--;
      return temp;
   }

   int& peak(){

      if(isEmpty()){
         throw out_of_range("Stack Empty");
      }

      return tab[top];
   }

   int size(){
      return (top+1); 
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
   Stack stos;

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
         stos.push(n);
         cout << x << " " << n << "   Dodane na stos\n";


      } else if(x == 'D'){
         cout << x << "    ";
         z = stos.pop();
         cout << "    Usunieto = " << z << "\n";

      } else if(x == 'S'){
         cout << x << "        Rozmiar = " << stos.size() << "\n";
      } else {break;}    
      }
      catch (exception& e){
         cout << e.what() << "\n";
      }
   }

   cout << "\n\n\nStos:\nTOP\n";
   for(int i = stos.top; i >= 0; i--){ cout << stos.tab[i] << "\n"; }

}
