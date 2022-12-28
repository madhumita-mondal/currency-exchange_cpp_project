#pragma once
#include "Currency.h"
#include <String>

class Dollar : public Currency
{
public:
	Dollar() : Currency("Dollar", 0, 0, "Cents") {}
	Dollar(int w_val, int f_val) : Currency("Dollar", w_val, f_val, "Cent") {}
	~Dollar() {}
	int getCurrencytype() { return DOLLAR; }
private:

};

class Euro :public Currency
{
public:
	Euro() : Currency("Euro", 0, 0, "Cents") {}
	Euro(int w_val, int f_val) : Currency("Euro", w_val, f_val, "Cent") {}
	~Euro() {}
	int getCurrencytype() { return EURO; }
	

};

class Yen :public Currency
{
public:
	Yen() : Currency("Yen", 0, 0, "Sen") {}
	Yen(int w_val, int f_val) : Currency("Yen", w_val, f_val, "Sen") {}
	~Yen() {}
	int getCurrencytype() { return YEN; }
	
};

class Rupee : public Currency
{
public:
	Rupee() : Currency("Rupee", 0, 0, "Paise") {}
	Rupee(int w_val, int f_val) : Currency("Rupee", w_val, f_val, "Paise") {}
	~Rupee() {}
	int getCurrencytype() { return RUPEE; }
	
private:
};


class Yuan : public Currency
{
public:
	Yuan() : Currency("Yuan", 0, 0, "Fen") {}
	Yuan(int w_val, int f_val) : Currency("Yuan", w_val, f_val, "Fen") {}
	~Yuan() {}
	int getCurrencytype() { return YUAN; }
	
};