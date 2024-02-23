#include <iostream>
#include <string_view>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime
};

struct Monster
{
    MonsterType type{};
    std::string_view name{};
    int health;
};

void printMonster(Monster m)
{   
    std::string_view montype{};
    switch (m.type)
    {
    case MonsterType::ogre:         montype = "ogre"; break;
    case MonsterType::dragon:       montype = "dragon"; break;
    case MonsterType::orc:          montype = "orc"; break;
    case MonsterType::giant_spider: montype = "giant_spider"; break;
    case MonsterType::slime:        montype = "slime"; break;
    default:                        montype = "???"; break;
    }
    std::cout << "This " << montype << " is named " << m.name << " and has " << m.health << " health.\n";
}

int main()
{
    Monster ogre1 {MonsterType::ogre, "Torg", 145};
    printMonster(ogre1);

    Monster slime1 {MonsterType::slime, "Blurp", 23};
    printMonster(slime1);
    return 0;
}