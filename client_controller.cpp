#include "client.h"

void DispatchDisconnect()
{
}

void DispatchReadyList(Message message)
{
    int num_of_players = message.payload.readyListResponseData.num_of_players;
    for (int i = 0; i < num_of_players; i++) {
        PlayerData player = message.payload.readyListResponseData.players[i];
        std::cout << player.id << std::endl;
        std::cout << player.username << std::endl;
        std::cout << player.name << std::endl;
        std::cout << player.money << std::endl;
        std::cout << player.wins << std::endl;
        std::cout << player.loses << std::endl;
        std::cout << player.pushes << std::endl;
        std::cout << std::endl;
    }
}