#include <iostream>

int main()
{

    char abet { 'a' };
    while (abet <= 'z')
    {
        std::cout << abet << ' ' << static_cast<int>(abet) << std::endl;
        ++abet;
    }

    return 0;
}