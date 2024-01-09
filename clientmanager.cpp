#include "clientmanager.hpp"

std::mutex ClientManager::s_mutex;
int ClientManager::s_nextId = 0;

ClientManager::~ClientManager()
{
    std::cout << "ClientManager destroyed" << std::endl;
    for (auto &pair : this->clients)
    {
        delete pair.second;
    }
    this->clients.clear();
}

ClientManager &ClientManager::instance()
{
    static ClientManager s_instance;
    return s_instance;
}

void ClientManager::AddClient(ClientContext *client)
{
    std::lock_guard<std::mutex> guard(s_mutex);
    this->clients[client->id_] = client;
}

void ClientManager::RemoveClient(ClientContext *client)
{
    std::lock_guard<std::mutex> guard(s_mutex);
    auto it = this->clients.find(client->id_);
    if (it != this->clients.end())
    {
        this->clients.erase(it);
    }
    else
    {
        std::cout << "[ClientManager - RemoveClient] Client not found" << std::endl;
    }
}

std::list<ClientContext *> ClientManager::GetLoggedClients()
{
    std::lock_guard<std::mutex> guard(s_mutex);
    std::list<ClientContext *> result;
    for (const auto &pair : this->clients)
    {
        ClientContext *p_Client = pair.second;
        if (p_Client->account_ != nullptr)
        {
            result.push_back(p_Client);
        }
    }
    return result;
}

int ClientManager::GetNextId()
{
    std::lock_guard<std::mutex> guard(s_mutex);
    return ++s_nextId;
}

ClientContext *ClientManager::getClientById(int id)
{
    std::lock_guard<std::mutex> guard(s_mutex);
    return this->clients[id];
}

ClientManager::ClientManager()
{
}

ClientContext::ClientContext(int socket, int id, std::thread &&thread, ClientState *state)
    : socket_(socket), id_(id), thread_(std::move(thread)), state_(nullptr), account_(nullptr)
{
    this->SetState(state);
}

ClientContext::~ClientContext()
{
    std::cout << "Client " << id_ << " destroyed" << std::endl;
    delete state_;
}

void ClientContext::SetState(ClientState *state)
{
    std::cout << "[Client " << this->id_ << "] set state to " << typeid(*state).name() << std::endl;

    if (this->state_ != nullptr)
    {
        delete this->state_;
    }

    this->state_ = state;
    this->state_->SetContext(this);
}

void ClientState::HandleDisconnect(Message message)
{
    // Default behavior
    std::cout << "[Client " << this->context_->id_ << "] disconnected.\n";
    this->context_->thread_.detach();
    // Logout
    if (this->context_->account_ != nullptr)
    {
        AccountManager::instance().Logout(this->context_->account_);
    }

    // Remove client
    ClientManager::instance().RemoveClient(this->context_);
    delete this->context_;
}

void ClientState::HandleSignUpRequest(Message message)
{
    // Default behavior
    // std::cout << "[Client " << this->context_->id_ << "] sent SIGNUP. INVALID. Current state: " << typeid(*this->context_).name() << std::endl;

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_INVALID_REQUEST;
    strcpy(responseMsg.payload.invalidRequestData.message, "Bad request");

    // Send
    send(this->context_->socket_, &responseMsg, sizeof(Message), 0);
}

void ClientState::HandleLoginRequest(Message message)
{
    // Default behavior
    // std::cout << "[Client " << this->context_->id_ << "] sent LOGIN. INVALID. Current state: " << typeid(*this->context_->state_).name() << std::endl;

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_INVALID_REQUEST;
    strcpy(responseMsg.payload.invalidRequestData.message, "Bad request");

    // Send
    send(this->context_->socket_, &responseMsg, sizeof(Message), 0);
}

void ClientState::HandleRoomListRequest(Message message)
{
    // Default behavior
    // std::cout << "[Client " << this->context_->id_ << "] sent ROOMLIST. INVALID. Current state: " << typeid(*this->context_->state_).name() << std::endl;

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_INVALID_REQUEST;
    strcpy(responseMsg.payload.invalidRequestData.message, "Bad request");

    // Send
    send(this->context_->socket_, &responseMsg, sizeof(Message), 0);
}

void ClientState::HandleReadyListRequest(Message message)
{
    // Default behavior
    // std::cout << "[Client " << this->context_->id_ << "] sent READYLIST. INVALID. Current state: " << typeid(*this->context_->state_).name() << std::endl;

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_INVALID_REQUEST;
    strcpy(responseMsg.payload.invalidRequestData.message, "Bad request");

    // Send
    send(this->context_->socket_, &responseMsg, sizeof(Message), 0);
}

void ClientState::HandleCreateRoomRequest(Message message)
{
    // Default behavior
    // std::cout << "[Client " << this->context_->id_ << "] sent CREATE_ROOM. INVALID. Current state: " << typeid(*this->context_->state_).name() << std::endl;

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_INVALID_REQUEST;
    strcpy(responseMsg.payload.invalidRequestData.message, "Bad request");

    // Send
    send(this->context_->socket_, &responseMsg, sizeof(Message), 0);
}

void ClientState::HandleJoinRoomRequest(Message message)
{
    // Default behavior
    // std::cout << "[Client " << this->context_->id_ << "] sent JOIN_ROOM. INVALID. Current state: " << typeid(*this->context_->state_).name() << std::endl;

    Message responseMsg;
    responseMsg.type = MessageType::SRV_INVALID_REQUEST;
    strcpy(responseMsg.payload.invalidRequestData.message, "Bad request");

    // Send
    send(this->context_->socket_, &responseMsg, sizeof(Message), 0);
}

