/**
  @mainpage Laboratorium 6 - Szablony klas i szablony funkcji

  Tresc zadan dla Panstwa:
  --------
Zadanie 0: absolutnie obowiazkowe, chociaz bez punktow
1. Pierwsza rzecza jest poprawa bledow kompilacji,
   czyli wpisanie poprawnych Panstwa danych w pliku: @ref main.cpp
2. Oddanne zadanie musi sie bezwzglednie kompilowac na systemie Linux:
   - Jesli sie nie skompiluje to jest to 0 punktow za zadanie!
   - Oczywiscie w razie problemow z kompilacja prosze się zgłaszać/pisać.
   - Dobrze, jesli nie byloby warningow kompilacji, ale za to nie obnizam punktow.
   - Aby się upewnić, że się kompiluje można skorzystać z [narzędzia online judge](https://domjudge.labagh.pl/) (VPN AGH konieczny).
     Aby wyslac zadanie nalezy wybrac odpowiednie dla zajec:
     konkurs (`context`), problem, oraz jezyk programowania.
     prosze zalaczyc pliki:
        - @ref myList.h i @ref mySorting.cpp
        - proszę nie załączać: @ref main.cpp
3. Oddane zadanie nie powinno crashować na żadnym teście,
   jeśli crashuje proszę zrobic implementacje -fake, ktora nie dopusci do crasha nawet jesli test bedzie failowal,
   ale za to testy nie beda sie crashowaly.
   W przypadku crasha biorę pod uwagę tylko tyle testów, ile przejdzie do czasu crasha!
4. Mam program antyplagiatowy, dlatego prosze pracowac samodzielnie!
   - Osoby ktore udostepniaja swoje rozwiazania rowniez beda mialy kare!
   - Na ukaranie prowadzący ma czas 2 tygodnie po terminie oddania,
      czyli nawet jak ktoś otrzyma punkty wcześniej ma pewność, że za oszustwa/łatwowierność dosięgnie go
      niewidzialna ręka sprawiedliwości.
5. Zadanie z zalozenia bedzie sprawdzane automatycznie, przez testy jednostkowe dostepne w pliku: @ref shapesTests.cpp,
6. *Dobrze jakby nie bylo warningow kompilacji (flagi: `-Wall -Wextra -pedantic -Werror`, a dla hardcorów jeszcze:  `-Weffc++`)
7. Punkty mogą być odejmowane za wycieki pamieci (jest podpiety `valgrind`)
8. Niewykluczone jest sprawdzanie reczne - zaleznie od prowadzacego dana grupe.
________________________________
Zadanie implementacyjne:
------------------------
1. Prosze utworzyć plik mylist.h, oraz dokonac nastepujacej implementacji:
   Proszę o zaimplementowanie szablonu klasy `MyList<T>`, reprezentujacej liste jednokierunkowa
   z glowa i iteratorami.
   Punktacja przydzielana za nastepujace metody (jak testy):
    1. za konstruktor bezargumentowy i metode `size()` zwracajaca ilosc elementow
    2. za metody `push_front` i `pop_front`, ktore odpowiednio dodaja/usuwaja element z poczatku
    3. metode `front()` zwracajaca element na poczatku,
       oraz aby `pop_front()` zwracala usuniety element.
       @note Standardowo w `std::list` metoda `pop_front()` nic nie zwraca.
       Jak myślisz - dlaczego?
    4. jesli pierwszy wezel (o nazwie head), oraz kazdy nastepny wezel (head->next)
       sa zaimplementowane przy pomocy `std::unique_ptr<MyList::Node>`
    5. jesli w razie zawolania `pop_front` na pustej liscie zostaje
       wyrzucony wyjatek `std::out_of_range`
    6. jesli kopiowanie (konstruktor kopiujacy i operator przypisania) jest niemozliwe dla listy
    7. jesli mamy zaimplementowane metody iteratora
       (tutaj jeszcze nie musza w pelni dzialac, chociaz powinny zwracac co nalezy)
    8. jesli napisany iterator dziala z petla for-zakresowym
    9. jesli nasz iterator dziala z algorytmami standardowymi na przykladzie `std::count_if`
       @note Do tego wymagane jest kilka aliasów typów.
   10. jesli mamy metode `remove(T element)`, ktora usuwa wszystkie elementy z listy o danej wartosci
   11. jesli lista ma operator wypisywania na strumien
       (forma wydruku dowolna, byleby byly wszystkie elementy)
2. Prosze o utworzenie pliku mySorting.h,
   W nim prosze o zaimplementowanie szablonu funkcji globalnej `void mySort(???)`:
   Punktacja (analogicznie jak testy):
    1. Sortowanie statycznej tablicy dziala
    2. Dziala z kontenerami standardowymi (na przykladzie `std::vector`)
    3. Dziala z nasza lista - specjalizacja
    4. Specjalizacja sortowania dla tablicy `char[][]`
       jesli dziala dla tablicy slów skladajacych sie wylacznie z DUZYCH LITER
    5. Jw. ale powinno dzialac z pominieciem wielkosci liter.
3. Tym razem kod ma się kompilować z flagami:
`-Wall -Wextra -pedantic -Werror`
dla hardcorów jeszcze:  `-Weffc++`
______________
Uwaga:
--------
1. Konieczne może się okazać zrobienie dwóch wersji metod begin/end -jedna stała, druga nie.
2. Należy zdefiniować dwie wersje iteratorów - stały `const_iterator` i zwykły `iterator` jako klasy zagnieżdżone.
    1. Informacje [jak zdefiniować własny iterator](https://medium.com/geekculture/iterator-design-pattern-in-c-42caec84bfc)
       lub [2](https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators).
       Najprościej jest dziedziczyć po `std::iterator`, niemniej jednak jest to deprecated.
3. Szablony muszą być zdefiniowane w całości w pliku nagłówkowym,
   jednakże proszę aby definicje metod dłuższych niż 1-linijkowe były pod klasą.
4. Można użyć `std::sort` lub `std::stable_sort` - tylko trzeba wiedzieć gdzie i jak.
**/

