#include "roommanager.hpp"

std::mutex RoomManager::s_mutex;
int RoomManager::s_nextId;

RoomManager::~RoomManager()
{
    std::cout << "RoomManager destroyed" << std::endl;
}

RoomManager &RoomManager::instance()
{
    static RoomManager s_instance;
    return s_instance;
}

int RoomManager::GetNextId()
{
    std::lock_guard<std::mutex> guard(s_mutex);
    return ++s_nextId;
}

void RoomManager::AddRoom(GameContext *game)
{
    std::lock_guard<std::mutex> guard(s_mutex);
    rooms.push_back(game);
}

GameContext *RoomManager::FindById(int id)
{
    std::lock_guard<std::mutex> guard(s_mutex);
    for (auto it = rooms.begin(); it != rooms.end(); it++)
    {
        GameContext *game = *it;
        if (game->id_ == id)
        {
            return game;
        }
    }
    return nullptr;
}

GameContext::GameContext()
    : id_(RoomManager::instance().GetNextId()), deck_(new Deck(1)), discarded_(new Deck()), dealerHand(new Hand()), state_(nullptr), currentTurn(-1), newPlayerTurnNumber(0)
{
    std::lock_guard<std::mutex> guard(mutex_);
    // Create deck and initialize
    std::cout << "Create new game" << std::endl;

    deck_->Shuffle();
    RoomManager::instance().AddRoom(this);

    this->SetState(new StateBetting);
}

GameContext::~GameContext()
{
    std::cout << "Room destroyed" << std::endl;
    for (auto &element : playerHands)
    {
        delete element;
    }
    delete state_;
    delete deck_;
    delete discarded_;
    delete dealerHand;
}

void GameContext::SetState(GameState *state)
{
    std::cout << "Game state set to " << typeid(*state).name() << std::endl;
    if (this->state_ != nullptr)
    {
        delete this->state_;
    }
    this->state_ = state;
    this->state_->SetContext(this);
}

void GameContext::CreateStateMsg()
{
    Message message;
    message.type = MessageType::SRV_GAME_STATE;
    message.payload.gameStateData.num_of_players = newPlayerTurnNumber;
    for (int i = 0; i < newPlayerTurnNumber; i++)
    {
        strcpy(message.payload.gameStateData.players[i].username, clients[i]->account_->username.c_str());
        message.payload.gameStateData.players[i].score = playerHands[i]->CalculateValue();
        message.payload.gameStateData.players[i].num_of_cards = playerHands[i]->Count();
        message.payload.gameStateData.players[i].money = clients[i]->account_->money;
        message.payload.gameStateData.players[i].bet = bet[i];
        for (int j = 0; j < playerHands[i]->Count(); j++)
        {
            Card *card = playerHands[i]->GetCard(j);
            message.payload.gameStateData.players[i].cards[j].rank = card->GetRank();
            message.payload.gameStateData.players[i].cards[j].suit = card->GetSuit();
        }
        // out come
    }
    message.payload.gameStateData.dealer_num_of_cards = dealerHand->Count();
    for (int i = 0; i < dealerHand->Count(); i++)
    {
        Card *card = dealerHand->GetCard(i);
        message.payload.gameStateData.dealer_cards[i].rank = card->GetRank();
        message.payload.gameStateData.dealer_cards[i].suit = card->GetSuit();
    }
    message.payload.gameStateData.dealer_score = dealerHand->CalculateValue();
    for (int i = 0; i < newPlayerTurnNumber; i++)
    {
        send(this->clients[i]->socket_, &message, sizeof(message), 0);
    }
}

void GameContext::AddClient(ClientContext *client)
{
    std::lock_guard<std::mutex> guard(mutex_);
    if (newPlayerTurnNumber >= 4)
    {
        return;
    }
    client->game_ = this;
    clients[newPlayerTurnNumber] = client;
    clients[newPlayerTurnNumber]->turn_ = newPlayerTurnNumber;
    playerHands[newPlayerTurnNumber] = new Hand();
    newPlayerTurnNumber++;
    CreateStateMsg();
}

void GameContext::Bet(int index, int betMoney)
{
    std::lock_guard<std::mutex> guard(mutex_);
    bet[index] = betMoney;
    for (int i = 0; i < newPlayerTurnNumber; i++)
    {
        if (bet[i] == 0)
        {
            return;
        }
    }
    std::cout << "Start round" << std::endl;

    if (deck_->CardsLeft() < 16)
    {
        deck_->Reload(discarded_);
    }

    dealerHand->TakeCardFromDeck(deck_);
    dealerHand->TakeCardFromDeck(deck_);

    for (int i = 0; i < newPlayerTurnNumber; i++)
    {
        playerHands[i]->TakeCardFromDeck(deck_);
        playerHands[i]->TakeCardFromDeck(deck_);
    }
    CreateStateMsg();

    SetState(new StatePlayerTurn);
}

void GameState::SetContext(GameContext *context)
{
    this->context_ = context;
}

void GameState::HandlePlayerBet(int idx, Message message)
{
    Message msg;
    msg.type = MessageType::SRV_INVALID_REQUEST;
    strcpy(msg.payload.invalidRequestData.message, "Bad request");

    send(this->context_->clients[idx]->socket_, &msg, sizeof(msg), 0);
}

