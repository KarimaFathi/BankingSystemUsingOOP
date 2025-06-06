#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


class clsDeleteUserScreen : protected clsScreen
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
    static void showDeleteUserScreen() {
        string title = "Delete User Screen";
        _drawScreenHeader(title);
        string userName = "";
        cout << "\nPlease enter the userName : ";
        userName = clsInputValidate::readString();
        while (!clsUser::isUserExists(userName)) {
            cout << "\nUserName is not found, choose another one : ";
            userName = clsInputValidate::readString();
        }
        clsUser User = clsUser::find(userName);
        _printUserInfo(User);

        cout << "Are you sure you want to delete this user (y/n) : ";
        char answer = 'n';
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            if (User.deleteUser() == true) {
                cout << "\nUser deleted successfully.\n";
                _printUserInfo(User);
            }
            else {
                cout << "\nError user was not deleted, \n";
            }
        }
    }
};

