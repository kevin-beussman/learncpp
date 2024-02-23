#include <iostream>
#include <array>
#include <random>
#include <algorithm>

enum Ranks
{
    r2,
    r3,
    r4,
    r5,
    r6,
    r7,
    r8,
    r9,
    r10,
    rJack,
    rQueen,
    rKing,
    rAce,
    max_ranks
};

enum Suits
{
    clubs,
    diamonds,
    hearts,
    spades,
    max_suits
};

struct Card
{
    Ranks rank{};
    Suits suit{};
};

using deck_type = std::array<Card, 52>;

void printCard(const Card& card)
{
    switch (card.rank)
    {
    case r2: std::cout << '2'; break;
    case r3: std::cout << '3'; break;
    case r4: std::cout << '4'; break;
    case r5: std::cout << '5'; break;
    case r6: std::cout << '6'; break;
    case r7: std::cout << '7'; break;
    case r8: std::cout << '8'; break;
    case r9: std::cout << '9'; break;
    case r10: std::cout << 'T'; break;
    case rJack: std::cout << 'J'; break;
    case rQueen: std::cout << 'Q'; break;
    case rKing: std::cout << 'K'; break;
    case rAce: std::cout << 'A'; break;
    default: std::cout << '?'; break;
    }

    switch (card.suit)
    {
    case clubs: std::cout << 'C'; break;
    case diamonds: std::cout << 'D'; break;
    case hearts: std::cout << 'H'; break;
    case spades: std::cout << 'S'; break;
    default: std::cout << '?'; break;
    }

}

deck_type createDeck()
{
    deck_type deck;
    for (int i{}; i < 52; ++i)
    {
        if (i < 13)
            deck[i] = Card{static_cast<Ranks>(i % 13), static_cast<Suits>(0)};
        else if (i < 26)
            deck[i] = Card{static_cast<Ranks>(i % 13), static_cast<Suits>(1)};
        else if (i < 39)
            deck[i] = Card{static_cast<Ranks>(i % 13), static_cast<Suits>(2)};
        else
            deck[i] = Card{static_cast<Ranks>(i % 13), static_cast<Suits>(3)};
    }
    return deck;
}

void printDeck(const deck_type& deck)
{
    for (Card card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffleDeck(deck_type& deck)
{
    static std::mt19937 mt{ std::random_device{}() };
    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(Card card)
{
    switch (card.rank)
    {
    case r2: return 2;
    case r3: return 3;
    case r4: return 4;
    case r5: return 5;
    case r6: return 6;
    case r7: return 7;
    case r8: return 8;
    case r9: return 9;
    case r10: return 10;
    case rJack: return 10;
    case rQueen: return 10;
    case rKing: return 10;
    case rAce: return 11;
    default: return 0;
    }
}

int deal(Card*& ptr_top)
{
    return getCardValue(*(ptr_top++));
}

bool playBlackjack(deck_type shuffled_deck)
{
    int dealer{};
    int player{};

    Card* ptr_topdeck{ &shuffled_deck[0] };

    dealer += deal(ptr_topdeck);
    player += deal(ptr_topdeck);
    player += deal(ptr_topdeck);

    std::cout << "Dealer has: " << dealer << "\n";
    std::cout << "Player has: " << player << "\n";

    char cont{'y'};
    while ((player < 21) && (cont == 'y'))
    {
        std::cout << "Hit? <y/n>: ";
        std::cin >> cont;

        if (cont == 'y')
        {
            player += deal(ptr_topdeck);
            std::cout << "Player has: " << player << "\n";
        }

        if (player > 21)
        {
            std::cout << "Player busts.\n";
            return false;
        }

    }

    while (dealer < 17)
    {
        dealer += deal(ptr_topdeck);
        std::cout << "Dealer has: " << dealer << "\n";

        if (dealer > 21)
        {
            std::cout << "Dealer busts.\n";
            return true;
        }

    }

    if (player > dealer)
    {
        std::cout << "You win!\n";
        return true;
    }
    else
    {
        std::cout << "You lose.\n";
        return false;
    }

}

int main()
{
    auto deck = createDeck();

    shuffleDeck(deck);

    printDeck(deck);

    playBlackjack(deck);

    return 0;
}