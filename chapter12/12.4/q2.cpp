#include <iostream>

int digitSum(int num)
{
    if (num < 10)
        return num;

    int curdigit{ num % 10 };
    return curdigit + digitSum((num - curdigit)/10);
}

int main()
{

    std::cout << "Digitsum of 93427 = " << digitSum(93427) << "\n";
    return 0;
}