#pragma once
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
 * Payload to send
 */
struct ClientDisconnectPayload
{
    char message[256];
};

/**
 * Payload to send . Including:
 * Message:
 * Reason:
 */
struct ServerDisconnectPayload
{
    char message[256];
};

/**
 * Payload to send . Including:
 */
struct InvalidRequestPayload
{
    char message[256];
};

/**
 * Payload to send
 */
struct LoginRequestPayload
{
    char username[64];
    char password[64];
};

/**
 * Payload to send . Including:
 */
struct SignupRequestPayload
{
    char username[64];
    char password[64];
    char confirm_password[64];
    char name[64];
};

/**
 * Payload to send
*/
struct LoginResponsePayload
{
    char message[128];
    uint8_t success;
    // Set state
};

/**
 * Payload to send
*/
struct SignupResponsePayload
{
    char message[128];
    uint8_t success;
};

/**
 * Type: command
 */
struct ViewOnlineRequestPayload
{
    uint8_t numberOfUsers;
};

/**
 * Payload to send
 */
struct ViewOnlineResponsePayload
{
    uint8_t numberOfUsers;
    // Players
};

/**
 * Payload to send
 */
struct GameStatePayload
{
};

/**
 * Payload to send
 */
struct OutcomePayload
{
};

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