#pragma once
#include <string>
#include "TarotDeck.h"
#include "ReadingRecord.h"
class TarotReading
{
public:
	TarotReading(TarotDeck& deck);
	void OneCardReading();
	void ThreeCardReading();
	void DisplayHistory() const;
private:
	TarotDeck& deck;
	bool DetermineOrientation() const;
	std::string GetOrientationText(bool isReveresed) const;

	std::vector<ReadingRecord> history;

	void DisplayThreeCardSpread(
		const TarotCard& past, bool pastReversed, 
		const TarotCard& present, bool presentReversed, 
		const TarotCard& future, bool futureReversed) const;

	void DisplayMeaning(const std::string& position, const TarotCard& card, bool isReversed) const;
};

