#include "Wallet.h"
using namespace std;

//creates an array of polymorphic currencies
Wallet::Wallet() 
{
	wal[DOLLAR] = new Dollar();
	wal[YEN] = new Yen();
	wal[EURO] = new Euro();
	wal[RUPEE] = new Rupee();
	wal[YUAN] = new Yuan();
}
//destructor, deletes all points in the currency array
Wallet::~Wallet()
{
	delete[] * wal;
	for (int x = 0; x < ARRAY_SIZE; x++)
		wal[x] = nullptr;
	
	
}
//checks if a currency has zero fractional and whole values
bool Wallet::isZero(int i) {
	if (wal[i]->isAmount_zero()) {
		return true;
	}
	else
	return false;
};
//checks if all currencies have zero amounts
bool Wallet::isZeroALL() {
	bool facts = false;
	if ((((wal[DOLLAR])->amntCur()) == 0) && (((wal[YEN])->amntCur()) == 0) && (((wal[EURO])->amntCur()) == 0) && (((wal[RUPEE])->amntCur()) == 0) && (((wal[YUAN])->amntCur()) == 0)) {
		facts = true;
	}
	return facts;

};
//zeros out a given currencies
void Wallet::zeroOut(int i) {
	wal[i]->zero_out();
};
//zeros out all currencies
void Wallet::zeroOutALL() {
	for (int i = 0; i < 5; i++) {
		(wal[i])->zero_out();
	}
}

//adds a given amount to a chosen currency
void Wallet::AddCurrency(Currency & a)//int t, int w_val, int f_val)
{
	string exception;
	if (a.getWhPart() < 0 || a.getFrcPart() < 0) {
		exception = "Invalid operation. Please enter postive integers";
		throw exception;
	}
	*(wal[a.getCurrencytype()])+ a;

}
//removes an amount of given currency
void Wallet::removeCurrency(Currency & a)//int t, int w_val, int f_val)
{
	string exception;
	if (a.getWhPart() < 0 ||a.getFrcPart()<0) {
		exception = "Invalid operation. Please enter postive integers";
		throw exception;
	}
	if (isZero(a.getCurrencytype()) || a.amntCur() > wal[a.getCurrencytype()]->amntCur()) {
		exception = "Insufficient Balance. Unable to complete operation.";
		throw exception;
	}
	else
		*wal[a.getCurrencytype()] - a;
	
};
void Wallet::report()
{
	system("CLS");
	for (int x = 0; x < ARRAY_SIZE; x++)
	{
		if (!(isZero(x)))
			cout << *wal[x];
	}

	if (numNonZero() == 0)
		cout << "Wallet is Empty" << endl;
	else
		cout << "Number of Non-Zero Currencies: " << numNonZero() << endl;

	system("pause");
}
void Wallet::reportAll()
{
	system("CLS");
	for (int x = 0; x < ARRAY_SIZE; x++)
	{
		cout << *wal[x];
	}
	cout << "Number of Non-Zero Currencies: " << numNonZero() << endl;
	system("pause");
}
int Wallet::numNonZero() {
	int count = 0;
	for (int x = 0; x < ARRAY_SIZE; x++)
	{
		if (!(isZero(x)))
			count++;
	}
	return count;
}

//Operator overloading checks if given index is within bounds
Currency & Wallet::operator[](const int i)
{
	if (i > 4||i<0)
 {
		std::cout << "Index out of bounds";
		return *(wal[0]);
	}
	return *(wal[i]);
};


