#include <iostream>
#include "io.hpp"

int readNumber()
{
    std::cout<<"Enter an integer\n";
    int integer{};
    std::cin>>integer;
    return integer;
}

void writeAnswer(int ans)
{
    std::cout<<"Sum: "<<ans<<'\n';
}