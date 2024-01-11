#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <time.h>
#include <string>
#include "UI/blackjack/message.h"

class Card
{
public:
    Card(Rank rank, Suit suit);
    Card(Suit suit, Rank rank);
    std::string ToString() const;
    int GetValue() const;
    Suit GetSuit() const;
    Rank GetRank() const;
private:
    Suit suit_;
    Rank rank_;
    std::string rankToString() const;
    std::string suitToString() const;
};

class Deck
{
public:
    Deck(int numberOfDecks);
    ~Deck();
    void Shuffle();
    Card* DealCard();
    bool IsNotEmpty() const;
    bool IsEmpty() const;
    void EmptyDeck();
    std::list<Card*> GetDeck();
    void AddCards(std::list<Card*> cards);
    void Reload(Deck *discarded);
    int CardsLeft();
    std::string ToString() const;
    Deck();
    
private:
    
    std::list<Card*> deck;
};

class Hand
{
public:
    ~Hand();
    void AddCard(Card *card);
    void TakeCardFromDeck(Deck *deck);
    void DiscardHandToDeck(Deck *discarded);
    int CalculateValue() const;
    Card* GetCard(int idx) const;
    int Count() const;
    std::string ToString() const;
private:
    std::list<Card*> hand;
};

#endif // BLACKJACK_H