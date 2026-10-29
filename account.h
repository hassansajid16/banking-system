//
// Created by Samuel Adebayo on 22/06/24.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H   //includes guard to prevent multiple inclusions of this header file

#include<iostream>
using namespace std;

class Account {


public:
    //properties (class atrributes: contain information about an object of the class)
    string accountName;     //Name of the account holder
    string accountNumber;   //Unique identifier for the account
    double balance;    //Current balance in the account

    //Parameterised constructor
    Account(const string& name, const string& num,double bal);

    //Setter: allow modification of the private attributes
    void setAccountName(const string& name);
    void setAccountNumber(const string& num);
    void setBalance(double bal);

    //No getter: ensures that the internal state of the object is protected

    //Methods: function that define behavior of the class
    void deposit(double amount);
    void withdraw(double amount);
    void display()const;

};
#endif
