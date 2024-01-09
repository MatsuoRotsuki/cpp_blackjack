#include "accountmanager.h"
#include "md5.h"

std::mutex AccountManager::mutex;
int AccountManager::nextId;

AccountManager::AccountManager()
{
    // Read
    std::ifstream inputFile("accounts.json");
    Json::Value root;
    inputFile >> root;
    inputFile.close();
    
    const Json::Value storedAccounts = root["accounts"];

    for (const auto& storedAccount : storedAccounts)
    {
        Account* p_Account = new Account();

        p_Account->id = storedAccount["id"].asInt();
        p_Account->username = storedAccount["username"].asString();
        p_Account->setPassword(storedAccount["password"].asString());
        p_Account->name = storedAccount["name"].asString();
        p_Account->wins = storedAccount["wins"].asInt();
        p_Account->loses = storedAccount["loses"].asInt();
        p_Account->pushes = storedAccount["pushes"].asInt();
        p_Account->money = storedAccount["money"].asInt();

        this->accounts.push_back(p_Account);
    }

    Account* p_LastAccount = accounts.back();
    nextId = p_LastAccount->id + 1;
}

AccountManager::~AccountManager()
{
    std::cout << "AccountManager destroyed" << std::endl;
    for (auto it = this->accounts.begin(); it != this->accounts.end(); it++)
    {
        delete *it;
    }
    this->accounts.clear();
}

AccountManager& AccountManager::instance()
{
    static AccountManager s_instance;
    return s_instance;
}

Account *AccountManager::FindAccountByUsername(std::string username) const
{
    for (auto it = this->accounts.begin(); it != this->accounts.end(); it++)
    {
        Account *p_Account = *it;
        if (p_Account->username == username)
        {
            return p_Account;
        }
    }
    return nullptr;
}

Account *AccountManager::FindAccountById(int id) const
{
    for (auto it = this->accounts.begin(); it != this->accounts.end(); it++)
    {
        Account *p_Account = *it;
        if (p_Account->id == id)
        {
            return p_Account;
        }
    }
    return nullptr;
}

bool AccountManager::Login(const std::string &username, std::string &password, Account *&p_loggedInAccount)
{
    // Mutex lock
    std::lock_guard<std::mutex> lock(mutex);

    // Hash input password
    std::string hashedPassword(md5(password));

    // Find and check
    Account* foundAccount = this->FindAccountByUsername(username);
    if (foundAccount != nullptr)
    {
        if(!foundAccount->isLogged && foundAccount->getPassword() == hashedPassword) {
            // Login success
            // Save the account as logged
            foundAccount->isLogged = true;
            this->loggedAccounts.push_back(foundAccount);

            //Output loggedInAccount
            p_loggedInAccount = foundAccount;

            return true;
        }
    }

    // Login failed
    return false;
}

bool AccountManager::SignUp(const std::string &username, std::string &password, std::string &name)
{
    // Mutex lock
    std::lock_guard<std::mutex> lock(mutex);

    if (FindAccountByUsername(username)) {
        return false;
    }

    // Create new account
    Account *newAcc = new Account();
    newAcc->id = nextId++;
    newAcc->username = username;
    newAcc->setPassword(md5(password));
    newAcc->name = name;
    newAcc->money = 1000;

    // Read
    std::ifstream inputFile("accounts.json");
    Json::Value root;
    inputFile >> root;
    inputFile.close();

    // Store new account into list
    this->accounts.push_back(newAcc);

    // Store new account into json
    Json::Value newAccountJson;
    newAccountJson["id"] = newAcc->id;
    newAccountJson["username"] = newAcc->username;
    newAccountJson["password"] = newAcc->getPassword();
    newAccountJson["name"] = newAcc->name;
    newAccountJson["wins"] = newAcc->wins;
    newAccountJson["loses"] = newAcc->loses;
    newAccountJson["money"] = newAcc->money;

    root["accounts"].append(newAccountJson);

    std::ofstream outputFile("accounts.json");
    if (outputFile.is_open()) {
        outputFile << root.toStyledString();
        outputFile.close();
        return true;
    } else {
        std::cerr << "[SIGNUP] Error opening the file" << std::endl;
        return false;
    }
}

void AccountManager::Logout(int id)
{
    // Mutex lock
    std::lock_guard<std::mutex> lock(mutex);

    Account *targetAcc = this->FindAccountById(id);
    if (targetAcc != nullptr && targetAcc->isLogged) {
        this->loggedAccounts.remove(targetAcc);
        targetAcc->isLogged = false;
    }
}

void AccountManager::Logout(Account *account)
{
    // Mutex lock
    std::lock_guard<std::mutex> lock(mutex);

    account->isLogged = false;
    this->loggedAccounts.remove(account);
}

std::list<Account *> AccountManager::GetAllLoggedAccount() const
{
    return this->loggedAccounts;
}

void AccountManager::Save(Account *p_Account)
{
    // Mutex lock
    std::lock_guard<std::mutex> lock(mutex);

    std::ifstream file("accounts.json");
    if (!file.is_open()) {
        std::cerr << "[SAVE] Error opening the file" << std::endl;
        return;
    }
    Json::Value root;
    file >> root;
    file.close();

    for (auto& account : root["accounts"]) {
        if (account["id"].asInt() == p_Account->id) {
            // Update the fields
            account["username"] = p_Account->username;
            account["password"] = p_Account->getPassword();
            account["name"] = p_Account->name;
            account["wins"] = p_Account->wins;
            account["loses"] = p_Account->loses;
            account["pushes"] = p_Account->pushes;
            account["money"] = p_Account->money;
            break;
        }
    }

    std::ofstream outputFile("accounts.json");
    if (outputFile.is_open()) {
        outputFile << root.toStyledString();
        outputFile.close();
    } else {
        std::cerr << "[SAVE] Error opening the file" << std::endl;
    }
}

void Account::setPassword(const std::string &pass)
{
    password = pass;
}

std::string Account::getPassword() const
{
    return password;
}

void Account::save()
{
    AccountManager::instance().Save(this);
}

void Account::printAccount()
{
    std::cout << "username: " << username << std::endl;
    std::cout << "password: " << password << std::endl;
    std::cout << "name: " << name << std::endl;
    std::cout << "money: " << money << std::endl;
    std::cout << "wins: " << wins << std::endl;
    std::cout << "loses: " << loses << std::endl;
    std::cout << "pushes: " << pushes << std::endl;
}

// void ThreadBar()
// {
//     Account *temp;
//     std::string username("antonylouis");
//     std::string password("123456");
    
//     if (AccountManager::instance().Login(username, password, temp)) {
//         std::cout << "Welcome " << temp->name << std::endl;
//     } else {
//         std::cout << "login failed" << std::endl;
//     }

//     temp->money = 100;
//     temp->wins = 1244;
//     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     temp->save();
// }

// void ThreadFoo()
// {
//     Account *temp;
//     std::string username("anton");
//     std::string password("anton");
    
//     if (AccountManager::instance().Login(username, password, temp)) {
//         std::cout << "Welcome " << temp->name << std::endl;
//     } else {
//         std::cout << "login failed" << std::endl;
//     }

//     temp->money = 3232;
//     temp->loses = 3453;
//     temp->wins = ;
//     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//     temp->save();
// }

// int main(int argc, char const *argv[])
// {
//     std::thread t1(ThreadBar);
//     std::thread t2(ThreadFoo);
//     t1.join();
//     t2.join();
//     return 0;
// }
