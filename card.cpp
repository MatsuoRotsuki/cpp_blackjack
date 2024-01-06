#include "card.h"

Card::Card(Rank _rank, Suit _suit) : rank(_rank), suit(_suit) {}

std::string Card::toString() const
{
    return "[" + rankToString() + " of " + suitToString() + "] (" + std::to_string(getValue()) + ")";
}

Suit Card::getSuit() const
{
    return suit;
}

Rank Card::getRank() const
{
    return rank;
}

int Card::getValue() const
{
    switch (rank)
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

std::string Card::rankToString() const
{
    switch (rank)
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
    switch (suit)
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
