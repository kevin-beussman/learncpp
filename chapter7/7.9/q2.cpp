#include <iostream>

int sumTo(int value)
{
    int totalsum { 0 };
    for (int i{ 1 }; i <= value; i += 1)
    {
        totalsum += i;
    }
    return totalsum;
}

int main()
{
    std::cout << "Enter a number: ";
    int uservalue { 0 };
    std::cin >> uservalue;

    std::cout << "Sum of numbers from 1 to " << uservalue << ": " << sumTo(uservalue) << std::endl;
}