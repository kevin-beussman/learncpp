#include <iostream>

class Average
{
private:
    double value{};
    int numsamples{};
public:
    friend std::ostream& operator<<(std::ostream& out, const Average& avg);
    friend Average& operator+=(Average& a1, int newnum);
};

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
    out << avg.value;
    return out;
}

Average& operator+=(Average& a1, int newnum)
{
    double newtot = a1.value * a1.numsamples + newnum;
    a1.numsamples += 1;
    a1.value = newtot / a1.numsamples;
    return a1;
}

int main()
{
	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}