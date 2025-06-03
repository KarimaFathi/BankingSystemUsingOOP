#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include<vector>
#include<iomanip>


class clsListUserScreen : protected clsScreen
{
	private:
    static void _printUserRecordLine(clsUser user) {
        cout << setw(8) << left << "" << "| " << left << setw(15) << user.userName;
        cout << "| " << left << setw(20) << user.fullName();
        cout << "| " << left << setw(12) << user.phone;
        cout << "| " << left << setw(20) << user.email;
        cout << "| " << left << setw(10) << user.password;
        cout << "| " << left << setw(12) << user.permissions << endl;
    }

    public:
    static void showUsersList() {
        string title = "Users List Screen";
        vector<clsUser> vUsers = clsUser::getUsersList();
        string subtitle = "(" + to_string(vUsers.size()) + ") Users ";
        _drawScreenHeader(title, subtitle);

        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << left << setw(15) << "userName";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";

        if (vUsers.size() == 0) {
            cout << "\t\t\t\tNo available users in the system !";
        }
        else {
            for (clsUser& user : vUsers) {
                _printUserRecordLine(user);
            }
        }
        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n";


    }





};








//public:
//    static void showClientsList() {
//        string title = "Client List Screen";
//        vector<clsBankClient> vBankClients = clsBankClient::getClientsList();
//        string subtitle = "(" + to_string(vBankClients.size()) + ") Clients ";
//        _drawScreenHeader(title, subtitle);
//
//        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";
//        cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
//        cout << "| " << left << setw(20) << "Client Name";
//        cout << "| " << left << setw(12) << "Phone";
//        cout << "| " << left << setw(20) << "Email";
//        cout << "| " << left << setw(10) << "Pin Code";
//        cout << "| " << left << setw(12) << "Balance";
//        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";
//
//        if (vBankClients.size() == 0) {
//            cout << "\t\t\t\tNo available client in the system !";
//        }
//        else {
//            for (clsBankClient& client : vBankClients) {
//                _printClientRecordLine(client);
//            }
//        }
//        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n";
//
//
//    }
//};
