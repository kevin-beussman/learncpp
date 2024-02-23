#include <iostream>

int main()
{
    std::cout << "Enter the first number: ";
    int smaller {};
    std::cin >> smaller;

    std::cout << "Enter the second number: ";
    int larger {};
    std::cin >> larger;

    if (larger < smaller)
    {
        std::cout << "Swapping the values" << std::endl;
        int temp {smaller};
        smaller = larger;
        larger = temp;
    }

    std::cout << "The smaller value is " << smaller << std::endl;

    std::cout << "The larger value is " << larger << std::endl;


    return 0;
}