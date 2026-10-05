#pragma once
#include "TarotDeck.h"
#include "TarotReading.h"
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
};

