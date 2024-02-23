#include <iostream>
#include <string_view>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck
};

constexpr std::string_view getAnimalName(Animal a)
{
    switch (a)
    {
    case Animal::pig:       return "pig";
    case Animal::chicken:   return "chicken";
    case Animal::goat:      return "goat";
    case Animal::cat:       return "cat";
    case Animal::dog:       return "dog";
    case Animal::duck:      return "duck";
    default:        return "error: unknown animal";
    }
}

void printNumberOfLegs(Animal a)
{

    int numlegs { 0 };
    switch (a)
    {
    case Animal::pig:       numlegs = 4; break;
    case Animal::chicken:   numlegs = 2; break;
    case Animal::goat:      numlegs = 4; break;
    case Animal::cat:       numlegs = 4; break;
    case Animal::dog:       numlegs = 4; break;
    case Animal::duck:      numlegs = 2; break;
    default:        std::cout << "error: unknown animal\n"; return;
    }
    std::cout << "A " << getAnimalName(a) << " has " << numlegs << " legs.\n";
}

int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);
    return 0;
}