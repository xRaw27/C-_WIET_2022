#include <iostream>
#include <cstring>
#include <cctype>
#include <utility>

#include "fraction.h"

int Fraction::removedFractions_ = 0;

Fraction::Fraction(int numerator, int denominator, std::string name) : fractionName(std::move(name)) {
    this->numerator = numerator;
    this->denominator = denominator;
}

void Fraction::print() const {
    std::cout << numerator << "/" << denominator << "\n";
}

void Fraction::save(std::ostream &os) const {
    os << numerator << "/" << denominator;
}

void Fraction::load(std::istream &is) {
    std::string str;
    is >> str;

    std::size_t pos = str.find('/');
    numerator = std::stoi(str.substr(0, pos));
    denominator = std::stoi(str.substr(pos + 1));
}
