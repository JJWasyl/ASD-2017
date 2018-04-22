#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){

   if(argc != 2) {
      std::cerr << "Podaj ilosc punktow do wygenerowania\n";
      return 1;
   }

   auto n = std::stoi(argv[1]);
   double x, y;

   if(n <= 0){
      std::cerr << "Liczba musi byc > 0\n";
      return 1;
   }

   srand(time(nullptr));

   for(int i = 0; i < n; i++){
      x = (double) (rand() % 10001)/10000;
      y = (double) (rand() % 10001)/10000;
      cout << x << " " << y << endl;
   }

return 0;
}
