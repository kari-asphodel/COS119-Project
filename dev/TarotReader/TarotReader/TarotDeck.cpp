#include "TarotDeck.h"
#include "TarotConstants.h"
#include "ConsoleColor.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

TarotDeck::TarotDeck()
{
    if (!LoadArtworkFromFile("data/major_arcana_art.txt"))
    {
        return;
    }
    LoadDeckFromFile("data/major_arcana.txt");
}
bool TarotDeck::LoadArtworkFromFile(const std::string& fileName)
{
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        ConsoleColor::Print(
            "Cannot open the Major Arcana artwork file.\n",
            ConsoleColor::Ink::Red
        );
        return false;
    }

    const int expectedCards =
        TarotConstants::LastMajorArcana -
        TarotConstants::FirstMajorArcana + 1;

    artworks.assign(expectedCards, "");
    std::vector<bool> found(expectedCards, false);

    std::string line;
    int currentNumber = -1;
    std::string currentArt;

    while (std::getline(inputFile, line))
    {
        // Ignore the optional file comment before the first card.
        if (currentNumber == -1 &&
            (line.empty() || line[0] == '#'))
        {
            continue;
        }

        if (line.rfind("CARD|", 0) == 0)
        {
            if (currentNumber != -1)
            {
                return false; // Previous card had no ENDCARD.
            }

            try
            {
                std::string numberText = line.substr(5);
                std::size_t processed = 0;
                int number = std::stoi(numberText, &processed);

                if (processed != numberText.length() ||
                    number < TarotConstants::FirstMajorArcana ||
                    number > TarotConstants::LastMajorArcana ||
                    found[number])
                {
                    return false;
                }

                currentNumber = number;
                currentArt.clear();
            }
            catch (const std::invalid_argument&)
            {
                return false;
            }
            catch (const std::out_of_range&)
            {
                return false;
            }
        }
        else if (line == "ENDCARD")
        {
            if (currentNumber == -1 || currentArt.empty())
            {
                return false;
            }

            artworks[currentNumber] = currentArt;
            found[currentNumber] = true;
            currentNumber = -1;
        }
        else if (currentNumber != -1)
        {
            // Preserve each art line, including leading spaces.
            currentArt += line + "\n";
        }
        else
        {
            return false; // Unexpected text outside a card block.
        }
    }

    if (currentNumber != -1)
    {
        return false;
    }

    for (bool wasFound : found)
    {
        if (!wasFound)
        {
            ConsoleColor::Print(
                "Artwork file is missing one or more cards.\n",
                ConsoleColor::Ink::Red
            );
            return false;
        }
    }

    return true;
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
            if (number < TarotConstants::FirstMajorArcana || number > TarotConstants::LastMajorArcana)
            {
                throw std::out_of_range("Invalid Major Arcana number");
            }
            std::string asciiArt = artworks.at(number);
            cards.push_back(TarotCard(number, name, keywords, uprightMeaning, reversedMeaning, asciiArt));
        }
        catch (const std::exception&)
        {
            ConsoleColor::Print("Invalid card number on line " + std::to_string(lineNumber) + ": " + numberText + "\n", ConsoleColor::Ink::Red);
        }
    }
    inputFile.close();
}


bool TarotDeck::IsValidIndex(int index) const
{
    return index >= 0 && index < static_cast<int>(cards.size());
}
bool TarotDeck::IsLoaded() const
{
    const int expectedCards = TarotConstants::LastMajorArcana - TarotConstants::FirstMajorArcana + 1;

    return static_cast<int>(cards.size()) == expectedCards && static_cast<int>(artworks.size()) == expectedCards;
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