#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;



class clsClientListScreen : protected clsScreen
{
private: 
    static void _printClientRecordLine(clsBankClient client) {
        cout << setw(8) << left << "" << "| " << left << setw(15) << client.accountNumber;
        cout << "| " << left << setw(20) << client.fullName();
        cout << "| " << left << setw(12) << client.phone;
        cout << "| " << left << setw(20) << client.email;
        cout << "| " << left << setw(10) << client.pinCode;
        cout << "| " << left << setw(12) << client.accountBalance << endl;
    }

public:
	static void showClientsList() {
		string title = "Client List Screen";
        vector<clsBankClient> vBankClients = clsBankClient::getClientsList();
        string subtitle = "(" + to_string(vBankClients.size()) + ") Clients ";
        _drawScreenHeader(title, subtitle);

        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";

        if (vBankClients.size() == 0) {
            cout << "\t\t\t\tNo available client in the system !";
        }
        else {
            for (clsBankClient& client : vBankClients) {
                _printClientRecordLine(client);
            }
        }
        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n";


	}
};

