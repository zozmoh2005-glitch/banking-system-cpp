#include "SavingsAccounts.h"
#include"Transaction.h"
#include<iostream>
#include<string>
using namespace std;
SavingsAccounts::SavingsAccounts(int i, string n, double bal, double rate):Account(i,n,bal),interestrate(rate)
{
}

SavingsAccounts::~SavingsAccounts()
{
}

double SavingsAccounts::withdraw(double amount)
{
	if (amount <= 0) {
		cout << "Please enter postive value" << endl;
		return balance;
	}
	if (amount > balance) {
		cout << "There is not enough balance" << endl;
		return balance;
	}
	
		balance -= amount;
		cout << "Your balance now after draw: " << amount << " Is: " << balance << endl;
		Transaction::tran("Withdraw (Savings) | ID: " + to_string(id) +
			" Amount: " + to_string(amount));
	
	return balance;
}

bool SavingsAccounts::addinterest()
{
	balance += balance * interestrate;
	Transaction::tran("Interest Added | ID: " + to_string(id) +
		" Rate: " + to_string(interestrate));
	return true;

}

void SavingsAccounts::print() const
{
	Account::print();
	cout << "Interest " << "(" << interestrate << ")" << "Type " << "(" << "Saving" << ")" << endl;
}
