#pragma once
#include "card.h"
#include "deck.h"

class Hand
{
public:
    Hand();
    void addCard(Card card);
    void takeCardFromDeck(Deck deck);
    void discardHandToDeck(Deck discardedDeck);
    int calculateValue() const;
    Card getCard(int idx) const;
    std::string toString() const;

private:
    std::vector<Card> hand;
};