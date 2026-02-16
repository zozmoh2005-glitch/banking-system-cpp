#include "CheckingAccountas.h"
#include"Transaction.h"
#include<iostream>
#include<string>
using namespace std;
CheckingAccountas::CheckingAccountas(int i, string n, double bal, double f):Account(i,n,bal),fee(f)
{
}

CheckingAccountas::~CheckingAccountas()
{
}

double CheckingAccountas::withdraw(double amount)
{
	if (amount <= 0){
		cout << "Please enter postive value" << endl;
	return balance;
}
if (amount + fee > balance) {
	cout << "There is not enough balance" << endl;
	return balance;
}	
		balance -= (amount+fee);
		cout << "Your balance now after draw: " << amount << " Is: " << balance << endl;
		Transaction::tran("Withdraw (Checking) | ID: " + to_string(id) +
			" Amount: " + to_string(amount));
	
	return balance;
}
bool CheckingAccountas::addinterest()
{
	cout << "Checking accounts do not earn interest" << endl;
	return false;
}
void CheckingAccountas::print() const
{
	Account::print();
	cout << "Fee " << "(" << fee << ")" << "Type " << "(" << "Checking" << ")" << endl;
}
