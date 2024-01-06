#pragma
#include "hand.h"

class Person
{
private:
    Hand hand;
    std::string name;

public:
    Person();
    Hand getHand();
    void setHand(Hand _hand);
    std::string getName();
    void setName(std::string _name);
    bool hasBlackjack();
    void printHand();
    void hit(Deck deck, Deck discard);
};

class Dealer : public Person
{
public:
    Dealer();
    void printFirstHand();
};

class Account : public Person
{
public:
    Account();
    void makeDecision(Deck deck, Deck discard);
};