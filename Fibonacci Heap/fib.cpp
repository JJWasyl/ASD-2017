#include <iostream>
#include <cmath>
#include <math.h>
#include <limits>
#include <cstdlib>

using namespace std;


/*
 * Deklaracja wezla
 */
struct node{
   int n;
   int degree;
   node* parent;
   node* child;
   node* left;
   node* right;
   char mark;
   char C;
};


/*
 * Deklaracja klasy
 */
class FibHeap{

   public:

      int nH;
      node *H;

      node* build();
      node *createNode(int);
      void push(node*);
      node *minimumNode();
      void consolidate();
      void link(node*, node*);
      void show();
      int size();
      node *Find(node*, int);
      int decreaseKey(int, int);
      void cut(node*, node*);
      void cascadeCut(node*);
      void removeKey(int);
      void removeMin(); //a.k.a. pop()
      int top();
      bool empty();
      FibHeap(){
         H = build();
         nH = 0;
      }
      
};


/*
 * Konstruktor
 */
node* FibHeap::build(){
   node* np;
   np = NULL;
   return np;
}


/*
 * Tworzenie wezla
 */
node* FibHeap::createNode(int val){
   node* x = new node;
   x->n = val;
   return x;
}


/*
 * Operacja push
 */
void FibHeap::push(node* x){
   x->degree = 0;
   x->parent = NULL;
   x->child = NULL;
   x->left = x;
   x->right = x;
   x->mark = 'F';
   x->C = 'N';

   if(H != NULL){
      (H->left)->right = x;
      x->right = H;
      x->left = H->left;
      H->left = x;
      if(x->n < H->n){
         H = x;
      }
   } else {
      H = x;
   }

   nH++;
}


/*
 * Operacja size
 */
int FibHeap::size(){
   return nH;
}


/*
 * Operacja Link wiazaca wezly (pomocnicza)
 */
void FibHeap::link(node* y, node* z){

      (y->left)->right = y->right;
      (y->right)->left = y->left;

      if(z->right == z){
         H = z;
      }

      y->left = y;
      y->right = y;
      y->parent = z;

      if(z->child == NULL){
         z->child = y;
      }

      y->right = z->child;
      y->left = (z->child)->left;
      ((z->child)->left)->right = y;
      (z->child)->left = y;

      if(y->n < (z->child)->n){
         z->child = y;
      }

      z->degree++;
}


/*
 * Operacja consolidate wyrownoje drzewa po zmianie struktury (pomocnicza)
 * Kroki w komentarzach odnosza sie do krakow algorytmu (szczegoly w README)
 */
void FibHeap::consolidate(){

   node* w, * next, * x, * y, * temp;
   node** A, ** rootList;

   int d, rootSize;
   int max_degree = static_cast<int>(floor(log(static_cast<double>(nH))/log(static_cast<double>(1 + sqrt(static_cast<double>(5)))/2)));
    
   // 1
   A = new node*[max_degree+2]; // plus two both for indexing to max degree and so A[max_degree+1] == NIL
   // 2, 3
   fill_n(A, max_degree+2, nullptr);
   // 4
   w = H;
   rootSize = 0;
   next = w;

   do{
      rootSize++;
      next = next->right;
   } while ( next != w );

   rootList = new node*[rootSize];

   for ( int i = 0; i < rootSize; i++ ){
      rootList[i] = next;
      next = next->right;
   }

   for ( int i = 0; i < rootSize; i++ ){
      w = rootList[i];
      // 5
      x = w;
      // 6
      d = x->degree;
      // 7

      while ( A[d] != nullptr ){
      // 8
      y = A[d];

      // 9
      if ( x->n > y->n ){
         // 10
	 temp = x;
	 x = y;
	 y = temp;
      }
      // 11
      link(y,x);
      // 12
      A[d] = nullptr;
      // 13
      d++;
      }

      // 14
      A[d] = x;
   }
   delete [] rootList;

   // 15
   H = nullptr;

   // 16
   for ( int i = 0; i < max_degree+2; i++ ){
      // 17
      if ( A[i] != nullptr ){
         // 18
	 if ( H == nullptr ){
	    // 19, 20
	    H = A[i]->left = A[i]->right = A[i];
	 } else {
            // 21
	    H->left->right = A[i];
	    A[i]->left = H->left;
	    H->left = A[i];
	    A[i]->right = H;

	    // 22
	    if ( A[i]->n < H->n ){
	       // 23
	       H = A[i];
            }
	 }
      }
   }
   delete [] A;
}


/*
 * Operacja minimumNode, usuwa najmniejszy wezel i go zwraca
 * Kroki w komentarzach odnosza sie do krakow algorytmu (szczegoly w README)
 */
node* FibHeap::minimumNode(){

   node *z, *x, *next;
   node ** childList;

   // 1
   z = H;
   // 2
   if ( z != nullptr ){
      // 3
      x = z->child;
      if ( x != nullptr ){

         childList = new node*[z->degree];
	 next = x;
	 for ( int i = 0; i < (int)z->degree; i++ ){
	    childList[i] = next;
            next = next->right;
	 }
	 for ( int i = 0; i < (int)z->degree; i++ ){
            x = childList[i];
	    // 4
	    H->left->right = x;
	    x->left = H->left;
	    H->left = x;
	    x->right = H;
	    // 5
	    x->parent = nullptr;
	 }
	 delete [] childList;
      }
      // 6
      z->left->right = z->right;
      z->right->left = z->left;
      // 7
      if ( z == z->right ){
      // 8
      H = nullptr;
      }
      else
      {
      // 9
         H = z->right;
      // 10
	 consolidate();
      }
      // 11
      nH--;
   }
   // 12
   return z;
}




