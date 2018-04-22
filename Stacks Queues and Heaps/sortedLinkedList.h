#include <iostream>

using namespace std;

//Wezel node
struct node{
   int mark;
   node* next;
   node* previous;
};

class SortedLinkedList{
private:
   //Head to najmniejszy wezel, tail najwiekszy
   //Head nigdy nie ma previous, tail nigdy nie ma next
   //p i r sa wezlami tymczasowymi, dodatkowo niektore funkcje wykorzystuja jeszcze temp
   node *head, *tail, *p, *r; 

public:

   int current_size; //Ilosc wezlow node

   SortedLinkedList(){ //Konstruktor
      head = NULL;
      tail = NULL;
      p = NULL;
      r = NULL;
      current_size = 0;
   };


   //Dodanie elementu do posortowanej listy
   void push(int x){
      node *temp = new node; //Alokacja nowej struktury node
      temp->mark = x; //tymczasowo przypisujemy wartosc do temp
      temp->next = NULL;
      temp->previous = NULL;

      if(current_size == 0){
         head = temp;
         tail = temp;
         p = head;
         p->next = NULL;
         p->previous = NULL;
         current_size++;

      } else {
         p = head;
         r = p;
         if(temp->mark <= p->mark){ //jesli x najmniejsze, staje sie nowym head
            temp->next = p;
            p->previous = temp;
            temp->previous = NULL;
            head = temp;
            p = head;
            while(p->next != NULL){
               p = p->next;
            }
            tail = p; //Po petli wyznaczamy ogon
            current_size++;

         } else if(temp->mark > p->mark){ //jesli x wieksze od glowy
            while(p != NULL && temp->mark > p->mark){
               r = p;
               p = p->next;
               if(p == NULL){ //Jesli x jest max, dodajemy na ogonie
                  r->next = temp;
                  temp->previous = r;
                  temp->next = NULL;
                  tail = temp;
                  current_size++;
                  break;

               } else if(temp->mark <= p->mark){ //to samo co bylo powyzej
                  r->next = temp; //Uzywam r, poniewaz p jest zajete obracaniem petli
                  temp->previous = r;
                  temp->next = p; // p juz przeszlo na next, x wstawiamy pomiedzy r i p
                  p->previous = temp;
                  if(p->next != NULL){ //jesli zmiana w srodku petli, musimy skonczyc przepychac wezly
                     while(p->next != NULL){
                        p = p->next;
                     }
                  }
                  tail = p;
                  current_size++;
                  break;
               }
            }
         }
      }
   }


   int pop(){
      if(current_size == 0){return -1;}
      p = head;
      head = p->next;
      head->previous = NULL;
      return p->mark;  
   }

  
   int erase(int i){
      node *temp = new node;
      int skok = 0;
      p = head;
      r = tail;
      if(current_size == 0){return -1;}
      if(i == 0 && current_size > 1){
         temp = p;
         p = p->next;
         head = p;
         head->previous = NULL; //Chyba redundant
         current_size--;
         return temp->mark;
      } else if(i == 0 && current_size == 1){
         temp = head;
         head = NULL;
         tail = NULL;
         current_size--;
         return temp->mark;
      } else {
         while(skok < i){
            p = p->next;
            skok++;
         }
         if(p == tail){
            temp = p;
            p = p->previous;
            p->next = NULL;
            tail = p;
            current_size--;
            return temp->mark;
         } else {
            temp = p;
            r = temp->next;
            p = temp->previous;
            r->previous = p;
            p->next = r;
            current_size--;
            return temp->mark;
         }
      }
   }


   int find(int x){
      int f = 0;
      if(current_size == 0){return -1;}
      p = head;
      while(p != NULL){
         if(p->mark == x){
             return f;
         } else {
            p = p->next;
            f++;
         }
      }
      return -1;
   }


   int size(){
      return current_size;
   }

   void remove(int x){
      if(current_size == 0){return;}
      node *temp = new node;
      p = head;
      while(p != NULL){
         if(p->mark == x){
            temp = p;
            if(temp == head){
               head = p->next; 
               head->previous = NULL;
               p = head;
            } else { 
               r = p->previous;
               r->next = p->next;
               p = r;
               if(temp == tail){tail = p;}
               current_size--;
            }
         }
         p = p->next;
      }
   }


   void print(){
      node *obecny = new node;
      obecny = head;
      if(obecny == NULL) cout << "EMPTY\n";
      while(obecny != NULL){
         cout << obecny->mark << ", ";
         obecny = obecny->next;
      }
      cout << "\n";
   }


   static SortedLinkedList merge(SortedLinkedList& a, SortedLinkedList& b){
      SortedLinkedList temporary;
      node *p, *r;
      temporary = a;
      p = b.head;
      while(p != NULL){
         temporary.push(p->mark);
         p = p->next;
      }
      return temporary;
   }


   void unique(){
      if(current_size == 0){return;}
      p = head;
      r = p->next;
      while(p->next != NULL){
         if(p->mark == r->mark){
            p->next = r->next;
            r = p->next;
            r->previous = p;
            current_size--;
         } else {
            p = p->next;
            r = r->next;
         }
      }
   }
};


