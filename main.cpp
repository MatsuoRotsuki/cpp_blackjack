#include <iostream>
#include "hand.h"
#include "game.h"

int main()
{
    Deck deck = Deck(2);
    deck.shuffle();
    std::cout << deck.toString();
}