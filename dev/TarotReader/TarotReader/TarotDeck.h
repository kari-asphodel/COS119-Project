#pragma once
#include <vector>
#include "TarotCard.h"
class TarotDeck
{
public:
	TarotDeck();
	void DisplayDeck() const;
	void DisplayCard(int index) const;
	void DrawCard() const;

private:
	std::vector<TarotCard> cards;

	void CreateDeck();
};

