#pragma once
#include <string>
#include <vector>
class ReadingRecord
{
public:
	ReadingRecord(const std::string& readingType, const std::string& question);
	void AddCard(const std::string& position, const std::string& cardName, bool isReversed);
	void Display() const;

private:
	std::string readingType;
	std::string question;

	std::vector<std::string>positions;
	std::vector<std::string>cardNames;
	std::vector<bool> reversedStates;
};

