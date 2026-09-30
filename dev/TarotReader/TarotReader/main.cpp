#include <iostream>
#include "ConsoleColor.h"
int main()
{
	ConsoleColor::Print("The cards are waiting...\n",
		ConsoleColor::Ink::Purple);
	std::cin.get();
	return 0;
}
