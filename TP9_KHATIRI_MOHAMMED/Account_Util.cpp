#include <iostream>
#include "Account_Util.hpp"

// Account
void display(const std::vector<Account>& accounts) {
    std::cout << "=== Accounts===========================================\n";
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}
void deposit(std::vector<Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================\n";
    for (auto& acc : accounts) {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
}
void withdraw(std::vector<Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================\n";
    for (auto& acc : accounts) {
        if (acc.withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
}

// Similar overloads for other types (Savings, Checking, Trust)
#define DEFINE_UTILS_FOR_TYPE(TYPE, LABEL) \
void display(const std::vector<TYPE>& accounts) { \
    std::cout << "\n=== " << LABEL << " Accounts=====================================\n"; \
    for (const auto& acc : accounts) std::cout << acc << std::endl; \
} \
void deposit(std::vector<TYPE>& accounts, double amount) { \
    std::cout << "\n=== Depositing to " << LABEL << " Accounts===========================\n"; \
    for (auto& acc : accounts) { \
        if (acc.deposit(amount)) \
            std::cout << "Deposited " << amount << " to " << acc << std::endl; \
        else \
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl; \
    } \
} \
void withdraw(std::vector<TYPE>& accounts, double amount) { \
    std::cout << "\n=== Withdrawing from " << LABEL << " Accounts=======================\n"; \
    for (auto& acc : accounts) { \
        if (acc.withdraw(amount)) \
            std::cout << "Withdrew " << amount << " from " << acc << std::endl; \
        else \
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl; \
    } \
}

DEFINE_UTILS_FOR_TYPE(Savings_Account, "Savings")
DEFINE_UTILS_FOR_TYPE(Checking_Account, "Checking")
DEFINE_UTILS_FOR_TYPE(Trust_Account, "Trust")
