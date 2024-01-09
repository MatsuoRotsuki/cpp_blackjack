#pragma once
#include <iostream>
#include <memory>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include "UI/blackjack/message.h"
#include "state.h"
#include "accountmanager.h"
#include "clientmanager.hpp"

#define BACK_LOG 10

struct Client
{
    int socket;
    int id;
    std::thread thread;
    State state;
    Account *player = nullptr;
};
/**
 * Function to handle on Ctrl + C
*/
void HandleInterrupt(int signal);
void HandleClient(int client_socket, int id);
int FindClientSocketById(int id);
std::vector<Client> *getAllClients();
State getClientState(int id);
void setClientState(int id, State state);
void DispatchViewOnline(int id, Message reqMsg);
