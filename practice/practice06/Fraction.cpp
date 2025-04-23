#include "Fraction.h"

Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n, int d) : num(n) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    den = d;
    simplify();
}

int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return den;
}

void Fraction::setNumerator(int n) {
    num = n;
    simplify();
}

void Fraction::setDenominator(int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    den = d;
    simplify();
}

void Fraction::simplify() {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero");

    int a = num, b = den;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;
    num /= gcd;
    den /= gcd;

    // Ensure denominator is positive
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int n = lhs.num * rhs.den + rhs.num * lhs.den;
    int d = lhs.den * rhs.den;
    return Fraction(n, d);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int n = lhs.num * rhs.den - rhs.num * lhs.den;
    int d = lhs.den * rhs.den;
    return Fraction(n, d);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.num, lhs.den * rhs.den);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.num == 0) throw std::invalid_argument("Cannot divide by zero");
    return Fraction(lhs.num * rhs.den, lhs.den * rhs.num);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.num << "/" << f.den;
    return os;
}
