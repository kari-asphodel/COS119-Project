#include <iostream>
#include <vector>

void Case3()
{
    std::vector<int> scores = { 10, 20, 30 };

    for (int i = 0; i <= scores.size(); i++)
    {
        std::cout << scores[i] << "\n";
    }
}