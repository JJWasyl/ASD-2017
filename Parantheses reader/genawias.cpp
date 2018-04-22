#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int maximum = 1000;

int main(int argc, char *argv[]){

   int in, c;
   bool squaredflag, curvedflag, sharpflag;

   if(argc != 2){
      cerr << "Prosze podac dlugosc wyrazenia\n";
      return 1;
   }
   srand(time(nullptr));
   in = atoi(argv[1]);
   if(in <= 0) {
      cerr << "Dlugosc nie moze byc rowna 0\n";
      return 1;
   }

   squaredflag = 0;
   curvedflag = 0;
   sharpflag = 0;

//Wprowadzamy "uczciwy system" z 25% szans na pewne trafienie poprawnej sekwencji
if((rand()%4) == 0){

      for(int i = 0; i < in; i++){
         c = rand()%9;
         if(c == 0){cout << "[]";}
         if(c == 1){cout << "()";}
         if(c == 2){cout << "{}";}
         if(c == 3){cout << "["; squaredflag = 1;}
         if(c == 4){cout << "("; curvedflag = 1;}
         if(c == 5){cout << "{"; sharpflag = 1;}
         if(c == 6){
            if(squaredflag == 1){
               cout << "]"; 
               squaredflag = 0;
            } else {
               cout << "[]";
            }
         }
         if(c == 7){
            if(curvedflag == 1){
               cout << ")"; 
               curvedflag = 0;
            } else {
               cout << "()";
            }
         }
         if(c == 8){
            if(sharpflag == 1){
               cout << "}"; 
               sharpflag = 0;
            } else {
               cout << "{}";
            }
         }
      }

    if(squaredflag == 1){
       cout << "]"; 
       squaredflag = 0;
    }
    if(curvedflag == 1){
       cout << ")"; 
       curvedflag = 0;
    }
    if(sharpflag == 1){
       cout << "}"; 
       sharpflag = 0;
    }

} else {

      for(int i = 0; i < in; i++){
         c = rand()%8;
         if(c == 0){cout << "[]";}
         if(c == 1){cout << "()";}
         if(c == 2){cout << "{}";}
         if(c == 3){cout << "["; squaredflag = 1;}
         if(c == 4){cout << "("; curvedflag = 1;}
         if(c == 5){cout << "{"; sharpflag = 1;}
         if(c == 6){
            if(squaredflag == 1){
               cout << "]"; 
               squaredflag = 0;
            } else {
               cout << "[]";
            }
         }
         if(c == 7){
            if(curvedflag == 1){
               cout << ")"; 
               curvedflag = 0;
            } else {
               cout << "()";
            }
         }
         if(c == 8){
            if(sharpflag == 1){
               cout << "}"; 
               sharpflag = 0;
            } else {
               cout << "{}";
            }
         }
      }
}
}
