#include "Account.h"
#include"Transaction.h"
#include<iostream>
#include<string>
#include <stdexcept>
using namespace std;
int Account::activeaccounts = 0;
Account::Account(int i, string n, double bal):id(i),owner(n),balance(bal)
{
    activeaccounts++;
}
Account::~Account()
{
    activeaccounts--;
    cout << "Account closed for " << owner << endl;
}
double Account::deposit(double amount)
{
    if (amount <= 0)throw invalid_argument("Deposit must be positive");
    
        balance += amount;
        cout << "Your balance now after adding: " << amount << " Is: " << balance << endl;
        Transaction::tran("Deposit | ID: " + to_string(id) +
            " Amount: " + to_string(amount));
    return balance;
}

bool Account::transferfrom(double amount)
{
    if (amount <= 0) {
        cout << "Please enter postive value" << endl;
        return false;
    }
    if (amount > balance) {
        cout << "There is not enough balance" << endl;
        return false;
    }
    balance -= amount;
    cout << "Your balance now: " << balance << endl;
    return true;
}

double Account::transferto(double amount)
{
    balance += amount;
    return balance;
    
}

void Account::print() const
{
    cout << "Name " << "(" << owner << ")" << " Id" << "(" << id << ")" << " Balance" << "(" << balance << ")";

}

int Account::getid() const
{
    return id;
}

double Account::getbalance() const
{
    return balance;
}

