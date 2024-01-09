#pragma once
#include <iostream>
#include <memory>
#include <errno.h>
#include <thread>
#include <mutex>
#include <list>
#include <atomic>

class Room;
/**
 * The RoomManager implemented using Singleton design pattern
 */
class RoomManager
{
private:
    static RoomManager *p_instance;
    static std::mutex mutex_;
    std::list<Room *> rooms_;

protected:
    RoomManager() {}
    ~RoomManager() {}
public:
    RoomManager(RoomManager &other) = delete;
    void operator=(const RoomManager &) = delete;
    static RoomManager *instance();
    void all();
    void create();
    void destroy();
    void join();
};

class Room
{
    
}