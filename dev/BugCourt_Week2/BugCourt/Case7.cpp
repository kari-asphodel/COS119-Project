#include <iostream>
void Case7()
{
    int dragons = 5;

    dragons -= 10;

    if (dragons < 0)
    {
        dragons = 0;
    }

    std::cout << dragons;
}