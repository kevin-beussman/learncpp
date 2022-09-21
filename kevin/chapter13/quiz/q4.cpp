#include <algorithm> // std::shuffle
#include <array>
#include <cassert>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937

class Card
{
public:
    enum Suit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum Rank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };
private:
    Rank m_rank{};
    Suit m_suit{};
public:
    Card(Rank rank=Rank::rank_ace, Suit suit=Suit::spade): m_rank{rank}, m_suit{suit} {};

    void print() const
    {
        switch (m_rank)
        {
        case Rank::rank_2:      std::cout << '2';   break;
        case Rank::rank_3:      std::cout << '3';   break;
        case Rank::rank_4:      std::cout << '4';   break;
        case Rank::rank_5:      std::cout << '5';   break;
        case Rank::rank_6:      std::cout << '6';   break;
        case Rank::rank_7:      std::cout << '7';   break;
        case Rank::rank_8:      std::cout << '8';   break;
        case Rank::rank_9:      std::cout << '9';   break;
        case Rank::rank_10:     std::cout << 'T';   break;
        case Rank::rank_jack:   std::cout << 'J';   break;
        case Rank::rank_queen:  std::cout << 'Q';   break;
        case Rank::rank_king:   std::cout << 'K';   break;
        case Rank::rank_ace:    std::cout << 'A';   break;
        default:
            std::cout << '?';
            break;
        }

        switch (m_suit)
        {
        case Suit::club:       std::cout << 'C';   break;
        case Suit::diamond:    std::cout << 'D';   break;
        case Suit::heart:      std::cout << 'H';   break;
        case Suit::spade:      std::cout << 'S';   break;
        default:
            std::cout << '?';
            break;
        }
    }

    int value() const
    {
        switch (m_rank)
        {
        case Rank::rank_2:        return 2;
        case Rank::rank_3:        return 3;
        case Rank::rank_4:        return 4;
        case Rank::rank_5:        return 5;
        case Rank::rank_6:        return 6;
        case Rank::rank_7:        return 7;
        case Rank::rank_8:        return 8;
        case Rank::rank_9:        return 9;
        case Rank::rank_10:       return 10;
        case Rank::rank_jack:     return 10;
        case Rank::rank_queen:    return 10;
        case Rank::rank_king:     return 10;
        case Rank::rank_ace:      return 11;
        default:
            assert(false && "should never happen");
            return 0;
        }
    }
};

class Deck
{
    using Decktype = std::array<Card, 52>;
    using Index = Decktype::size_type;
private:
    Decktype m_deck{};
    int m_cardIndex{0};
public:
    Deck()
    {
        Index index{ 0 };

        for (int suit{ 0 }; suit < static_cast<int>(Card::Suit::max_suits); ++suit)
        {
            for (int rank{ 0 }; rank < static_cast<int>(Card::Rank::max_ranks); ++rank)
            {
                m_deck[index] = Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
                ++index;
            }
        }
    }

    void print() const
    {
        for (const auto& card : m_deck)
        {
            card.print();
            std::cout << ' ';
        }

        std::cout << '\n';
    }

    void shuffle()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

        std::shuffle(m_deck.begin(), m_deck.end(), mt);

        m_cardIndex = 0;
    }

    const Card& dealCard()
    {
        const Card& card{m_deck[m_cardIndex]};
        ++m_cardIndex;

        return card;
    }
};

// Maximum score before losing.
constexpr int g_maximumScore{ 21 };

// Minimum score that the dealer has to have.
constexpr int g_minimumDealerScore{ 17 };

class Player
{
private:
    int m_score{0};

public:
    int drawCard(Deck& deck)
    {
        const Card& card{ deck.dealCard() };

        m_score += card.value();

        return card.value();
    }

    int score() const
    {
        return m_score;
    }

    bool isBust()
    {
        return (m_score > g_maximumScore);
    }
};

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player)
{
    while (true)
    {
        if (player.isBust())
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                int cardValue{ player.drawCard(deck) };
                std::cout << "You were dealt a " << cardValue << " and now have " << player.score() << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer)
{
    // Draw cards until we reach the minimum value.
    while (dealer.score() < g_minimumDealerScore)
    {
        int cardValue{ dealer.drawCard(deck) };
        std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer.score() << '\n';

    }

    // If the dealer's score is too high, they went bust.
    if (dealer.isBust())
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

bool playBlackjack(Deck& deck)
{
    // Create the dealer and give them 1 card.
    Player dealer{};
    dealer.drawCard(deck);

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.score() << '\n';

    // Create the player and give them 2 cards.
    Player player{};
    player.drawCard(deck);
    player.drawCard(deck);

    std::cout << "You have: " << player.score() << '\n';

    if (playerTurn(deck, player))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck, dealer))
    {
        // The dealer went bust, the player wins.
        return true;
    }

    return (player.score() > dealer.score());
}

int main()
{
    Deck deck{};

    deck.shuffle();

    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}