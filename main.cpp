#include "account.h"

int main()
{
    Account jadon(1000000.55, "jadonn", "hehe", "0123");
    Account qua(30000.13, "quac", "hehe", "9876");

    jadon.add_friend(qua.get_user_id(), false);

    // Err
    qua.add_friend(jadon.get_user_id(), false);

    jadon.send_money(qua, 99999999999999.99);
    jadon.send_money(qua, 100.01);

    qua.withdraw(99999.9);

    qua.withdraw(2000.20);
}