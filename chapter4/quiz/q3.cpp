#include<iostream>

double getNum()
{
    std::cout << "Enter a double value: ";
    double num {};
    std::cin >> num;
    return num;
}

void doMath(double n1, double n2, char op)
{
    if (op == '+')
        std::cout << n1 << " " << op << " " << n2 << " is " << n1 + n2 << std::endl;
    else if (op == '*')
        std::cout << n1 << " " << op << " " << n2 << " is " << n1 * n2 << std::endl;
    else if (op == '-')
        std::cout << n1 << " " << op << " " << n2 << " is " << n1 - n2 << std::endl;
    else if (op == '/')
        std::cout << n1 << " " << op << " " << n2 << " is " << n1 / n2 << std::endl;
}

int main()
{

    double num1{ getNum() };
    double num2{ getNum() };

    std::cout << "Enter one of the following: +, -, *, or /: ";
    char operation {};
    std::cin >> operation;

    doMath(num1, num2, operation);

    return 0;
}