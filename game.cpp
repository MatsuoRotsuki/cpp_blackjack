#include "game.h"

Game::Game()
{
    deck = Deck(2);
    discarded = Deck();

    dealer = Dealer();
    player = Account();

    deck.shuffle();
    startRound();
}

void Game::startRound()
{
    if (wins > 0 || losses > 0 || pushes > 0)
    {
        std::cout << "\nStart Next Round... Wins: " << wins << " Loses: " << losses << " Pushes: " << pushes << std::endl;
        dealer.getHand().discardHandToDeck(discarded);
        player.getHand().discardHandToDeck(discarded);
    }

    if (deck.cardsLeft() < 16)
    {
        deck.reloadDeckFromDiscard(discarded);
    }

    dealer.getHand().takeCardFromDeck(deck);
    player.getHand().takeCardFromDeck(deck);

    dealer.getHand().takeCardFromDeck(deck);
    player.getHand().takeCardFromDeck(deck);

    dealer.printFirstHand();
    player.printHand();

    if (dealer.hasBlackjack())
    {
        dealer.printHand();

        if (player.hasBlackjack())
        {
            std::cout << "You both have Blackjack - Push" << std::endl;
            pushes++;
            startRound();
        }
    }

    // Check if player has blackjack to start
    // If we got to this point, we already know the dealer didn't have blackjack
    if (player.hasBlackjack())
    {
        std::cout << "You have Blackjack! You win!" << std::endl;
        wins++;
        startRound();
    }

    player.makeDecision(deck, discarded);

    if (player.getHand().calculateValue() > 21)
    {
        std::cout << "You have gone over 21. Burst." << std::endl;
        losses++;
        startRound();
    }

    dealer.printHand();
    while (dealer.getHand().calculateValue() < 17)
    {
        dealer.hit(deck, discarded);
    }

    // Check won wins
    if (dealer.getHand().calculateValue() > 21)
    {
        std::cout << "Dealer burst" << std::endl;
        wins++;
    }
    else if (dealer.getHand().calculateValue() > player.getHand().calculateValue())
    {
        std::cout << "You lose." << std::endl;
        losses++;
    }
    else if (player.getHand().calculateValue() > dealer.getHand().calculateValue())
    {
        std::cout << "You win." << std::endl;
        wins++;
    }
    else
    {
        std::cout << "Push." << std::endl;
        pushes++;
    }

    startRound();
}
