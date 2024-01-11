#include "server.h"

int listenfd;

std::mutex exit_mtx;

bool exit_flag = false;

int main(int argc, char const *argv[])
{
    // Initializing server, check parameters
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <PortNumber>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr, client_addr;

    // Create listening TCP socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error #000 ");
        exit(EXIT_FAILURE);
    }
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind server address structure to listenfd
    if (bind(listenfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Error #001");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(listenfd, BACK_LOG) == -1)
    {
        perror("Error #002");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server is listening on " << argv[1] << "...\n";

    // Signal
    // signal(SIGINT, HandleInterrupt);

    // Begin to communicate
    socklen_t len;
    int client_socket;

    while (1)
    {
        // Accept
        len = sizeof(sockaddr_in);
        if ((client_socket = accept(listenfd, (struct sockaddr *)&client_addr, &len)) == -1)
        {
            perror("Error #003");
            exit(EXIT_FAILURE);
        }

        // Print new connection address and port
        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_addr.sin_addr), clientIP, INET_ADDRSTRLEN);
        std::cout << "New connection accepted from " << clientIP << ":" << ntohs(client_addr.sin_port) << std::endl;

        // Create thread args, initialize client thread
        int currentClientId = ClientManager::instance().GetNextId();
        std::thread newThread(HandleClient, client_socket, currentClientId);
        
        // Create new client context
        ClientContext *client = new ClientContext(client_socket, currentClientId, (move(newThread)), new StateUnloggedIn);
        ClientManager::instance().AddClient(client);
    }

    // Wait for client threads to finish, join all client threads
    std::list<ClientContext*> allClients = ClientManager::instance().GetAllClients();
    for (auto it = allClients.begin(); it != allClients.end(); it++)
    {
        ClientContext* p_Client = *it;
        if (p_Client->thread_.joinable())
        {
            p_Client->thread_.join();
        }
    }

    // Close server socket
    close(listenfd);

    return 0;
}

// void HandleInterrupt(int signal)
// {
//     std::lock_guard<std::mutex> guard(exit_mtx);
//     exit_flag = true;

//     // Close server socket
//     close(listenfd);
// }

void HandleClient(int client_socket, int id)
{
    Message msgBuff;
    ssize_t received_bytes;

    while (1)
    {
        ClientContext* currentClient = ClientManager::instance().getClientById(id);
        // Check for exit flag
        if (exit_flag)
        {
            // Create SRV_DISCONNECT error message
            Message disconnectMsg;
            disconnectMsg.type = MessageType::SRV_DISCONNECT;
            strcpy(disconnectMsg.payload.serverDisconnectData.message, "Service Unavailable");

            // Send SRV_DISCONNECT
            send(client_socket, &disconnectMsg, sizeof(disconnectMsg), 0);

            // Exit client handler thread
            std::cout << "Client handler thread terminated.\n";
            return;
        }

        // Nonblocking recv
        received_bytes = recv(client_socket, &msgBuff, sizeof(Message), MSG_DONTWAIT);
        if (received_bytes > 0)
        {

            // Handle message
            switch (msgBuff.type)
            {
            case MessageType::CLT_DISCONNECT:
                // Remove client
                currentClient->state_->HandleDisconnect(msgBuff);
                // End Connection
                close(client_socket);
                // Terminate 
                std::cout << "Client handler thread " << id << " terminated.\n";
                return;

            case MessageType::CLT_SIGNUP_REQ:
                currentClient->state_->HandleSignUpRequest(msgBuff);
                break;

            case MessageType::CLT_LOGIN_REQ:
                currentClient->state_->HandleLoginRequest(msgBuff);
                break;

            case MessageType::CLT_READYLIST_REQ:
                currentClient->state_->HandleReadyListRequest(msgBuff);
                break;

            case MessageType::CLT_ROOMLIST_REQ:
                currentClient->state_->HandleRoomListRequest(msgBuff);
                break;

            case MessageType::CLT_JOIN_ROOM_REQ:
                currentClient->state_->HandleJoinRoomRequest(msgBuff);
                break;

            case MessageType::CLT_CREATE_ROOM_REQ:
                currentClient->state_->HandleCreateRoomRequest(msgBuff);
                break;

            case MessageType::CLT_PLAYER_BET:
                currentClient->state_->HandlePlayerBet(msgBuff);
                break;

            case MessageType::CLT_PLAYER_ACTION:
                currentClient->state_->HandlePlayerAction(msgBuff);
                break;

            case MessageType::CLT_LEAVE_ROOM:
                currentClient->state_->HandleLeaveRoom(msgBuff);
                break;

            case MessageType::CLT_INVITE:
                currentClient->state_->HandleInvite(msgBuff);
                break;

            case MessageType::CLT_INVITE_REPLY:
                currentClient->state_->HandleInviteReply(msgBuff);
                break;

            default:
                //INVALID
                Message responseMsg;
                responseMsg.type = MessageType::SRV_INVALID_REQUEST;
                strcpy(responseMsg.payload.invalidRequestData.message, "Bad request");

                send(client_socket, &responseMsg, sizeof(Message), 0);
            }
        }
        else if (received_bytes == 0)
        {
            // Force close connection
            // Logout and destroy client
            currentClient->state_->HandleDisconnect(msgBuff);
            close(client_socket);
            
            // Terminate thread
            return;
        }
        else if (received_bytes == -1)
        {
            // No data available yet from this client
            if (errno == EWOULDBLOCK || errno == EAGAIN)
            {
                continue;
            }
            else
            {
                perror("Error #004");
                return;
            }
        }
    }
}
