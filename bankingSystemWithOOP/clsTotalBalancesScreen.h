#pragma once
#include<iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtilities.h"




class clsTotalBalancesScreen : protected clsScreen
{


private:
    static void _printClientBalanceRecordLine(clsBankClient client) {
        cout << setw(25) << left << "" << "| " << left << setw(15) << client.accountNumber;
        cout << "| " << left << setw(40) << client.fullName();
        cout << "| " << left << setw(12) << client.accountBalance << endl;
    }

public:
	static void showTotalBalances() {
		string title = "Client List Screen";
		vector<clsBankClient> vBankClients = clsBankClient::getClientsList();
		string subtitle = "(" + to_string(vBankClients.size()) + ") Clients ";
		_drawScreenHeader(title, subtitle);
        cout << setw(25) << left << "" << "\n\t\t\t________________________________________________________________________________________\n\n";
        cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "\n\t\t\t________________________________________________________________________________________\n\n";
        double totalBalances = clsBankClient::getTotalBalances();
        if (vBankClients.size() == 0) {
            cout << "\t\t\t\tNo available client in the system !";
        }
        else {
            for (clsBankClient& client : vBankClients) {
                _printClientBalanceRecordLine(client);
            }
        }
        cout << setw(25) << left << "" << "\n\t\t\t________________________________________________________________________________________\n";
        cout << "\t\t\t\t\t\t   Total Balances = " << totalBalances << endl;
        cout << "\t\t\t\t\t   ( " << clsUtilities::numberToText(totalBalances) << ")";

	}
};

