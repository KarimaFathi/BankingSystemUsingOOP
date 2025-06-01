#pragma once
#include<iostream>
#include<iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;



class clsTransactionsScreen : protected clsScreen
{
private:
	enum _enTransactionsMenu { deposite = 1, withdraw = 2, totalBalance = 3, mainMenu = 4 };

	 static short _readMenuOption() {
		cout << setw(37) << left << "" << "Please select an option from the menu above(1 - 4) : ";
		short number = clsInputValidate::readIntNumberBetween(1, 8, "Option is out of range, please select a number between 1 to 4 : ");
		return number;
	}

	 static void _goBackToTransactionMenu() {
		 cout << "\n\nPress any key to go back to Main Menu...";
		 system("pause>0");
		 system("cls");
		 showTransactionsMenu();
	 }
	 static void  _showDepositScreen() {}
	 static void _showBalanceScreen() {}
	static void _showWithdrawScreen() {}
	static void _showMainMenu(){}




	 static void _performTransactionsOptions(_enTransactionsMenu transactionOption) {
		 switch (transactionOption) {
		 case _enTransactionsMenu::deposite:
			 system("cls");
			 _showDepositScreen();
			 _goBackToTransactionMenu();
			 break;
		 case _enTransactionsMenu::totalBalance:
			 system("cls");
			 _showBalanceScreen();
			 _goBackToTransactionMenu();
			 break;
		 case _enTransactionsMenu::withdraw:
			 system("cls");
			 _showWithdrawScreen();
			 _goBackToTransactionMenu();
			 break;
		 case _enTransactionsMenu::mainMenu:
			 system("cls");
			 _showMainMenu();
		 }
	}
public:

	static void showTransactionsMenu() {

		_drawScreenHeader("Transactions Screen");
		cout << setw(37) << left << "" << "=========================================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menu Screen\n";
		cout << setw(37) << left << "" << "=========================================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
		cout << setw(37) << left << "" << "=========================================================\n";
		_performTransactionsOptions((_enTransactionsMenu)_readMenuOption());
	}

};

