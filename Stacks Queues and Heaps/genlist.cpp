#include <iostream>
#include <cstdlib>

using namespace std;

const int maximum = 100000;

int main(int argc, char *argv[]){

   int in;

   if(argc != 2){
      cerr << "Prosze podac dlugosc listy\n";
      return 1;
   }
   srand(time(nullptr));
   in = atoi(argv[1]);
   if(in <= 0) {
      cerr << "Dlugosc nie moze byc rowna 0\n";
      return 1;
   }
   
   cout << in << "\n";

   for(int i = 0; i < in; i++){
      cout << rand() % maximum << "\n";
   }
}
