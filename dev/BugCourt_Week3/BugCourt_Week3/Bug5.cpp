#include <iostream>

int CreateScore()
{
    int score = 100;

    return score;
}

int main()
{
    int score = CreateScore();

    std::cout << score << '\n';

    return 0;
}