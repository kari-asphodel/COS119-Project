#include <iostream>
void Case10()
{
    std::cout << "Enter a number: ";
    std::string input;
    std::getline(std::cin, input);
    try
    {
        int choice = std::stoi(input);
    }
    catch (...)
    {
        std::cout << "You didn't enter correctly."
    }

    std::cout << "You chose: " << choice;
}