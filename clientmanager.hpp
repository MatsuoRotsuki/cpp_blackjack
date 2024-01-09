#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <mutex>
#include <thread>
#include <chrono>
#include <errno.h>
#include <memory>
#include <sys/socket.h>
#include "accountmanager.h"
#include "UI/blackjack/message.h"

class ClientContext;

class Account;

class ClientState
{
    /**
     * @var Context
     */
protected:
    ClientContext *context_;

public:
    virtual ~ClientState()
    {
    }

    void SetContext(ClientContext *context)
    {
        this->context_ = context;
    }

    virtual void HandleDisconnect(Message message);
    virtual void HandleSignUpRequest(Message message);
    virtual void HandleLoginRequest(Message message);
    virtual void HandleRoomListRequest(Message message);
    virtual void HandleReadyListRequest(Message message);
    virtual void HandleCreateRoomRequest(Message message);
    virtual void HandleJoinRoomRequest(Message message);
};

class ClientContext
{
public:
    ClientContext(int socket, int id, std::thread &&thread, ClientState *state);
    ~ClientContext();
    void SetState(ClientState *state);
    int socket_;
    int id_;
    std::thread thread_;
    ClientState *state_;
    Account *account_;
};

class StateUnloggedIn : public ClientState
{
public:
    // void HandleDisconnect(Message message) override;
    void HandleSignUpRequest(Message message) override;
    void HandleLoginRequest(Message message) override;
};

class StateReady : public ClientState
{
    // void HandleDisconnect(Message message) override;
    void HandleRoomListRequest(Message message) override;
    void HandleReadyListRequest(Message message) override;
    void HandleCreateRoomRequest(Message message) override;
    void HandleJoinRoomRequest(Message message) override;
};

class StatePlaying : public ClientState
{
};

/**
 * ClientManager là lớp có trách nhiệm quản lý các client đang kết nối
 */
class ClientManager
{
public:
    ClientManager(ClientManager &other) = delete;
    void operator=(const ClientManager &) = delete;
    static ClientManager &instance();
    void AddClient(ClientContext *client);
    void RemoveClient(ClientContext *client);
    std::list<ClientContext*> GetLoggedClients();
    int GetNextId();
    ClientContext* getClientById(int id);

private:
    explicit ClientManager();
    ~ClientManager();
    static std::mutex s_mutex;
    static int s_nextId;
    std::map<int, ClientContext*> clients;
};

#endif