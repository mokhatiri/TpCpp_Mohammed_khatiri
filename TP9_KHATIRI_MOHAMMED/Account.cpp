#include "Account.hpp"

Account::Account(std::string name, double balance)
    : name{name}, balance{balance} {
}

bool Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}

bool Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}
