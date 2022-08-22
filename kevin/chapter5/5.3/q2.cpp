#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int usernum { };
    std::cin >> usernum;

    std::cout << usernum << " is ";
    if (usernum % 2)
        std::cout << "odd" << std::endl;
    else
        std::cout << "even" << std::endl;
    
    return 0;
}