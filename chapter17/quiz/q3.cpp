#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <iostream>
#include <string>
#include <string_view>


int getRandomNumber(int min, int max)
{
  static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) }; // static used for efficiency, so we only calculate this value once
  // evenly distribute the random number across our range
  return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}
class Creature
{
protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_attack{};
    int m_gold{};
public:
    Creature(std::string_view name, char symbol, int health, int attack, int gold):
    m_name{name}, m_symbol{symbol}, m_health{health}, m_attack{attack}, m_gold{gold}
    {}

    const std::string& getName() const { return m_name; }
    auto getSymbol() const { return m_symbol; }
    auto getHealth() const { return m_health; }
    auto getAttack() const { return m_attack; }
    auto getGold() const { return m_gold; }

    void reduceHealth(int damage)
    { m_health -= damage; } //reduces the Creature’s health by an integer amount.
    
    bool isDead()
    { return m_health <= 0; } //returns true when the Creature’s health is 0 or less.
    
    void addGold(int gold)
    { m_gold += gold; } //adds gold to the Creature.
};

class Player: public Creature
{
private:
    int m_level{1};
public:
    Player(std::string_view name): Creature(name, '@', 10, 1, 0)
    {}

    void levelUp()
    {
        ++m_level;
        ++m_attack;
    }
    
    auto getLevel()
    { return m_level; }
    
    bool hasWon() const
    { return m_level >= 20; }
};

class Monster: public Creature
{
public:
    enum Type
    {
        DRAGON,
        ORC,
        SLIME,

        max_types
    };

private:
    static const Creature& getDefaultCreature(Type t)
    {
        static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
            { { "dragon", 'D', 20, 4, 100 },
            { "orc", 'o', 4, 2, 25 },
            { "slime", 's', 1, 1, 10 } }
        };

        return monsterData.at(static_cast<std::size_t>(t));
    }

public:

    Monster(Type t): Creature{ getDefaultCreature(t) }
    {}

    static Monster getRandomMonster()
  {
    int num{ getRandomNumber(0, static_cast<int>(Type::max_types) - 1) };
    return Monster{ static_cast<Type>(num) };
  }
};

void attackPlayer(Player& p, Monster& m)
{
    std::cout << "Monster attacks player for " << m.getAttack() << " damage\n";
    p.reduceHealth(m.getAttack());
}

void attackMonster(Player& p, Monster& m)
{
    std::cout << "Player attacks monster for " << p.getAttack() << " damage\n";
    m.reduceHealth(p.getAttack());
}

void fightMonster(Player& p)
{
    Monster m{ Monster::getRandomMonster() };
    std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";

    std::cout << "(R)un or (F)ight: ";
    char choice{};
    std::cin >> choice;

    if (choice == 'r' || choice == 'R')
    {
        if (getRandomNumber(0,1))
        {
            std::cout << "You escaped!\n";
        }
        else
        {
            std::cout << "Escape failed!\n";
            attackPlayer(p, m);
        }
    }
    else if (choice == 'f' || choice == 'F')
    {
        attackMonster(p, m);
        if (m.isDead())
        {
            p.addGold(m.getGold());
            p.levelUp();
        }
        else
        {
            attackPlayer(p, m);
        }
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    std::rand(); // get rid of first result

    std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player p{ playerName };
	std::cout << "Welcome, " << p.getName() << ".\n";

    while (!(p.isDead()) && !(p.hasWon()))
    {
        fightMonster(p);
    };

    if (p.hasWon())
    {
        std::cout << "You win!";
    }
    else
    {
        std::cout << "You lose!";
    }

	return 0;
}