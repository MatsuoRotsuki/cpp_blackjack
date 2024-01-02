#include "model.h"

int main() {
    // C++ code as a string
    std::string username = "antonylouis";
    std::string password = "123456";
    std::string confirm_password = "123456";
    std::string name = "Loc Pham";

    // Create a JSON object
    Json::Value root;
    root["username"] = username;
    root["password"] = password;

    // Convert the JSON object to a string
    std::string jsonString = root.toStyledString();

    // Write the JSON string to a file
    std::ofstream outputFile("cpp_code.json");
    if (outputFile.is_open()) {
        outputFile << jsonString;
        outputFile.close();
        std::cout << "C++ code stored in cpp_code.json" << std::endl;
    } else {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    return 0;
}