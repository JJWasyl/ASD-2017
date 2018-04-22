#include<iostream>
#include<string>
#include<stack>
#include<sstream>

using namespace std;

/*
 * Tworzymy Histogram sasiadujacych jedynek i szukamy w nim maksymalnego pola
 */

#define MAX 100

int N = 5, M = 5;

int maxHistogram(int r[]){

   stack<int> result;

   int top_val;
   int max_area = 0;
   int area = 0;

   //Przejscie po kazdym slupie histogramu (rzedzie macierzy)
   int i = 0;
   while(i < M){
      if(result.empty() || r[result.top()] <= r[i]){
         result.push(i++);
      } else {
         top_val = r[result.top()];
         result.pop();
         area = top_val * i;

         if(!result.empty()){
            area = top_val * (i - result.top() - 1);
         }
         max_area = max(area, max_area);
      }
   }

   while(!result.empty()){
      top_val = r[result.top()];
      result.pop();
      area = top_val * i;
      if(!result.empty()){
         area = top_val * (i - result.top() - 1);
      }
   }
   return max_area;
}

int maxRect(int Matrix[][MAX]){

   int result = maxHistogram(Matrix[0]);

   for(int i = 1; i < N; i++){
      for(int j = 0; j < M; j++){
         //Jak 1 w macierzy to rowniez znaczy ze true
         if(Matrix[i][j]){
            Matrix[i][j] += Matrix[i - 1][j];
         }
      result = max(result, maxHistogram(Matrix[i]));
      }
   }
   return result;
}

//Algorytm bruteForce o zlozonosci O(n^2)
int bruteForce(int Matrix[][MAX]){
   int max = 0;
   for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
         if(Matrix[i][j] == 1){
            int current_size = 1;
            bool flag = true;
            while(current_size + i < N && current_size + j < M && flag){
               for(int k = j; k <= current_size + j; k++){
                  if(Matrix[i + current_size][k] == 0){
                     flag = false;
                     break;
                  }
               }
               for(int k = 0; k <= current_size + i; k++){
                  if(Matrix[k][j + current_size] == 0){
                     flag = false;
                     break;
                  }
               }
               if(flag){
                  current_size++;
               }
            }
            if(max < current_size){
               max = current_size;
            }
         }
      }
   }
   return (max*max);
}



int main(int argc, char *argv[]){

   string cin_input;
   stringstream stream;
   int x;

   cin >> N; cin >> M;

   //Nie szkodzi ze macierz ma sztywny rozmiar
   //Funkcje wykorzystuja globalne zmienne determinujace rzeczywisty rozmiar macierzy
   int Matrix[MAX][MAX];

   for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
         cin >> x;
         Matrix[i][j] = x;
      }
   }

   cout << "\nPole najwiekszego prostokata = " << maxRect(Matrix) << "\n\n";
//   cout << "\nPole najwiekszego prostokata brute = " << bruteForce(Matrix) << "\n\n";

}

