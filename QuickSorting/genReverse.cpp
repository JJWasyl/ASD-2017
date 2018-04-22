#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

   if(argc != 2){
      cerr << "Podaj dlugosc ciagu" << endl;
      return 0;
   }

   int n = stoi(argv[1]);

   for(int i = n; i >= 1; i--){
      cout << i << endl;
   }
}
