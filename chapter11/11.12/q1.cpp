#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::cout << "How many names do you want to enter?: ";
    int u_numnames{};
    std::cin >> u_numnames;

    auto* names{ new std::string[u_numnames]{} };
    for (int ind{0}; ind != u_numnames; ++ind)
    {
        std::cout << "Enter name " << ind + 1 << ": ";
        std::cin >> names[ind];
    }

    std::sort(names, names + u_numnames);


    std::cout << "Here is the sorted names list:\n";
    for (int ind{0}; ind != u_numnames; ++ind)
    {
        std::cout << names[ind] << "\n";
    }

    return 0;
}