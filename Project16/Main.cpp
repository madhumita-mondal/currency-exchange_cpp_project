/*CIS 22C


Partner:
Partner Score:

Partner:
Partner Score:
Lab 1
Create a wallet that holds 5 different currencies
Demonstrate operator overloading of +,- , << ,>>
Demonstrate inheritence
Demonstrate Polymorphism with parent class currency
*/

/*Preprocessor Directives*/
#include <iostream>
#include <iomanip>
#include <String>
#include "Wallet.h"
using namespace std;


/*****************************************************************************/
//                                  main()
//
/*****************************************************************************/
/*
********************
Variables:
Wallet w; creates a new wallet
Currency *ptr[5]: Array of Currency obj pointers
string in; saves input of user
/*****************************************************************************/

int main() {
	Wallet w;
	Currency *ptr[5];
	ptr[0] = new Dollar;
	ptr[1] = new Euro;
	ptr[2] = new Yen;
	ptr[3] = new Rupee;
	ptr[4] = new Yuan;

	char choice;
	do
	{
		system("CLS");
		cout << "---------------------------" << endl;
		cout <<setw(14)<<right<<"Wallet" << endl;

		cout << "---------------------------" << endl;
		cout << "(1) View Wallet Balances" << endl;
		cout << "(2) Add Money               " << endl;
		cout << "(3) Remove Money            " << endl;
		cout << "(4) Zero out Wallet/Currency         " << endl;
		cout << "(5) Exit                    " << endl;
		cout << "---------------------------" << endl;
		cout << "Enter Choice(1,2,3,4,5)";
		cin >> choice;

		string input;
		switch (choice)
		{

		case '1':
			do
			{
				system("CLS");
				cout << setw(14) <<right << "Wallet Balances"<<endl;
				cout << "---------------------------" << endl;
				cout << "(1) All Currency Balances" << endl;
				cout << "(2) Non-Zero Balances   " << endl;
				cout << "(3) Return to Main Menu  " << endl;
				cout << "Enter Choice(1,2,3,)" << endl;
				cin >> input;
				if (atoi(input.c_str()) == 1)
					w.reportAll();
				else if (atoi(input.c_str()) == 2)
					w.report();
				
			} while (!(atoi(input.c_str()) == 3));

			break;
		case '2':
		case '3':
			do {
				system("CLS");
				if (choice == '2')
				cout << setw(14) << right << "Add Money"<<endl;
				else
				cout << setw(14) << right  << "Remove Money"<<endl;
				cout << "---------------------------" << endl;
				cout << "(1) Dollars" << endl;
				cout << "(2) Euro    " << endl;
				cout << "(3) Yen   " << endl;
				cout << "(4) Rupee  " << endl;
				cout << "(5) Yuan    " << endl;
				cout << "(6) Return to Main Menu  " << endl;
				cout << "Enter Choice(1,2,3,4,5,6)"<<endl;
				cin >> input;
				if (atoi(input.c_str()) >= 0 && atoi(input.c_str()) <= 5)
				{
					
					cout << "Current Balance: " << w[atoi(input.c_str())-1] << endl;
					
					if (choice == '2') 
					{
						cout << "Enter the amount to add:" << endl;
						cin >> *ptr[atoi(input.c_str()) - 1];
						try 
						{
							w.AddCurrency(*ptr[atoi(input.c_str()) - 1]);
						}
						catch (string exception)
						{
							cout << exception << endl;
						}
					}
					else 
					{
						cout << "Enter the amount to remove:" << endl;
						cin >> *ptr[atoi(input.c_str()) - 1];
						try 
						{
							w.removeCurrency(*ptr[atoi(input.c_str()) - 1]);
						}
						catch (string exception)
						{
							cout << exception << endl;
						}
					}
					cout << "\nNew Balance: " << w[atoi(input.c_str())-1];
					system("pause");
				}
				
			} while (atoi(input.c_str()) !=6);
			break;
	
		case '4':
			do 
			{
				system("CLS");
				cout << setw(13) << right << "Zero out Wallet/Currency"<<endl;
				cout << "---------------------------" << endl;
				cout << "(1) Dollars" << endl;
				cout << "(2) Euro   " << endl;
				cout << "(3) Yen   " << endl;
				cout << "(4) Rupee  " << endl;
				cout << "(5) Yuan    " << endl;
				cout << "(6) All    " << endl;
				cout << "(7) Return to Main Menu  " << endl;
				cout << "Enter Choice(1,2,3,4,5,6,7)"<<endl;
				cin >> input;
				if (atoi(input.c_str()) >= 1 && atoi(input.c_str()) <= 5)
					w.zeroOut(atoi(input.c_str())-1);

				else if (atoi(input.c_str()) == 6)
					w.zeroOutALL();

				system("pause");
			} while (atoi(input.c_str()) !=7);
			break;
		case '5':
			break;
		default:
			break;
		}

	} while (choice != '5');

	delete[] *ptr;
	for (int x = 0; x < ARRAY_SIZE; x++)
		ptr[x] = nullptr;
	system("pause");
	return 0;
}
