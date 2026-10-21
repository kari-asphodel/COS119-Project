#pragma once
#include <string>
#include <vector>
#include "TarotCard.h"
// this class handles the entire tarot deck
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
	std::vector<std::string> artworks;

	void LoadDeckFromFile(const std::string& fileName);
	bool IsValidIndex(int index)const;
	bool LoadArtworkFromFile(const std::string& fileName);
};