void GameState::HandlePlayerAction(int idx, Message message)
{
    Message msg;
    msg.type = MessageType::SRV_INVALID_REQUEST;
    strcpy(msg.payload.invalidRequestData.message, "Bad request");

    send(this->context_->clients[idx]->socket_, &msg, sizeof(msg), 0);
}

void StateBetting::HandlePlayerBet(int idx, Message message)
{
    std::lock_guard<std::mutex> guard(this->context_->mutex_);
    int betMoney = message.payload.playerBetData.bet;
    this->context_->bet[idx] = betMoney;
    for (int i = 0; i < this->context_->newPlayerTurnNumber; i++)
    {
        if (this->context_->bet[i] == 0)
        {
            return;
        }
    }

    std::cout << "Start round" << std::endl;

    if (this->context_->deck_->CardsLeft() < 16)
    {
        this->context_->deck_->Reload(this->context_->discarded_);
    }

    this->context_->dealerHand->TakeCardFromDeck(this->context_->deck_);
    this->context_->dealerHand->TakeCardFromDeck(this->context_->deck_);

    for (int i = 0; i < this->context_->newPlayerTurnNumber; i++)
    {
        this->context_->playerHands[i]->TakeCardFromDeck(this->context_->deck_);
        this->context_->playerHands[i]->TakeCardFromDeck(this->context_->deck_);
    }
    this->context_->CreateStateMsg();

    this->context_->currentTurn = 0;
    this->context_->SetState(new StatePlayerTurn);
}

void StatePlayerTurn::HandlePlayerAction(int idx, Message message)
{
    std::lock_guard<std::mutex> guard(this->context_->mutex_);

    // Get all betted players
    int betted = 0;
    for (int i = 0 ; i < this->context_->newPlayerTurnNumber; i++)
    {
        if (this->context_->bet[i] != 0)
        {
            betted++;
        }
    }

    // Check if it's right for player
    if (this->context_->currentTurn != idx)
    {
        return;
    }

    if (this->context_->bet[idx] == 0)
    {
        return;
    }

    if (message.payload.PlayerActionData.action == PlayerAction::HIT)
    {
        if (this->context_->deck_->IsEmpty())
        {
            this->context_->deck_->Reload(this->context_->discarded_);
            this->context_->deck_->Shuffle();
        }

        this->context_->playerHands[idx]->TakeCardFromDeck(this->context_->deck_);

        std::cout << this->context_->clients[idx]->account_->username << " got a card." << std::endl;

        if (this->context_->playerHands[idx]->CalculateValue() > 20)
        {
            //Burst or Blackjack
            this->context_->currentTurn++;
        }

        this->context_->CreateStateMsg();
    }
    else if (message.payload.PlayerActionData.action == PlayerAction::STAND)
    {
        std::cout << this->context_->clients[idx]->account_->username << " stand." << std::endl;
        this->context_->currentTurn++;

        this->context_->CreateStateMsg();
    }

    if (this->context_->currentTurn == betted) {
        // Control dealer
        
        while(this->context_->dealerHand->CalculateValue() < 17)
        {
            if (this->context_->deck_->IsEmpty())
            {
                this->context_->deck_->Reload(this->context_->discarded_);
                this->context_->deck_->Shuffle();
            }

            this->context_->dealerHand->TakeCardFromDeck(this->context_->deck_);

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            this->context_->CreateStateMsg();
        }

        this->context_->CreateStateMsg();

        for (int i = 0; i < this->context_->currentTurn; i++)
        {
            if (this->context_->dealerHand->CalculateValue() > 21){
                // Dealer burst
                this->context_->clients[i]->account_->wins++;
                this->context_->clients[i]->account_->money += this->context_->bet[i];
                this->context_->clients[i]->account_->save();
            }
            else if (this->context_->playerHands[i]->CalculateValue() > this->context_->dealerHand->CalculateValue())
            {
                //Win
                this->context_->clients[i]->account_->wins++;
                this->context_->clients[i]->account_->money += this->context_->bet[i];
                this->context_->clients[i]->account_->save();
            } else if (this->context_->playerHands[i]->CalculateValue() < this->context_->dealerHand->CalculateValue()) {
                //Lose
                this->context_->clients[i]->account_->loses++;
                this->context_->clients[i]->account_->money -= this->context_->bet[i];
                this->context_->clients[i]->account_->save();
            } else {
                this->context_->clients[i]->account_->pushes++;
                this->context_->clients[i]->account_->save();
            }
        }

        //Outcome
        this->context_->CreateStateMsg();

        this->context_->dealerHand->DiscardHandToDeck(this->context_->discarded_);
        for (int i = 0; i < this->context_->currentTurn; i++)
        {
            this->context_->playerHands[i]->DiscardHandToDeck(this->context_->discarded_);
        }

        memset(this->context_->bet, 0, sizeof(this->context_->bet));

        this->context_->currentTurn = -1;

        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        this->context_->CreateStateMsg();


        this->context_->SetState(new StateBetting);
    }
}
