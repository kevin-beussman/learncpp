#include "io.hpp"

int main()
{
    int int1{readNumber()};
    int int2{readNumber()};
    writeAnswer(int1+int2);
    return 0;
}