#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student
{
    std::string name{};
    int grade{};
};

Student getStudent()
{
    Student newStudent;
    std::cout << "Enter student name: ";
    std::cin >> newStudent.name;

    std::cout << "Enter " << newStudent.name << "'s grade: ";
    std::cin >> newStudent.grade;

    return newStudent;
}

int main()
{
    std::cout << "How many students do you want to enter?: ";
    int u_numstudents {};
    std::cin >> u_numstudents;

    std::vector<Student> students(u_numstudents);
    for (int istudent{0}; istudent < u_numstudents; ++istudent)
    {
        students[istudent] = getStudent();
    }

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b){return (a.grade > b.grade);});

    for (const auto& student : students)
    {
        std::cout << student.name << " has grade " << student.grade << ".\n";
    }

    return 0;
}