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
public:
    Apple(const std::string& color): Fruit{"apple", color}
    {}
};

class Banana: public Fruit
{
public:
    Banana(): Fruit{"banana", "yellow"}
    {}
};

class GrannySmith: public Apple
{
public:
    GrannySmith(): Apple("green")
    {}

    std::string getName()
    {
        return "granny smith " + Apple::getName();
    }
};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}
