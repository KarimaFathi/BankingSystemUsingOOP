#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _readClientInfo(clsBankClient& client) {
        cout << "\nEnter FirstName: ";
        client.firstName = clsInputValidate::readString();

        cout << "\nEnter LastName: ";
        client.lastName = clsInputValidate::readString();

        cout << "\nEnter Email: ";
        client.email = clsInputValidate::readString();

        cout << "\nEnter Phone: ";
        client.phone = clsInputValidate::readString();

        cout << "\nEnter PinCode: ";
        client.pinCode = clsInputValidate::readString();

        cout << "\nEnter Account Balance: ";
        client.accountBalance = clsInputValidate::readFloatNumber();
    }

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
	static void showAddNewClientScreen() {
		string title = "Add New Client Screen";
		_drawScreenHeader(title);
        string accountNumber = "";
        cout << "\nPlease enter the account number : ";
        accountNumber = clsInputValidate::readString();
        while (clsBankClient::isClientExists(accountNumber)) {
            cout << "\nAccount number already exists, choose another one : ";
            accountNumber = clsInputValidate::readString();
        }
        clsBankClient client = clsBankClient::addNewClientObject(accountNumber);
        _readClientInfo(client);
        clsBankClient::enSaveResult saveResult = client.save();
        switch (saveResult) {
        case clsBankClient::enSaveResult::failedAccountNumberExists:
            cout << "\nError account was not added  because it does already exists";
            break;
        case clsBankClient::enSaveResult::successeded:
            cout << "\nAccount added Successfully :-)\n";
            _printClientInfo(client);
            break;
        }
	}
};

