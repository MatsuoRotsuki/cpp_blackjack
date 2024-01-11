#include "client.h"
#include "blackjack.hpp"

void DispatchDisconnect()
{
}

void DispatchReadyList(Message message)
{
    int num_of_players = message.payload.readyListResponseData.num_of_players;
    for (int i = 0; i < num_of_players; i++) {
        PlayerData player = message.payload.readyListResponseData.players[i];
        std::cout << player.id << std::endl;
        std::cout << player.client_id << std::endl;
        std::cout << player.username << std::endl;
        std::cout << player.name << std::endl;
        std::cout << player.money << std::endl;
        std::cout << player.wins << std::endl;
        std::cout << player.loses << std::endl;
        std::cout << player.pushes << std::endl;
        std::cout << std::endl;
    }
}

void DispatchRoomList(Message message)
{
    struct RoomListResponsePayload payload = message.payload.roomListResponseData;
    int num_of_players = payload.num_of_players;
    int num_of_rooms = payload.num_of_rooms;
    for (int i = 0; i < num_of_rooms; i++)
    {
        RoomData data = message.payload.roomListResponseData.rooms[i];
        std::cout << "id: " << data.id << std::endl;
        std::cout << "num_players: " << data.num_of_players << std::endl;
        std::cout << std::endl;
    }
    for (int i = 0; i < num_of_players; i++)
    {
        PlayerData data = message.payload.roomListResponseData.players[i];
        std::cout << "id: " << data.id << std::endl;
        std::cout << "client id: " << data.client_id << std::endl;
        std::cout << "username: " << data.username << std::endl;
        std::cout << "name: " << data.name << std::endl;
        std::cout << "money: " << data.money << std::endl;
        std::cout << "wins: " << data.wins << std::endl;
        std::cout << "loses: " << data.loses << std::endl;
        std::cout << "pushes: " << data.pushes << std::endl;
        if (data.state == State::PLAYING)
        {
            std::cout << "state: Playing" << std::endl;
        } else if (data.state == State::READY)
        {
            std::cout << "state: Ready" << std::endl;
        }
        std::cout << std::endl;
    }
}

void DispatchGameState(Message message)
{
    std::cout << "num_of_players: " << message.payload.gameStateData.num_of_players << std::endl;
    std::cout << "dealer_num_cards: " << message.payload.gameStateData.dealer_num_of_cards << std::endl;
    std::cout << "dealer_score: " << message.payload.gameStateData.dealer_score << std::endl;
    for (int i = 0; i < message.payload.gameStateData.dealer_num_of_cards; i++)
    {
        Suit suit = message.payload.gameStateData.dealer_cards[i].suit;
        Rank rank = message.payload.gameStateData.dealer_cards[i].rank;
        Card *card = new Card(suit, rank);
        std::cout << card->ToString() << std::endl;
        delete card;
    }

    for (int i = 0 ; i < message.payload.gameStateData.num_of_players; i++) {
        std::cout << std::endl;
        std::cout << "username: " << message.payload.gameStateData.players[i].username << std::endl;
        std::cout << "score: " << message.payload.gameStateData.players[i].score << std::endl;
        std::cout << "money " << message.payload.gameStateData.players[i].money << std::endl;
        std::cout << "num_of_cards " << message.payload.gameStateData.players[i].num_of_cards << std::endl;
        std::cout << "bet " << message.payload.gameStateData.players[i].bet << std::endl;
        for (int j = 0; j < message.payload.gameStateData.players[i].num_of_cards; j++)
        {
            Suit suit = message.payload.gameStateData.players[i].cards[j].suit;
            Rank rank = message.payload.gameStateData.players[i].cards[j].rank;
            Card *card = new Card(suit, rank);
            std::cout << card->ToString() << std::endl;
            delete card;
        }
        std::cout << std::endl;
    }
}

void DispatchInvite(Message message)
{
    struct ServerInvitePayload data = message.payload.serverInviteData;
    int room_id = data.roomData.id;
    int num_of_players = data.roomData.num_of_players;
    int sender_id = data.sender_id;
    char sender_username[64];
    strcpy(sender_username, data.sender_username);

    std::cout << "Player " << sender_username << " invite you to join room " << room_id << std::endl;
}
