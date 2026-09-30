#include <iostream>
#include "ConsoleColor.h"
#include "TarotCard.h"
int main()
{
    TarotCard tower(
        16,
        "The Tower",
        "Upheaval, revelation, sudden change",
        "The Tower represents sudden disruption or revelation that challenges an unstable foundation.",
        "You may be resisting necessary change or attempting to delay an unavoidable transformation.",
        R"(
        +-------------------+
        |        XVI        |
        |        /\/\       |
        |       / /\ \      |
        |      / /  \ \     |
        |       | [] |      |
        |      /| [] |\     |
        |     /_|____|_\    |
        |                   |
        |     THE TOWER     |
        +-------------------+
)"
);	
    tower.DisplayCard();
    std::cin.get();
}
