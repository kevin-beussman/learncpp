#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";

    int num{0};
    // num << std::cin;
    std::cin >> num;

    std::cout << "Double your number: " << num * 2 << "\n";
    
    std::cout << "Triple your number: " << num * 3 << "\n";
 
    return 0;
}
