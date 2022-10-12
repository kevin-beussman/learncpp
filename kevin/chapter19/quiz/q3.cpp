/* Does not compile, my version nor the author's */

#include <iostream>
#include <string>

template <typename T>
class StringValuePair
{
private:
    std::string m_first;
    T m_second{};

public:
    StringValuePair(const std::string& first, const T& second): m_first{first}, m_second{second}{};

    std::string& first() { return m_first; }
    T& second() { return m_second; }
    const std::string& first() const { return m_first; }
    const T& second() const { return m_second; }
};

int main()
{
	StringValuePair<int> svp { static_cast<std::string>("Hello"), 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}

// #include <iostream>
// #include <string>

// template <typename T, typename S>
// class Pair
// {
// private:
// 	T m_x {};
// 	S m_y {};

// public:
// 	Pair(const T& x, const S& y)
// 		: m_x { x } , m_y { y }
// 	{
// 	}

// 	T& first() { return m_x; }
// 	S& second() { return m_y; }
// 	const T& first() const { return m_x; }
// 	const S& second() const { return m_y; }
// };

// template <typename S>
// class StringValuePair : public Pair<std::string, S>
// {
// public:
// 	StringValuePair(const std::string& key, const S& value)
// 		: Pair<std::string, S> { key, value }
// 	{
// 	}
// };

// int main()
// {
// 	StringValuePair<int> svp { "Hello", 5 };
// 	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

// 	return 0;
// }