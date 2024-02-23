#include <array>
#include <iostream>

class Stack
{
    std::array<int, 10> m_intarray;
    int m_int {};

public:
    void reset()
    {
        m_int = 0;
    }

    bool push(int a)
    {
        if (m_int > m_intarray.size())
            return false;
        
        m_intarray[m_int++] = a;
        return true;
    }

    bool pop()
    {
        if (m_int == 0)
            return false;
        
        --m_int;
        return true;
    }

    void print()
    {
        std::cout << "( ";
        for (int ind{0}; ind < m_int; ++ind)
        {
            std::cout << m_intarray[ind] << " ";
        }
        std::cout << ")\n";
    }
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}