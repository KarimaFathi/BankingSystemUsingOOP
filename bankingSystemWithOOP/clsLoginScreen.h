#pragma once
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "global.h"



class clsLoginScreen : protected clsScreen
{
private:

	

	static bool _login() {
		bool failedLogin = false;
		string userName, password;
		short failedTrials = 0;
		do {
			if (failedLogin == true) {
				failedTrials++;
				cout << "\nInvalid UserName/Password\n";
				cout << "You have " << 3 - failedTrials << " trial(s) to login.";
			}
			if (failedTrials == 3) {
				cout << "\n\nYou are locked after 3 failed trials ! \n";
				return false;
			}
			cout << "\n\nEnter UserName : ";
			userName = clsInputValidate::readString();
			cout << "Enter password : ";
			password = clsInputValidate::readString();
			currentUser = clsUser::find(userName, password);
			failedLogin = currentUser.isEmpty();
		} while (failedLogin);
		currentUser.registerLogin();
		clsMainScreen::showMainMenu();
		return true;
	}




public:
	static bool showLoginScreen() {
		system("cls");
		_drawScreenHeader("Login Screen");
		return _login();
	}

};

