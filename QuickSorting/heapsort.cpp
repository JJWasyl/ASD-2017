#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int swap_count = 0;
int compares = 0;

class Heap {
   
private:

   void heapify(int i){
      int min = i;
      if((2*i) + 1 <= rozmiar-1 && heap[(2*i) + 1] < heap[min]){
         min = 2*i + 1;
         compares++;
      }
      if(2*i + 2 <= rozmiar-1 && heap[2*i + 2] < heap[min]){
         min = 2*i + 2;
         compares++;
      }
      if(min != i){
         swap(heap[min], heap[i]); 
         swap_count++;
         heapify(min);
      }
   }

   int child;

public:
   
   //Front oznacza tutaj "najmlodsze" child (najnizej, po prawej)
   vector<int> heap;
   int rozmiar;

   Heap(){ 
      rozmiar = 0;
   }

   void build(vector<int> vec){
      for(int i = 0; i < vec.size(); i++){
         heap.push_back(vec[i]);
      }
      rozmiar = vec.size();
      for(int j = rozmiar-1; j >= 0; j--){
         heapify(j);
      }
   }
 
   void printHeap(){
      for(int i = rozmiar; i > 0; i--){
         cout << heap[0] << endl;
         heap[0] = heap.back();
         heap.pop_back(); rozmiar--;
         heapify(0);
      }
   }
};

int main(int argc, char *argv[]){

   int x;
   vector<int> v;
   Heap kopiec;
   
   //While zapycha wektor danymi z wejscia
   while(cin >> x)
   v.push_back(x);

   //Timer
   auto start = std::chrono::high_resolution_clock::now();

   //Wykonujemy sortowanie i drukowanie
   kopiec.build(v);
   kopiec.printHeap();

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed = end - start;
   std::cerr << "Elapsed time[s] = " << elapsed.count() << endl;

   cerr << "Porownania = " << compares << ", Zamiany = " << swap_count << endl;
   return 0;

}

