#include "hand.h"

Hand::Hand()
{
}

Hand::Hand(std::vector<Card> cards)
{
    for (std::vector<Card>::iterator it = cards.begin(); it != cards.end(); it++)
    {
        hand.push_back(*it);
    }
}

void Hand::addCard(Card card)
{
    hand.push_back(card);
}

void Hand::takeCardFromDeck(Deck deck)
{
    Card card = deck.dealCard();
    addCard(card);
}

void Hand::discardHandToDeck(Deck discardedDeck)
{
    discardedDeck.addCards(hand);
    hand.clear();
}

int Hand::calculateValue() const
{
    int value = 0;
    int aceCount = 0;
    for (Card card : hand)
    {
        value += card.getValue();
        // Count how many aces have been added
        if (card.getValue() == 11)
        {
            aceCount++;
        }
    }
    // If we have a scenario where we have multiple aces, as may be the case of drawing 10, followed by two or more aces, (10+11+1 > 21)
    // Go back and set each ace to 1 until get back under 21, if possible
    if (value > 21 && aceCount > 0)
    {
        while (aceCount > 0 && value > 21)
        {
            aceCount--;
            value -= 10;
        }
    }
    return value;
}

Card Hand::getCard(int idx) const
{
    return hand[idx];
}

std::string Hand::toString() const
{
    std::string result = "";
    for (Card card : hand)
    {
        result += card.toString();
        result += " - ";
    }
    return result;
}
