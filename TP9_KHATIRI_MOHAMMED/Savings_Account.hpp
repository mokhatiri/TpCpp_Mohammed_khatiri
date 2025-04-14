#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.hpp"

class Savings_Account : public Account {
private:
    static constexpr double def_int_rate = 0.0;
    double int_rate;

public:
    Savings_Account(std::string name = "Unnamed Savings Account", double balance = 0.0, double int_rate = def_int_rate);
    bool deposit(double amount);
    // withdraw inherited
    friend std::ostream& operator<<(std::ostream& os, const Savings_Account& account);
    double get_int_rate() const { return int_rate; } // Added getter for interest rate
};

#endif