/*
 * Operacja show pokazuje korzenie
 */
void FibHeap::show(){

   node* p = H;

   if(p == NULL){
      cout << "Pusty Kopiec" << endl;
      return;
   }

   cout << "Korzenie kopca:" << endl;

   while(p->right != NULL){
      cout << p->n;
      p = p->right;
      if(p != H){
         cout << "-->";
      }
      if(p == H){
         break;
      }
   }
   cout << endl;
}


/*
 * Operacja Decrease Key
 */
int FibHeap::decreaseKey(int x, int k){

   node* y;

   if(H == NULL){
      cout << "Kopiec jest pusty" << endl;
      return 0;
   }

   node* ptr = Find(H, x);
   if(ptr == NULL){
      cout << "Nie znaleziono wezla" << endl;
      return 1;
   }

   if(ptr->n < k){
      cout << "Wprowadzony klucz jest wiekszy niz obecny" << endl;
      return 0;
   }

   ptr->n = k;
   y = ptr->parent;

   if(y != NULL && ptr->n < y->n){
      cut(ptr, y);
      cascadeCut(y);
   }
   if(ptr->n < H->n){
      H = ptr;
   }
   return 0;
}


/*
 * Operacja cut do redukcji klucza (pomocnicza)
 */
void FibHeap::cut(node* x, node* y){

   if(x == x->right){
      y->child = NULL;

   } else {

      x->left->right = x->right;
      x->right->left = x->left;

      if(x == y->child){
         y->child = x->right;
      }
   }

   y->degree--;
   x->right = x;
   x->left = x;
   H->left->right = x;
   x->right = H;
   x->left = H->left;
   H->left = x;
   x->parent = NULL;
   x->mark = 'F';
}


/*
 * Operacja cascadeCut (pomocnicza)
 */
void FibHeap::cascadeCut(node* y){

   node* z = y->parent;

   if(z != NULL){

      if(y->mark == 'F'){

         y->mark = 'T';

      } else {
         cut(y, z);
         cascadeCut(z);
      }
   }
}


/*
 * Operacja Find (pomocnicza)(rekurencyjna)
 */
node* FibHeap::Find(node* H, int k){

   node* x = H;
   x->C = 'Y';
   node* p = NULL;

   if(x->n == k){
      p = x;
      x->C = 'N';
      return p;
   }
   if(p == NULL){
      if(x->child != NULL){
         p = Find(x->child, k);
      }
      if(x->right->C != 'Y'){
         p = Find(x->right, k);
      }
   }
   x->C = 'N';
   return p;
}


/*
 * Operacja remove, usuwa wskazany klucz
 */
void FibHeap::removeKey(int k){

   node* np = NULL;
   int t;
   t = decreaseKey(k, numeric_limits<int>::min());
   if(!t){
      np = minimumNode();
   }
   if(np != NULL){
      delete np;
      cout << "Klucz usuniety" << endl;
   } else {
      cout << "Nie usunieto klucza" << endl;
   }
}


/*
 * Operacja zwracajaca najmniejszy element
 */
int FibHeap::top(){
   return H->n;
}


void FibHeap::removeMin(){
   node* fn = minimumNode();
   if(fn != NULL){
      cout << fn->n;
      delete fn;
   }
}

bool FibHeap::empty(){
   return nH == 0;
}


/*
 * Funkcja main, interaktywna budowa kocpa
 */
int main(int argc, char *argv[]){

   int n, m, l;
   FibHeap fh;
   node* p;

   while(1){
      cout << endl;
      cout << "=======================================" << endl;
      cout << "          Kopiec Fibonacciego" << endl;
      cout << "=======================================" << endl;
      cout << "[1] Dodaj liczbe do kopca" << endl;
      cout << "[2] Usun najmniejszy element w kopcu" << endl;
      cout << "[3] Wyswietl korzenie kopca" << endl;
      cout << "[4] Wyswietl rozmiar kopca" << endl;
      cout << "[5] Zmniejsz wartosc elementu" << endl;
      cout << "[6] Usun element" << endl;
      cout << "[7] Wyswietl najmniejszy element" << endl;
      cout << "[8] Zakoncz" << endl;
      cin >> l;
      switch(l){

         case 1:
           cout << endl;
           cout << "Wprowadz wartosc: ";
           cin >> m;
           p = fh.createNode(m);
           fh.push(p);
           cout << endl;
           break;

        case 2:
           cout << endl;
           if(fh.empty() == false){
              cout << "Usunieto najmniejszy element kopca = ";
              fh.removeMin();
              cout << endl;
           } else {
              cout << "Kopiec jest pusty" << endl;
           }
           cout << endl;
           break;
            
        case 3:
           cout << endl;
           fh.show();
           cout << endl;
           break;

        case 4:
           cout << endl;
           cout << "Rozmiar kopca = " << fh.size() << endl;
           cout << endl;
           break;

        case 5:
           cout << endl;
           cout << "Wprowadz klucz do zredukowania: ";
           cin >> m;
           cout << "Wprowadz nowa wartosc klucza: ";
           cin >> l;
           fh.decreaseKey(m, l);
           cout << endl;
           break;

        case 6:
           cout << endl;
           cout << "Wprowadz klucz do usuniecia: ";
           cin >> m;
           fh.removeKey(m);
           cout << endl;
           break;

        case 7:
           cout << endl;
           cout << "Najmniejszy element = " << fh.top() << endl;
           cout << endl;
           break;

        case 8:
           exit(1);

        default:
           cout << endl;
           cout << "Bledny wybor" << endl;
           cout << endl;
      }
   }

   return 0;
}
