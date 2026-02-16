#pragma once
#include "Account.h"
#include<iostream>
#include<string>
using namespace std;
class CheckingAccountas :
    public Account
{
private:
    double fee;
public:
    CheckingAccountas(int i, string n, double bal, double f);
    ~CheckingAccountas();
    double withdraw(double amount) override;
    bool addinterest()override;
    void print() const override;
};

