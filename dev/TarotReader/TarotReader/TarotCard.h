#pragma once
#include <string>
#include <vector>
class TarotCard
{
public:
	TarotCard(
		int number,
		const std::string& name,
		const std::string& keywords,
		const std::string& uprightMeaning,
		const std::string& reversedMeaning,
		const std::string& asciiArt
	);	
	int GetNumber() const;
	std::string GetName() const; 
	std::string GetKeywords() const; 
	std::string GetUprightMeaning() const; 
	std::string GetReversedMeaning() const; 
	std::string GetAsciiArt() const; 

	std::vector<std::string> GetAsciiLines() const;

	void DisplayCard() const;
	void DisplayReading(bool isReversed) const;
private:
	int number;
	std::string name;
	std::string keywords;
	std::string uprightMeaning;
	std::string reversedMeaning;
	std::string asciiArt;
};

