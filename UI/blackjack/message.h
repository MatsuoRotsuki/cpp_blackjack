#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <string.h>

enum class MessageType
{
    CLT_DISCONNECT, //OK
    SRV_DISCONNECT, //OK
    SRV_INVALID_REQUEST, //OK
    CLT_SIGNUP_REQ, //OK
    CLT_LOGIN_REQ, //OK
    SRV_SIGNUP_RES, //OK
    SRV_LOGIN_RES, //OK
    CLT_READYLIST_REQ, //OK
    SRV_READYLIST_RES, //OK
    CLT_ROOMLIST_REQ, //OK
    SRV_ROOMLIST_RES, //OK
    CLT_JOIN_ROOM_REQ,
    CLT_CREATE_ROOM_REQ,
    SRV_ADDTOROOM,
    SRV_START_ROUND,
    SRV_BET_REQUEST,
    CLT_PLAYER_BET,
    SRV_PLAYER_BET,
    SRV_GAME_STATE,
    SRV_ACTION_REQUEST,
    CLT_PLAYER_ACTION,
    SRV_OUTCOME,
    SRV_READY_REQUEST,
    CLT_PLAYER_READY,
    CLT_LEAVE_ROOM,
    CLT_INVITE,
    SRV_INVITE,
    CLT_INVITE_REPLY,
    SRV_INVITE_OUTCOME
};

std::string MessageTypeToString(MessageType type);

/*
============================================================================
Các cấu trúc được sử dụng chung
============================================================================
*/

struct PlayerData {
    int id;
    char username[64];
    char name[64];
    int wins;
    int loses;
    int pushes;
    int money;
    int state;
};

struct RoomData {
    int id;
    int num_of_players;
    int min_credits;
};

enum class Suit {
    CLUB = 0,
    DIAMOND,
    HEART,
    SPADE,
};

enum class Rank {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

struct CardData {
    Suit suit;
    Rank rank;
};

enum class PlayerAction {
    HIT,
    STAND,
};

/*
============================================================================
Dưới đây là cấu trúc payload của các thông điệp cụ thể
============================================================================
*/

/**
 * Payload to send when a client want to disconnect from server.
 * - message: Disconnect message content
 */
struct ClientDisconnectPayload
{
    char message[256];
};

/**
 * Payload to send when server want to disconnect to all clients
 * - message: Disconnect message content
 */
struct ServerDisconnectPayload
{
    char message[256];
};

/**
 * Payload sent to a client when server received bad request from that client.
 * - message: Invalid request message content
 */
struct InvalidRequestPayload
{
    char message[256];
};

/**
 * Payload to send to server when a client want to login.
 * - username: Username
 * - password: Password
 */
struct LoginRequestPayload
{
    char username[64];
    char password[64];
};

/**
 * Payload to send to server when a client want to sign up.
 * - username: Username
 * - password: Password
 * - confirm_password: Confirm Password
 * - name: Name
 */
struct SignupRequestPayload
{
    char username[64];
    char password[64];
    char confirm_password[64];
    char name[64];
};

/**
 * Payload to send back to client when server received login request from a client.
 * - message: Success or Fail message, may also including validation error message.
 * - success: 0 if failed, 1 if succeeded.
*/
struct LoginResponsePayload
{
    char message[64];
    int success;
    int id;
    char username[64];
    char name[64];
    int wins;
    int loses;
    int pushes;
    int money;
};

/**
 * Payload to send back to client when server received sign up request from a client.
 * - message: Success or Fail message, may also including validation error message.
 * - success: 0 if failed, 1 if succeeded.
*/
struct SignupResponsePayload
{
    char message[128];
    int success;
};

/**
 * Command to get all online users from server.
 * - limit: number of users can received. Maximum is 10.
 * - offset: number of users to skip
 */
struct ViewOnlineRequestPayload
{
    // Empty payload
};

/**
 * Payload to send back to client on received get all online users command from client.
 * - limit: number of users can received. Maximum is 10.
 * - offset: number of users to skip
 * - players: players data
 */
struct ViewOnlineResponsePayload
{
    int success;
    int num_of_players;
    struct PlayerData players[10];
};

struct RoomListRequestPayload
{
    // Empty payload
};

struct RoomListResponsePayload
{
    int success;
    int num_of_rooms;
    struct RoomData rooms[10];
    int num_of_players;
    struct PlayerData players[10];
};

struct JoinRoomRequestPayload {
    int room_id;
};

struct CreateRoomRequestPayload {
    // Empty payload
};

struct AddToRoomPayload {

};

struct StartRoundPayload {

};

struct BetRequestPayload {

};

struct PlayerBetPayload {
    int bet;
};

/**
 * Payload to send
 */
struct GameStatePayload
{
    int num_of_players;
    struct Player {
        char username[32];
        char outcome[32];
        int score;
        int num_of_cards;
        struct CardData cards[10];
        int money;
        int bet;
        int current;
    } players[4];
    int canBet;
    int canAction;
    int dealer_num_of_cards;
    struct CardData dealer_cards[10];
    int dealer_score;
    char start_round[32];
};

struct ActionRequestPayload {

};

struct PlayerActionPayload {
    PlayerAction action;
};

/**
 * Payload to send
 */
struct OutcomePayload
{
};

struct PlayerReadyPayload {

};

struct LeaveRoomPayload {

};

struct ClientInvitePayload {

};

struct ServerInvitePayload {

};

struct InviteReplyPayload {

};

struct InviteOutcomePayload {

};

/**
 * 
*/
typedef struct Message_
{
    MessageType type;
    union Payload_
    {
        struct ClientDisconnectPayload clientDisconnectData;
        struct ServerDisconnectPayload serverDisconnectData;
        struct InvalidRequestPayload invalidRequestData;
        struct LoginRequestPayload loginRequestData;
        struct SignupRequestPayload signupRequestData;
        struct LoginResponsePayload loginResponseData;
        struct SignupResponsePayload signupResponseData;
        struct ViewOnlineRequestPayload readyListRequestData;
        struct ViewOnlineResponsePayload readyListResponseData;
        struct RoomListRequestPayload roomListRequestData;
        struct RoomListResponsePayload roomListResponseData;
        struct JoinRoomRequestPayload joinRoomRequestData;
        struct CreateRoomRequestPayload createRoomRequestData;
        struct GameStatePayload gameStateData;
        struct PlayerBetPayload playerBetData;
        struct PlayerActionPayload PlayerActionData;
    } payload;
} Message;

#endif // MESSAGE_H
