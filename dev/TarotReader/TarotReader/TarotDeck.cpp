#include "TarotDeck.h"
#include "TarotConstants.h"
#include "ConsoleColor.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

TarotDeck::TarotDeck()
{
    LoadDeckFromFile("data/major_arcana.txt");
}

void TarotDeck::LoadDeckFromFile(const std::string& fileName)
{
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open())
    {
        ConsoleColor::Print("\nUnable to open the tarot deck file.\n", ConsoleColor::Ink::Red);
        return;
    }
    cards.clear();

    std::string line;
    int lineNumber = 0;
    while (std::getline(inputFile, line))
    {
        lineNumber++;
        if (line.empty() || line[0] == '#')
        {
            continue;
        }
        std::stringstream stream(line);
        std::string numberText;
        std::string name;
        std::string keywords;
        std::string uprightMeaning;
        std::string reversedMeaning;

        if (!std::getline(stream, numberText, '|') ||
            !std::getline(stream, name, '|') ||
            !std::getline(stream, keywords, '|') ||
            !std::getline(stream, uprightMeaning, '|') ||
            !std::getline(stream, reversedMeaning))
        {
            ConsoleColor::Print("Invalid card data on line " + std::to_string(lineNumber) + ".\n", ConsoleColor::Ink::Red);
            continue;
        }

        try
        {
            std::size_t processedCharacters = 0;
            int number = std::stoi(numberText, &processedCharacters);
            if (processedCharacters != numberText.length())
            {
                throw std::invalid_argument("Invalid card number");
            }
            std::string asciiArt = CreateAsciiArt(number, name);
            cards.push_back(TarotCard(number, name, keywords, uprightMeaning, reversedMeaning, asciiArt));
        }
        catch (const std::exception&)
        {
            ConsoleColor::Print("Invalid card number on line " + std::to_string(lineNumber) + ": " + numberText + "\n", ConsoleColor::Ink::Red);
        }
    }
    inputFile.close();
}
std::string TarotDeck::CreateAsciiArt(int number, const std::string& name) const
{
    std::stringstream art;
    art
        << "+-----------------------+\n"
        << "|                       |\n"
        << "|          "
        << number;
    if (number < 10)
    {
        art << " ";
    }
    art
        << "           |\n"
        << "|                       |\n"
        << "|           *           |\n"
        << "|          /|\\          |\n"
        << "|          / \\          |\n"
        << "|                       |\n";
    std::string displayName = name;
    if (displayName.length() > 21)
    {
        displayName = displayName.substr(0, 21);
    }
    int totalPadding = 23 - static_cast<int>(displayName.length());
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;
    art << "|";
    for (int i = 0; i < leftPadding; i++)
    {
        art << " ";
    }
    art << displayName;
    for (int i = 0; i < rightPadding; i++)
    {
        art << " ";
    }
    art
        << "|\n"
        << "+-----------------------+\n";
    return art.str();
}

bool TarotDeck::IsValidIndex(int index) const
{
    return index >= 0 && index < static_cast<int>(cards.size());
}
bool TarotDeck::IsLoaded() const
{
    return cards.size() == 22;
}

void TarotDeck::DisplayDeck() const
{
    std::cout << "\n==== MAJOR ARCANA ====\n\n";
    for (const TarotCard& card:cards)
    {
        std::cout << card.GetNumber()
            << " - "
            << card.GetName()
            << "\n";
    }
}

void TarotDeck::DisplayCard(int index) const
{
    if (index >= 0 && index < static_cast<int>(cards.size()))
    {
        cards[index].DisplayCard();
    }
}

const TarotCard& TarotDeck::DrawCard() const
{
    int randomIndex = std::rand() % static_cast<int>(cards.size());
    return cards[randomIndex];
}

const TarotCard& TarotDeck::GetCard(int index) const
{
    return cards[index];
}

std::vector<int>TarotDeck::DrawUniqueCard(int amount) const
{
    std::vector<int> selectedIndexes;
    if (cards.empty())
    {
        return selectedIndexes;
    }
    int cardCount = static_cast<int>(cards.size());

    if (amount > cardCount)
    {
        amount = cardCount;
    }
    while (static_cast<int>(selectedIndexes.size()) < amount)
    {
        int randomIndex = std::rand() % cardCount;

        bool alreadySelected = false;

        for (int index : selectedIndexes)
        {
            if (index == randomIndex)
            {
                alreadySelected = true;
                break;
            }
        }
        if (!alreadySelected)
        {
            selectedIndexes.push_back(randomIndex);
        }
    }
    return selectedIndexes;
}