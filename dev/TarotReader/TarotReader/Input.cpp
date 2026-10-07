#include "Input.h"
#include "ConsoleColor.h"
#include <iostream>
#include <stdexcept>
#include <string>

int Input::GetNumber(const std::string& prompt, int min, int max)
{
	while (true)
	{
		ConsoleColor::Print(prompt, ConsoleColor::Ink::Yellow);
		std::string input;
		std::getline(std::cin, input);
		try
		{
			int number = std::stoi(input);
			if (number >= min && number <= max)
			{
				return number;
			}
			ConsoleColor::Print("That number is outside the available choices.\n", ConsoleColor::Ink::Red);
		}
		catch (...)
		{
			ConsoleColor::Print("That number is outside the available choices.\n", ConsoleColor::Ink::Red);
		}
	}
}

std::string Input::GetString(const std::string& prompt)
{
	while (true)
	{
		ConsoleColor::Print(prompt, ConsoleColor::Ink::Yellow);

		std::string input;
		std::getline(std::cin, input);
		if (!input.empty())
		{
			return input;
		}
		ConsoleColor::Print("The void cannot answer an empty question.\n", ConsoleColor::Ink::Red);
	}
}