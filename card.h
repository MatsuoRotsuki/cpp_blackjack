#pragma once
#include <iostream>

enum class Suit
{
    CLUB = 0,
    DIAMOND,
    HEART,
    SPADE,
};

enum class Rank
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

class Card
{
public:
    Card(Rank _rank, Suit _suit);
    std::string toString() const;
    int getValue() const;
    Suit getSuit() const;
    Rank getRank() const;

private:
    Suit suit;
    Rank rank;
    std::string rankToString() const;
    std::string suitToString() const;
};