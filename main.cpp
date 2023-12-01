#include <bits/stdc++.h>
#include "hand.h"
#include "game.h"

int main()
{
    Deck deck = Deck(2);
    Hand hand = Hand();
    Card card = deck.dealCard();
    hand.addCard(card);
    card = deck.dealCard();
    hand.addCard(card);
    card = deck.dealCard();
    hand.addCard(card);
    std::cout << hand.calculateValue();

    // Game game = Game();
}