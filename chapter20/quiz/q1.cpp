#include <iostream>
#include <stdexcept>

class Fraction
{
private:
    int m_num{};
    int m_den{};
public:
    Fraction(int num, int den) : m_num{num}, m_den{den}{
        if (den <= 0)
            throw std::runtime_error("Fraction: Denominator cannot be zero.");
            // throw "Fraction: Denominator cannot be zero.";
    }
};

int main()
{
    std::cout << "Enter numerator: ";
    int u1{};
    std::cin >> u1;

    std::cout << "Enter denominator: ";
    int u2{};
    std::cin >> u2;

    try
    {
        Fraction frac {u1, u2};
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}