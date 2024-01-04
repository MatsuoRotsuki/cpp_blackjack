#include "message.h"

std::string MessageTypeToString(MessageType type)
{
    switch(type)
    {
        case MessageType::CLT_DISCONNECT: return "CLT_DISCONNECT";
        case MessageType::SRV_DISCONNECT: return "SRV_DISCONNECT";
        case MessageType::SRV_INVALID_REQUEST: return "SRV_INVALID_REQUEST";
        case MessageType::CLT_SIGNUP_REQ: return "CLT_SIGNUP_REQ";
        case MessageType::CLT_LOGIN_REQ: return "CLT_LOGIN_REQ";
        case MessageType::SRV_SIGNUP_RES: return "SRV_SIGNUP_RES";
        case MessageType::SRV_LOGIN_RES: return "SRV_LOGIN_RES";
        case MessageType::CLT_VIEWONLINE_REQ: return "CLT_VIEWONLINE_REQ";
        case MessageType::SRV_VIEWONLINE_RES: return "SRV_VIEWONLINE_RES";
        case MessageType::CLT_ROOMLIST_REQ: return "CLT_ROOMLIST_REQ";
        case MessageType::SRV_ROOMLIST_RES: return "SRV_ROOMLIST_RES";
        case MessageType::CLT_JOIN_ROOM_REQ: return "CLT_JOIN_ROOM_REQ";
        case MessageType::CLT_CREATE_ROOM_REQ: return "CLT_CREATE_ROOM_REQ";
        case MessageType::SRV_ADDTOROOM: return "SRV_ADDTOROOM";
        case MessageType::SRV_START_ROUND: return "SRV_START_ROUND";
        case MessageType::SRV_BET_REQUEST: return "SRV_BET_REQUEST";
        case MessageType::CLT_PLAYER_BET: return "CLT_PLAYER_BET";
        case MessageType::SRV_PLAYER_BET: return "SRV_PLAYER_BET";
        case MessageType::SRV_GAME_STATE: return "SRV_GAME_STATE";
        case MessageType::SRV_ACTION_REQUEST: return "SRV_ACTION_REQUEST";
        case MessageType::CLT_PLAYER_ACTION: return "CLT_PLAYER_ACTION";
        case MessageType::SRV_OUTCOME: return "SRV_OUTCOME";
        case MessageType::SRV_READY_REQUEST: return "SRV_READY_REQUEST";
        case MessageType::CLT_PLAYER_READY: return "CLT_PLAYER_READY";
        case MessageType::CLT_LEAVE_ROOM: return "CLT_LEAVE_ROOM";
        case MessageType::CLT_INVITE: return "CLT_INVITE";
        case MessageType::SRV_INVITE: return "SRV_INVITE";
        case MessageType::CLT_INVITE_REPLY: return "CLT_INVITE_REPLY";
        case MessageType::SRV_INVITE_OUTCOME: return "SRV_INVITE_OUTCOME";
        default: return "Unknown";
    }
}