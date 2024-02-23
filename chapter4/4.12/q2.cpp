#include <iostream>

int printascii(int n)
{
    return n;
}

int main()
{
    std::cout << "Enter a single character: ";
    char userchar {};
    std::cin >> userchar;

    std::cout << "You entered \'" << userchar << "\', which has ASCII code " << printascii(userchar) << "." << std::endl;
    return 0;
}