#ifndef MESSAGE_H
#define MESSAGE_H

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

struct InvalidRequestPayload
{
    char message[256];
};

typedef struct Message_
{
    MessageType type;
    union Payload_
    {
        struct InvalidRequestPayload invalidRequestData;
    } payload;
} Message;

#endif // MESSAGE_H
