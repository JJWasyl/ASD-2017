Jakub Wasylkowski
Zestaw 1 - Sortowanie

Zadanie 1.
==========

Programy zawieraja standardowe algorytmy sortowania.
Dane sa wczytane z pliku input_xk.txt, gdzie x oznacza ilosc losowo wygenerowanych liczb.
Kady program posiada timer obejmujacy algorytm sortowania i wyswietla czas pracy w terminalu.

Dane wczytywane sa do wektora, po czym sa sortowane wewnatrz osobnej funckji sortujacej.
Program drukuje plik wyjsciowy (jesli podany w tarminalu) zgodnie z formatem w zadaniu.


Zadanie 2.
==========
Zlozonosc obliczeniowa
----------------------

Wariant optymistyczny = lista posortowana
Wariant pesymistyczny = lista odwrotnie posortowana

Bubble sort:
- W obu wariantach algorytm pokonuje cala liste czyli N operacji
- Jesli lista jest posortowana po pierwszym przejsciu (lub byla posortowana od poczatku) zlozonosc pozostaje = O(N) Optymistyczna (np. 10k porownan dla listy 10k)
- Jesli potrzebna jest kolejna seria wymian, petla pokona liste jeszcze raz = O(n^2) Pesymistyczna
- Dla 10k danych srednia liczba operacji: (10'000 + 100'000'000)/2 = 50'005'000

Insertion sort:
- Podobnie jak powyzej, najlepszy przypadek zachodzi gdy lista input jest posortowana = O(n)
- Kazdy przechwycony element do posortowania w liscie odwrotnie posortowanej musi przejsc cala liste aby znalezc swoje miejsce, zatem = O(n^2)
- Dla 10k danych srednia liczba operacji: (10'000 + 100'000'000)/2 = 50'005'000
 
Counting sort:
- Ten algorytm stosuje osobne funkcje for jedna po drugiej, zatem zlozonosc w przypadku optymistycznym i pesymistycznym wynosi = O(2*n)
-  Dla 10k danych srednia liczba operacji: 20'000 

Selection sort:
- Algorytm w obu przypadkach pokonuje cala liste. Znalezienie minimum wymaga jednego skanu (n)
- Znalezienie nastepnego najnizszego elementu po przemieszczeniu minimum zajmuje (n-1)
- Zlozonosc sprowadza sie do O(n^2) dodatkowo proces wymiany n elementow posiada zlozonosc O(n)
- O(n^2 + n) = O(n^2) Przypadek taki sam dla wariantu optymistycznego i pesymistycznego.
-  Dla 10k danych srednia liczba operacji: 100'000'00'000

std::sort:
- wg. Biblioteki C++ std::sort posiada zlozonosc O(n log n)
- Liczba operacji dla 10k wartosci: 10'000*log10'000 = 40'000 


Czas sortowania
---------------

Wykres zalaczony w folderze

