#include <iostream>
//#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "shapecomposite.h"
#include "memory"


/**
  @mainpage Laboratorium 4 - rysowanie kształtów

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
     konkurs (context), problem, oraz jezyk programowania.
     prosze zalaczyc pliki:
        - @ref circle.h i @ref circle.cpp
        - @ref rectangle.h i @ref rectangle.cpp
        - @ref shape.h
        - @ref shapecomposite.h i @ref shapecomposite.cpp
        - proszę nie załączać: @ref stage.h i @ref stage.cpp
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
7. Punkty beda odejmowane za wycieki pamieci (jest podpiety `valgrind`)
8. Niewykluczone jest sprawdzanie reczne - zaleznie od prowadzacego dana grupe.

Tresc do implementacji - szukaj w plikach *.h
**/

using namespace Shapes;
using namespace std;

int main()
{
    Rectangle rect(0, 0, 4, 4);
    Circle circle(0, 0, 4);

//    cout << rect.essa() << endl;
    Shape* shape1 = &rect;
    Shape* shape2 = &circle;

//    cout << shape1->isIn(3, 3) << endl;
//    cout << shape2->isIn(3, 3) << endl;
//    cout << shape2->isIn(2, 2) << endl;

    std::shared_ptr<Shape> p1(new Rectangle(0, 0, 4, 4));
    std::shared_ptr<Shape> p2(new Circle(0, 0, 4));

    ShapeComposite comp(p1, p2, ShapeOperation::SUM);

    Shape* shape3 = &comp;
    cout << shape3->isIn(3, 3) << endl;
}
