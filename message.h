#pragma once
#include <iostream>
#include <string.h>
/*
============================================================================

============================================================================
*/
enum class MessageType
{
    CLT_DISCONNECT, //OK
    SRV_DISCONNECT, //OK
    SRV_INVALID_REQUEST, //OK
    CLT_SIGNUP_REQ, //OK
    CLT_LOGIN_REQ, //OK
    SRV_SIGNUP_RES, //OK
    SRV_LOGIN_RES, //OK
    CLT_VIEWONLINE_REQ, //OK
    SRV_VIEWONLINE_RES, //OK
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
    char message[128];
    uint8_t success;
    // Set state
};

/**
 * Payload to send back to client when server received sign up request from a client.
 * - message: Success or Fail message, may also including validation error message.
 * - success: 0 if failed, 1 if succeeded.
*/
struct SignupResponsePayload
{
    char message[128];
    uint8_t success;
};

/**
 * Command to get all online users from server.
 * - limit: number of users can received. Maximum is 10.
 * - offset: number of users to skip
 */
struct ViewOnlineRequestPayload
{
    uint8_t limit;
    uint8_t offset;
};

/**
 * Payload to send back to client on received get all online users command from client.
 * - limit: number of users can received. Maximum is 10.
 * - offset: number of users to skip
 * - players: players data
 */
struct ViewOnlineResponsePayload
{
    uint8_t limit;
    uint8_t offset;
    // players
};

struct RoomListRequestPayload
{
    uint8_t limit;
    uint8_t offset;
};

struct RoomListResponsePayload
{
    uint8_t limit;
    uint8_t offset;
    // rooms
};

struct JoinRoomRequest {

};

struct CreateRoomRequest {

};

struct AddToRoomPayload {

};

struct StartRoundPayload {

};

struct BetRequestPayload {

};

struct PlayerBetPayload {

};

/**
 * Payload to send
 */
struct GameStatePayload
{
};

struct ActionRequestPayload {

};

struct PlayerActionPayload {

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
        struct ViewOnlineRequestPayload clientViewOnlineData;
    } payload;
} Message;