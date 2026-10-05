#include "TarotReading.h"
#include "ConsoleColor.h"
#include "Input.h"
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>

TarotReading::TarotReading(TarotDeck& deck) : deck(deck)
{ }

bool TarotReading::DetermineOrientation() const
{
	int randomValue = std::rand() % 2;
	if (randomValue == 0)
	{
		return true;
	}
	return false;
}

void TarotReading::OneCardReading()
{
    ConsoleColor::Print(
        "\n========================================\n",
        ConsoleColor::Ink::Purple
    );

    ConsoleColor::Print(
        "            ONE-CARD READING\n",
        ConsoleColor::Ink::Purple
    );

    ConsoleColor::Print(
        "========================================\n\n",
        ConsoleColor::Ink::Purple
    );

    std::cout << "Take a moment to consider your question.\n\n";
    std::string question = Input::GetString("Enter your question or intention:\n");

    ConsoleColor::Print("\nThe cards are shuffling...\n", ConsoleColor::Ink::Purple);

    const TarotCard& card = deck.DrawCard();

    bool isReversed = DetermineOrientation();
    ConsoleColor::Print("\nYour card is...\n", ConsoleColor::Ink::Cyan);
    ConsoleColor::Print(card.GetAsciiArt(), ConsoleColor::Ink::Purple);
    std::cout << "\n";

    card.DisplayReading(isReversed);
    ConsoleColor::Print("\nYour question:\n", ConsoleColor::Ink::Yellow);
    std::cout << question << "\n";
}

void TarotReading::ThreeCardReading()
{
    ConsoleColor::Print(
        "\n========================================\n",
        ConsoleColor::Ink::Purple
    );

    ConsoleColor::Print(
        "       PAST - PRESENT - FUTURE\n",
        ConsoleColor::Ink::Purple
    );

    ConsoleColor::Print(
        "========================================\n\n",
        ConsoleColor::Ink::Purple
    );
    std::cout << "Think about the situation you would like the cards to explore.\n\n";
    std::string question = Input::GetString("Enter your question or intention:\n");
    ConsoleColor::Print("\nShuffling the deck...\n\n", ConsoleColor::Ink::Purple);
    std::vector<int> selectedCards = deck.DrawUniqueCard();
    const TarotCard& past = deck.GetCard(selectedCards[0]);
    const TarotCard& present = deck.GetCard(selectedCards[1]);
    const TarotCard& future = deck.GetCard(selectedCards[2]);

    bool pastReversed = DetermineOrientation();
    bool presentReversed = DetermineOrientation();
    bool futureReversed = DetermineOrientation();
    DisplayThreeCardSpread(past, pastReversed, present, presentReversed, future, futureReversed);
    DisplayMeaning("PAST", past, pastReversed);
    DisplayMeaning("PRESENT", present, presentReversed);
    DisplayMeaning("FUTURE", future, futureReversed);
    ConsoleColor::Print(
        "\n========================================\n",
        ConsoleColor::Ink::Purple
    );

    ConsoleColor::Print(
        "Your question:\n",
        ConsoleColor::Ink::Yellow
    );

    std::cout
        << question
        << "\n";
}