#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/**
  * Definicja i "konstruktor" wezla. To jest rozwiazanie bezklasowe
  */

struct node{
   string word; //Przechowywane slowo
   int height; //Wysokosc drzewa
   struct node *left, *right; //Wskazniki na wezly potomne
};

struct combo{
   struct node *small;
   struct node *big;
};


//Funkcja tworzaca nowy wezel z kluczem i zapisujaca dane slowo
struct node *newNode(string w){
   struct node *temp = (struct node *)malloc(sizeof(struct node)*32);
   temp->word = w;
   temp->height = 1;
   temp->left = temp->right = NULL; //Generujemy wskazniki null
   return temp;
}


//Funkcja max int
int max(int a, int b){
   return (a > b)? a : b;
}

//Wysokosc drzewa, przechowywana w wezlach
int depth(struct node * node){
   if(node == NULL){
      return 0;
   }
   return node->height;
}


/**
  * Funkcje rotacji drzewa, balans
  */ 

struct node *rightRotate(struct node *y){
   struct node *x = y->left;
   struct node *T2 = x->right;

   //Rotacja
   x->right = y;
   y->left = T2;

   //Nowe wysokosci
   y->height = max(depth(y->left), depth(y->right))+1;
   x->height = max(depth(x->left), depth(x->right))+1;

   return x;
}


struct node *leftRotate(struct node *x){
   struct node *y = x->right;
   struct node *T2 = y->left;

   //Rotacja
   y->left = x;
   x->right = T2;

   //Nowe wysokosci
   x->height = max(depth(x->left), depth(x->right))+1;
   y->height = max(depth(y->left), depth(y->right))+1;

   return y;
}

//Funkcja balansu czyli o ile roznia sie wysokosci poddrzew
int getBalance(struct node * node){
   if(node == NULL){
      return 0;
   }
   return depth(node->left) - depth(node->right);
}



//Funkcja przejscia drzewa InOrder od korzenia
void inorder(struct node *root){
   if(root != NULL){
      inorder(root->left);
      cout << root->word << endl;
      inorder(root->right);
   }
}

/**
  * Funkcja postorder czyli left->right->root przy czym jak right ma dzieci 
  * to robimy je zanim wracamy do glownego cyklu
  */
void postorder(struct node *node){
   if(node == NULL){
      return;
   }

   postorder(node->left);
   postorder(node->right);
   printf("%s \n", node->word);
}

//Funkcja preorder czyli root->left->right
void preorder(struct node * node){
   if(node == NULL){
      return;
   }

   cout << node-> word << endl;
   preorder(node->left);
   preorder(node->right);
}

//Funkcja dodania do drzewa rekurencja z sprawdzaniem balansu
struct node *insert(struct node* node, string w){
   if(node == NULL) 
      return newNode(w);

   //Dodanie jak w BST
   if(w < node->word){
      node->left = insert(node->left, w);
   } else if(w > node->word){
      node->right = insert(node->right, w);
   } else
      return node;

   //Inkrementacja wysokosci drzewa
   node->height = 1 + max(depth(node->left), depth(node->right));

   //Sprawdzamy balans
   int balance = getBalance(node);


   //Rozpatrywanie czterech przypadkow rozbalansowania drzewa
   //left left
   if(balance > 1 && w < node->left->word)
      return rightRotate(node);

   //right right
   if(balance < -1 && w > node->right->word)
      return leftRotate(node);

   //left right
   if(balance > 1 && w > node->left->word){
      node->left = leftRotate(node->left);
      return rightRotate(node);
   }

   //right left
   if(balance < -1 && w < node->right->word){
      node->right = rightRotate(node->right);
      return leftRotate(node);
   }

   return node;
}


//Wyszukiwanie najmniejszego wezla idac maksymalnie w lewo
struct node *minimumNode(struct node* node){
   struct node* current = node;

   while(current->left != NULL){
      current = current->left;
   }
   return current;
}

//Wyszukiwanie najwiekszego wezla idac maksymalnie w prawo
struct node *maximumNode(struct node* node){
   struct node* current = node;

   while(current->left != NULL){
      current = current->right;
   }
   return current;
}


/**
  * Usuwanie wezla z dana wartoscia zwraca nowy root
  */ 

struct node *deleteNode(struct node * root, string w){

   //usuwanie BST na start
   if(root == NULL){
      return root;
   }

   if(w.compare(root->word) < 0){
      root->left = deleteNode(root->left, w);
   } else if(w.compare(root->word) > 0){
      root->right = deleteNode(root->right, w);
   } else {

      //jesli slowa takie same
      //Przypadek braku lub jednego poddrzewa
      if((root->left == NULL) || (root->right == NULL)){
         struct node *temp = root->left ? root->left : root->right;

         //Sprawdzamy czy sa drzewa potomne, jesli tak to kopiujemy to poddrzewo
         if(temp == NULL){
            temp = root;
            root = NULL;
         } else {
            *root = *temp;
            delete(temp); //Uwalnia pamiec temp
         }

      //Przypadek dwoch poddrzew
      } else {

         //Nastepca to minimum prawego poddrzewa czyli kolejne slowo
         struct node *temp = minimumNode(root->right);
         root->word = temp->word;

         //Usuwamy znaleziony wezel
         root->right = deleteNode(root->right, temp->word);
      }
   }

