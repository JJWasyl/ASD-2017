#include <iostream>
#include <vector>
#include <chrono>

using namespace std;


//Algorytm sortowanie przez scalanie
//Wersja rekurencyjna
int sort(vector<int>& vec, int left, int mid, int right){

   int i, j, inversions;
   vector<int> L, R;

   for (int i = left; i <= mid; ++i) L.push_back(vec[i]);
   for (int j = mid + 1; j <= right; ++j) R.push_back(vec[j]);

   L.push_back(numeric_limits<int>::max());
   R.push_back(numeric_limits<int>::max());

   i = 0; j = 0; inversions = 0;

   for(int k = left; k <= right; ++k){
      if(L[i] <= R[j]){
         vec[k] = L[i];
         i++;
      } else {
         vec[k] = R[j];
         j++;
         inversions += mid - left + 1 - i;
      }
   }
   return inversions;
}

//Rekurencyjna funkcja dzielenia wektora
int merge_sort(vector<int>& vec, int left, int right){
   
   int mid, inversions = 0;
   if(right > left){

      mid = (right + left)/2;
 
      inversions = merge_sort(vec, left, mid);
      inversions += merge_sort(vec, mid+1, right);
      inversions += sort(vec, left, mid, right);
   }
   return inversions;
}


int getInvCount(vector<int> &arr, int n){
   int inv_count = 0;
   for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
         if (arr[i] > arr[j])
            inv_count++;
 
   return inv_count;
}
 

//Funkcja ladujaca do std::cout kolejne wartosci posortowanego wczesniej wektora
void printVector(vector<int> vec){
   for(size_t i = 0; i < vec.size(); i++){
      cout << vec[i] << "\n";
   }
}

int main(int argc, char *argv[]){

   int x, inversions;
   vector<int> v;  

   while(cin >> x)
      v.push_back(x);

   cerr << "Permutacje Simple = " << getInvCount(v, v.size()) << endl;
   inversions = merge_sort(v, 0, v.size()-1);
   cerr << "Permutacje Merge Sort = " << inversions << endl;
   return 0;
}
