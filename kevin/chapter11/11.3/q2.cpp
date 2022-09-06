#include <iostream>
#include <limits>

int getUserNum()
{
    bool input_success{false};
    int x{};
    while (!input_success)
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> x;
        if (std::cin.fail() || (x < 1 || x > 9))
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
        }
        else input_success = true;
    }
    return x;
}

int main()
{
    int usernum = getUserNum();

    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    int userind{};
    for (int i{0}; i < std::size(array); ++i)
    {
        if (i > 0) std::cout << " ";
        std::cout << array[i];
        if (array[i] == usernum) userind = i;
    }
    std::cout << "\nThe number " << usernum << " has index " << userind << "\n";

    return 0;
}