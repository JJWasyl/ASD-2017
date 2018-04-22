#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

#include "binaryTree.h"

using namespace std;


int main(int argc, char *argv[]){

   struct node *root = NULL;

   /*
   //Test roboczy
   root = insert(root, 50);
   insert(root, 30);
   insert(root, 100);
   insert(root, 80);
   insert(root, 40);
   insert(root, 25);
   insert(root, 20);

   cout << "\nDrzewo inOrder:\n";
   inorder(root);

   cout << "\n\nDrzewo postOrder:\n";
   postorder(root);

   cout << "\n\nDrzewo preOrder:\n";
   preorder(root);

   cout << "\nMin/Max\n";
   minimum(root);
   maximum(root);

   cout << "\nSize = " << size(root) << endl;
   cout << "\nDepth = " << depth(root) << endl;

   cout << "\nTest Recursive Search:\n";
   cout << "Search 10: " << (searchRecursive(root, 10) != NULL) << endl;
   cout << "Search 25: " << (searchRecursive(root, 25) != NULL) << endl;

   cout << "\nTest Iterative Search:\n";
   cout << "Search 10: " << (searchIterative(root, 10) != NULL) << endl;
   cout << "Search 25: " << (searchIterative(root, 25) != NULL) << endl;
   */


   //Test Wlasciwy  
   srand(time(nullptr));
   int count;
   int n;
   cin >> count;
   cin >> n;

   root = insert(root, n);


   for(int i = 1; i < count; i++){
      cin >> n;
      insert(root, n);
   }

   /*
   cout << "\nDrzewo inOrder:\n";
   inorder(root);
   */

   cout << "\nDrzewo inOrder iteracyjne:\n";
   inOrder(root);

   cout << "\nTest Recursive Search:\n";
   for(int k = 0; k < 10; k++){
      int x = (int) rand() % n;
      string Success;
      if(searchRecursive(root, x) != NULL){
         Success = "Yes";
      } else {
         Success = "No";
      }
      cout << "Search " << x << ": " << Success << endl;
   }


   return 0;
}
