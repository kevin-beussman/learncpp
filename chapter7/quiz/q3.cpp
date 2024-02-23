#include <iostream>
#include <random>
#include <limits>

void ignoreline()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool playagain()
{
    while (true)
    {
        char userplayagain{ ' ' };
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> userplayagain;
        ignoreline();

        switch (userplayagain)
        {
            case 'y':
                return true;
            case 'n':
                return false;
        }
    }
}

int main()
{
	std::random_device rd;
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // get 8 integers of random numbers from std::random_device for our seed
	std::mt19937 mt{ ss }; // initialize our Mersenne Twister with the std::seed_seq

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution ch100{ 1, 100 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };


    bool keepplaying { true };
    while (keepplaying)
    {
        int answer{ ch100(mt) };

        std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";

        int nguesses{ 1 };
        int usernum{ 0 };
        while (nguesses <= 7)
        {
            std::cout << "Guess #" << nguesses << ":";
            std::cin >> usernum;
            ignoreline();

            if (usernum > answer)
            {
                std::cout << "Your guess is too high.\n";
            }
            else if (usernum < answer)
            {
                std::cout << "Your guess is too low.\n";
            }
            else
            {
                std::cout << "Correct! You win!\n";
                break;
            }

            ++nguesses;
        }
        if (nguesses > 7)
        {
            std::cout << "Sorry, you lose. The correct number was " << answer << ".\n";
        }

        keepplaying = playagain();
    }

	return 0;
}