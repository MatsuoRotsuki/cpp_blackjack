#include "blackjack.hpp"

Card::Card(Rank rank, Suit suit) : rank_(rank), suit_(suit) {}
Card::Card(Suit suit, Rank rank) : rank_(rank), suit_(suit) {}

std::string Card::rankToString() const
{
    switch (rank_)
    {
    case Rank::ACE:
        return "Ace";
    case Rank::TWO:
        return "Two";
    case Rank::THREE:
        return "Three";
    case Rank::FOUR:
        return "Four";
    case Rank::FIVE:
        return "Five";
    case Rank::SIX:
        return "Six";
    case Rank::SEVEN:
        return "Seven";
    case Rank::EIGHT:
        return "Eight";
    case Rank::NINE:
        return "Nine";
    case Rank::TEN:
        return "Ten";
    case Rank::JACK:
        return "Jack";
    case Rank::QUEEN:
        return "Queen";
    case Rank::KING:
        return "King";
    default:
        return "Unknown Rank";
    }
}

std::string Card::suitToString() const
{
    switch (suit_)
    {
    case Suit::HEART:
        return "Hearts";
    case Suit::DIAMOND:
        return "Diamonds";
    case Suit::CLUB:
        return "Clubs";
    case Suit::SPADE:
        return "Spades";
    default:
        return "Unknown Suit";
    }
}

std::string Card::ToString() const
{
    return "[" + rankToString() + " of " + suitToString() + "] (" + std::to_string(GetValue()) + ")";
}

int Card::GetValue() const
{
    switch (rank_)
    {
    case Rank::ACE:
        return 11;
    case Rank::TWO:
        return 2;
    case Rank::THREE:
        return 3;
    case Rank::FOUR:
        return 4;
    case Rank::FIVE:
        return 5;
    case Rank::SIX:
        return 6;
    case Rank::SEVEN:
        return 7;
    case Rank::EIGHT:
        return 8;
    case Rank::NINE:
        return 9;
    case Rank::TEN:
        return 10;
    case Rank::JACK:
        return 10;
    case Rank::QUEEN:
        return 10;
    case Rank::KING:
        return 10;
    default:
        return -1;
    }
}

Suit Card::GetSuit() const
{
    return suit_;
}

Rank Card::GetRank() const
{
    return rank_;
}

Deck::Deck(int numberOfDecks)
{
    for (int i = 0; i < numberOfDecks; i++)
    {
        for (int s = static_cast<int>(Suit::CLUB); s <= static_cast<int>(Suit::SPADE); s++)
        {
            for (int r = static_cast<int>(Rank::ACE); r <= static_cast<int>(Rank::KING); r++)
            {
                Card *card = new Card(static_cast<Rank>(r), static_cast<Suit>(s));
                this->deck.push_back(card);
            }
        }
    }
}

Deck::~Deck()
{
    for (auto it = this->deck.begin(); it != this->deck.end(); it++)
    {
        Card *card = *it;
        delete card;
    }
}

void Deck::Shuffle()
{
    std::vector<Card*> deckVec(deck.begin(), deck.end());
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deckVec.begin(), deckVec.end(), g);
    std::copy(deckVec.begin(), deckVec.end(), deck.begin());
}

Card *Deck::DealCard()
{
    Card* cardToDeal = this->deck.front();
    this->deck.erase(this->deck.begin());
    return cardToDeal;
}

bool Deck::IsNotEmpty() const
{
    return !this->deck.empty();
}

bool Deck::IsEmpty() const
{
    return this->deck.empty();
}

void Deck::EmptyDeck()
{
    this->deck.clear();
}

std::list<Card*> Deck::GetDeck()
{
    return deck;
}

void Deck::AddCards(std::list<Card *> cards)
{
    for (auto it = cards.begin(); it != cards.end(); it++)
    {
        Card *card = *it;
        deck.push_back(card);
    }
}

void Deck::Reload(Deck *discarded)
{
    this->deck.splice(this->deck.end(), discarded->GetDeck());
    Shuffle();
    discarded->EmptyDeck();
}

int Deck::CardsLeft()
{
    return this->deck.size();
}

std::string Deck::ToString() const
{
    std::string result = "";
    for (auto it = this->deck.begin(); it != this->deck.end(); it++)
    {
        Card *card = *it;
        result += card->ToString();
        result += "\n";
    }
    return result;
}

Deck::Deck()
{
}

void Hand::AddCard(Card *card)
{
    this->hand.push_back(card);
}

void Hand::TakeCardFromDeck(Deck *deck)
{
    Card *card = deck->DealCard();
    AddCard(card);
}

void Hand::DiscardHandToDeck(Deck *discarded)
{
    discarded->AddCards(hand);
    hand.clear();
}

int Hand::CalculateValue() const
{
    int value = 0;
    int aceCount = 0;
    for (auto it = hand.begin(); it != hand.end(); it++)
    {
        Card *card = *it;
        value += card->GetValue();
        if (card->GetValue() == 11)
        {
            aceCount++;
        }
    }

    if (value > 21 && aceCount > 0)
    {
        while(aceCount > 0 && value > 21)
        {
            aceCount--;
            value -= 10;
        }
    }
    return value;
}

Card *Hand::GetCard(int idx) const
{
    if (idx < hand.size())
    {
        auto it = hand.begin();
        std::advance(it, idx);
        Card *element = *it;
        return element;
    } else {
        return nullptr;
    }
}

int Hand::Count() const
{
    return hand.size();
}

std::string Hand::ToString() const
{
    std::string result = "";
    for (auto it = hand.begin(); it != hand.end(); it++)
    {
        Card *card = *it;
        result += card->ToString();
        result += " - ";
    }
    return result;
}
