#include <iostream>

int main()
{
    // outer loops between 1 and 5
    int outer{ 5 };
    while (outer >= 1)
    {
        // For each iteration of the outer loop, the code in the body of the loop executes once

        // inner loops between 1 and outer
        int inner{ 1 };
        while (inner <= outer)
        {
            std::cout << inner << ' ';
            ++inner;
        }

        // print a newline at the end of each row
        std::cout << '\n';
        --outer;
    }

    return 0;
}