#include <iostream>
#include <string>
#include <string_view>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()
#include <array>

class Monster
{
public:
    enum class Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types
    };

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hp{};

public:
    Monster(Type type, const std::string& name, const std::string& roar, int hp) :
        m_type{type}, m_name{name}, m_roar{roar}, m_hp{hp}
    {}

    std::string_view getTypeString() const
    {
        switch (m_type)
        {
        case Type::dragon: return "dragon";
        case Type::goblin: return "goblin";
        case Type::ogre: return "ogre";
        case Type::orc: return "orc";
        case Type::skeleton: return "skeleton";
        case Type::troll: return "troll";
        case Type::vampire: return "vampire";
        case Type::zombie: return "zombie";
        default: return "???";
        }
    }

    void print() const
    {
        std::cout << getTypeString();
        // std::cout << m_name << " the " << getTypeString() << " has " << m_hp << " hit points and says " << m_roar << "\n";
    }
};

class MonsterGenerator
{
private:
    static constexpr std::array s_names{"a", "b", "c", "d", "e", "f"};
    static constexpr std::array s_roars{"*hi*", "*how*", "*are*", "*you*", "*im*", "*kev*"};

public:
    static Monster generateMonster()
    {
        return Monster(static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types))), 
            s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], getRandomNumber(1, 100));
    }

    // Generate a random number between min and max (inclusive)
    // Assumes srand() has already been called
    static int getRandomNumber(int min, int max)
    {
        static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };  // static used for efficiency, so we only calculate this value once
        // evenly distribute the random number across our range
        return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
    }
};

int main()
{
    // Monster skeleton{ Monster::Type::skeleton, "Bones", "*rattle*", 4 };
    // skeleton.print();

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // If using Visual Studio, discard first random value

    Monster m{ MonsterGenerator::generateMonster() };
	m.print();

    return 0;
}