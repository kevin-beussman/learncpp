#include <iostream>

int readNumber();
void writeAnswer(int ans);

int main()
{
    int int1{readNumber()};
    int int2{readNumber()};
    writeAnswer(int1+int2);
    return 0;
}