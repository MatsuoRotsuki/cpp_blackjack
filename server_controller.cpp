#include "server.h"

void DispatchViewOnline(int id, Message reqMsg)
{
    std::cout << "[Client " << id << "] sent VIEWONLINE message.\n";

    // Handle view online message
    // int limit = reqMsg.payload.readyListRequestData.limit;
    // int offset = reqMsg.payload.readyListRequestData.offset;

    std::vector<Client> *p_clients = getAllClients();
    for (const auto &client : *p_clients)
    {
        std::cout << client.id << std::endl;
        std::cout << client.socket << std::endl;
        std::cout << StateToString(client.state) << std::endl;
    }

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_READYLIST_RES;
}