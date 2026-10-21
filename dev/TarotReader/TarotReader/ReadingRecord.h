#pragma once
#include <string>
#include <vector>
// this class holds the record of one reading. 
class ReadingRecord
{
public:
	ReadingRecord(const std::string& readingType, const std::string& question, const std::string& date);
	void AddCard(const std::string& position, const std::string& cardName, bool isReversed);
	void Display() const;
	std::string GetReadingType() const;
	std::string GetQuestion() const;
	std::string GetDate() const;
	int GetCardCount() const;
	std::string GetPosition(int index) const;
	std::string GetCardName(int index) const;
	bool GetReversedState(int index) const;

private:
	std::string readingType;
	std::string question;
	std::string date;

	std::vector<std::string>positions;
	std::vector<std::string>cardNames;
	std::vector<bool> reversedStates;
};

