#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <mutex>
#include <json/json.h>
#include "clientmanager.hpp"
// #include <thread>
// #include <chrono>

class ClientContext;

class Account
{
private:
    std::string password = "";

public:
    int id = 0;
    std::string username = "";
    std::string name = "";
    int wins = 0;
    int loses = 0;
    int pushes = 0;
    int money = 0;
    bool isLogged = false;
    ClientContext* client = nullptr;
    void setPassword(const std::string &pass);
    std::string getPassword() const;
    void save();
    void printAccount();
};

class AccountManager
{
private:
    explicit AccountManager();
    ~AccountManager();
    static std::mutex mutex;
    static int nextId;
    std::list<Account *> loggedAccounts;
    std::list<Account *> accounts;
    Account *FindAccountByUsername(std::string username) const;
    Account *FindAccountById(int id) const;

public:
    AccountManager(AccountManager &other) = delete;
    void operator=(const AccountManager &) = delete;
    static AccountManager& instance();
    bool Login(const std::string &username, std::string &password, Account *&p_loggedInAccount);
    bool SignUp(const std::string &username, std::string &password, std::string &name);
    void Logout(int id);
    void Logout(Account *account);
    std::list<Account *> GetAllLoggedAccount() const;
    void Save(Account *p_Account);
};

#endif // ACCOUNT_MANAGER_H
