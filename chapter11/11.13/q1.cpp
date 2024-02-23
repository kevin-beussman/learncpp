#include<iostream>
#include<string_view>

int main()
{
    std::string_view names[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    
    std::cout << "Enter a name: ";
    std::string u_name {};
    std::cin >> u_name;

    for (const auto& name : names)
    {
        if (name == u_name)
        {
            std::cout << u_name << " was found.\n";
            return 0;
        }
    }
    std::cout << u_name << " was not found.\n";

    return 0;
}