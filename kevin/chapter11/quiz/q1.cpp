#include <iostream>
#include <array>
#include <numeric>

enum Item
{
    health_potions,
    torchs,
    arrows
};

int countTotalItems(std::array<int, 3> player)
{
    return std::reduce(player.begin(), player.end());
}

int main()
{
    std::array<int, 3> playerInventory{2, 5, 10};

    std::cout << "Player has " << countTotalItems(playerInventory) << " items.\n";
    std::cout << "Player has " << playerInventory[torchs] << " torches.\n";

    return 0;
}