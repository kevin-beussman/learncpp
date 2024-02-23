#include <iostream>

struct Fraction
{
    int numerator {};
    int denominator {};
};

Fraction getUserInput()
{
    Fraction frac;
    std::cout << "Enter a value for the numerator: ";
    std::cin >> frac.numerator;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> frac.denominator;
    return frac;
}

Fraction multiplyFractions(Fraction f1, Fraction f2)
{
    return {f1.numerator * f2.numerator, f1.denominator * f2.denominator};
}

void printFraction(Fraction frac)
{
    std::cout << "Your fractions multiplied together: " << frac.numerator << "/" << frac.denominator << "\n";
}

int main()
{
    Fraction frac1 = getUserInput();
    Fraction frac2 = getUserInput();

    printFraction(multiplyFractions(frac1, frac2));
    return 0;
}