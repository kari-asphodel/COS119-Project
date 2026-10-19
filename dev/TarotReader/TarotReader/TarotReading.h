#pragma once
#include <string>
#include <vector>
#include "TarotDeck.h"
#include "ReadingRecord.h"
class TarotReading
{
public:
	TarotReading(TarotDeck& deck);
	void OneCardReading();
	void ThreeCardReading();
	void DisplayHistory() const;
	std::string CenterText(const std::string& text, int width) const;
	void SaveHistory(const std::string& fileName) const;
	void LoadHistory(const std::string& fileName);
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
	std::string GetCurrentDate() const;
};

