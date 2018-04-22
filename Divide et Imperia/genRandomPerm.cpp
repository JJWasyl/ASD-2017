#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){

   if(argc != 2) {
      std::cerr << "Podaj dlugosc zbioru\n";
      return 1;
   }

   auto n = std::stoi(argv[1]);

   if(n <= 0){
      std::cerr << "Liczba musi byc > 0\n";
      return 1;
   }

   vector<int> vec;

   for(int i = 1; i <= n; i++){
      vec.push_back(i);
   }  

   random_shuffle(vec.begin(), vec.end());

   for(int i = 0; i < n; i++){
      cout << vec[i] << endl;
   }

return 0;
}
