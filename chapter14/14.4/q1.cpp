#include <iostream>
#include <numeric>
#include <limits>

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
    friend std::ostream& operator<< (std::ostream& out, const Fraction& frac);
    friend std::istream& operator>> (std::istream& in, Fraction& frac);
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

std::ostream& operator<< (std::ostream& out, const Fraction& frac)
{
    out << frac.numerator << "/" << frac.denominator;

    return out;
}

std::istream& operator>> (std::istream& in, Fraction& frac)
{
    in >> frac.numerator;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
    in >> frac.denominator;

    return in;
}

int main()
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

	return 0;
}
