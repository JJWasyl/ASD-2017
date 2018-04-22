#include <iostream>
#include <string>
#include <array>

using namespace std;

template<class B> class ArrayList{

public:

   static const int rozmiar = 10000;
   B tab[rozmiar];
   int koniec;

   ArrayList(){
      koniec = 0;
      tab[rozmiar] = {0};
   }

   void push_front(B x){
      for(int i = rozmiar; i > 0; i--){
         tab[i] = tab[i-1];
      }
      tab[0] = x;
      koniec++;
   }

   B pop_front(){
      B temp = tab[0];
      for(int i = 0; i < sizeof(tab); i++){
         tab[i] = tab[i+1];
         if(i == koniec - 1) {koniec--; break;}
      }
      return temp;
   }

   void push_back(B x){
      tab[koniec] = x;
      koniec++;
   }

   B pop_back(){
      B temp;
      for(int i = sizeof(tab) - 1; i >= 0; i--){
         if(i == koniec - 1){
            temp = tab[i];
            koniec--;
            break;
         }
      }
      return temp;
   }

   B* find(B x){
      B *f;
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
   return koniec;
   }

   void killMe(){
      delete this;
   }
};
