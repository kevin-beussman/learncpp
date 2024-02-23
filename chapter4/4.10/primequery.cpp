#include <iostream>

bool isPrime(int x)
{
    if (x == 2)
        return true;
    else if (x == 3)
        return true;
    else if (x == 5)
        return true;
    else if (x == 7)
        return true;
    
    return false;
}

int main()
{
    std::cout << "Enter a number between 0 and 9: ";
    int num{};
    std::cin >> num;
    if (isPrime(num))
        std::cout << num << " is prime." << std::endl;
    else
        std::cout << num << " is not prime." << std::endl;

    return 0;
}