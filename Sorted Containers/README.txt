Zadanie 1 & 2: Umieszczone w plikach .h
- Funkcja static SortedArrayList merge() zaimplementowana poprzez zagniezdzenie funckji push z tej samej klasy

Zadanie 3:
- program gen2list i gen1list generuja odpowiednio dwie lub jedna liste, podajac w pliku wyjscowym wpierw dlugosc, newline, potem zawartosc listy odzielona spacjami. gen2list sluzy w zadaniu 3, gen1list sluzy w zadaniu 4.
- Maksymalny laczny rozmiar obu list ustawiony sztywno na 50k w generatorze.
- Zadanie zaimplementowane dla trzech typow list w programach merge_repeat oraz merge_unique. Oba programy przyjmuja argumenty z plikow generatora oraz recznie podajac: dlugosc listy, newline, kolejne inty oddzielone spacjami (zakonczone spacja), newline.

Zadanie 4:
- Podobna implementacja jak w poprzednich zadaniach ale wygenerowawszy jedna pelna liste na 50k elementow.
- Program sortAddRemove wpierw zapelnia listy elementami, wypisuje ich wartosc do std::cout nastepnie usuwa losowe pozycje uzywajac losowych iteratorow (ktorych pula maleje wraz z rozmiarem listy).
- Program mierzy czas dla obu operacji: ponizej przykaldowy czas dla oddzielnych list przy wejsciu 50k elementow.
SortedArrayList: ~5,5 sekund;
SortedLinkedList: ~16,1 sekund;
- Zgodnie z obserwacja Stroustrupa, lista wskaznikowa dwukierunkowa wymaga dluzszej pracy w celu skutecznego oproznienia jej zawartosci
