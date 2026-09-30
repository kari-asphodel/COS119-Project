#include "TarotDeck.h"
#include <cstdlib>
#include <iostream>

TarotDeck::TarotDeck()
{
	CreateDeck();
}

void TarotDeck::CreateDeck()
{
    cards.push_back(TarotCard(
        0,
        "The Fool",
        "Beginnings, freedom, adventure",
        "A new journey is beginning. Be open to possibilities and trust yourself as you move forward.",
        "A warning against recklessness, poor planning, or rushing into something without considering the consequences.",
        R"(
        +-------------------+
        |         0         |
        |                   |
        |         O         |
        |        /|\        |
        |        / \        |
        |      _/   \_      |
        |     /       \     |
        |                   |
        |     THE FOOL      |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        1,
        "The Magician",
        "Willpower, skill, manifestation",
        "You have the skills and resources needed to turn an idea into reality.",
        "Potential is being wasted or abilities may be used without clear purpose or direction.",
        R"(
        +-------------------+
        |         I         |
        |       _____       |
        |      /     \      |
        |         O         |
        |       --|--       |
        |         |         |
        |        / \        |
        |                   |
        |   THE MAGICIAN    |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        2,
        "The High Priestess",
        "Intuition, mystery, inner knowledge",
        "Listen closely to your intuition and pay attention to what may exist beneath the surface.",
        "You may be ignoring your intuition or struggling to hear your own inner voice.",
        R"(
        +-------------------+
        |        II         |
        |      (     )      |
        |       \ O /       |
        |        /|\        |
        |         |         |
        |        / \        |
        |                   |
        |                   |
        | HIGH PRIESTESS    |
        +-------------------+
)"
));
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

void TarotDeck::DrawCard() const
{
    int randomIndex = std::rand() & cards.size();
    cards[randomIndex].DisplayCard();
}