#include "BankSystem.h"
#include"Account.h"
#include"SavingsAccounts.h"
#include"CheckingAccountas.h"
#include"Transaction.h"
#include<iostream>
#include<string>
using namespace std;
Account* BankSystem::findaccount(int id)
{
    auto it = accounts.find(id);
    if (it != accounts.end())return it->second;
    return nullptr;
}
BankSystem::~BankSystem()
{
    for (auto& acc : accounts)
        delete acc.second;
}
void BankSystem::createacount()
{
    int type, id;
    string name;
    double bal;
    cout << "1.SavingAccount  2.CheckingAccount :  ";cin >> type;
    
    cout << "Enter your name: "; cin.ignore(); getline(cin, name);
    cout << "Enter id: "; cin >> id;
    if (accounts.count(id)) {
        cout << "ID Already Exists" << endl;
        return;
    }
    cout << "Enter Balance: "; cin >> bal;
    if (bal == 0) {
        cout << "You can not make account with no balance" << endl;
        return;
    }
    if (type == 1)
        accounts[id] = new SavingsAccounts(id, name, bal, 0.05);
    else if (type == 2)
        accounts[id] = new CheckingAccountas(id, name, bal, 10);
    else {
 cout << "Wrong input" << endl;
 return;
    }
    cout << "Account created succesfully" << endl;
}

void BankSystem::deposit()
{
    int id;
    double amount;
    cout << "Enter your id: "; cin >> id;
    Account* acc = findaccount(id);
    if (!acc) {
        cout << "Account not found" << endl;
        return;
    }
    cout << "Enter amount: "; cin >> amount;
    acc->deposit(amount);
}

void BankSystem::withdraw()
{
    int id;
    double amount;
    cout << "Enter your id: "; cin >> id;
    Account* acc = findaccount(id);
    if (!acc) {
        cout << "Account not found" << endl;
        return;
    }
    cout << "Enter amount: "; cin >> amount;
    acc->withdraw(amount);
}

void BankSystem::addinterest()
{
    int id;
    cout << "Enter your id: ";
    cin >> id;

    Account* acc = findaccount(id);
    if (!acc) {
        cout << "Account not found" << endl;
        return;
    }

    acc->addinterest();
    cout << "Interest added successfully" << endl;
}

void BankSystem::transfer()
{
    int first_id, second_id;
    double amount;
    cout << "Enter your id: "; cin >> first_id;
    Account* first_acc = findaccount(first_id);
    if (!first_acc) {
        cout << "Account not found" << endl;
        return;
    }
    cout << "Enter id of the second account: "; cin >> second_id;
    Account* second_acc = findaccount(second_id);
    if (!second_acc) {
        cout << "Account not found" << endl;
        return;
    }
    if (first_acc == second_acc) {
        cout << "Cannot transfer to the same account" << endl;
        return;
    }
    cout << "Enter amount: "; cin >> amount;
    if (amount == 0) {
        cout << "You can not transfer 0" << endl;
        return;
    }
    if (first_acc->transferfrom(amount)) {
second_acc->transferto(amount);
Transaction::tran("Transfer from ID: " + to_string(first_id) + " To ID: " + to_string(second_id) +
    " Amount: " + to_string(amount));
Transaction::tran("Transfer To ID: " + to_string(second_id) +
    " Amount: " + to_string(amount));

cout << "Transfer compeleted succesfully" << endl;
    }
    
}

void BankSystem::showaccount()
{
    int id;
    cout << "Enter your id: "; cin >> id;
    Account* acc = findaccount(id);
    if (!acc) {
        cout << "Account not found" << endl;
        return;
    }
    acc->print();
}

void BankSystem::showallaccounts()
{
    int pass;
    cout << "Enter password please: "; cin >> pass;
    const int Admin_Pass = 0000;
    if (pass == Admin_Pass)
        for (auto& acc : accounts)
            acc.second->print();
    else cout << "Wrong password" << endl;
}

void BankSystem::showactiveacounts()
{
    int pass;
    cout << "Enter password please: "; cin >> pass;
    const int Admin_Pass = 0000;
    if (pass == Admin_Pass)
        cout <<"Active accounts: " << Account::activeaccounts << endl;
    else cout << "Wrong password" << endl;
}

void BankSystem::menu()
{
    int choice;
    do {
        cout << "1 To Create Account" << endl;
        cout << "2 To Deposit" << endl;
        cout << "3 To Withdraw" << endl;
        cout << "4 To AddInterest" << endl;
        cout << "5 To Transfer" << endl;
        cout << "6 To ShowAccount" << endl;
        cout << "7 To ShowAllAccounts" << endl;
        cout << "8 To ShowActiveAccounts" << endl;
        cout << "0 for Exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:createacount(); break;
        case 2:deposit(); break;
        case 3:withdraw(); break;
        case 4:addinterest(); break;
        case 5:transfer(); break;
        case 6:showaccount(); break;
        case 7:showallaccounts(); break;
        case 8:showactiveacounts(); break;
        }
    } while (choice != 0);
}
