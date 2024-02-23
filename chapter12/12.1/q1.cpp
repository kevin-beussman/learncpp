#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int getInteger()
{
    std::cout << "Enter an integer: ";
    int u_in{};
    std::cin >> u_in;
    return u_in;
}

char getOperation()
{
    char u_op{};
    do
    {
        std::cout << "Enter an operator <+,-,*,/>: ";
        std::cin >> u_op;
    } while ((u_op != '+' && u_op != '-' && u_op != '*' && u_op != '/'));
    
    return u_op;
}

int add(int a, int b)
{
    return (a + b);
}

int subtract(int a, int b)
{
    return (a - b);
}

int multiply(int a, int b)
{
    return (a * b);
}

int division(int a, int b)
{
    return (a / b);
}

ArithmeticFunction getArithmeticFunction(char op)
{
    switch(op)
    {
        case '+': return &add;
        case '-': return &subtract;
        case '*': return &multiply;
        case '/': return &division;
    }

    return nullptr;

}

int main()
{

    int u_in1 = getInteger();
    char u_op = getOperation();
    int u_in2 = getInteger();

    ArithmeticFunction opfcn = getArithmeticFunction(u_op);

    std::cout << u_in1 << ' ' << u_op << ' ' << u_in2 << " = " << opfcn(u_in1, u_in2) << "\n";

    return 0;
}