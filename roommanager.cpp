#include "roommanager.h"

RoomManager *RoomManager::p_instance{nullptr};
std::mutex RoomManager::mutex_;

RoomManager *RoomManager::instance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (p_instance == nullptr)
    {
        p_instance = new RoomManager();
    }
    return p_instance;
}