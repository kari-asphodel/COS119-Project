#include "ReadingRecord.h"
#include "ConsoleColor.h"
#include <iostream>

ReadingRecord::ReadingRecord(const std::string& readingType, const std::string& question)
{
	this->readingType = readingType;
	this->question = question;
}
void ReadingRecord::AddCard(const std::string& position, const std::string& cardName, bool isReversed)
{
	positions.push_back(position);
	cardNames.push_back(cardName);
	reversedStates.push_back(isReversed);
}

void ReadingRecord::Display() const
{
	ConsoleColor::Print(readingType + "\n", ConsoleColor::Ink::Purple);
	std::cout << "\n";
	ConsoleColor::Print("Question: ", ConsoleColor::Ink::Yellow);
	std::cout << question << "\n\n";
	for (size_t i = 0; i < cardNames.size(); i++)
	{
		if (!positions[i].empty())
		{
			ConsoleColor::Print(positions[i] + ": ", ConsoleColor::Ink::Cyan);
		}
		std::cout << cardNames[i];
		if (reversedStates[i])
		{
			ConsoleColor::Print(" - REVERSED\n", ConsoleColor::Ink::Red);
		}
		else
		{
			ConsoleColor::Print(" - UPRIGHT\n", ConsoleColor::Ink::Green);
		}
	}
	ConsoleColor::Print(
		"----------------------------------------\n",
		ConsoleColor::Ink::Purple
	);
}