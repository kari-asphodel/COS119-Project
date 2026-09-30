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

    cards.push_back(TarotCard(
        3,
        "The Empress",
        "Abundance, creativity, nurturing",
        "The Empress represents growth, creativity, comfort, and nurturing energy.",
        "You may be neglecting your own needs, feeling creatively blocked, or giving too much of yourself to others.",
        R"(
        +-------------------+
        |        III        |
        |       .---.       |
        |      (  O  )      |
        |       \ | /       |
        |        /|\        |
        |       / | \       |
        |      /  |  \      |
        |                   |
        |    THE EMPRESS    |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        4,
        "The Emperor",
        "Structure, authority, stability",
        "The Emperor represents structure, leadership, boundaries, and creating a stable foundation.",
        "Too much control or rigidity may be creating conflict. It may be time to reconsider your boundaries.",
        R"(
        +-------------------+
        |        IV         |
        |       _____       |
        |      /_____\      |
        |        [O]        |
        |       /|#|\       |
        |      / |#| \      |
        |       /   \       |
        |                   |
        |    THE EMPEROR    |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        5,
        "The Hierophant",
        "Tradition, guidance, learning",
        "The Hierophant represents tradition, shared knowledge, mentorship, and learning from established wisdom.",
        "It may be time to question traditions or expectations that no longer fit your beliefs.",
        R"(
        +-------------------+
        |         V         |
        |        /+\        |
        |       /___\       |
        |        (O)        |
        |       --|--       |
        |         |         |
        |        / \        |
        |                   |
        |  THE HIEROPHANT   |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        6,
        "The Lovers",
        "Love, harmony, choices",
        "The Lovers represents connection, shared values, meaningful relationships, and choices made from the heart.",
        "Conflict, imbalance, or misaligned values may require an honest look at a relationship or decision.",
        R"(
        +-------------------+
        |        VI         |
        |       \  |  /     |
        |        \ | /      |
        |      O   *   O    |
        |     /|\     /|\   |
        |     / \     / \   |
        |                   |
        |                   |
        |    THE LOVERS     |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        7,
        "The Chariot",
        "Determination, direction, victory",
        "The Chariot represents determination, focused action, and moving forward despite opposing forces.",
        "A lack of direction or self-discipline may be preventing progress.",
        R"(
        +-------------------+
        |        VII        |
        |       _____       |
        |      |  O  |      |
        |      | /|\ |      |
        |      |_____|      |
        |      O     O      |
        |     /       \     |
        |                   |
        |    THE CHARIOT    |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        8,
        "Strength",
        "Courage, patience, compassion",
        "Strength represents quiet courage, patience, compassion, and confidence in your ability to handle challenges.",
        "Self-doubt, insecurity, or uncontrolled emotions may be making a situation harder to manage.",
        R"(
        +-------------------+
        |       VIII        |
        |        ___        |
        |      _(o o)_      |
        |     /   ^   \     |
        |     \  ---  /     |
        |      \_____/      |
        |                   |
        |                   |
        |     STRENGTH      |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        9,
        "The Hermit",
        "Reflection, solitude, inner guidance",
        "The Hermit suggests stepping away from outside noise to reflect, learn, and seek answers within yourself.",
        "Isolation or excessive withdrawal may be keeping you disconnected from useful perspectives or support.",
        R"(
        +-------------------+
        |        IX         |
        |          *        |
        |         /|\       |
        |        / | \      |
        |          O        |
        |         /|\       |
        |         / \       |
        |                   |
        |    THE HERMIT     |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        10,
        "Wheel of Fortune",
        "Cycles, change, turning points",
        "The Wheel of Fortune represents changing circumstances, cycles, and unexpected turning points.",
        "Resistance to change or an unwanted shift may leave you feeling as though circumstances are outside your control.",
        R"(
        +-------------------+
        |         X         |
        |                   |
        |       .-----.     |
        |      /   |   \    |
        |     | ---+--- |   |
        |      \   |   /    |
        |       '-----'     |
        |                   |
        | WHEEL OF FORTUNE  |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        11,
        "Justice",
        "Truth, fairness, accountability",
        "Justice represents truth, balance, accountability, and accepting the consequences of decisions.",
        "Dishonesty, unfairness, or avoiding responsibility may need to be addressed.",
        R"(
        +-------------------+
        |        XI         |
        |         |         |
        |      ---+---      |
        |     /   |   \     |
        |    (_)  |  (_)    |
        |         |         |
        |        / \        |
        |                   |
        |      JUSTICE      |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        12,
        "The Hanged Man",
        "Pause, surrender, new perspective",
        "The Hanged Man suggests pausing, releasing control, and viewing the situation from another perspective.",
        "Delays, resistance, or unwillingness to change perspective may be keeping you stuck.",
        R"(
        +-------------------+
        |        XII        |
        |     ---------     |
        |         |         |
        |        / \        |
        |         |         |
        |        /|\        |
        |         O         |
        |                   |
        |  THE HANGED MAN   |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        13,
        "Death",
        "Endings, transformation, transition",
        "Death represents an ending that creates space for transformation, transition, and something new.",
        "Fear of endings or resistance to necessary change may be preventing growth.",
        R"(
        +-------------------+
        |       XIII        |
        |                   |
        |       _____       |
        |      / x x \      |
        |     |   ^   |     |
        |     |  ___  |     |
        |      \_____/      |
        |        ||         |
        |       DEATH       |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        14,
        "Temperance",
        "Balance, moderation, harmony",
        "Temperance represents patience, balance, and blending different parts of life into something harmonious.",
        "Excess, imbalance, or impatience may be disrupting your sense of stability.",
        R"(
        +-------------------+
        |        XIV        |
        |      \  O  /      |
        |       \ | /       |
        |        \|/        |
        |       __|__       |
        |      /     \      |
        |                   |
        |                   |
        |    TEMPERANCE     |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        15,
        "The Devil",
        "Attachment, temptation, restriction",
        "The Devil represents unhealthy attachments, temptation, or patterns that may be limiting your choices.",
        "Awareness is returning, making it possible to break away from a limiting pattern or attachment.",
        R"(
        +-------------------+
        |        XV         |
        |      \     /      |
        |       \ O /       |
        |      --\|/--      |
        |        / \        |
        |       /   \       |
        |      o     o      |
        |                   |
        |     THE DEVIL     |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
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
));

    cards.push_back(TarotCard(
        17,
        "The Star",
        "Hope, renewal, inspiration",
        "The Star represents hope, healing, inspiration, and renewed confidence after difficulty.",
        "Discouragement or a loss of faith may make it difficult to recognize possibilities ahead.",
        R"(
        +-------------------+
        |       XVII        |
        |         *         |
        |     *   |   *     |
        |       \ | /       |
        |    * ---*--- *    |
        |       / | \       |
        |     *   |   *     |
        |         *         |
        |     THE STAR      |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        18,
        "The Moon",
        "Intuition, uncertainty, illusion",
        "The Moon represents intuition, uncertainty, dreams, and situations where everything may not yet be clear.",
        "Confusion may be beginning to lift, allowing hidden information or fears to come into view.",
        R"(
        +-------------------+
        |       XVIII       |
        |       .---.       |
        |      /     )      |
        |     |     /       |
        |      \   /        |
        |       '-'         |
        |      /\   /\      |
        |                   |
        |     THE MOON      |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        19,
        "The Sun",
        "Joy, success, vitality",
        "The Sun represents optimism, confidence, warmth, success, and clarity.",
        "Temporary doubt or negativity may be making it difficult to appreciate the positive things around you.",
        R"(
        +-------------------+
        |        XIX        |
        |    \    |    /    |
        |      \  |  /      |
        |   ----  O  ----   |
        |      /  |  \      |
        |    /    |    \    |
        |                   |
        |                   |
        |      THE SUN      |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        20,
        "Judgement",
        "Reflection, awakening, renewal",
        "Judgement represents reflection, self-evaluation, awakening, and making choices based on what you have learned.",
        "Self-doubt or refusal to learn from the past may be preventing you from moving forward.",
        R"(
        +-------------------+
        |        XX         |
        |      \  |  /      |
        |       \ | /       |
        |        \O/        |
        |         |         |
        |      O  O  O      |
        |     /|\/|\/|\     |
        |                   |
        |    JUDGEMENT      |
        +-------------------+
)"
));

    cards.push_back(TarotCard(
        21,
        "The World",
        "Completion, achievement, wholeness",
        "The World represents completion, accomplishment, fulfillment, and reaching the end of an important cycle.",
        "Something may still need closure before you can fully move forward into the next chapter.",
        R"(
        +-------------------+
        |        XXI        |
        |      .-------.    |
        |     /    O    \   |
        |    |    /|\    |  |
        |    |    / \    |  |
        |     \         /   |
        |      '-------'    |
        |                   |
        |     THE WORLD     |
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