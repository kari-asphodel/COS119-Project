#include <iostream>
#include "ConsoleColor.h"
#include <ctime>
#include <cstdlib>
#include "TarotDeck.h"
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    TarotDeck deck;

    deck.DisplayDeck();
    std::cout << "\nThe cards are shuffling...\n";
    std::cout << "Your card is: \n";
    deck.DrawCard();
    std::cin.get();
}
