#include <iostream>
void Case6()
{
    int health = 50;

    while (health < 100)
    {
        std::cout << "Healing...\n";
        health += 10;
    }
}