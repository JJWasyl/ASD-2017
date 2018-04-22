#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct node{
   int key; //Przechowywana wartosc
   struct node *left, *right; //Wskazniki na wezly potomne
};

//Funkcja tworzaca nowy wezel
struct node *newNode(int x){
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->key = x;
   temp->left = temp->right = NULL; //Generujemy wskazniki null
   return temp;
}

//Funkcja przejscia drzewa InOrder od korzenia
void inorder(struct node *root){
   if(root != NULL){
      inorder(root->left);
      printf("%d \n", root->key);
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
   printf("%d \n", node->key);
}

//Funkcja preorder czyli root->left->right
void preorder(struct node * node){
   if(node == NULL){
      return;
   }

   printf("%d \n", node->key);
   preorder(node->left);
   preorder(node->right);
}

//Funkcja dodania do drzewa
struct node* insert(struct node* node, int key){
   if(node == NULL) return newNode(key);

   if(key < node->key){
      node->left = insert(node->left, key);
   } else if(key > node->key){
      node->right = insert(node->right, key);
   }

   return node;
}

//Funkcja search, rekurencyjna
struct node* searchRecursive(struct node* root, int key){
   
   //Podstawowy check zakanczajacy rekurencje
   if(root == NULL || root->key == key){
      return root;
   }

   if(root->key < key){
      return searchRecursive(root->right, key);
   }

   return searchRecursive(root->left, key);
}

//Funkcja search, iteracyjna
struct node* searchIterative(struct node * root, int key){
   if(root == NULL || root->key == key){
      return root;
   }

   queue<node *> q;
   q.push(root);

   /**
     * Kolejka przyjmuje galezie korzenia, sprawdzamy oba, jak pudlo, wyjmujemy korzen i dodajemy
     * Galezie jednej z galezi (obie sa dodane wiec przejdziemy po lewej i prawej stronie)
     * Ostatecznie, jak nic nie znajdziemy, kolejka sie oprozni
     */
   while(q.empty() == false){
      node * node = q.front();
 
      if(node->key == key){
         return node;
      }

      q.pop();
      if(node->left != NULL){
         q.push(node->left);
      }
      if(node->right != NULL){
         q.push(node->right);
      }
   }
 
   //Jak nic nie ma to null
   return NULL;

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

//Wyszukiwanie najmniejszego wezla idac maksymalnie w lewo
struct node * minimumNode(struct node* node){
   struct node* current = node;

   while(current->left != NULL){
      current = current->left;
   }

   return current;
}

//Faktyczna funkcja minimum
void minimum(struct node * node){
   cout << minimumNode(node)->key << endl;
}

//Wyszukiwanie najwiekszego wezla idac maksymalnie w prawo
struct node * maximumNode(struct node* node){
   struct node* current = node;

   while(current->right != NULL){
      current = current->right;
   }

   return current;
}

//Faktyczna funkcja minimum
void maximum(struct node * node){
   cout << maximumNode(node)->key << endl;
}

//Wysokosc drzewa, rekurencyjne, podobnie jak rozmiar dodajemy + 1 za aktywny wezel
int depth(struct node * node){
   if(node == NULL){
      return 0;
   }

   int lDepth = depth(node->left);
   int rDepth = depth(node->right);

   if(lDepth > rDepth){
      return(lDepth + 1);
   } else {
      return(rDepth + 1);
   }
}


/**
  * Implementacja nierekurencyjnego przejscia po drzewie
  */

//Wezel stosowy, kombinujemy linkedlist i stos
struct sNode{
   struct node *t; //Przechowywany wezel
   struct sNode *next;
};


void push(struct sNode** top_ref, struct node *t){
   struct sNode * new_Node = (struct sNode*) malloc(sizeof(struct sNode));

   if(new_Node == NULL){
      cerr << "Stack Overflow\n";
      exit(0);
   }

   new_Node->t = t; //Przypisujemy wezel do wezla stosowego
   new_Node->next = (*top_ref); //Przenosimy wskaznik head do nowego Node
   (*top_ref) = new_Node;
}

//Funkcja pomocnicza
bool isEmpty(struct sNode * top){
   return(top == NULL) ? 1 : 0;
}


//Funkcja pop
struct node *pop(struct sNode** top_ref){
   struct node *res;
   struct sNode *top;

   if(isEmpty(*top_ref)){
      cout << "Stack Underflow\n";
      exit(0);
   } else {
      top = *top_ref;
      res = top->t;
      *top_ref = top->next;
      free(top);
      return res;
   }
}


//Przejscie po drzewie, iteracyjne
void inOrder(struct node *root){
   struct node *current = root;
   struct sNode *s = NULL;
   bool done = 0;

   //Zbieramy najbardziej lewy wezel do stosu a potem do gory
   while(!done){
      if(current != NULL){
         push(&s, current);
         current = current->left;
      } else {
         if(!isEmpty(s)){
            current = pop(&s);
            printf("%d \n", current->key);
 
            //Przechodzimy na prawy wezel i znowu zejscie
            current = current->right;
         } else {
            done = 1;
         }
      }
   }
}


