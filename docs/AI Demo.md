
``` cpp
#include <iostream>
#include <string>

int main()
{
    std::string input;

    std::cout << "1. Play\n";
    std::cout << "2. Exit\n";
    std::cout << "Choice: ";

    std::getline(std::cin, input);

    if (input == "1")
    {
        std::cout << "Starting game...\n";
    }
    else if (input == "2")
    {
        std::cout << "Goodbye!\n";
    }
    else
    {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
```