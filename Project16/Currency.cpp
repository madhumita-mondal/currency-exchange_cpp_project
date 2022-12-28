#include <iostream>
#include "Currency.h" 
using namespace std;

void Currency::setWhPart(int a)
{
	if (a < 0)
	{
		std::string e = "Error:Invalid input. Must be positive Int";
		throw e;
	}

	whPart = a;

}
void Currency::setFrcPart(int a)
{
	if (a < 0)
	{
		std::string e = "Error:Invalid input. Must be positive Int";
		throw e;
	}
	frcPart = a;

}

//Checks if a currency has zero amount
bool Currency::isAmount_zero()
{
	bool a = false;
	if (whPart == 0 && frcPart == 0)
	{
		a = true;
	}
	return a;
}
//sets value of a currency to zero
void Currency::zero_out() {

	whPart = 0;
	frcPart = 0;
}



//Returns the amount of a given currency to two decimal places as a double
double Currency::amntCur() {
	double total;
	total = (double)whPart + (((double)frcPart) / 100);
	return total;
}



void Currency::simplify() {

	if (frcPart >= 100)	{
		whPart += frcPart / 100;
		frcPart = frcPart % 100;
	}

	else if (frcPart < 0){
		whPart -= (abs(frcPart) / 100) + 1;
		frcPart = 100 - (abs(frcPart) % 100);
		if (frcPart == 100)	{
			whPart++;
			frcPart = 0;
		}
	}
	
}

bool Currency::operator==(Currency &t1) {
	bool r = false;
	if (this->getCurrencytype() == t1.getCurrencytype()) {
		r = true;
	}
	return r;
}

//Overloaded operator takes in double instead of currency, so new currency doesnt have to be declared each time
Currency Currency::operator + (Currency& a) {
	if (*this == a) {

		whPart += a.whPart;
		frcPart += a.frcPart;
	}
	simplify();

	return *this;
}
//Overloaded operator takes in double instead of currency, so new currency doesnt have to be declared each time

Currency Currency :: operator - (Currency& a)
{
	if (*this == a)
	{
		whPart -= a.whPart;
		frcPart -= a.frcPart;
	}
	simplify();

	return *this;

}
//Overloaded operator takes the amount of currency whole parts and fractions
std::istream& operator >> (std::istream  &is, Currency &c1)
{
	int input;
	cout << "Enter " << c1.curName << ":";
	is >> input;
	try
	{
		c1.setWhPart(input);

		cout << "Enter " << c1.frcName << ":";
		is >> input;
		c1.setFrcPart(input);
	}
	catch (string e)
	{
		c1.whPart = 0;
		c1.frcPart = 0;
		cout << e << endl;
	}
	c1.simplify();

	return is;
}
//Overloaded operator returns the amount of currency
std::ostream& operator<<(std::ostream& os, const Currency& c2)
{
	os << c2.curName << "," << c2.whPart << "," << c2.frcPart << ","
		<< c2.frcName << endl;
	return os;
}