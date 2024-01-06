#pragma once
#include <string>

enum class State 
{
    UNLOGGED_IN,
    LOGGED_IN,
    NEW_ROUND,
    BETTING,
    DEALING,
    OTHER_PLAYER_TURN,
    PLAYING,
    DEALER_TURN,
    OUTCOME,
    UNKNOWN,
};

std::string StateToString(State state);