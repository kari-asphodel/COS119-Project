#pragma once
#include <string>
#include "TarotDeck.h"
class TarotReading
{
public:
	TarotReading(TarotDeck& deck);
	void OneCardReading();
	void ThreeCardReading();
private:
	TarotDeck& deck;
	bool DetermineOrientation() const;

	void DisplayThreeCardSpread(
		const TarotCard& past, bool pastReversed, 
		const TarotCard& present, bool presentReversed, 
		const TarotCard& future, bool futureReversed) const;

	void DisplayMeaning(const std::string& position, const TarotCard& card, bool isReversed) const;
};

