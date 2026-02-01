#include<iostream>
#include<string>
#include"BankSystem.h"
using namespace std;
int main() {
	try {
		BankSystem bank;
		bank.menu();
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}
	return 0;
}