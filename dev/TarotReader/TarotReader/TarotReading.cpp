#include "TarotReading.h"
#include "ConsoleColor.h"
#include "TarotConstants.h"
#include "Input.h"
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <fstream>
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
std::string TarotReading::GetOrientationText(bool isReversed) const
{
    if (isReversed)
    {
        return "REVERSED";
    }
    return "UPRIGHT";
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
    ReadingRecord record("ONE-CARD READING", question, GetCurrentDate());
    record.AddCard("", card.GetName(), isReversed);
    history.push_back(record);
    SaveHistory("data/reading_history.txt");
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
    std::vector<int> selectedCards = deck.DrawUniqueCard(TarotConstants::ThreeCardSpreedSize);
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

    ReadingRecord record("PAST - PRESENT - FUTURE", question, GetCurrentDate());
    record.AddCard("PAST", past.GetName(), pastReversed);
    record.AddCard("PRESENT", present.GetName(), presentReversed);
    record.AddCard("FUTURE", future.GetName(), futureReversed);
    history.push_back(record);
    SaveHistory("data/reading_history.txt");

}

void TarotReading::DisplayThreeCardSpread(
    const TarotCard& past, bool pastReversed,
    const TarotCard& present, bool presentReversed,
    const TarotCard& future, bool futureReversed) const
{
    std::vector<std::string> pastArt = past.GetAsciiLines();
    std::vector<std::string> presentArt = present.GetAsciiLines();
    std::vector<std::string> futureArt = future.GetAsciiLines();

    const int columnWidth = TarotConstants::SpreadColumnWidth;

    ConsoleColor::Print(
        "\n==========================================================================================\n",
        ConsoleColor::Ink::Purple
    );

    std::cout
        << CenterText("PAST", columnWidth)
        << CenterText("PRESENT", columnWidth)
        << CenterText("FUTURE", columnWidth)
        << "\n";

    ConsoleColor::Print(
        "==========================================================================================\n\n",
        ConsoleColor::Ink::Purple
    );

    // Find the tallest card so every row displays correctly.
    std::size_t lineCount = pastArt.size();

    if (presentArt.size() > lineCount)
    {
        lineCount = presentArt.size();
    }

    if (futureArt.size() > lineCount)
    {
        lineCount = futureArt.size();
    }

    for (std::size_t i = 0; i < lineCount; i++)
    {
        std::string pastLine = "";
        std::string presentLine = "";
        std::string futureLine = "";

        if (i < pastArt.size())
        {
            pastLine = pastArt[i];
        }

        if (i < presentArt.size())
        {
            presentLine = presentArt[i];
        }

        if (i < futureArt.size())
        {
            futureLine = futureArt[i];
        }

        std::cout
            << CenterText(pastLine, columnWidth)
            << CenterText(presentLine, columnWidth)
            << CenterText(futureLine, columnWidth)
            << "\n";
    }

    std::cout << "\n"
        << CenterText(GetOrientationText(pastReversed), columnWidth)
        << CenterText(GetOrientationText(presentReversed), columnWidth)
        << CenterText(GetOrientationText(futureReversed), columnWidth)
        << "\n";
}
std::string TarotReading::CenterText(
    const std::string& text,
    int width) const
{
    if (text.length() >= static_cast<std::size_t>(width))
    {
        return text;
    }

    int totalPadding =
        width - static_cast<int>(text.length());

    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;

    return std::string(leftPadding, ' ')
        + text
        + std::string(rightPadding, ' ');
}
void TarotReading::DisplayMeaning(const std::string& position, const TarotCard& card, bool isReversed) const 
{
    ConsoleColor::Print(
        "\n----------------------------------------\n",
        ConsoleColor::Ink::Purple
    );
    ConsoleColor::Print(position + " - " + card.GetName() + "\n", ConsoleColor::Ink::Yellow);
    if (isReversed)
    {
        ConsoleColor::Print("REVERSED\n", ConsoleColor::Ink::Red);
    }
    else
    {
        ConsoleColor::Print("UPRIGHT\n", ConsoleColor::Ink::Green);
    }
    ConsoleColor::Print("Keywords: ", ConsoleColor::Ink::Cyan);
    std::cout << card.GetKeywords() << "\n\n";
    
    ConsoleColor::Print("Meaning: ", ConsoleColor::Ink::Cyan);
    if (isReversed)
    {
        std::cout << card.GetReversedMeaning() << "\n";
    }
    else
    {
        std::cout << card.GetUprightMeaning() << "\n";
    }
}

