#include <iostream>

void doubleNumber(int num)
{
    std::cout << num << " doubled is " << 2 * num << std::endl;
}

int main()
{
    std::cout << "Please input a number: ";
    int inputnum{};
    std::cin >> inputnum;

    doubleNumber(inputnum);
    return 0;
}