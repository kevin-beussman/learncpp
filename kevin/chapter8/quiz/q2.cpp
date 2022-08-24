#include <iostream>

using radunit_t = double;
using degunit_t = double;

namespace constants
{
    inline constexpr double pi { 3.14159 };
}

radunit_t convertToRadians(degunit_t degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    degunit_t degrees{};
    std::cin >> degrees;

    radunit_t radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}