#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

int main(int argc, char *argv[]){

   //Deklaracja zmiennych i obiektow
   string cin_input;
   stringstream stream;
   int count;
   char x;
   int n;
   int z;
   bool flag;
   cin >> count;
   list<int> lista;

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
         cout << x << " " << n << "   Dodane do tablicy\n";


      } else if(x == 'F'){
         flag = false;
         cout << x << " " << n;
         for(auto v: lista){
            if(v == n){flag = true; break;}
         }
         if(flag == true){
            cout << "   TRUE\n";
         } else {cout << "   FALSE\n";}

      } else if(x == 'D'){
         cout << x << "    ";
         if(lista.empty() == false){
            lista.pop_front();
            cout << "    Usunieto element z przodu" << "\n";
         } else {
            cout << "    EMPTY\n";
         }


      } else if(x == 'S'){
         cout << x << "        Rozmiar = " << lista.size() << "\n";
      } else {break;}
      n = 0;     
   }

   cout << "\n\n\nLista:\nHEAD\n";
   for(auto v: lista)
      cout << v << "\n";
   cout << "TAIL\n\n";
}
