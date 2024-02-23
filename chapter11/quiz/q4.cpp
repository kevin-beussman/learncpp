#include <iostream>

void printStr(const char* str)
{
    while (*str)
    {
        std::cout << *str;
        ++str;
    }
}

int main()
{
    const char* teststr{"Hello, world!"};
    printStr(teststr);
    return 0;
}