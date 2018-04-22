#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>

#include "AVLTree.h"

using namespace std;


int main(int argc, char *argv[]){

   struct node *root1 = NULL;
   struct node *root2 = NULL;
   struct node *root3 = NULL;

   string cin_input;
   string line;
   //getline(cin, cin_input);
   //root1 = insert(root1, cin_input);

   while(getline(cin, cin_input)){
      if(cin_input.empty()) break;
      root1 = insert(root1, cin_input);
   }


   root2 = insert(root2, "dom");
   root2 = insert(root2, "ala");
   root2 = insert(root2, "kot");
   root2 = insert(root2, "drap");

   root3 = insert(root3, "wiatrak");
   root3 = insert(root3, "schody");
   root3 = insert(root3, "kilof");
   root3 = insert(root3, "aligator");  

   root2 = mergeTrees(root2, root3);

   inorder(root2);

   if(argc > 1){
      line = argv[1];
      if(searchWord(root1, line) != NULL){
         cout << "Success" << endl;
      } else {
         cout << "Fail" << endl;
      }
   }   

   return 0;
}
