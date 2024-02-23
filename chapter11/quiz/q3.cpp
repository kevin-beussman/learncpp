#include <iostream>

void swap(int& a, int& b)
{
    int temp{b};
    b = a;
    a = temp;
}

int main()
{
    int a = 5;
    int b = 3;

    std::cout << "(a, b) is (" << a << ", " << b << ")\n";

    swap(a, b);

    std::cout << "(a, b) is (" << a << ", " << b << ")\n";

    return 0;
}