#pragma once
#include <string>
class TarotCard
{
public:
	TarotCart(int number, const std::string& name,
		const std::string& keywords, const std::string& uprightMeaning, const std::string& reversedMeaning, const std::string& asciiArt);
	int GetNumber() const;
	std::string GetName() const; 
	std::string GetKeywords() const; 
	std::string GetUprightMeaning() const; 
	std::string GetReversedMeaning() const; 
	std::string GetAsciiArt() const; 
	void DisplayCard() const;
private:
	int number;
	std::string name;
	std::string keywords;
	std::string uprightMeaning;
	std::string reversedMeaning;
	std::string asciiArt;
};

