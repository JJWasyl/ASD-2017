#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

//Przywodca ciagu pewny (Moore's voting algorithm) O(n)
int certLeader(int tab[], int n){
   int leader = tab[0];
   int count = 1;

   for(int j = 1; j < n; j++){
      if(tab[j] == leader){
         count++;
      } else {
         count--;
         if(count == 0){
            leader = tab[j];
            count = 1;
         }
      }
   }
   return leader;
}


//Przywodca ciagu niepewny
int uncertLeader(int tab[], int n){
   int leader = tab[0];
   int count = 1;

   for(int j = 1; j < n; j++){
      if(tab[j] == leader){
         count++;
      } else {
         count--;
         if(count == 0){
            leader = tab[j];
            count = 1;
         }
      }
   }
   
   //teraz sprawdzamy czy lider pojawia sie > n/2 razy
   count = 0;
   for(int i = 0; i < n; i++){
      if(tab[i] == leader){
         count++;
      }
   }
   if(count >= n/2)
      return leader;
   else
      return -1;
}

int main(int argc, char *argv[]){

   if(argc != 2) {
      std::cerr << "Podaj dlugosc zbiorow\n";
      return 1;
   }

   int n = stoi(argv[1]);

   srand(time(nullptr));
   int tab1[n], tab2[n];
   int val;

   val = rand() % n;

   cout << "\nZbior1:\n";
   for(int i = 0; i < n; i++){
      if((rand() % 101) > 50){ 
         tab1[i] = val;
         cout << val << ", ";
      } else {
         tab1[i] = i;
         cout << i << ", ";
      }
   }

   cout << "\nLider = " << certLeader(tab1, n) << "\n";

   cout << "\nZbior2:\n";
   for(int i = 0; i < n; i++){
      if((rand() % 101) > 75){ 
         tab2[i] = val;
         cout << val << ", ";
      } else {
         tab2[i] = i;
         cout << i << ", ";
      }
   }
   int result = uncertLeader(tab2, n);
   if(result == -1){
      cout << "\nBrak Lidera\n";
   } else {
      cout << "\nLider = " << result << "\n";
   }


return 0;
}
