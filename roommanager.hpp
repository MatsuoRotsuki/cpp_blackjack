#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <iostream>
#include <memory>
#include <errno.h>
#include <thread>
#include <mutex>
#include <list>
#include <map>
#include <thread>
#include <sys/socket.h>
#include "clientmanager.hpp"
#include "UI/blackjack/message.h"
#include "blackjack.hpp"

class GameContext;

class ClientContext;

class GameState
{
protected:
    GameContext *context_;

public:
    virtual ~GameState() {}
    void SetContext(GameContext *context);

    virtual void HandlePlayerBet(int idx, Message message);
    virtual void HandlePlayerAction(int idx, Message message);
    virtual void HandleLeaveRoom(int idx, Message message);
    virtual void HandleInvite(int idx, Message message);
};

class GameContext
{
public:
    GameContext();
    ~GameContext();
    void SetState(GameState *state);
    GameState *state_;
    Deck* deck_;
    Deck* discarded_;
    Hand* dealerHand;
    Hand* playerHands[5];
    int bet[5] = {0, 0, 0, 0};
    ClientContext* clients[5];
    int id_;
    int newPlayerTurnNumber;
    int currentTurn;
    std::mutex mutex_;
    void CreateStateMsg();
    void AddClient(ClientContext *client);
};

class StateBetting : public GameState {
public:
    void HandlePlayerBet(int idx, Message message) override;
    void HandleLeaveRoom(int idx, Message message) override;
};

class StatePlayerTurn: public GameState {
public:
    void HandlePlayerAction(int idx, Message message) override;
};

class RoomManager
{
public:
    RoomManager(RoomManager &other) = delete;
    void operator=(const RoomManager &) = delete;
    static RoomManager &instance();
    int GetNextId();
    void AddRoom(GameContext *game);
    GameContext* FindById(int id);
    std::list<GameContext*> GetAllRooms();

private:
    explicit RoomManager() {}
    ~RoomManager();
    std::list<GameContext*> rooms;
    static std::mutex s_mutex;
    static int s_nextId;
};

#endif // ROOMMANAGER_H