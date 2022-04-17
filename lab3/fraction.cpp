#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric> // std::gcd

#include "fraction.h"

Fraction::Fraction(int numerator, int denominator) : numerator_{numerator}, denominator_{denominator} {
    if (denominator == 0) {
        throw std::invalid_argument("denominator cannot be zero");
    }
}

void Fraction::setDenominator(int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("denominator cannot be zero");
    }
    this->denominator_ = denominator;
}

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    Fraction fraction_sum;
    int numerator = f1.numerator() * f2.denominator() + f2.numerator() * f1.denominator();
    int denominator = f1.denominator() * f2.denominator();
    int gcd = std::gcd(numerator, denominator);

    fraction_sum.setNumerator(numerator / gcd);
    fraction_sum.setDenominator(denominator / gcd);

    return fraction_sum;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    Fraction fraction_product;
    int numerator = f1.numerator() * f2.numerator();
    int denominator = f1.denominator() * f2.denominator();
    int gcd = std::gcd(numerator, denominator);

    fraction_product.setNumerator(numerator / gcd);
    fraction_product.setDenominator(denominator / gcd);

    return fraction_product;
}

