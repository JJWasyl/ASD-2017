#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]){

   if(argc != 3) {
      std::cerr << "Podaj wymiary macierzy\n";
      return 1;
   }

   auto n = stoi(argv[1]);
   auto m = stoi(argv[1]);
   

   if(n <= 0 || m <= 0){
      std::cerr << "Liczba musi byc > 0\n";
      return 1;
   }

   srand(time(nullptr));

   cout << n << " " << m << endl;

   for(int j = 0; j < n; j++){
      vector<int> vec;
      for(int i = 0; i < m; i++){
         vec.push_back(rand() % 2);
      }

      random_shuffle(vec.begin(), vec.end());

      for(int i = 0; i < m; i++){
         cout << vec[i] << " ";
      }
      cout << endl;
   }

return 0;
}
