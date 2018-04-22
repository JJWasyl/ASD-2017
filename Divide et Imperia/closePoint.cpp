#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

#include "quicksort.h"
#include "ArrayList.h"

struct Point{
   double x, y;
};

class Pair{
public:
   Point p1, p2;
   double distance = 2;

   void refresh(){
      p1.x = 0; p1.y = 0;
      p2.x = 0; p2.y = 0;
      distance = 2;
   }
};

//Przechowanie wynikow
Pair para;

//Odleglosc miedzy punktami
double dist(Point p1, Point p2){
   return sqrt((p1.x - p2.x) * (p1.x - p2.x) + 
               (p1.y - p2.y) * (p1.y - p2.y));
}


//metoda Brute Force
double bruteForce(ArrayList<Point> list, int n){
   double min = sqrt(2);
   for(int i = 0; i < n; i++){
      for(int j = i+1; j < n; j++){
         if(dist(list.tab[i], list.tab[j]) < min){
            min = dist(list.tab[i], list.tab[j]);
            if(min < para.distance){
               para.p1 = list.tab[i]; 
               para.p2 = list.tab[j]; 
               para.distance = min;
            }
         }
      }
   }
   return min;
}


//Znalezienie minimum dwoch double
double min(double x, double y){
   return (x < y)? x : y;
}

//Jak wyznaczymy sekcje w osi x, wykonujemy ponizsze aby znalezc dwa najblizsze punkty wzgledem y
double stripClosest(ArrayList<Point> strip, int size, double d){
   double min = d; //Minimalny dystans
   quick_sort(strip, false);

   for(int i = 0; i < size; i++){
      for(int j = i+1; j < size && (strip.tab[j].y - strip.tab[i].y) < min; ++j){
         if(dist(strip.tab[i], strip.tab[j]) < min){
            min = dist(strip.tab[i], strip.tab[j]);
            if(min < para.distance){
               para.p1 = strip.tab[i]; 
               para.p2 = strip.tab[j]; 
               para.distance = min;
            }
         }
      }
   }
   return min;
}

double closestUtil(ArrayList<Point> &list, int n){

   double dl, dr;
   Point inter1, inter2;

   if(n <= 3){
      return bruteForce(list, n);
   }

   //Srodkowy punkt
   int mid = n/2;
   Point midPoint = list.tab[mid];
   ArrayList<Point> rlist;

   for(int i = mid; i < n; i++){
      rlist.push_back(list.tab[i]);
   }

   //Rekurencja dzielaca kwadrat na mniejsze
   dl = closestUtil(list, mid);
   dr = closestUtil(rlist, rlist.size());

   //Najmniejszy dystans
   double d = min(dl, dr);

   ArrayList<Point> strip;
   int j = 0;
   for(int i = 0; i < n; i++){
      if(abs(list.tab[i].x - midPoint.x) < d){
         strip.push_back(list.tab[i]);
         j++;
      }
   }
   double minstrip = sqrt(2);
   if(j > 1)
      minstrip = stripClosest(strip, j, d);

   if(minstrip < d){

      return minstrip;
   } else {

      return d;
   }
}


double closest(ArrayList<Point> &list, int n){
   quick_sort(list, true);  
   return closestUtil(list, n);
}

int main(int argc, char *argv[]){

   string cin_input;
   stringstream stream;
   ArrayList<Point> Points;
   int i = 0, n;

   //Ladowanie par x,y do arrayListy Points
   while(getline(cin, cin_input)){
      istringstream stream(cin_input);
      Point p;
      stream >> p.x >> p.y;
      Points.push_back(p);
      stream.clear();
      i++;
   }

   n = Points.size();

   cout << "\nBrute Force dist = " << bruteForce(Points, n) << "\n";
   cout << "(" << para.p1.x << ", " << para.p1.y << ")" << " ; "
        << "(" << para.p2.x << ", " << para.p2.y << ")\n";

   para.refresh();

   cout << "Qsort dist = " << closest(Points, n) << "\n";
   cout << "(" << para.p1.x << ", " << para.p1.y << ")" << " ; "
        << "(" << para.p2.x << ", " << para.p2.y << ")\n";


/*
   while(i != 0){
      Point temp = Points.pop_back();
      cerr << temp.x << " " << temp.y << endl;
      i--;
   }
*/
return 0;
}
