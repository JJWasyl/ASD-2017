#include <iostream>
#include <string>
#include <random>

using namespace std;

int main(int argc, char *argv[]){

   if(argc != 2){
      cerr << "Podaj dlugosc ciagu" << endl;
      return 0;
   }

   srand(time(NULL));
   int n = stoi(argv[1]);

   for(int i = 1; i < n; i++){
      cout << i << endl;
   }

   cout << rand() % (n+1) << endl;
}
