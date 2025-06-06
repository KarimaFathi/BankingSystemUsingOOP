#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include<vector>



class clsAddNewUserScreen : protected clsScreen
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
			cout << "Show clients list ? (y/n)";
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


	static void _printUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.firstName;
		cout << "\nLastName    : " << User.lastName;
		cout << "\nFull Name   : " << User.fullName();
		cout << "\nEmail       : " << User.email;
		cout << "\nPhone       : " << User.phone;
		cout << "\nUser Name   : " << User.userName;
		cout << "\nPassword    : " << User.password;
		cout << "\nPermissions : " << User.permissions;
		cout << "\n___________________\n";

	}
public:
    static void showAddNewUserScreen() {
        string title = "Add New User Screen";
        _drawScreenHeader(title);
        string userName = "";
        cout << "\nPlease enter the userName : ";
        userName = clsInputValidate::readString();
        while (clsUser::isUserExists(userName)) {
            cout << "\nUserName already exists, choose another one : ";
            userName = clsInputValidate::readString();
        }
        clsUser user = clsUser::addNewUserObject(userName);
        _readUserInfo(user);
        clsUser::enSaveResult saveResult = user.save();
        switch (saveResult) {
        case clsUser::enSaveResult::failedUserExists:
            cout << "\nError user was not added  because he does already exists";
            break;
        case clsUser::enSaveResult::successeded:
            cout << "\nUser added Successfully :-)\n";
            _printUser(user);
            break;
        }
    }
};
