#include "deck.h"

Deck::Deck()
{
}

Deck::Deck(int numberOfDecks)
{
    for (int i = 0; i < numberOfDecks; i++)
    {
        for (int s = static_cast<int>(Suit::CLUB); s <= static_cast<int>(Suit::SPADE); s++)
        {
            for (int r = static_cast<int>(Rank::ACE); r <= static_cast<int>(Rank::KING); r++)
            {
                deck.emplace_back(static_cast<Rank>(r), static_cast<Suit>(s));
            }
        }
    }
}

Deck::Deck(std::vector<Card> cards)
{
    deck = cards;
}

std::vector<Card> Deck::getDeck()
{
    return deck;
}

std::string Deck::toString()
{
    std::string result = "";
    for (Card card : deck)
    {
        result += card.toString();
        result += "\n";
    }
    return result;
}

void Deck::shuffle()
{
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(deck.begin(), deck.end(), rng);
}

Card Deck::dealCard()
{
    Card cardToDeal = deck[0];
    deck.erase(deck.begin());
    return cardToDeal;
}

bool Deck::isNotEmpty() const
{
    return !deck.empty();
}

void Deck::emptyDeck()
{
    deck.clear();
}

void Deck::addCards(std::vector<Card> cards)
{
    for (std::vector<Card>::iterator it = cards.begin(); it != cards.end(); it++)
    {
        deck.push_back(*it);
    }
}

void Deck::addCard(Card card)
{
    deck.push_back(card);
}

void Deck::reloadDeckFromDiscard(Deck discard)
{
    addCards(discard.getDeck());
    shuffle();
    discard.emptyDeck();
    std::cout << "Ran out of cards, creating new deck from discard pile & shuffling deck.";
}

int Deck::cardsLeft() const
{
    return deck.size();
}