void StateUnloggedIn::HandleSignUpRequest(Message message)
{
    // Override behavior
    std::cout << "[Client " << this->context_->id_ << "] sent SIGNUP.\n";

    // Handle sign up logic
    std::string username(message.payload.signupRequestData.username);
    std::string password(message.payload.signupRequestData.password);
    std::string confirm_password(message.payload.signupRequestData.confirm_password);
    std::string name(message.payload.signupRequestData.name);

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_SIGNUP_RES;

    if (username.empty() || password.empty() || confirm_password.empty() || name.empty())
    {
        responseMsg.payload.signupResponseData.success = false;
        strcpy(responseMsg.payload.signupResponseData.message, "All input fields is required");
        // Send
        send(this->context_->socket_, &responseMsg, sizeof(responseMsg), 0);
        return;
    }

    // Check matching password and confirm password
    if (confirm_password != password)
    {
        responseMsg.payload.signupResponseData.success = false;
        strcpy(responseMsg.payload.signupResponseData.message, "Passwords mismatch");
        // Send
        send(this->context_->socket_, &responseMsg, sizeof(responseMsg), 0);
        return;
    }

    if (AccountManager::instance().SignUp(username, password, name))
    {
        responseMsg.payload.signupResponseData.success = true;
        strcpy(responseMsg.payload.signupResponseData.message, "Signed up success. Please login");
    }
    else
    {
        responseMsg.payload.signupResponseData.success = false;
        strcpy(responseMsg.payload.signupResponseData.message, "Username has already taken");
    }

    send(this->context_->socket_, &responseMsg, sizeof(responseMsg), 0);
}

void StateUnloggedIn::HandleLoginRequest(Message message)
{
    std::cout << "[Client " << this->context_->id_ << "] sent LOGIN.\n";

    std::string username(message.payload.loginRequestData.username);
    std::string password(message.payload.loginRequestData.password);

    Message responseMsg;
    responseMsg.type = MessageType::SRV_LOGIN_RES;

    Account *tempAccount;
    bool loginSuccess = false;

    if (username.empty() || password.empty())
    {
        responseMsg.payload.loginResponseData.success = false;
        strcpy(responseMsg.payload.signupResponseData.message, "All input fields is required");
        // Send
        send(this->context_->socket_, &responseMsg, sizeof(responseMsg), 0);
        return;
    }

    if ((loginSuccess = AccountManager::instance().Login(username, password, tempAccount)))
    {
        // Login success
        this->context_->account_ = tempAccount;
        tempAccount->client = this->context_;
        responseMsg.payload.loginResponseData.success = true;
        strcpy(responseMsg.payload.loginResponseData.message, "Login success.");
        responseMsg.payload.loginResponseData.id = tempAccount->id;
        strcpy(responseMsg.payload.loginResponseData.username, tempAccount->username.c_str());
        strcpy(responseMsg.payload.loginResponseData.name, tempAccount->name.c_str());
        responseMsg.payload.loginResponseData.wins = tempAccount->wins;
        responseMsg.payload.loginResponseData.loses = tempAccount->loses;
        responseMsg.payload.loginResponseData.pushes = tempAccount->pushes;
        responseMsg.payload.loginResponseData.money = tempAccount->money;
    }
    else
    {
        // Login failed
        responseMsg.payload.loginResponseData.success = false;
        strcpy(responseMsg.payload.loginResponseData.message, "Login failed. Please try again.");
    }

    // Send response
    send(this->context_->socket_, &responseMsg, sizeof(responseMsg), 0);

    if (loginSuccess)
    {
        this->context_->SetState(new StateReady);
    }
}

void StateReady::HandleRoomListRequest(Message message)
{
    std::cout << "[Client " << this->context_->id_ << "] sent ROOMLIST.\n";

    Message responseMsg;
    responseMsg.type = MessageType::SRV_ROOMLIST_RES;

    send(this->context_->socket_, &responseMsg, sizeof(responseMsg), 0);
}

void StateReady::HandleReadyListRequest(Message message)
{
    std::cout << "[Client " << this->context_->id_ << "] sent READYLIST.\n";

    // Create response message
    Message responseMsg;
    responseMsg.type = MessageType::SRV_READYLIST_RES;

    // Get list of ready players
    std::list<ClientContext *> allLoggedClients = ClientManager::instance().GetLoggedClients();
    
    int index = 0;
    for (auto it = allLoggedClients.begin(); it != allLoggedClients.end(); it++)
    {
        ClientContext* p_Client = *it;
        // If the client's state is ready, add struct
        if (StateReady* stateReadyPtr = dynamic_cast<StateReady*>(p_Client->state_)) {
            PlayerData playerData;
            playerData.id = p_Client->account_->id;
            strcpy(playerData.username, p_Client->account_->username.c_str());
            strcpy(playerData.name, p_Client->account_->name.c_str());
            playerData.money = p_Client->account_->money;
            playerData.wins = p_Client->account_->wins;
            playerData.loses = p_Client->account_->loses;
            playerData.pushes = p_Client->account_->pushes;
            responseMsg.payload.readyListResponseData.players[index] = playerData;
            index++;
        }
    }
    responseMsg.payload.readyListResponseData.success = true;
    responseMsg.payload.readyListResponseData.num_of_players = index;
    // Send
    send(this->context_->socket_, &responseMsg, sizeof(responseMsg), 0);
}

void StateReady::HandleCreateRoomRequest(Message message)
{
    std::cout << "[Client " << this->context_->id_ << "] sent CREATE_ROOM.\n";
}

void StateReady::HandleJoinRoomRequest(Message message)
{
    std::cout << "[Client " << this->context_->id_ << "] sent JOIN_ROOM.\n";
}
