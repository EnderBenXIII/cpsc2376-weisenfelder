#include "MixedFraction.h"

MixedFraction::MixedFraction(int w, int n, int d)
    : Fraction(n + w * d, d), whole(w) {}

MixedFraction::MixedFraction(const Fraction& f) : Fraction(f) {
    whole = getNumerator() / getDenominator();
}

std::ostream& operator<<(std::ostream& os, const MixedFraction& mf) {
    int n = mf.getNumerator();
    int d = mf.getDenominator();
    int whole = n / d;
    int remainder = abs(n % d);

    if (remainder == 0)
        os << whole;
    else if (whole == 0)
        os << remainder << "/" << d;
    else
        os << whole << " " << remainder << "/" << d;

    return os;
}
