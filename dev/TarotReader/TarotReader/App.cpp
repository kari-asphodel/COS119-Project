#include "App.h"
#include "ConsoleColor.h"
#include "TarotConstants.h"
#include "Input.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

App::App() : reading(deck)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
    reading.LoadHistory("data/reading_history.txt");
}

void App::Run()
{
    if (!deck.IsLoaded())
    {
        ConsoleColor::Print("\nThe tarot deck could not be loaded.\n", ConsoleColor::Ink::Red);
        ConsoleColor::Print("The program cannot continue.\n", ConsoleColor::Ink::Yellow);
        Input::WaitForEnter();
        return;
    }
    DisplayWelcome();
    Input::WaitForEnter();

	int choice = 0;
    while (choice != TarotConstants::MenuMaximum)
	{
        ClearScreen();
		DisplayMenu();
        choice = Input::GetNumber("\nEnter a menu option between 1-6: ", TarotConstants::MenuMinimum, TarotConstants::MenuMaximum);
		switch (choice)
		{
		case 1:
			reading.OneCardReading();
            Input::WaitForEnter();
            ClearScreen();
			break;
		case 2:
			reading.ThreeCardReading();
            Input::WaitForEnter();
            ClearScreen();
			break;
		case 3: 
			BrowseCards();
            Input::WaitForEnter();
            ClearScreen();
			break;
        case 4:
            reading.DisplayHistory();
            Input::WaitForEnter();
            ClearScreen();
            break;
        case 5:
            DisplayAbout();
            Input::WaitForEnter();
            ClearScreen();
            break;
		case 6:
			std::cout << "\n";
			std::cout << "The cards have spoken...Until next time.\n";
			break;
		default:
			ConsoleColor::Print("\nThe cards do not recognize that choice.\n", ConsoleColor::Ink::Red);
			break;
		}
        if (choice != TarotConstants::MenuMaximum)
        {
            Input::WaitForEnter();
            ClearScreen();
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
        "4. Reading History\n",
        ConsoleColor::Ink::Cyan
    );

    ConsoleColor::Print(
        "5. About Tarot\n",
        ConsoleColor::Ink::Cyan
    );

    ConsoleColor::Print(
        "6. Exit\n",
        ConsoleColor::Ink::Cyan
    );

    std::cout << "\n";
}



void App::BrowseCards()
{
    deck.DisplayDeck();
    int cardChoice = 0;
    std::cout << "\n";
    cardChoice = Input::GetNumber("\nEnter a card number (0-21): ", TarotConstants::FirstMajorArcana, TarotConstants::LastMajorArcana);
    if (cardChoice >= TarotConstants::FirstMajorArcana && cardChoice <= TarotConstants::LastMajorArcana)
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

void App::ClearScreen() const
{
    std::system("cls");
 }