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
			std::size_t processedCharacters = 0;
			int number = std::stoi(input, &processedCharacters);
			if (processedCharacters != input.length())
			{
				ConsoleColor::Print("Please enter numbers only.\n", ConsoleColor::Ink::Red);
				continue;
			}
			if (number < min || number > max)
			{
				ConsoleColor::Print("That number is outside the available choices.\n", ConsoleColor::Ink::Red);
				continue;
			}
			return number;
		}
		catch (...)
		{
			ConsoleColor::Print("The cards require a valid number, mortal.\n", ConsoleColor::Ink::Red);
		}
	}
}

std::string Input::GetString(const std::string& prompt , bool allowEmpty)
{
	while (true)
	{
		ConsoleColor::Print(prompt, ConsoleColor::Ink::Yellow);

		std::string input;
		std::getline(std::cin, input);
		if (allowEmpty || !input.empty())
		{
			return input;
		}

		ConsoleColor::Print("The void cannot answer an empty question.\n", ConsoleColor::Ink::Red);
	}
}