#include <iostream>
#include <string>
#include <sstream>
#include <array>

using namespace std;

struct node{
   int mark;
   node* next;
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
      if(head == NULL){
         head = temp;
         tail = temp;
         head->next = NULL;
         tail->next = NULL;
         temp = NULL;        
      } else {
         temp->next = head;
         head = temp;
      }
      current_size++; //Rozmiar w gore
   }

   //Usuwamy pozycje od strony HEAD
   int pop_front(){
      if(head == NULL) return -1;
      int wartosc = head->mark; //wartosc do zwrocenia
      node *temp = new node;
      temp = head;
      head = head->next; //Uzywamy wskaznika do nast. node aby wyznaczyc nowy head
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
         temp = NULL; //Po przypisaniu temp jest niepotrzebny
      } else {
         tail->next = temp; //stary tail wskazuje na nowy wezel
         tail = temp; //temp zajmuje nowy wezel
      }
      current_size++; //Rozmiar w gore
   }
   
   //Kasujemy node przy tail
   int pop_back(){
      if(head == 0) return -1;
      int wartosc = tail->mark; //Zachowujemy wartosc do zwrocenia
      node *obecny = new node;
      node *poprzedni = new node;
      obecny = head; //Musimy pokonac cala liste w celu znalezienia przedostatniego node
      while(obecny->next != NULL){ //Zatrzymamy sie kiedy node wskaze nam na NULL czyli brak nastepnego
         poprzedni = obecny;
         obecny = obecny->next;
      }
      tail = poprzedni; //Poprzedni ogonem bo oceny zostaje skasowany
      poprzedni->next = NULL; //Zerowanie next w nowym ogonie
      delete obecny;
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

   //Drukowanie listy w celach testowych, podobne do find
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
         cout << x << " " << n << "   Dodane do listy\n";


      } else if(x == 'F'){
         cout << x << " " << n;
           if(lista.find(n) != nullptr){
              cout << "   TRUE\n";
           } else {
              cout << "   FALSE\n";
           }


      } else if(x == 'D'){
         cout << x << "    ";
         z = lista.pop_back();
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
