#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
private:
    std::vector<StudentGrade> m_map{};
public:
    char& operator[] (std::string_view u_name);
};

char& GradeMap::operator[] (std::string_view u_name)
{
    auto is_name = [&](const auto& u){ return u.name == u_name; };
    auto existingStudent{ std::find_if(m_map.begin(), m_map.end(), is_name) };
    if (existingStudent != m_map.end())
    {
        return existingStudent->grade;
    }
    else
    {
        m_map.push_back(StudentGrade{std::string{u_name}});
        return m_map.back().grade;
    }
}

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}