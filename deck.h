#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <random>
#include "card.h"

class Deck
{
private:
    std::vector<Card> deck;

public:
    Deck();
    Deck(int numberOfDecks);
    Deck(std::vector<Card> cards);
    std::vector<Card> getDeck();
    std::string toString();
    void shuffle();

    /**
     * Return top card
    */
    Card dealCard();
    bool isNotEmpty();
    void emptyDeck();
    void addCards(std::vector<Card> cards);
    void reloadDeckFromDiscard(Deck discard);
    int cardsLeft();
};