#include <iostream>
#include <vector>

void BonusRound()
{
    std::vector<std::string> items = { "Sword", "Shield", "Potion" };

    std::cout << items[3];
    // A. Sword
    // B. Shield
    // C. Potion
    // D. Out-of-bounds problem - THIS ONE
}