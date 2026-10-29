#ifndef PROJECT_CHECKING_ACCOUNT_H
#define PROJECT_CHECKING_ACCOUNT_H

#include "account.h"
#include <string>

using namespace std;

class CheckingAccount : public Account {
public:
    //constructor to initialise the account with a balance and to store account holders name
    CheckingAccount(const std::string& name, const std::string& num, double bal, double transaction_fee);

    //applies a monthly fee if balance is under a threshold
    void applyMonthlyChanges();

    double getTransactionFee();

private:
    double Transaction_fee_rate;

    //this function uses the account balance to calculate the fee

};

#endif //PROJECT_CHECKING_ACCOUNT_H
