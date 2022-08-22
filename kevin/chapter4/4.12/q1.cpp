#include <iostream>

int main()
{
    std::cout << "Enter a single character: ";
    char userchar {};
    std::cin >> userchar;

    std::cout << "You entered \'" << userchar << "\', which has ASCII code " << static_cast<int>(userchar) << "." << std::endl;
    return 0;
}