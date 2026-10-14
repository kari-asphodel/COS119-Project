#pragma once
#include <string>
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

	int GetCardCount() const;
	bool IsLoaded() const;

private:
	std::vector<TarotCard> cards;

	void LoadDeckFromFile(const std::string& fileName);
	std::string CreateAsciiArt(int number, const std::string& name) const;
	bool IsValidIndex(int index)const;
};

