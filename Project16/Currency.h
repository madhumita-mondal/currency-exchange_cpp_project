#pragma once
#include <iostream>
#include <string>
int const ARRAY_SIZE = 5;
//Enums for index of array
typedef enum{
	DOLLAR,
	EURO,
	YEN,
	RUPEE,
	YUAN,
} currencyType;

class Currency
{
public:
	Currency() :curName(""), frcName(""),whPart(0),frcPart(0) {}
	Currency(std::string cn, int wp, int fp, std::string fn) :
		curName(cn), whPart(wp), frcPart(fp), frcName(fn) {}
	virtual ~Currency() {}

	Currency operator + (Currency& a);
	Currency operator - (Currency& a);
	bool operator==(Currency &t1);
	friend std::istream& operator>>(std::istream& is, Currency &c1);
	friend std::ostream& operator<<(std::ostream& os, const Currency &c2);

	double amntCur();
	void zero_out();
	bool isAmount_zero();
	virtual int getCurrencytype() { return -1; }
	void simplify();

	void setCurName(std::string a) { curName = a; }
	void setFrcName(std::string a) { frcName = a; }
	void setWhPart(int a);
	void setFrcPart(int a);
	
	std::string getCurName() { return curName; }
	std::string getFrcName() { return frcName; }
	int getWhPart() { return whPart; }
	int getFrcPart() { return frcPart; }

protected:
	std::string curName;
	int  whPart;
	int  frcPart;
	std::string frcName;
};