void TarotReading::DisplayHistory() const
{
    ConsoleColor::Print(
        "\n========================================\n",
        ConsoleColor::Ink::Purple
    );

    ConsoleColor::Print(
        "             READING HISTORY\n",
        ConsoleColor::Ink::Purple
    );

    ConsoleColor::Print(
        "========================================\n",
        ConsoleColor::Ink::Purple
    );
    if (history.empty())
    {
        ConsoleColor::Print("\nThe cards have no stories to remember yet..\n", ConsoleColor::Ink::Cyan);
        return;
    }
    for (size_t i = 0; i < history.size(); i++)
    {
        std::cout << "\n";
        ConsoleColor::Print("Reading " + std::to_string(i + 1) + "\n", ConsoleColor::Ink::Yellow);
        history[i].Display();
        std::cout << "\n";
    }
}

std::string TarotReading::GetCurrentDate() const
{
    std::time_t currentTime =
        std::time(nullptr);

    std::tm localTime{};

    localtime_s(
        &localTime,
        &currentTime
    );

    std::ostringstream date;

    date<< std::setfill('0')
        << std::setw(2)
        << localTime.tm_mon + 1
        << "/"
        << std::setw(2)
        << localTime.tm_mday
        << "/"
        << localTime.tm_year + 1900;

    return date.str();
}

void TarotReading::SaveHistory(const std::string& fileName) const
{
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open())
    {
        ConsoleColor::Print("\nThe reading history could not be saved.\n", ConsoleColor::Ink::Red);
        return;
    }
    for (const ReadingRecord& record : history)
    {
        outputFile << "READING\n";
        outputFile << record.GetReadingType() << "\n";
        outputFile << record.GetDate() << "\n";
        outputFile << record.GetQuestion() << "\n";
        outputFile << record.GetCardCount() << "\n";
        for (int i = 0; i < record.GetCardCount(); i++)
        {
            outputFile << record.GetPosition(i) << "|" << record.GetCardName(i) << "|" << record.GetReversedState(i) << "\n";
        }
        outputFile << "END\n";
    }
    outputFile.close();
}

void TarotReading::LoadHistory(const std::string& fileName) 
{
    std::ifstream inputFile(
        fileName
    );

    if (!inputFile.is_open())
    {
        return;
    }

    history.clear();

    std::string line;

    while (std::getline(
        inputFile,
        line))
    {
        if (line != "READING")
        {
            continue;
        }

        std::string readingType;
        std::string date;
        std::string question;
        std::string cardCountText;

        if (!std::getline(
            inputFile,
            readingType) ||
            !std::getline(
                inputFile,
                date) ||
            !std::getline(
                inputFile,
                question) ||
            !std::getline(
                inputFile,
                cardCountText))
        {
            break;
        }

        int cardCount = 0;

        try
        {
            cardCount =
                std::stoi(
                    cardCountText
                );
        }
        catch (...)
        {
            continue;
        }

        ReadingRecord record(
            readingType,
            question,
            date
        );

        bool validRecord = true;

        for (int i = 0;
            i < cardCount;
            i++)
        {
            std::string cardLine;

            if (!std::getline(
                inputFile,
                cardLine))
            {
                validRecord = false;
                break;
            }

            std::stringstream stream(
                cardLine
            );

            std::string position;
            std::string cardName;
            std::string reversedText;

            if (!std::getline(
                stream,
                position,
                '|') ||
                !std::getline(
                    stream,
                    cardName,
                    '|') ||
                !std::getline(
                    stream,
                    reversedText))
            {
                validRecord = false;
                break;
            }

            bool isReversed =
                reversedText == "1";

            record.AddCard(
                position,
                cardName,
                isReversed
            );
        }

        std::string endMarker;

        if (!std::getline(
            inputFile,
            endMarker))
        {
            break;
        }

        if (validRecord &&
            endMarker == "END")
        {
            history.push_back(
                record
            );
        }
    }

    inputFile.close();
}