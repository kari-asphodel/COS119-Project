#include <iostream>
void Case2()
{
    while (true)
    {
        std::cout << "1. Exit\n";

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            std::cout << "Goodbye!\n";
            break;
        }
    }
}