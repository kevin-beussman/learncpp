#include <iostream>

int factorial(int num)
{
    if (num <= 1)
        return 1;
    else
        return num * factorial(num - 1);
}

int main()
{
    std::cout << "1! = " << factorial(1) << "\n";
    std::cout << "5! = " << factorial(5) << "\n";
    std::cout << "7! = " << factorial(7) << "\n";

    return 0;
}