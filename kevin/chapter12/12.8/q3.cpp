#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

enum GuessResult
{
    correct,
    incorrect,
    completed
};

std::vector<int> createSquares(int start, int count)
{
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution multiplier{ 2, 4 };
    int m = multiplier(mt);

    std::vector<int> squares(count);

    for (int i{0}; i < count; ++i)
    {
        squares[i] = (start + i)*(start + i)*m;
    }

    std::cout << "I generated " << count << " square numbers. Do you know what each number is after multiplying it by " << m << "?\n> ";

    return squares;
}

GuessResult userGuess(std::vector<int>& squares, int userguess)
{
    auto found { std::find(squares.begin(), squares.end(), userguess) };

    if (found != squares.end())
    {
        squares.erase(found);
    }
    else
    {
        std::cout << userguess << " is wrong!";

        auto closest{std::min_element(squares.begin(), squares.end(), [&](const auto& a, const auto& b){
            return ((abs(a - userguess) < abs(b - userguess)));
        })};

        if (abs(*closest - userguess) <= 4)
        {
            std::cout << " Try " << *closest << " next time.\n";
        }
        else
        {
            std::cout << "\n";
        }
        return GuessResult::incorrect;
    }

    if (std::size(squares) == 0)
    {
        std::cout << "Nice! You found all numbers, good job!\n";
        return GuessResult::completed;
    }
    else
    {
        std::cout << "Nice! " << std::size(squares) << " number(s) left.\n> ";
        return GuessResult::correct;
    }

}

int main()
{
    std::cout << "Start where?: ";
    int u_start{};
    std::cin >> u_start;

    std::cout << "How many?: ";
    int u_count{};
    std::cin >> u_count;

    auto squares { createSquares(u_start, u_count) };

    GuessResult result{};
    do
    {
        int u_guess{};
        std::cin >> u_guess;
        result = userGuess(squares, u_guess);
    } while (result == GuessResult::correct);

    return 0;
}