#include <iostream>
#include <string>
#include <sstream>
#include <array>

using namespace std;

class CursorList{

public:

   static const int rozmiar = 100;
   int current_size;
   int head;
   int free;

   struct node{
      int mark;
      int next;
   };
   
   //Inicjacja tablicy struktur do 0 i wyznaczenie "glowy"
   node tab[rozmiar] = {{0},{0}};

   //Konstruktor ustawiajacy glowe i rozmiar na 0
   //Rowniez zwazajac na "sztywny" rozmiar listy, mozna zainicjowac wszystkie indeksy next
   CursorList(){
      head = 0;
      current_size = 0;
      free = 0;
      for(int sizer = 1; sizer < rozmiar; sizer++){
         tab[sizer-1].next = sizer;
         if(sizer == rozmiar) break;
      }
   };


   void push_front(int x){
      if(head == 0 && free == 0){
         tab[0].next = 1;
         tab[0].mark = x;
         free = 1;
      } else {
         int temp = free;
         free = tab[free].next;
         tab[temp].next = free; 
         tab[temp].mark = x; 
         head = temp; 
      }
      current_size++;
   }

   int pop_front(){
      if(head == 0 && free == 0){
         return -1;
      }
      int wartosc = tab[head].mark;
      int temp = head;
      current_size--;
      if(current_size == 0){
         head = 0; free = 0; return wartosc;
      }
      int i = 0;
      while(1){
         if(tab[i].next == head){head = i; break;}
         i++; 
      }
      free = temp;
      return wartosc;
   }

   void push_back(int x){
      if(head == 0 && free == 0){
         tab[0].next = 1;
         tab[0].mark = x;
         free = 1;
      } else {
         tab[free].mark = x;
         free = tab[free].next;
         tab[head].next = free;
         tab[free].mark = 0;
      }
      current_size++;
   }

   int pop_back(){
      if(head == 0 && free == 0){
         return -1;
      }
      int wart;
      int temp = head - current_size;
      wart = tab[temp].mark;
      tab[temp].mark = 0;
      tab[free].next = temp;
      free = temp;
      tab[head].next = free;
      current_size--;
      if(current_size == 0){head = 0; free = 0; return wart;}
      return wart;
   }

   int* find(int x){
      int *f;
      for(int j = 0; j < rozmiar; j++){
         if(tab[j].mark == x){
            f = &tab[j].mark;
             return f;
         } else {
            return nullptr;
         }
      }
   }

   int size(){
   return current_size;
   }
};


int main(int argc, char *argv[]){

   //Deklaracja zmiennych i obiektow
   string cin_input;
   stringstream stream;
   int count;
   char x;
   int n;
   int z;
   cin >> count;
   CursorList lista;

   cout << endl << "Ilosc instrukcji = " << count << "\n\n";

   //Wyrzucenie niepotrzebnych znakow
   getline(cin, cin_input); 
   stream << cin_input; 
   stream.clear(); 

   //Nadanie indeksow next

    
   //Ladowanie strumienia i interpretacja znakow
   while(getline(cin, cin_input)){  
      stream << cin_input;
      stream >> x;
      stream >> n;
      stream.clear();
      if(cin_input.empty()) break;

      if(x == 'A'){
         lista.push_front(n);
         cout << x << " " << n << "   Dodane do listy\n";


      } else if(x == 'F'){
         cout << x << " " << n;
           if(lista.find(n) != nullptr){
              cout << "   TRUE\n";
           } else {
              cout << "   FALSE\n";
           }


      } else if(x == 'D'){
         cout << x << "    ";
         z = lista.pop_front();
         if (z == -1){ 
            cout << "    EMPTY\n";
         } else {
            cout << "    Usunieto = " << z << "\n";
         }


      } else if(x == 'S'){
         cout << x << "        Rozmiar = " << lista.size() << "\n";
      } else {break;}
      n = 0;     
   }

   cout << "\n\n\nLista:\nBack\n\n";
   for(int i = 0; i < lista.size(); i++){ cout << lista.tab[i].mark << "\n"; }
   cout << "\nFront\n\n";
}
