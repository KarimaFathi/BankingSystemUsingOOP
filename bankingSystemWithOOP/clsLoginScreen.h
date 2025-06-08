#pragma once
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "global.h"


class clsLoginScreen : protected clsScreen 
{
private:
	static void _login() {
		bool failedLogin = false;
		string userName, password;
		do {
			if (failedLogin == true) {
				cout << "\nInvalid UserName/Password\n";
			}
			cout << "\nEnter UserName : ";
			userName = clsInputValidate::readString();
			cout << "\nEnter password : ";
			password = clsInputValidate::readString();
			currentUser = clsUser::find(userName, password);
			failedLogin = currentUser.isEmpty();
		} while (failedLogin);
		clsMainScreen::showMainMenu();
	}
public: 
	static void showLoginScreen() {
		system("cls");
		_drawScreenHeader("Login Screen");
		_login();
	}
};

