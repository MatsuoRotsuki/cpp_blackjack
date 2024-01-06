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

/**
 * Handle function for CLT_DISCONNECT
*/
void EndConnection(int id);

/**
 * Handle function for INVALID
*/
void DispatchInvalid(int client_socket, int id);

/**
 * Handle function for CLT_LOGIN_REQ
*/
void DispatchLogin(int id, Message loginMsg);

/**
 * Handle function for CLT_SIGNUP_REQ
*/
void DispatchSignup(int id, Message signUpMsg);

/**
 * Handle function for CLT_VIEWONLINE_REQ
*/
void DispatchViewOnline(int id, Message reqMsg);
