//
// Created by imhas on 06/07/2024.


#include "account.h"
#ifndef SAVINGS_ACCOUNT_SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_SAVINGS_ACCOUNT_H
class SavingsAccount : public Account {

    double interestRate;
public:
    SavingsAccount (const std::string& name, const std::string& num, double bal, double rate);
    void applyMonthlyChanges();

};
#endif //SAVINGS_ACCOUNT_SAVINGS_ACCOUNT_H