#include "myList.h"
#include "mySorting.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <type_traits>
#include <iterator>
#include <deque>
#include <typeinfo>

#ifndef _MSC_VER

#   include <cxxabi.h>

#endif

#include <memory>
#include <string>
#include <cstdlib>

template<class T>
std::string

type_name() {
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void (*)(void *)> own
            (
#ifndef _MSC_VER
            abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                nullptr, nullptr),
#else
            nullptr,
#endif
            std::free
    );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

bool IsOdd(int i) { return ((i % 2) == 1); }

int main() {
    MyList<int> list1;

    list1.push_front(2);
    list1.push_front(1);
    list1.push_front(2);
    list1.push_front(3);
    list1.push_front(7);
    list1.push_front(2);
    list1.push_front(2);

    std::cout << list1;
    std::cout << "size: " << list1.size() << "\n";

    list1.remove(2);

    std::cout << list1;
    std::cout << "size: " << list1.size() << "\n";

    const auto counterWords = std::count_if(list1.begin(), list1.end(), IsOdd);
    std::cout << "counterWords = " << counterWords << "\n";

    std::vector<int> v1{-1, 3, 5, -8, 0};

    mySort(v1);

    for (auto elem: v1) {
        std::cout << elem << " ";
    }
    std::cout << "\n";


    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    mySort(arr);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";


    const std::vector<int> sortedValues = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};

    MyList<int> l;
    std::copy(sortedValues.begin(), sortedValues.end(), std::front_inserter(l));

    mySort(l);

    std::cout << l;


    char words[][20] = {"Bazyli", "lubi", "Malfreda", "ktorego", "poznal", "u", "Stoigniewa", "stojacego", "przy",
                        "barze", "mamy"};

    mySort(words);

    for (auto &word: words) {
        std::cout << word << " ";
    }
    std::cout << "\n";
}
