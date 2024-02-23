#include <iostream>
#include <string>
#include <cassert>

class MyString
{
private:
    std::string m_string{};

public:
    MyString(const std::string& str): m_string{str} {};
    
    MyString operator()(int start, int length);

    friend std::ostream& operator<< (std::ostream& out, const MyString& str);
};

std::ostream& operator<< (std::ostream& out, const MyString& str)
{
    out << str.m_string;
    return out;
}

MyString MyString::operator()(int start, int length)
{
    // assert(start >= 0);
    // assert(start + length <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): Substring is out of range");

    return m_string.substr(start, length);
}

int main()
{
    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}