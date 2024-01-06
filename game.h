#include "deck.h"
#include "player.h"

class Game {
private:
    Deck deck;
    Deck discarded;
    Dealer dealer;
    Account player;
    int wins, losses, pushes;
public:
    Game();
    void startRound();
};