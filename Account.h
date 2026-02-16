#pragma once
#include<iostream>
#include<string>
using namespace std;
class Account
{
protected:
	int id;
	string owner;
	double balance;
public:
	Account(int i, string n, double bal);
	/*
	 i used virtual distractor in the base class  when life time of object ended call the distractor for the
	drived class first then call the distractor for the base class second
	*/
	virtual ~Account();
	static int activeaccounts;
	virtual  double deposit(double amount);
	virtual bool transferfrom(double amount);
	virtual double transferto(double amount);
	virtual bool addinterest() = 0;
	virtual  double withdraw(double amount)=0;
	virtual void print() const;
	int getid() const;
	double getbalance() const;

};
