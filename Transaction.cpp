#include "Transaction.h"
#include<fstream>
void Transaction::tran(const string& message)
{
	ofstream file("transaction.txt", ios::app);
	file << message << endl;
	file.close();
}
