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
        default: return "Unknown";
    }
}