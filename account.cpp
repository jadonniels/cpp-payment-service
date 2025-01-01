#include "account.h"

unordered_map<size_t, unique_ptr<Account>> Account::accounts_list;
size_t Account::id_increment = 0;

void Account::send_money(Account &receiver, double amount)
{
    if (amount > balance ||
        receiver.get_blocklist().find(id) != receiver.get_blocklist().end())
    {
        std::cout << "Send failed." << std::endl;

        if (amount > balance)
            std::cout << "Insufficient funds." << std::endl;

        return;
    }

    balance -= amount;
    receiver.set_balance(receiver.get_balance() + amount);

    std::cout << "Money sent successfully! New balance: " << balance << std::endl;
}

void Account::withdraw(double amount)
{
    // FIXME - This will need to use some library for communication between a bank or some such
    // Bank API?
    balance -= amount;
}

void Account::deposit(double amount)
{
    // Bank API?
    balance += amount;
}

// FIXME - Can be more elegant
void Account::add_friend(const size_t user_id, bool return_add)
{
    if (return_add)
    {
        friends_list.insert(user_id);
        return;
    }
    else if (accounts_list.find(user_id) == accounts_list.end())
    {
        std::cout << "Error: Account not found." << std::endl;
        return;
    }
    else if (friends_list.find(user_id) != friends_list.end())
    {
        std::cout << "Error: Already friends!" << std::endl;
        return;
    }

    friends_list.insert(user_id);
    accounts_list[user_id]->add_friend(id, true);

    std::cout << "Friend successfully added!" << std::endl;
}

void Account::delete_friend(const size_t user_id)
{
    if (friends_list.find(user_id) == friends_list.end())
    {
        std::cout << "Error: This User is not a friend." << std::endl;
        return;
    }

    friends_list.erase(user_id);
}

void Account::block_user(const size_t user_id)
{
    if (accounts_list.find(user_id) == accounts_list.end())
    {
        std::cout << "Error: Account not found." << std::endl;
        return;
    }

    user_blocklist.insert(user_id);
}
