#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Savings_Account.hpp"

class Trust_Account : public Savings_Account {
private:
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
    int num_withdrawals;

public:
    Trust_Account(std::string name = "Unnamed Trust Account", double balance = 0.0, double int_rate = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
    friend std::ostream& operator<<(std::ostream& os, const Trust_Account& account);
};

#endif
