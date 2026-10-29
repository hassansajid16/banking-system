#include "savings_account.h"
#include "account.h"
#include <iostream>
//constructor
SavingsAccount::SavingsAccount(const std::string& name, const std::string& num, double bal, double rate): Account(name, num, bal), interestRate(rate) {}

void SavingsAccount ::applyMonthlyChanges() {

    if (interestRate > 0) {
        double monthlyInterest = Account::balance * ((interestRate / 12) / 100); // Assuming interest rate is given in percentage
        Account::balance += monthlyInterest;
        std::cout << "Monthly interest applied: £" << monthlyInterest << "\n";
    } else {
        std::cerr << "Invalid interest rate.\n";
    }
}


