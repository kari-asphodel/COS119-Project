#pragma once
#include <vector>
#include "TarotCard.h"
class TarotDeck
{
public:
	TarotDeck();
	void DisplayDeck() const;
	void DisplayCard(int index) const;
	const TarotCard& GetCard(int index) const;
	const TarotCard& DrawCard() const;
	std::vector<int>DrawUniqueCard(int amount) const;

private:
	std::vector<TarotCard> cards;

	void CreateDeck();
};

