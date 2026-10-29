#include "checking_account.h"
#include "account.h"

using namespace std;

// Static constant member variable initialization

// Constructor to initialize the account with a balance and to store account holder's name
CheckingAccount::CheckingAccount(const string& name, const string& num, double bal, double transaction_fee)
        : Account(name, num, bal), Transaction_fee_rate(transaction_fee) {
}

// Apply monthly charges if balance is under a threshold
void CheckingAccount::applyMonthlyChanges() {
    if (balance < 2500.0) {
        //ouble monthly_charge = (Transaction_fee_rate/100)* balance;
        withdraw(Transaction_fee_rate);
        cout << "Monthly charge of $" << Transaction_fee_rate << " applied." << endl;
    }
    else {
        cout << "No fee applied. Account balance is above the specified threshold" << endl;
    }
}

// Method to calculate transaction fee based on the account balance
double CheckingAccount::getTransactionFee() {
    return Transaction_fee_rate;
}