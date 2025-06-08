#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


class clsFindUserScreen : protected clsScreen
{
private:
    static void _printUserInfo(clsUser user) {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nUserName        : " << user.userName;
        cout << "\nFirstName       : " << user.firstName;
        cout << "\nLastName        : " << user.lastName;
        cout << "\nFull Name       : " << user.fullName();
        cout << "\nEmail           : " << user.email;
        cout << "\nPhone           : " << user.phone;
        cout << "\nPassword        : " << user.password;
        cout << "\nPermissions     : " << user.permissions;
        cout << "\n___________________\n";
    }

public:
    static void showFindUser() {
        _drawScreenHeader("\tFind User Screen");
        string userName = "";
        cout << "\nPlease enter the userName: ";
        userName = clsInputValidate::readString();
        while (!clsUser::isUserExists(userName)) {
            cout << "\nuserName is not found, choose another one : ";
            userName = clsInputValidate::readString();
        }
        clsUser user = clsUser::find(userName);
        if (!user.isEmpty())
        {
            cout << "\n UserFound :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _printUserInfo(user);
    }
};

