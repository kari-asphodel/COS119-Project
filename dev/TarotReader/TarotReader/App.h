#pragma once
#include "TarotDeck.h"
#include "TarotReading.h"
// This class handles user input, menu options and getting  the application running
class App
{
public:
	App();
	void Run();
private:
	TarotDeck deck;
	TarotReading reading;

	void DisplayWelcome() const;
	void DisplayMenu() const;
	void BrowseCards();
	void DisplayAbout() const;
	void ClearScreen() const;
};

