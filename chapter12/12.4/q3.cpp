#include <iostream>
#include <string>

void printBinary(uint32_t num)
{
    if (num < 2)
    {
        std::cout << num;
        return;
    }
    
    printBinary(num / 2);
    if (num % 2) // remainder is 0
        std::cout << 1;
    else
        std::cout << 0;
}

int main()
{
    std::cout << "Enter an integer: ";
    int u_num{};
    std::cin >> u_num;

    printBinary(u_num);

    return 0;
}