//
// Created by Samuel Adebayo on 22/06/24.
//
#include "account.h"

Account::Account(const std::string& name, const std::string& num, double bal)
        : accountName(name), accountNumber(num), balance(bal) {}

void Account::setAccountName(const std::string& name) {
    accountName = name;
}

void Account::setAccountNumber(const std::string& num) {
    accountNumber = num;
}

void Account::setBalance(double bal) {
    balance = bal;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        std::cerr << "Deposit amount must be positive.\n";
    }
}

void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    } else {
        std::cerr << "Invalid withdrawal amount.\n";
    }
}

void Account::display() const {
    std::cout << "Account Name: " << accountName
              << "\nAccount Number: " << accountNumber
              << "\nBalance: $" << balance << std::endl;
}
