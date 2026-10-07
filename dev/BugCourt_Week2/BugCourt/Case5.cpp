#include <iostream>
#include <vector>
void Case5()
{
    std::vector<std::string> inventory;

    inventory.push_back("Sword");

    inventory.clear();

    if (!inventory.empty())
    {
        std::cout << inventory[0];
    }
}