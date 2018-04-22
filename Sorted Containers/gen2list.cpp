#include <iostream>
#include <cstdlib>

using namespace std;

const int maximum = 10000;

int main(int argc, char *argv[]){

   int in, y, x;

   if(argc != 2){
      cerr << "Prosze podac laczna dlugosc obu list\n";
      return 1;
   }
   srand(time(nullptr));
   in = atoi(argv[1]);
   if(in <= 0) {
      cerr << "Dlugosc nie moze byc rowna 0\n";
      return 1;
   }
   

   //Generowanie dlugosci obu list
   x = rand() % in;
   y = in - x;
   cout << x << "\n";

   for(int i = 0; i < x; i++){
      cout << rand() % maximum << " ";
   }

   cout << "\n" << y << "\n";
   for(int j = 0; j < y; j++){
      cout << rand() % maximum << " ";
   }
}
