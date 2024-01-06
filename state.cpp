#include "state.h"

std::string StateToString(State state)
{
    switch(state) {
        case State::UNLOGGED_IN: return "UNLOGGED_IN";
        case State::LOGGED_IN: return "LOGGED_IN";
        case State::NEW_ROUND: return "NEW_ROUND";
        case State::BETTING: return "BETTING";
        case State::DEALING: return "DEALING";
        case State::OTHER_PLAYER_TURN: return "OTHER_PLAYER_TURN";
        case State::PLAYING: return "PLAYING";
        case State::DEALER_TURN: return "DEALER_TURN";
        case State::OUTCOME: return "OUTCOME";
        default: return "Unknown State Type";
    }
}