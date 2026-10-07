#include <iostream>
void Case9()
{
    Potion* potion = new Potion();

    potion->drink();

    delete potion;
    potion = nullptr;
}