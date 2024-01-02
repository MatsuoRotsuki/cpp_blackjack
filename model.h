#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

class Player
{
private:
    std::string password;

public:
    std::string username;
    std::string name;
    uint8_t wins = 0;
    uint8_t loses = 0;
    uint8_t pushes = 0;
    uint8_t money = 0;
};