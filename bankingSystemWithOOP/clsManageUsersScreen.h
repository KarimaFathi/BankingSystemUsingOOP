#pragma once
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUserScreen.h"


class clsManageUsersScreen : protected clsScreen
{
private:
	enum _enManageUsersMenu { showUsers = 1, addUser = 2, deleteUser = 3, updateUser = 4, findUser = 5, exitManageUsers = 6 };

	static short _readMenuOption() {
		cout << setw(37) << left << "" << "Please select an option from the menu above(1 - 6) : ";
		short number = clsInputValidate::readIntNumberBetween(1, 6, "Option is out of range, please select a number between 1 to 6 : ");
		return number;
	}


	static void  _ShowAllUsersScreen() {
		clsListUserScreen::showUsersList();
	}
	static void _goBackToManageUsersMenu() {}
	static void _ShowAddNewUsersScreen() {}
	static void _ShowDeleteNewUsersScreen() {}
	static void _ShowUpdateUsersScreen() {}
	static void _ShowFindUsersScreen() {}
	static void _showMainMenu() {}

	static void _performManageUsersMenuOptions(_enManageUsersMenu choice) {
		switch (choice) {
		case _enManageUsersMenu::showUsers:
			system("cls");
			_ShowAllUsersScreen();
			_goBackToManageUsersMenu();
			break;
		case _enManageUsersMenu::addUser:
			system("cls");
			_ShowAddNewUsersScreen();
			_goBackToManageUsersMenu();
			break;
		case _enManageUsersMenu::deleteUser:
			system("cls");
			_ShowDeleteNewUsersScreen();
			_goBackToManageUsersMenu();
			break;
		case _enManageUsersMenu::updateUser:
			system("cls");
			_ShowUpdateUsersScreen();
			_goBackToManageUsersMenu();
			break;
		case _enManageUsersMenu::findUser:
			system("cls");
			_ShowFindUsersScreen();
			_goBackToManageUsersMenu();
			break;
		case _enManageUsersMenu::exitManageUsers:
			//_showMainMenu();
			break;
		}
	}

public:

	static void showManageUsersMenu() {

		_drawScreenHeader("Transactions Screen");
		cout << setw(37) << left << "" << "=========================================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Menu Screen\n";
		cout << setw(37) << left << "" << "=========================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "=========================================================\n";
		_performManageUsersMenuOptions((_enManageUsersMenu)_readMenuOption());
	}

};

