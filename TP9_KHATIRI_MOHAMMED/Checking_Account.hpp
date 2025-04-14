#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include "Account.hpp"

class Checking_Account : public Account {
private:
    static constexpr double per_check_fee = 1.50;

public:
    Checking_Account(std::string name = "Unnamed Checking Account", double balance = 0.0);
    bool withdraw(double amount);
    // deposit inherited
    friend std::ostream& operator<<(std::ostream& os, const Checking_Account& account);
};

#endif
