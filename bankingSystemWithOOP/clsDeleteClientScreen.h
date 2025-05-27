#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


class clsDeleteClientScreen : protected clsScreen
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
    static void showDeleteClientScreen() {
        string title = "Delete Client Screen";
        _drawScreenHeader(title);
        string accountNumber = "";
        cout << "\nPlease enter the account number : ";
        accountNumber = clsInputValidate::readString();
        while (!clsBankClient::isClientExists(accountNumber)) {
            cout << "\nAccount number is not found, choose another one : ";
            accountNumber = clsInputValidate::readString();
        }
        clsBankClient client = clsBankClient::find(accountNumber);
        _printClientInfo(client); 

        cout << "Are you sure you want to delete this client (y/n) : ";
        char answer = 'n';
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            if (client.deleteClient() == true) {
                cout << "\nClient deleted successfully.\n";
                _printClientInfo(client);
            }
            else {
                cout << "\nError client was not deleted, \n";
            }
        }
    }
};

