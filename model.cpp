#include "model.h"
#include <fstream>
#include <json/json.h>
#include "md5.h"

bool isUsernameExists(const std::string& username) {
    // Read
    std::ifstream inputFile("cpp_code.json");
    Json::Value root;
    inputFile >> root;
    inputFile.close();

    
    const Json::Value accounts = root["accounts"];

    // check
    for (const auto& account : accounts) {
        std::string storedUsername = account["username"].asString();

        // check username
        if (storedUsername == username) {
            return true;  // Username exist
        }
    }
    return false;  // Username oke
}

void signUp(const std::string& username, const std::string& password, const std::string& name) {
    if (isUsernameExists(username)) {
        std::cerr << "Username already exists. Please choose another username." << std::endl;
        return;
    }

    // Hash
    std::string hashedPassword = md5(password);

    // Creat
    Player player;
    player.username = username;
    player.name = name;
    player.setPassword(hashedPassword);  

    Json::Value newAccount;
    newAccount["username"] = player.username;
    newAccount["password"] = player.getPassword();  
    newAccount["name"] = player.name;
    newAccount["wins"] = player.wins;
    newAccount["loses"] = player.loses;
    newAccount["pushes"] = player.pushes;
    newAccount["money"] = player.money;

    // Lưu tài khoản mới vào file JSON
    std::ifstream inputFile("cpp_code.json");
    Json::Value root;
    inputFile >> root;
    inputFile.close();

    root["accounts"].append(newAccount);

    std::ofstream outputFile("cpp_code.json");
    if (outputFile.is_open()) {
        outputFile << root.toStyledString();
        outputFile.close();
        std::cout << "Account created and stored in cpp_code.json" << std::endl;
    } else {
        std::cerr << "Error opening the file." << std::endl;
    }
}

bool login(const std::string& username, const std::string& password) {
    // hash md5
    std::string hashedPassword = md5(password);

    // read
    std::ifstream inputFile("cpp_code.json");
    Json::Value root;
    inputFile >> root;
    inputFile.close();

    
    const Json::Value accounts = root["accounts"];
    
    // check
    for (const auto& account : accounts) {
        std::string storedUsername = account["username"].asString();
        std::string storedPassword = account["password"].asString();

        // check login
        if (storedUsername == username && storedPassword == hashedPassword) {
            return true;  
        }
    }
    return false;  // Fail
}


int main() {
    std::string choice;
    std::cout << "Welcome to the game!" << std::endl;
    std::cout << "1. Sign Up\n2. Login\nYour choice: ";
    std::cin >> choice;

    if (choice == "1") {
        std::string username, password, name;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        std::cout << "Enter name: ";
        std::cin >> name;
        signUp(username, password, name);
    } else if (choice == "2") {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        if (login(username, password)) {
            std::cout << "Login successful!" << std::endl;
        } else {
            std::cout << "Login failed!" << std::endl;
        }
    } else {
        std::cerr << "Invalid choice!" << std::endl;
        return 1;
    }

    return 0;
}
