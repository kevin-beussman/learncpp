#include<iostream>

void printHeight(double startingheight, int time)
{
    constexpr double gravity {9.8};
    double distancefallen { gravity * time * time / 2.0 };
    
    if (distancefallen > startingheight)
        std::cout << "At " << time << " seconds, the ball is on the ground." << std::endl;
    else
        std::cout << "At " << time << " seconds, the ball is at height: " << startingheight - distancefallen << " meters" << std::endl;
}

int main()
{

    std::cout << "Enter the height of the tower in meters: ";
    double height { };
    std::cin >> height;

    printHeight(height, 0);
    printHeight(height, 1);
    printHeight(height, 2);
    printHeight(height, 3);
    printHeight(height, 4);
    printHeight(height, 5);

    return 0;
}