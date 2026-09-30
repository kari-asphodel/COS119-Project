#pragma once
#include "TarotDeck.h"
class App
{
public:
	App();
	void Run();
private:
	TarotDeck deck;

	void DisplayMenu() const;
	void DrawCard();
	void BrowseCards();
	void DisplayAbout();
};

