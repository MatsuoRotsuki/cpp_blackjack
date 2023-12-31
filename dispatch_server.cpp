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

    // Create response message
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

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_SIGNUP_RES;
    responseMsg.payload.signupResponseData.success = true;
    strcpy(responseMsg.payload.signupResponseData.message, "Sign up success");
    send(FindClientSocketById(id), &responseMsg, sizeof(responseMsg), 0);
}

void DispatchViewOnline(int id)
{
    std::cout << "[Client " << id << "] sent VIEWONLINE message.\n";

    // Handle view online message

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_VIEWONLINE_RES;
}