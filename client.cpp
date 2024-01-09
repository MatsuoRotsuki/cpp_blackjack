#include "client.h"

std::atomic<bool> exit_flag(false);
int client_socket;
std::thread sendingThread, receivingThread;

int main(int argc, char const *argv[])
{
    // Initializing client, check parameters
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <IPAddress> <PortNumber>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create client TCP socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("[Client - Error #001]");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(atoi(argv[2]));
    client_addr.sin_addr.s_addr = inet_addr(argv[1]);
    bzero(&client_addr.sin_zero, 0);

    // Connect
    if (connect(client_socket, (struct sockaddr *)&client_addr, sizeof(struct sockaddr_in)) == -1)
    {
        perror("[Client - Error #005]");
        exit(EXIT_FAILURE);
    }

    // Signal
    signal(SIGINT, HandleInterrupt);

    // Create thread args, initialize sending thread
    std::thread t1(HandleSendingThread, client_socket);
    sendingThread = move(t1);

    // Create thread args, initialize receiving thread
    std::thread t2(HandleReceivingThread, client_socket);
    receivingThread = move(t2);

    // Join 2 threads
    if (sendingThread.joinable())
        sendingThread.join();
    if (receivingThread.joinable())
        receivingThread.join();

    // Close socket
    close(client_socket);

    return 0;
}

void HandleInterrupt(int signal)
{
    // Send disconnect message to server
    Message disconnectMsg;
    disconnectMsg.type = MessageType::CLT_DISCONNECT;
    strcpy(disconnectMsg.payload.clientDisconnectData.message, "Disconnected due to Ctrl C");
    send(client_socket, &disconnectMsg, sizeof(Message), 0);

    // Set exit flag
    exit_flag = true;
}

void HandleSendingThread(int client_socket)
{
    while (1)
    {
        // Action
        int cmd;
        std::cin >> cmd;

        // Create request
        Message requestMsg;

        switch (cmd)
        {
        case 1:
            requestMsg.type = MessageType::CLT_LOGIN_REQ;
            strcpy(requestMsg.payload.loginRequestData.username, "antonylouis");
            strcpy(requestMsg.payload.loginRequestData.password, "123456");
            break;

        case 2:
            requestMsg.type = MessageType::CLT_SIGNUP_REQ;
            strcpy(requestMsg.payload.signupRequestData.username, "antonylouis");
            strcpy(requestMsg.payload.signupRequestData.password, "123456");
            strcpy(requestMsg.payload.signupRequestData.confirm_password, "123456");
            strcpy(requestMsg.payload.signupRequestData.name, "Loc Pham");
            break;
        case 3:
            requestMsg.type = MessageType::CLT_READYLIST_REQ;
            break;
        case 4:
            requestMsg.type = MessageType::CLT_ROOMLIST_REQ;

        case 5:
            requestMsg.type = MessageType::CLT_JOIN_ROOM_REQ;

        case 6:
            requestMsg.type = MessageType::CLT_CREATE_ROOM_REQ;
        }

        // Check exit flag
        if (exit_flag)
            return;

        // Send
        send(client_socket, &requestMsg, sizeof(requestMsg), 0);
    }
}

void HandleReceivingThread(int client_socket)
{
    while (1)
    {
        // Check exit flag
        if (exit_flag)
        {
            std::cout << "Closing receiving thread..." << std::endl;
            return;
        }

        // Nonblocking recv
        Message msgBuff;
        ssize_t received_bytes;
        received_bytes = recv(client_socket, &msgBuff, sizeof(msgBuff), MSG_DONTWAIT);
        if (received_bytes > 0)
        {
            std::cout << MessageTypeToString(msgBuff.type) << std::endl;
            // Validate

            // Output action
            switch (msgBuff.type)
            {
            case MessageType::SRV_DISCONNECT:
                std::cout << "[Server] " << msgBuff.payload.serverDisconnectData.message << "\n";
                exit_flag = true;
                break;

            case MessageType::SRV_INVALID_REQUEST:
                std::cout << "[Server] " << msgBuff.payload.invalidRequestData.message << "\n";
                break;

            case MessageType::SRV_SIGNUP_RES:
                std::cout << "[Server] " << msgBuff.payload.signupResponseData.message << "\n";
                break;

            case MessageType::SRV_LOGIN_RES:
                std::cout << "[Server] " << msgBuff.payload.loginResponseData.message << "\n";
                break;

            case MessageType::SRV_READYLIST_RES:
                DispatchReadyList(msgBuff);
                break;
            case MessageType::SRV_ROOMLIST_RES:
                break;
            }
        }
        else if (received_bytes == 0)
        {
            std::cout << "Close connection by server" << std::endl;
            exit_flag = true;
        }
        else if (received_bytes == -1)
        {
            // No data available yet
            if (errno == EWOULDBLOCK || errno == EAGAIN)
            {
                continue;
            }
            else
            {
                perror("[Client - Error #004]");
                return;
            }
        }
    }
}