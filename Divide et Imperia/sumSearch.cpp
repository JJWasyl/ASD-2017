#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <unordered_set>

using namespace std;

//Rozwiazanie stosujace hashtable O(n)
void pairs(int tab1[], int tab2[], int n, int x){

   //Kopiujemy pierwsza tablice do hashtable
   unordered_set<int> s;
   for(int i = 0; i < n; i++){
      s.insert(tab1[i]);
   }

   cout << "\nPary dajace sume x:\n";
   for(int j = 0; j < n; j++){
      if(s.find(x - tab2[j]) != s.end()){
         cout << x-tab2[j] << ", " << tab2[j] << "; ";
      }
   }
}


int main(int argc, char *argv[]){

   if(argc != 3) {
      std::cerr << "Podaj dlugosc zbiorow i liczbe x\n";
      return 1;
   }

   int n = stoi(argv[1]);
   int x = stoi(argv[2]);

   srand(time(nullptr));
   int tab1[n], tab2[n];
   int val;

   cout << "\nZbior1:\n";
   tab1[0] = rand() % 10; cout << tab1[0] << ", ";
   for(int i = 1; i < n; i++){
      tab1[i] = tab1[i-1] + rand() % n;
      cout << tab1[i] << ", ";
   }

   cout << "\nZbior2:\n";
   tab2[0] = rand() % 10; cout << tab2[0] << ", ";
   for(int i = 1; i < n; i++){
      tab2[i] = tab2[i-1] + rand() % n;
      cout << tab2[i] << ", ";
   }

   pairs(tab1, tab2, n, x);
   cout << "\n";


return 0;
}
