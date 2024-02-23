#include <iostream>

class IntPair
{
public:
    int m_in1{};
    int m_in2{};

    void set(int u_in1, int u_in2)
    {
        m_in1 = u_in1;
        m_in2 = u_in2;
    }

    void print()
    {
        std::cout << "Pair(" << m_in1 << ", " << m_in2 << ")\n";
    }
};

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}