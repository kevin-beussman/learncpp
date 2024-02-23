#include <iostream>
#include <numeric>

class Fraction
{
private:
    int numerator{};
    int denominator{};
public:
    Fraction(int num=0, int denom=1): numerator{num}, denominator{denom} {
        (*this).reduce();
    }

    void print()
    {
        std::cout << numerator << "/" << denominator << "\n";
    }

    void reduce()
    {
        int gcd{std::gcd(numerator, denominator)};
        numerator /= gcd;
        denominator /= gcd;
    }

    friend Fraction operator*(const Fraction& frac, const int integer);
    friend Fraction operator*(const int integer, const Fraction& frac);
    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2);
};

Fraction operator*(const Fraction& frac, const int integer)
{
    return Fraction{frac.numerator * integer, frac.denominator};
}

Fraction operator*(const int integer, const Fraction& frac)
{
    return Fraction{frac.numerator * integer, frac.denominator};
}

Fraction operator*(const Fraction& frac1, const Fraction& frac2)
{
    return Fraction{frac1.numerator * frac2.numerator, frac1.denominator * frac2.denominator};
}

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}
