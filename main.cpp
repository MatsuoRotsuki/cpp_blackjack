#include <iostream>
#include "blackjack.hpp"

int main()
{
    Deck *deck = new Deck(1);
    deck->Shuffle();
    Deck *discard = new Deck();
    Hand *hand = new Hand();
    
    hand->TakeCardFromDeck(deck);
    hand->TakeCardFromDeck(deck);
    hand->TakeCardFromDeck(deck);
    std::cout << hand->ToString() << std::endl;

    hand->DiscardHandToDeck(discard);
    std::cout << hand->ToString() << std::endl;
    std::cout << discard->ToString() << std::endl;

    delete hand;
    delete discard;
    delete deck;
}