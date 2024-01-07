#include "server.h"

void DispatchInvalid(int client_socket, int id)
{
    std::cout << "[Client " << id << "] sent INVALID message.\n";

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_INVALID_REQUEST;
    strcpy(responseMsg.payload.invalidRequestData.message, "Bad request");

    // Send
    send(client_socket, &responseMsg, sizeof(Message), 0);
}

void DispatchLogin(int id, Message loginMsg)
{
    std::cout << "[Client " << id << "] sent LOGIN message.\n";

    // Handle login logic
    std::string username(loginMsg.payload.loginRequestData.username);
    std::string password(loginMsg.payload.loginRequestData.password);

    std::cout << username << std::endl;
    std::cout << password << std::endl;

    Message responseMsg;
    responseMsg.type = MessageType::SRV_LOGIN_RES;
    responseMsg.payload.loginResponseData.success = true;
    strcpy(responseMsg.payload.loginResponseData.message, "Login success");

    // Send response
    send(FindClientSocketById(id), &responseMsg, sizeof(responseMsg), 0);
}

void DispatchSignup(int id, Message signUpMsg)
{
    std::cout << "[Client " << id << "] sent SIGNUP message.\n";

    // Handle sign up logic
    std::string username(signUpMsg.payload.signupRequestData.username);
    std::string password(signUpMsg.payload.signupRequestData.password);
    std::string confirm_password(signUpMsg.payload.signupRequestData.confirm_password);
    std::string name(signUpMsg.payload.signupRequestData.name);

    std::cout << name << std::endl;
    std::cout << username << std::endl;
    std::cout << password << std::endl;
    std::cout << confirm_password << std::endl;

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_SIGNUP_RES;
    responseMsg.payload.signupResponseData.success = false;
    strcpy(responseMsg.payload.signupResponseData.message, "Password doesn\'t match confirm password");

    // Send
    send(FindClientSocketById(id), &responseMsg, sizeof(responseMsg), 0);
}

void DispatchViewOnline(int id, Message reqMsg)
{
    std::cout << "[Client " << id << "] sent VIEWONLINE message.\n";

    // Handle view online message
    uint8_t limit = reqMsg.payload.clientViewOnlineData.limit;
    uint8_t offset = reqMsg.payload.clientViewOnlineData.offset;

    std::vector<Client> *p_clients = getAllClients();
    for (const auto& client : *p_clients) {
        std::cout << client.id << std::endl;
        std::cout << client.socket << std::endl;
        std::cout << StateToString(client.state) << std::endl;
    }

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_VIEWONLINE_RES;
}