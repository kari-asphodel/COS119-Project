#include "TarotCard.h"
#include "ConsoleColor.h"
#include <iostream>

TarotCard::TarotCard(
	int number,
	const std::string& name,
	const std::string& keywords,
	const std::string& uprightMeaning,
	const std::string& reversedMeaning,
	const std::string& asciiArt)
{
	this->number = number;
	this->name = name;
	this->keywords = keywords;
	this->uprightMeaning = uprightMeaning;
	this->reversedMeaning = reversedMeaning;
	this->asciiArt = asciiArt;
}
int TarotCard::GetNumber() const
{
	return number;
}
std::string TarotCard::GetName() const
{
	return name;
}

std::string TarotCard::GetKeywords() const
{
	return keywords;
}

std::string TarotCard::GetUprightMeaning() const
{
	return uprightMeaning;
}

std::string TarotCard::GetReversedMeaning() const
{
	return reversedMeaning;
}

std::string TarotCard::GetAsciiArt() const
{
	return asciiArt;
}

void TarotCard::DisplayCard() const
{
	std::cout << "\n";
	ConsoleColor::Print(asciiArt, ConsoleColor::Ink::Purple);
	std::cout << "\n";
	ConsoleColor::Print("---------------------------------\n",
		ConsoleColor::Ink::Purple);
	ConsoleColor::Print(std::to_string(number) + " - " + name + "\n",
		ConsoleColor::Ink::Purple);
	ConsoleColor::Print("---------------------------------\n",
		ConsoleColor::Ink::Purple);
	ConsoleColor::Print("Kewords: ", ConsoleColor::Ink::Yellow);
	std::cout << keywords << "\n\n";
	ConsoleColor::Print("Upright Meaning:\n", ConsoleColor::Ink::Green);
	std::cout << uprightMeaning << "\n";
	ConsoleColor::Print("Reversed Meaning:\n", ConsoleColor::Ink::Green);
	std::cout << reversedMeaning << "\n";
	ConsoleColor::Print("---------------------------------\n",
		ConsoleColor::Ink::Purple);

}