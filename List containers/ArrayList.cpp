#include <iostream>
#include <string>
#include <sstream>
#include <array>

using namespace std;

class ArrayList{

public:

   static const int rozmiar = 100;
   int tab[rozmiar] = {0};
   int koniec = 0;

   void push_front(int x){
      for(int i = rozmiar; i > 0; i--){
         tab[i] = tab[i-1];
      }
      tab[0] = x;
      koniec++;
   }

   int pop_front(){
      if(koniec == 0){ 
         return -1;
      } else {
         int temp = tab[0];
         for(int i = 0; i < sizeof(tab); i++){
            tab[i] = tab[i+1];
            if(i == koniec) {koniec--; break;}
         }
         return temp;
      }
   }

   void push_back(int x){
      tab[koniec] = x;
      koniec++;
   }

   int pop_back(){
      int temp;
      if(koniec == 0){ 
         return -1;
      } else {
         for(int i = sizeof(tab); i > 0; i--){
            if(i != koniec){
               temp = tab[i];
               tab[i] = 0;
               koniec--;
               break;
            }
         }
      return temp;
      }
   }

   int* find(int x){
      int *f;
      for(int j = 0; j < sizeof(tab); j++){
         if(tab[j] == x){
            f = &tab[j];
             return f;
         } else {
            return nullptr;
         }
      }
   }

   int size(){
      int j = 0;
      while(j != koniec){
         j++;
      }
   return j;
   }

   void killMe(){
      delete this;
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
   ArrayList lista;

   cout << endl << "Ilosc instrukcji = " << count << "\n\n";

   //Wyrzucenie niepotrzebnych znakow
   getline(cin, cin_input); 
   stream << cin_input; 
   stream.clear(); 
    
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
      //n = 0;     
   }

   cout << "\n\n\nLista:\nFRONT\n";
   for(int i = 0; i < lista.koniec; i++){ cout << lista.tab[i] << "\n"; }
   cout << "BACK\n";
}
