#pragma once

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <mutex>
#include <thread>
#include <chrono>
#include <errno.h>
#include <memory>

class Client
{
private:
public:
};

class ClientManager
{
public:
    ~ClientManager();
    ClientManager(ClientManager &other) = delete;
    void operator=(const ClientManager &) = delete;
    static ClientManager *GetInstance();
    
private:
    ClientManager();
    static ClientManager *s_instance;
    static std::mutex s_mutex;
    static int s_nextId;
};