#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include<vector>
#include<iomanip>
using namespace std;


class clsLoginRegisterScreen : protected clsScreen
{
private:
    static void _printLoginsRecordLine(vector<string > vLoginData) {
        if (vLoginData.size() < 4) {
            cout << "Invalid data line: less than 4 fields." << endl;
            return; // Or handle differently
        }
        std::cout << setw(8) << left << "" << "| " << left << setw(40) << vLoginData[0];
        std::cout << "| " << left << setw(15) << vLoginData[1];
        std::cout << "| " << left << setw(15) << vLoginData[2];
        std::cout << "| " << left << setw(15) << vLoginData[3] << endl;
    }

public:
    static void showLoginsDataList() {
        if (!checkAccessRights(clsUser::enPermissions::showLoginRegister))
        {
            return;// this will exit the function and it will not continue
        }
        string title = "Login Register List Screen";
        vector<vector<string>> vLoginsData = clsUser::getLoginsDataList();
        string subtitle = "(" + to_string(vLoginsData.size()) + ") Record(s) ";
        _drawScreenHeader(title, subtitle);

        std::cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";
        std::cout << setw(8) << left << "" << "| " << left << setw(40) << "Date/Time";
        std::cout << "| " << left << setw(15) << "UserName";
        std::cout << "| " << left << setw(15) << "Password";
        std::cout << "| " << left << setw(15) << "Permissions";
        std::cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";

    
       for (vector<string> & loginData : vLoginsData) {
                _printLoginsRecordLine(loginData);
            }
        
        std::cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n";


    }


};

