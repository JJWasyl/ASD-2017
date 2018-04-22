#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct node{
   int mark;
   node* next;
   node* previous;
};

class LinkedList{
private:
   node* head; //Head jest frontem listy i sie nie przemieszcza
   node* tail; //wskaznik przemieszcza sie z rozwojem listy


public:

   int current_size; //Ilosc wezlow node

   LinkedList(){
      head = NULL;
      current_size = 0;
      tail = NULL;
   };

   //Nowy head, node na starcie
   void push_front(int x){
      node *temp = new node; //Alokacja nowej struktury node
      temp->mark = x; //tymczasowo przypisujemy wartosc do temp
      temp->previous = NULL;
      if(head == NULL){
         temp->next = NULL;
         head = temp;
         tail = temp;
         temp = NULL;
      } else {
         temp->next = head;
         head->previous = temp;
         head = temp;
         temp = NULL;
      }
      current_size++; //Rozmiar w gore
   }

   //Usuwamy pozycje od strony HEAD
   int pop_front(){
      if(head == NULL) return -1;
      int wartosc = head->mark; //wartosc do zwrocenia
      if(current_size == 1){head = NULL; tail = NULL; return wartosc;}
      node *temp = new node;
      temp = head;
      head = temp->next; //Uzywamy wskaznika do nast. node aby wyznaczyc nowy head
      head->previous = NULL;
      delete temp; //Usuwamy stary head
      current_size--;
      if(current_size == 0){head = NULL; tail = NULL;}
      return wartosc;
   }

   //Dodajemy node przy tail
   void push_back(int x){
      node *temp = new node; //Alokacja nowej struktury node
      temp->mark = x; //tymczasowo przypisujemy wartosc do temp
      temp->next = NULL; //nastepna wartosc to 0
      if(head == NULL){ //Jesli nie ma listy
         head = temp;
         tail = temp;
         head->previous = NULL; //Nie ma el. przed head
         tail->previous - NULL; //Podobnie z tail
         temp = NULL; //Po przypisaniu temp jest niepotrzebny
      } else {
         tail->next = temp; //stary tail wskazuje na nowy wezel
         temp->previous = tail; //Tail zaraz stanie sie przedostatnim elementem
         tail = temp; //temp zajmuje nowy wezel tail
         temp = NULL;
      }
      current_size++; //Rozmiar w gore
   }
   
   //Kasujemy node przy tail
   int pop_back(){
      if(head == NULL || tail == NULL) return -1;
      if(current_size == 0){head = NULL; tail = NULL; return -1;}
      int wartosc = tail->mark; //Zachowujemy wartosc do zwrocenia
      if(head == tail){head = NULL; tail = NULL; return wartosc;}
      node* temp = new node;
      temp = tail; //stary tail idzie do temp aby zostac usuniety
      tail = temp->previous; //tail zchodzi na poprzednia wartosc
      delete temp;
      tail->next = NULL;
      current_size--;
      if(current_size == 0){head = NULL; tail = NULL;}
      return wartosc;
   }

   int* find(int x){
      int *f;
      node *obecny = new node;
      if(current_size == 0) return nullptr;
      obecny = head;
      while(obecny != NULL){
         if(obecny->mark == x){
            f = &obecny->mark;
             return f;
         } else {
            obecny = obecny->next;
         }
      }
      return nullptr;
   }

   int size(){
      return current_size;
   }

   //Drukowanie listy w celach testowych, podobne do metody find
   void print(){
      node *obecny = new node;
      obecny = head;
      if(obecny == NULL) cout << "EMPTY\n";
      while(obecny != NULL){
         cout << obecny->mark << "\n";
         obecny = obecny->next;
      }
   }

};


int main(int argc, char *argv[]){

   //Deklaracja zmiennych i obiektow
   string cin_input;
   stringstream stream;
   int count;
   char x;
   int n;
   int z;
   cin >> count;
   LinkedList lista;

   cout << endl << "Ilosc instrukcji = " << count << "\n\n";

   //Wyrzucenie niepotrzebnych znakow
   getline(cin, cin_input); 
   stream << cin_input; 
   stream.clear(); 
    
   //Ladowanie strumienia i interpretacja znakow
   while(getline(cin, cin_input)){  
      stream << cin_input;
      stream >> x;
      stream >> n;
      stream.clear();
      if(cin_input.empty()) break;

      if(x == 'A'){
         lista.push_back(n);
         cout << x << " " << n << "   Dodane do tablicy\n";


      } else if(x == 'F'){
         cout << x << " " << n;
           if(lista.find(n) != nullptr){
              cout << "   TRUE\n";
           } else {
              cout << "   FALSE\n";
           }


      } else if(x == 'D'){
         cout << x << "    ";
         z = lista.pop_front();
         if (z == -1){ 
            cout << "    EMPTY\n";
         } else {
            cout << "    Usunieto = " << z << "\n";
         }


      } else if(x == 'S'){
         cout << x << "        Rozmiar = " << lista.size() << "\n";
      } else {break;}
      n = 0;     
   }

   cout << "\n\n\nLista:\nHEAD\n";
   lista.print();
   cout << "TAIL\n\n";
}
