#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::unique_ptr;
using std::unordered_map;
using std::unordered_set;

class Account
{
    static unordered_map<size_t, unique_ptr<Account>> accounts_list;
    static size_t id_increment;
    size_t id;
    double balance;
    string username;
    string password;
    string pin;

    unordered_set<size_t> friends_list;
    unordered_set<size_t> user_blocklist;

public:
    Account(double initial_balance, const string &username_in,
            const string &password_in, const string &pin_in)
        : id(id_increment++), balance(initial_balance),
          username(username_in), password(password_in), pin(pin_in)
    {
        accounts_list[id] = std::make_unique<Account>(*this);
    }

    Account(const Account &other)
        : id(id_increment++), balance(other.balance),
          username(other.username), password(other.password), pin(other.pin) {}

    Account &operator=(const Account &other)
    {
        if (this == &other)
            return *this;

        id = other.id;
        balance = other.balance;
        username = other.username;
        password = other.password;
        pin = other.pin;

        return *this;
    }

    ~Account() = default;

    // Getters and Setters

    size_t get_user_id()
    {
        return id;
    }

    double get_balance()
    {
        return balance;
    }

    void set_balance(double amount)
    {
        balance = amount;
    }

    unordered_set<size_t> &get_blocklist()
    {
        return user_blocklist;
    }

    // Begin basic functionality

    void send_money(Account &receiver, double amount);
    void withdraw(double amount);
    void deposit(double amount);
    void add_friend(const size_t new_friend_id, bool return_add);
    void delete_friend(const size_t friend_id);
    void block_user(const size_t user_id);
};

#endif
