#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>
#include"Account.h"
using namespace std;
class BankSystem
{
private:
	unordered_map<int, Account*>accounts;
	Account* findaccount(int id);
public:
	~BankSystem();
	void createacount();
	void deposit();
	void withdraw();
	void addinterest();
	void transfer();
	void showaccount();
	void showallaccounts();
	void showactiveacounts();
	void menu();
};

