#pragma once
#include "Account.h"
#include<iostream>
#include<string>
using namespace std;
class SavingsAccounts :
    public Account
{
private:
    double interestrate;
public:
    SavingsAccounts(int i, string n, double bal, double rate);
    ~SavingsAccounts();
    double withdraw(double amount) override;
    double addinterest() override;
    void print() const override;
};

