#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


class clsUpdateUserScreen : protected clsScreen
{
private:
    static void _readUserInfo(clsUser& user) {
        cout << "\nEnter FirstName: ";
        user.firstName = clsInputValidate::readString();

        cout << "\nEnter LastName: ";
        user.lastName = clsInputValidate::readString();

        cout << "\nEnter Email: ";
        user.email = clsInputValidate::readString();

        cout << "\nEnter Phone: ";
        user.phone = clsInputValidate::readString();

        cout << "\nEnter Password: ";
        user.password = clsInputValidate::readString();

        cout << "\nEnter Permissions: ";
        user.permissions = readPermissionsToSet();
    }

    static int readPermissionsToSet() {
        char answer = 'n';
        int userPermission = 0;
        cout << "Do you want to give full access ? ";
        cin >> answer;
        if (tolower(answer) == 'y') {
            userPermission = clsUser::enPermissions::allPermissions;

        }
        else {
            cout << "Do you want to give access to : \n";
            cout << "Show user list ? (y/n)";
            cin >> answer;
            if (tolower(answer) == 'y') {
                userPermission += clsUser::enPermissions::showAllClients;
            }
            cout << "Add New Client? (y/n)";
            cin >> answer;
            if (tolower(answer) == 'y') {
                userPermission += clsUser::enPermissions::addNewClient;
            }
            cout << "Delete Client? (y/n)";
            cin >> answer;
            if (tolower(answer) == 'y') {
                userPermission += clsUser::enPermissions::deleteClients;
            }
            cout << "Update Client? (y/n)";
            cin >> answer;
            if (tolower(answer) == 'y') {
                userPermission += clsUser::enPermissions::updateClients;
            }
            cout << "Find Client? (y/n)";
            cin >> answer;
            if (tolower(answer) == 'y') {
                userPermission += clsUser::enPermissions::findClients;
            }
            cout << "Manage transactions? (y/n)";
            cin >> answer;
            if (tolower(answer) == 'y') {
                userPermission += clsUser::enPermissions::manageTransactions;
            }
            cout << "Manage Users? (y/n)";
            cin >> answer;
            if (tolower(answer) == 'y') {
                userPermission += clsUser::enPermissions::AdministerUsers;
            }
        }
        return userPermission;
    }

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
    static void showUpdateUserScreen() {
        string title = "Update User Screen";
        _drawScreenHeader(title);
        string userName = "";
        cout << "\nPlease enter the userName : ";
        userName = clsInputValidate::readString();
        while (!clsUser::isUserExists(userName)) {
            cout << "\nUserName is not found, choose another one : ";
            userName = clsInputValidate::readString();
        }
        clsUser user = clsUser::find(userName);
        _printUserInfo(user);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";

            _readUserInfo(user);

            clsUser::enSaveResult saveResult = user.save();
            switch (saveResult) {
            case clsUser::enSaveResult::failedEmptyObject:
                cout << "\nError user was not saved because it's Empty";
                break;
            case clsUser::enSaveResult::successeded:
                cout << "\nUser Updated Successfully :-)\n";
                _printUserInfo(user);;
                break;
            }
        }
        else {
            cout << "\nNo updates were applied.";
        }
    }
};

