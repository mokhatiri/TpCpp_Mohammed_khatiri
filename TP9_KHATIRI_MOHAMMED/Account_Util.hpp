#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include <vector>
#include "Account.hpp"
#include "Savings_Account.hpp"
#include "Checking_Account.hpp"
#include "Trust_Account.hpp"

void display(const std::vector<Account>& accounts);
void deposit(std::vector<Account>& accounts, double amount);
void withdraw(std::vector<Account>& accounts, double amount);

void display(const std::vector<Savings_Account>& accounts);
void deposit(std::vector<Savings_Account>& accounts, double amount);
void withdraw(std::vector<Savings_Account>& accounts, double amount);

void display(const std::vector<Checking_Account>& accounts);
void deposit(std::vector<Checking_Account>& accounts, double amount);
void withdraw(std::vector<Checking_Account>& accounts, double amount);

void display(const std::vector<Trust_Account>& accounts);
void deposit(std::vector<Trust_Account>& accounts, double amount);
void withdraw(std::vector<Trust_Account>& accounts, double amount);

#endif
