#include "server.h"

int seed = 0;

int listenfd;

std::vector<Client> clients;

std::mutex clients_mtx, exit_mtx;

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

        // Create thread args, initialize client thread
        std::thread newThread(HandleClient, client_socket, ++seed);
        std::lock_guard<std::mutex> guard(clients_mtx);
        clients.push_back({client_socket, seed, (move(newThread))});
    }

    // Wait for client threads to finish, join all client threads
    for (std::vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        if (it->thread.joinable())
            it->thread.join();
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
    // Thread detach

    Message msgBuff;
    ssize_t received_bytes;

    while (1)
    {
        // Check for exit flag
        if (exit_flag)
        {
            // Create SRV_DISCONNECT error message
            Message disconnectMsg;
            disconnectMsg.type = MessageType::SRV_DISCONNECT;
            strcpy(disconnectMsg.payload.serverDisconnectData.message, "Service Unavailable");

            // Send SRV_DISCONNECT
            send(client_socket, &disconnectMsg, sizeof(disconnectMsg), 0);

            // End connection
            EndConnection(id);

            // Exit client handler thread
            std::cout << "Client handler thread terminated.\n";
            return;
        }

        // Nonblocking recv
        received_bytes = recv(client_socket, &msgBuff, sizeof(Message), MSG_DONTWAIT);
        if (received_bytes > 0)
        {
            // Validate

            // Handle message
            switch (msgBuff.type)
            {
            case MessageType::CLT_DISCONNECT:
                // End connection
                EndConnection(id);
                // Terminate thread
                std::cout << "Client handler thread " << id << " terminated.\n";
                return;

            case MessageType::CLT_SIGNUP_REQ:
                DispatchSignup(id, msgBuff);
                break;

            case MessageType::CLT_LOGIN_REQ:
                DispatchLogin(id, msgBuff);
                break;

            case MessageType::CLT_VIEWONLINE_REQ:
                DispatchViewOnline(id);
                break;

            case MessageType::CLT_ROOMLIST_REQ:
                break;

            default:
                DispatchInvalid(client_socket, id);
            }
        }
        else if (received_bytes == 0)
        {
            // Close connection
            EndConnection(id);
            std::cout << "Client handler thread " << id << " terminated.\n";
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

int FindClientSocketById(int id)
{
    for (std::vector<Client>::iterator p_Client = clients.begin(); p_Client != clients.end(); p_Client++)
    {
        if (p_Client->id == id)
            return p_Client->socket;
    }
    return -1; // NOT FOUND
}

void EndConnection(int id)
{
    std::cout << "[Client " << id << "] disconnected\n";

    for (std::vector<Client>::iterator p_Client = clients.begin(); p_Client != clients.end(); p_Client++)
    {
        if (p_Client->id == id)
        {
            // Mutex guard, remove client
            std::lock_guard<std::mutex> guard(clients_mtx);
            p_Client->thread.detach();
            clients.erase(p_Client);

            // Close client socket
            close(p_Client->socket);
            break;
        }
    }
}
