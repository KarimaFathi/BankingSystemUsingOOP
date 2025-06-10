#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsShowTransferScreen : protected clsScreen
{
private:
    static float _readTransferAmount(clsBankClient client) {
        float transferAmount = 0;
        cout << "\nEnter transfer amount: ";
        transferAmount = clsInputValidate::readFloatNumber();
        while (transferAmount > client.accountBalance) {
            cout << "\nAmount exceeds the available balance, enter another one : ";
            transferAmount = clsInputValidate::readFloatNumber();
        }
        return transferAmount;
    }

    static void _printClientInfo(clsBankClient client) {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << client.fullName();
        cout << "\nAcc. Number : " << client.accountNumber;
        cout << "\nBalance     : " << client.accountBalance;
        cout << "\n___________________\n";
    }


    static string _readAccountNumber(string message) {
        string accountNumber = "";
        cout << message;
        accountNumber = clsInputValidate::readString();
        while (!clsBankClient::isClientExists(accountNumber)) {
            cout << "\nAccount number is not found, choose another one : ";
            accountNumber = clsInputValidate::readString();
        }
        return accountNumber;
    }


public:
    static void showTransferScreen() {

        string title = "Transfer Screen";
        _drawScreenHeader(title);
        string senderAccountNumber = _readAccountNumber("\nPlease enter the account number to transfer from  : ");
        string receiverAccountNumber = _readAccountNumber("\nPlease enter the account number to transfer to  : ");

        clsBankClient senderClient = clsBankClient::find(senderAccountNumber);
        _printClientInfo(senderClient);

       
        clsBankClient receiverClient = clsBankClient::find(receiverAccountNumber);
        _printClientInfo(receiverClient);

        float transferAmount = _readTransferAmount(senderClient);

        cout << "\nAre you sure you want to perform this operation ? (y/n) : ";

        char answer = 'n';

        cin >> answer;

        if (answer == 'y' || answer == 'Y') {

            if (senderClient.Transfer(transferAmount, receiverClient) == true) {

                cout << "\nTransfer done successfully :)";
                _printClientInfo(senderClient);
                _printClientInfo(receiverClient);
            }
            else
            {
                cout << "\nTransfer Failed \n";
            }
        }

        else {
            cout << "\nNo changes have been applied.";
        }
    }
};

