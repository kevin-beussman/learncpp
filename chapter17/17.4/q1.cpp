#include <iostream>
#include <string>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};
public:
    Fruit(const std::string& name, const std::string& color): m_name{name}, m_color{color}
    {}

    const std::string& getName()
    {
        return m_name;
    }

    const std::string& getColor()
    {
        return m_color;
    }
};

class Apple: public Fruit
{
private:
    double m_fiber{};
public:
    Apple(const std::string& name, const std::string& color, double fiber): Fruit{name, color}, m_fiber{fiber}
    {}

    double getFiber()
    {
        return m_fiber;
    }

    friend std::ostream& operator<<(std::ostream& out, Apple a);
};

class Banana: public Fruit
{
public:
    Banana(const std::string& name, const std::string& color): Fruit{name, color}
    {}

    friend std::ostream& operator<<(std::ostream& out, Banana b);
};

std::ostream& operator<<(std::ostream& out, Apple a)
{
    out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ")";
    return out;
}

std::ostream& operator<<(std::ostream& out, Banana b)
{
    out << "Banana(" << b.getName() << ", " << b.getColor() << ")";
    return out;
}

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}