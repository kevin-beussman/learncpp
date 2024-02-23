#include "io.hpp"
#include <iostream>

int readNumber()
{
    std::cout << "Input a number: ";
    int num{};
    std::cin >> num;
    return num;
}

void writeAnswer(int x)
{
    std::cout << "Added is " << x << std::endl;
}