#include "account.h"
#include "savings_account.h"
#include "check_credentials.h"
#include "checking_account.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

class helper {

public:
    template <typename T>
    static void ExpandArray(T**& acc, T*& add, int& count) {

        T** temp = acc;
        acc = new T * [count + 1];

        for (int i = 0; i < count; i++)
        {
            acc[i] = temp[i];
        }
        acc[count++] = add;
        delete[] temp;
    }

};

void bankManagement(CheckingAccount** &checkAccounts, SavingsAccount** &savingsAccounts, int& checkingAccountCount, int &savingAccountCount) {

    cout << "1. Create Savings Account\n2. Create Checking Account\n3. Deposit Money\n4. Withdraw Money\n5. Display All Accounts\n6. Apply Monthly Updates\n7. Exit\n";
    int choice = 0;
    cout << "Choose an option (Press numbers 1-7) = ";
    cin >> choice;
    switch (choice)
    {

        case 1: {
            //const std::string & name, const std::string& num, double bal, double rate)
            string name;
            cout << "Enter Account Name: " << endl;
            cin >> name;
            string num;
            cout << "Enter Account Number: " << endl;
            cin >> num;
            double balance;
            cout << "Enter Account Balance: " << endl;
            cin >> balance;
            double rate;
            cout << "Enter ROI: " << endl;
            cin >> rate;
            SavingsAccount* savingAcc = new SavingsAccount(name, num, balance, rate);
            helper::ExpandArray(savingsAccounts, savingAcc, savingAccountCount);
            cout << "Account created successfully\n";
            bankManagement(checkAccounts, savingsAccounts, checkingAccountCount, savingAccountCount);
            break;
        }
        case 2: {

            string name;
            cout << "Enter Account Name: " << endl;
            cin >> name;
            string num;
            cout << "Enter Account Number: " << endl;
            cin >> num;
            double balance;
            cout << "Enter Account Balance: " << endl;
            cin >> balance;
            double transactionFee;
            cout << "Enter Transaction Fee rate: " << endl;
            cin >> transactionFee;
            CheckingAccount* CheckingAcc = new CheckingAccount(name, num, balance, transactionFee);
            helper::ExpandArray(checkAccounts, CheckingAcc, checkingAccountCount);
            cout << "Account created successfully\n";
            bankManagement(checkAccounts, savingsAccounts, checkingAccountCount, savingAccountCount);
            break;
        }
        case 3:
        {
            cout << "What account to deposit money?\n";//<< "(" << accountCount << ")\n";
            string accountChoice;
            cin >> accountChoice;
            Account* temp = NULL;
            int i = 0;
            for (; i < savingAccountCount; i++)
            {
                if (savingsAccounts[i]->accountNumber == accountChoice) {
                    temp = savingsAccounts[i];
                    int deposit = 0;
                    cout << "What amount to deposit?\n";
                    cin >> deposit;
                    temp->deposit(deposit);
                    break;
                }
            }
            if (temp == nullptr) {
                i = 0;
                for (; i < checkingAccountCount; i++)
                {
                    if (checkAccounts[i]->accountNumber == accountChoice) {
                        temp = checkAccounts[i];
                        int deposit = 0;
                        cout << "What amount to deposit?\n";
                        cin >> deposit;
                        if(deposit>1000)
                            checkAccounts[i]->withdraw(checkAccounts[i]->getTransactionFee());
                        temp->deposit(deposit);
                        break;
                    }
                }
            }

            if (temp == nullptr) {
                cout << "Enter Valid Account Number\n";
            }

            bankManagement(checkAccounts, savingsAccounts, checkingAccountCount, savingAccountCount);
            break;

        }

        case 4:
        {
            cout << "What account to withdraw money from?\n";//<< "(" << accountCount << ")\n";
            string accountChoice;
            cin >> accountChoice;

            Account* temp = NULL;
            int i = 0;
            for (; i < savingAccountCount; i++)
            {
                if (savingsAccounts[i]->accountNumber == accountChoice) {
                    temp = savingsAccounts[i];
                    int withdraw = 0;
                    cout << "What amount to withdraw?\n";
                    cin >> withdraw;
                    temp[i].withdraw(withdraw);
                    break;
                }
            }
            if (temp== NULL) {
                i = 0;
                for (; i < checkingAccountCount; i++)
                {
                    if (checkAccounts[i]->accountNumber == accountChoice) {
                        temp = checkAccounts[i];
                        int withdraw = 0;
                        cout << "What amount to withdraw?\n";
                        cin >> withdraw;
                        if (withdraw > 1000)
                            checkAccounts[i]->withdraw(checkAccounts[i]->getTransactionFee());
                        temp[i].withdraw(withdraw);
                        break;
                    }
                }
            }

            if (temp== NULL) {
                cout << "Enter Valid Account Number\n";
            }

            bankManagement(checkAccounts, savingsAccounts, checkingAccountCount, savingAccountCount);
            break;
        }
        case 5:
        {
            if (savingAccountCount == 0 && checkingAccountCount == 0) {
                cout << "** No account Found **\n";
            }

            for (int i = 0; i < savingAccountCount; i++)
            {
                savingsAccounts[i]->display();
            }
            for (int i = 0; i < checkingAccountCount; i++)
            {
                checkAccounts[i]->display();
            }

            bankManagement(checkAccounts, savingsAccounts, checkingAccountCount, savingAccountCount);
            break;
        }
        case 6:
        {
            for (int i = 0; i < savingAccountCount; i++)
            {
                savingsAccounts[i]->applyMonthlyChanges();
            }
            for (int i = 0; i < checkingAccountCount; i++)
            {
                checkAccounts[i]->applyMonthlyChanges();
            }
            cout << "Monthly Changes Applied. Successfully!" << endl;
            bankManagement(checkAccounts, savingsAccounts, checkingAccountCount, savingAccountCount);
            break;
        }
        case 7:
        {
            cout << "Exiting. Thank You";
            break;
        }
        default:
            break;
    }
}


int main(){
    {
        CheckingAccount** checkAccounts = NULL;
        SavingsAccount** savingAccounts = NULL;
        int CheckingAccountCount = 0;
        int savingAccountCount = 0;

        if (checkAdminCredentials()) {
            bankManagement(checkAccounts, savingAccounts, CheckingAccountCount, savingAccountCount);
        }
        else {
            cout << "Sorry you can't login";
        }

        for (int i = 0; i < savingAccountCount; i++)
        {
            delete savingAccounts[i];
        }
        delete[] savingAccounts;

        for (int i = 0; i < CheckingAccountCount; i++)
        {
            delete checkAccounts[i];
        }
        delete[] checkAccounts;
    }
}


