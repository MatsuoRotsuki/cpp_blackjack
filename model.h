#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>

class Player {
private:
    std::string password;

public:
    std::string username;
    std::string name;
    uint8_t wins = 0;
    uint8_t loses = 0;
    uint8_t pushes = 0;
    uint8_t money = 0;

    void setPassword(const std::string& pass) {
        password = pass;
    }

    std::string getPassword() const {
        return password;
    }
};

#endif // MODEL_H
