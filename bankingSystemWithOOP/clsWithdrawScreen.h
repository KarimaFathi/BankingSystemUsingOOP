#pragma once
#include<iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"



class clsWithdrawScreen : protected clsScreen
{
private:
	static void _printClientInfo(clsBankClient client) {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << client.firstName;
		cout << "\nLastName    : " << client.lastName;
		cout << "\nFull Name   : " << client.fullName();
		cout << "\nEmail       : " << client.email;
		cout << "\nPhone       : " << client.phone;
		cout << "\nAcc. Number : " << client.accountNumber;
		cout << "\nPassword    : " << client.pinCode;
		cout << "\nBalance     : " << client.accountBalance;
		cout << "\n___________________\n";
	}
public:
	static void showWithdrawScreen() {
		_drawScreenHeader("Withdraw Screen");
		string accountNumber = "";
		cout << "\nPlease enter the account number : ";
		accountNumber = clsInputValidate::readString();
		while (!clsBankClient::isClientExists(accountNumber)) {
			cout << "\nAccount number is not found, choose another one : ";
			accountNumber = clsInputValidate::readString();
		}
		clsBankClient client = clsBankClient::find(accountNumber);
		_printClientInfo(client);
		cout << "\nPlease enter withdraw amount : ";
		double withdrawAmount = clsInputValidate::readDblNumber();
		cout << "\nAre you sure you want to perform this transaction ? ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			if (client.withdraw(withdrawAmount) == true) {
				cout << "\nWithdrawal successful..\n";
				cout << "\nNew balance is : " << client.accountBalance;
			}
			else {
				cout << "\nCannot withdraw, insufficient balance !";
			}
		}
		else {
			cout << "\nOperation was cancelled.\n";
		}

	}

};

