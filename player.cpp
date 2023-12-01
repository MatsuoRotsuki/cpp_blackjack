#include "player.h"


Person::Person()
{
    name = "";
    hand = Hand();
}

Hand Person::getHand()
{
    return hand;
}

void Person::setHand(Hand _hand)
{
    hand = _hand;
}

std::string Person::getName()
{
    return name;
}

void Person::setName(std::string _name)
{
    name = _name;
}

bool Person::hasBlackjack()
{
    return (getHand().calculateValue() == 21);
}

void Person::printHand()
{
    std::cout << name << "\'s hand looks like this: " << std::endl;
    std::cout << hand.toString() << " Valued at: " << hand.calculateValue() << std::endl;
}

void Person::hit(Deck deck, Deck discard)
{
    if (!deck.isNotEmpty())
    {
        deck.reloadDeckFromDiscard(discard);
    }
    hand.takeCardFromDeck(deck);
    std::cout << name << " gets a card" << std::endl;
    printHand();
}

Dealer::Dealer()
{
    setName("Dealer");
}

void Dealer::printFirstHand()
{
    std::cout << "The dealer's hand looks shit like this:" << std::endl;
    std::cout << getHand().getCard(0).toString() << std::endl;
    std::cout << "The second card is face down" << std::endl;
}

Player::Player()
{
    setName("Player");
}

void Player::makeDecision(Deck deck, Deck discard)
{
    int decision = 0;
    bool getNum = true;

    std::cout << "Would you like to: 1) Hit or 2) Stand"<< std::endl;
    std::cin >> decision;

    if (decision == 1)
    {
        hit(deck, discard);

        if (getHand().calculateValue() > 20)
        {
            return;
        }
        else
        {
            makeDecision(deck, discard);
        }
    }
    else
    {
        std::cout << "You stand." << std::endl;
    }
}
