#ifndef MATRIX_H
#define MATRIX_H

/** @file matrix.h
@brief Przeciążanie operatorów na przykładzie Macierzy:
v 1. Zaimplementuj klasę TwoDimensionMatrix odzwierciedlajaca macierz 2*2, zawierającą:
v    - tablice typu MatrixElement (tzn. int), oraz size (=2)
v    - konstruktory:
v        - bezargumentowy - zerujący wszystkie elementy
v        - kopiujący
v        - przyjmujący jako argument tablicę (const MatrixElement matrix[size][size]) i kopiujący z niej wartości
v    - funkcja składowa do dostępu do elementów (get() zwracająca odpowiedni element
v    - funkcja zwracająca size o nazwie (getSize()), proponuję aby była static constexpr
v 2. Uzupełnij klasy o następujące operacje zdefiniowane poprzez przeciążenie operatorów:
v    - operator przypisania kopiujący (głęboko): operator=()
v    - operatory wypisywania do strumienia (funkcja zewn.) - forma dowolna, byleby wszystkie elementy były w strumieniu
v    - operatory wczytywania z strumienia (funkcja zewn.) - format dla macierzy:
v      { a, b }
v      { c, d }
v      powinno się odbyć:
v      ```
v        a b
v        c d
v      ```
v    - operatory arytmetyczne (stosujące odpowiednie operacje na macierzach):
v        - TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2); // jako funkcja globalna
        - TwoDimensionMatrix& operator*=(MatrixElement number); // metoda klasy
v        - Zadany operator logiczny (metoda klasy):
v          `TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;`
v        - operator tablicowy dostający się po indeksie do pierwszego z wymiarów tablicy (metoda klasy), **proszę pamiętać o wersji const**
v          `MatrixElement* operator[](size_t i);`
v        - operator konwersji do size_t, zwracający to co `getSize()` (metoda klasy),
v    Deklaracja klasy i funkcji globalnych powinna się znaleźć w pliku "matrix.h", natomiast definicje funkcji zewnętrznych i metod klas w pliku źródłowym "matrix.cpp"
____________________________________________________________________________________
## Uwaga:
Wszystkie atrybuty powinny być prywatne, konstruktory i metody - publiczne,
metody większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane
poza klasą, obiekty typów klasowych powinny być w miarę możliwości przekazywane
w argumentach funkcji przez referencję, proszę też stosować słówko "const" w
odpowiednich miejscach.

Mozna tworzyc dowolna ilosc metod pomocniczych, jednakze aby byly one prywatne.
____________________________________________________________________________________
## Punktacja:
Na maksa przejście wszystkich testów
____________________________________________________________________________________
## Najczestrze pytania:
1. Jak ma działać && dla macierzy?
    Wykonująca na każdym z elementów &&, czyli:
    ```
    { 0, 0 }      { 0, 6 }      { 0, 0 }
    {-3, 9 }  &&  { 0, -9 }  =  { 0, 1 }
    ```
2. Jak ma działać operator tablicowy []?
    Operator ten przyjmuje tylko jeden argument (poza this), a chcemy odnieść się w następujący sposób:
    `matrix[row][column]`, dlatego ten operator musi zwrócić matrix[row] typu `MatrixElement*`.
3. Mam operator indeksowania [], a kompilator jakby go nie widzi.
    To najczęstrzy błąd w tym zadaniu - muszą być dwie wersje - jedna zwykła, a druga stała (przydomek `const`)
____________________________________________________________________________________
# Pytania po implementacji ćwiczenia:
@note A. Jaka jest różnica między przeciążaniem operatorów jako metoda klasy vs jako funkcja?
@note B. Których operatorów nie da się przeciążać?
@note C. Wymień operatory mające różną ilość argumentów?
@note D. Jakie konsekwencje będzie miało przeciążanie operatorów logicznych? (chodzi o lazy-evaluation)
**/

#include <iosfwd>

#include "matrixElement.h"


class TwoDimensionMatrix
{
    constexpr static size_t size = 2;

public:
    TwoDimensionMatrix() : matrix{} {};
    TwoDimensionMatrix(const TwoDimensionMatrix &);
    explicit TwoDimensionMatrix(const MatrixElement matrix[size][size]);

    static constexpr size_t getSize() { return size; };
    [[nodiscard]] MatrixElement get(const size_t x, const size_t y) const { return matrix[x][y]; };

    MatrixElement* operator[](size_t);
    const MatrixElement* operator[](size_t) const;
    TwoDimensionMatrix& operator=(const TwoDimensionMatrix &);

    TwoDimensionMatrix& operator*=(MatrixElement);
    TwoDimensionMatrix operator&&(const TwoDimensionMatrix&) const;

    explicit operator size_t() const;

private: // methods:

private: // fields:
    MatrixElement matrix[size][size]{};
};

std::ostream & operator<< (std::ostream&, const TwoDimensionMatrix&);
std::istream & operator>> (std::istream&, TwoDimensionMatrix&);
TwoDimensionMatrix operator+(const TwoDimensionMatrix&, const TwoDimensionMatrix&);


#endif // MATRIX_H
