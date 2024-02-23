#include <iostream>
#include <utility>

int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    bool madeswap{};
    for (int iter{0}; iter < (std::size(array) - 1); ++iter)
    {
        madeswap = false;
        for (int i{0}; i < (std::size(array) - iter - 1); ++i)
        {
            if (array[i+1] < array[i])
            {
                std::swap(array[i], array[i+1]);
                madeswap = true;
            }
        }
        if (!madeswap)
        {
            std::cout << "Early termination on iteration " << iter + 1 << "\n";
            break;
        }
    }

    for (int i{0}; i < std::size(array); ++i)
    {
        if (i > 0) std::cout << " ";
        std::cout << array[i];
    }
    std::cout << "\n";

    return 0;
}