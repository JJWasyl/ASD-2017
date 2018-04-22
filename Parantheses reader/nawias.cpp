#include<iostream>
#include<stack>
#include<string>

using namespace std;

//Czy mamy pasujace pary
bool isPair(char l,char p){

   if(l == '(' && p == ')'){return true;}
   else if(l == '{' && p == '}'){return true;}
   else if(l == '[' && p == ']'){return true;}

   return false;
}

//Przechodzimy po wyrazeniu (wepchanym do stosu)
bool rownowaga(string in){

   stack<char>  s;
   for(int i =0;i<in.length();i++){

      if(in[i] == '(' || in[i] == '{' || in[i] == '['){
         s.push(in[i]);

      } else if(in[i] == ')' || in[i] == '}' || in[i] == ']'){

         if(s.empty() || !isPair(s.top(),in[i])){ 
            return false;

         } else {
            s.pop();
         }
      }
   }
   return s.empty() ? true:false;
}

int main(int argc, char *argv[]){

   string input;
   cout<<"Wprowadz wyrazenie: ";
   cin>>input;
   if(rownowaga(input)){
      cout<<"CORRECT\n";

   } else {
      cout<<"INCORRECT\n";
   }
}
