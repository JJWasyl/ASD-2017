Zestaw 2: Listy

Wszystkie programy zczytuja dane ze standardowego wejscia w formacie char(Instrukcja) i int(liczba dotyczaca instrukcji). Dane mozna wprowadzac recznie lub za pomoca pipe.

UWAGA: Jesli uruchamiamy program indywidualnie, nalezy jako pierwsza wartosc cin podac zamierzona ilosc argumentow. Jest to czysto informacyjna wartosc potrzebna gdy program przyjmuje dane przez pipe.

Array List tworzy zwykla liste tablicowa, elementy zostaja dodane na koniec listy badz na jej poczatek, przesuwajac indeksowo wszystkie jej elementy. Klasa listy zapamietuje rowniez dlugosc listy w celu obliczenia jej dlugosci lub dokonania operacji usuniecia/wyszukania elementu. Dlugosc listy jest podana na sztywno i wymaga recznej zmiany w kodzie.

Cursor list dziala podobnie do array list ale przechowuje dane przodu listy oraz dane kolejnej wolnej pozycji. Podobnie, dlugosc listy jest podana recznie na sztywno.

Linked List i Single List sa listami implementujacymi jedno i dwukierunkowa liste, przechowujac wskazniki do nastepnego i w przypadku LinkedList, poprzedniego wezla listy. to oznacza ze przy modyfikacji listy, wezel dodany musi utworzyc wskazniki do odpowiednich wezlow sasiadujacych. przy usuwaniu z kolei wezel musi zostac jawnie usuniety a wskazniki na niego wskazujace przekierowane lub wyzerowane.
