#include <iostream>

int readNumber()
{
    std::cout<<"Enter an integer\n";
    int integer{};
    std::cin>>integer;
    return integer;
}

void writeAnswer(int ans)
{
    std::cout<<"Sum: "<<ans;
}

int main()
{
    int int1{readNumber()};
    int int2{readNumber()};
    writeAnswer(int1+int2);
    return 0;
}