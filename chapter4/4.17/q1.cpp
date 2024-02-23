#include<iostream>
#include<string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string fullname{};
    std::getline(std::cin >> std::ws, fullname);

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    std::cout << "Your age + length of name is: " << age + static_cast<int>(fullname.length()) << std::endl;
    return 0;
}