   //Jesli drzewo mialo tylko jeden wezel
   if(root == NULL){
      return root;
   }

   root->height = 1 + max(depth(root->left), depth(root->left));


   //Rebalans drzewa tak samo jak w insert
   int balance = getBalance(root);

   //left left
   if(balance > 1 && getBalance(root->left) >= 0)
      return rightRotate(root);

   //right right
   if(balance < -1 && getBalance(root->right) <= 0)
      return leftRotate(root);

   //left right
   if(balance > 1 && getBalance(root->left) < 0){
      root->left = leftRotate(root->left);
      return rightRotate(root);
   }

   //right left
   if(balance < -1 && getBalance(root->right) > 0){
      root->right = rightRotate(root->right);
      return leftRotate(root);
   }

   return root;
}


//Funkcja searchWord, rekurencyjna
struct node *searchWord(struct node* root, string w){
   
   //Podstawowy check zakanczajacy rekurencje
   if(root == NULL || w.compare(root->word) == 0){
      return root;
   }

   if(root->word.compare(w) < 0){
      return searchWord(root->right, w);
   }

   return searchWord(root->left, w);
}


/**
  * Funkcja rozmiaru, tutaj dodajemy +1 zatrzymujac sie na kazdym wezle
  * Jak nie ma wezla to rekurencja sie zatrzymuje i mamy +0
  */
int size(struct node * node){
   if(node == NULL){
      return 0;
   }
   return(size(node->left) + 1 + size(node->right));
}

//Faktyczna funkcja minimum
void minimum(struct node * node){
   cout << minimumNode(node)->word << endl;
}


/**
  * Funkcja laczaca oba drzewa za pomoca ich korzeni
  * Zwraca korzen lacznego drzewa
  * Cale rozwiazanie bedzie uzywac polaczenia posortowanych tablic
  */ 

//Deklaracje
struct node *transfer(string tab[], int start, int end);
string *merge(string tab1[], string tab2[], int m, int n);
void storeInorder(struct node * node, string inorder[], int *index);
struct node *transfer(string tab[], int start, int end);

//Funkcja merge z mergeSort, bez sortowania
string *merge(string tab1[], string tab2[], int m, int n){
   string *merged = new string[m + n];
   int i = 0, j = 0, k = 0;

   while(i < m && j < n){
      if(tab1[i].compare(tab2[j]) < 0){
         merged[k] = tab1[i];
         i++;
      } else {
         merged[k] = tab2[j];
         j++;
      }
      k++;
   }

   while(i < m){
      merged[k] = tab1[i];
      i++; k++;
   }

   while(j < n){
      merged[k] = tab2[j];
      j++; k++;
   }

   return merged;
}


//funkcja store in order umieszcza w tablicy odpowiednie elementy drzewa
void storeInorder(struct node * node, string inorder[], int *index){
   if(node == NULL)
      return;

   //rekurencje lewa i prawa
   storeInorder(node->left, inorder, index);

   inorder[*index] = node->word;
   (*index)++;

   storeInorder(node->right, inorder, index);
}


//funkcja budujaca AVL z tablicy
struct node *transfer(string tab[], int start, int end){
   if(start > end)
      return NULL;

   //root ze srodkowego elementu
   int mid = (start + end)/2;
   struct node *root = newNode(tab[mid]);

   //Rekurencyjna budowa obu poddrzew
   root->left = transfer(tab, start, mid-1);
   root->right = transfer(tab, mid+1, end);

   return root;
}

//Tworzy kombinacje obu tablic i zwraca korzen nowego drzewa
struct node *mergeTrees(struct node * small, struct node * big){
   
   int m = size(small);
   int n = size(big);

   //przechowujemy oba drzewa w tablicach
   string *tab1 = new string[m];
   int i = 0;
   storeInorder(small, tab1, &i);

   string *tab2 = new string[n];
   int j = 0;
   storeInorder(big, tab2, &j);

   string *merged = merge(tab1, tab2, m, n);

   return transfer(merged, 0, m+n-1);
}


/**
  * Funkcja split tree zwraca pare wezlow jako nowe drzewa
  */

struct combo *splitTrees(struct node * root, string w){

   struct combo *temp;

   if(root == NULL){
      temp->small = NULL;
      temp->big = NULL;
      return temp;
   }

   if(w.compare(root->word) <= 0){
      temp = splitTrees(root->left, w);
      struct node *temp2 = mergeTrees(temp->big, root->right);
      temp->big = temp2;
   } else {
      temp = splitTrees(root->right, w);
      struct node *temp2 = mergeTrees(temp->small, root->left);
      temp->small = temp2;
   }
   return temp;
}


