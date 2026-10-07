#include "App.h"
#include "ConsoleColor.h"
#include "Input.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

App::App() : reading(deck)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void App::Run()
{
    DisplayWelcome();
	int choice = 0;
	while (choice != 5)
	{
		DisplayMenu();
        choice = Input::GetNumber("\nEnter a menu option between 1-5: ", 1, 5);
		switch (choice)
		{
		case 1:
			reading.OneCardReading();
			break;
		case 2:
			reading.ThreeCardReading();
			break;
		case 3: 
			BrowseCards();
			break;
        case 4:
            DisplayAbout();
            break;
		case 5:
			std::cout << "\n";
			std::cout << "The cards have spoken...Until next time.\n";
			break;
		default:
			ConsoleColor::Print("\nThe cards do not recognize that choice.\n", ConsoleColor::Ink::Red);
			break;
		}
	}
}


void App::DisplayMenu() const
{
	std::cout << "\n";
	ConsoleColor::Print("========================================\n", ConsoleColor::Ink::Purple);
    ConsoleColor::Print(
        "          THE VEILED ARCANA\n",
        ConsoleColor::Ink::Purple
    );

    ConsoleColor::Print(
        "             TAROT READER\n",
        ConsoleColor::Ink::Purple
    );

    ConsoleColor::Print(
        "========================================\n",
        ConsoleColor::Ink::Purple
    );

    std::cout << "\n";

    ConsoleColor::Print(
        "1. One-Card Reading\n",
        ConsoleColor::Ink::Cyan
    );

    ConsoleColor::Print(
        "2. Three-Card Reading\n",
        ConsoleColor::Ink::Cyan
    );

    ConsoleColor::Print(
        "3. Browse the Major Arcana\n",
        ConsoleColor::Ink::Cyan
    );
    ConsoleColor::Print(
        "4. About Tarot\n",
        ConsoleColor::Ink::Cyan
    );

    ConsoleColor::Print(
        "5. Exit\n",
        ConsoleColor::Ink::Cyan
    );

    std::cout << "\n";
}



void App::BrowseCards()
{
    deck.DisplayDeck();
    int cardChoice = 0;
    std::cout << "\n";
    cardChoice = Input::GetNumber("\nEnter a card number (0-21): ", 0, 21);
    if (cardChoice >= 0 && cardChoice <= 21)
    {
        deck.DisplayCard(cardChoice);
    }
    else
    {
        ConsoleColor::Print("\nThat card does not exist.\n", ConsoleColor::Ink::Red);
    }
}
void App::DisplayAbout() const
{
    std::cout << "\n";
    std::cout << "ABOUT THE MAJOR ARCANA\n";
    std::cout << "----------------------------------------\n";
    std::cout << "The Major Arcana contains 22 cards,\n numbered from 0 to 21.\n\nThese cards often represent major themes,\nexperiences, lessons, and transistions.\n";
}

void App::DisplayWelcome() const
{
    ConsoleColor::Print(
        R"(
              .       *       .
        *                       *
                 .-------.
                /         \
               |    *      |
               |           |
                \         /
                 '-------'
            *                 .
                 .       *

        THE VEILED ARCANA
           TAROT READER

)",
ConsoleColor::Ink::Purple
);

    ConsoleColor::Print(
        "        The cards are waiting...\n\n",
        ConsoleColor::Ink::Cyan
    );
}