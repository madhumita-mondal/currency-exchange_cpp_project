#pragma once
#include "CurrencyType.h"

class Wallet {
	//creates a new pointer array
	Currency * wal[ARRAY_SIZE];

public:
	Wallet();
	
	~Wallet();
	void AddCurrency(Currency &);//int t, int w_val, int f_val);
	void removeCurrency(Currency &);//int t, int w_val, int f_val);
	void zeroOut(int i);
	void zeroOutALL();
	bool isZero(int i);
	bool isZeroALL();
	int numNonZero();
	void report();
	void reportAll();
	Currency &operator[](const int);

};