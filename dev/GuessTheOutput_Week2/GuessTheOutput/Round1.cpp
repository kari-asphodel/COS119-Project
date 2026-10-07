#include <iostream>

void Round1()
{
    int total = 0;

    for (int i = 1; i <= 3; i++)
    {
        total += i;
    }

    std::cout << total;
    // A. 3
    // B. 6 - THIS ONE 
    // C. 9
    // D. The Loop Has Betrayed Us
}