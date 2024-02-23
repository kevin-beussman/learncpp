#include <iostream>

int calculate(int a, int b, char op)
{
    switch(op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return a % b;
        default:
            std::cerr << "Invalid operator.\n";
            return 0;
    }
}

int main()
{
    std::cout << "Enter first integer: ";
    int num1 { };
    std::cin >> num1;

    std::cout << "Enter second integer: ";
    int num2 { };
    std::cin >> num2;

    std::cout << "Enter mathematical operator: ";
    char oper { };
    std::cin >> oper;

    std::cout << "Answer is: " << calculate(num1, num2, oper) << std::endl;

    return 0;
}