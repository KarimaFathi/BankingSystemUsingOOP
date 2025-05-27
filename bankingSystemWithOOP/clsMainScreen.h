#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
using namespace std;


class clsMainScreen : protected clsScreen 
{
	enum _enMainMenu { showClients = 1, addClient = 2, deleteClient = 3, updateClient = 4, findClient = 5, transactions = 6, manageUsers = 7, exitMenu = 8 };

	static short _readMenuOption() {
		cout << setw(37) << left << "" << "Please select an option from the menu above(1 - 8) : ";
		short number = clsInputValidate::readIntNumberBetween(1, 8, "Option is out of range, please select a number between 1 to 8 : ");
		return number;
	}


	static void _goBackToMainMenu() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";
		system("pause>0");
		system("cls");
		showMainMenu();
	}

	static void _showAllClientsScreen() {
		clsClientListScreen::showClientsList();
	}
	static void _showAddNewClientsScreen(){
		clsAddNewClientScreen::showAddNewClientScreen();
	}
	static void _showDeleteClientScreen() { }
	static void _showUpdateClientScreen() { }
	static void _ShowFindClientScreen() { }
	static void _showTransactionsMenu() { }
	static void _showManageUsersMenu() {  }
	static void _showEndScreen() { }


	static void _performMainMenuOptions(_enMainMenu mainMenuOption) {
		switch (mainMenuOption) {
		case _enMainMenu::showClients:
			system("cls");
			_showAllClientsScreen();
			_goBackToMainMenu();
			break;
		case _enMainMenu::addClient:
			system("cls");
			_showAddNewClientsScreen();
			_goBackToMainMenu();
			break;
		case _enMainMenu::deleteClient:
			system("cls");
			_showDeleteClientScreen();
			_goBackToMainMenu();
			break;
		case _enMainMenu::updateClient:
			system("cls");
			_showUpdateClientScreen();
			_goBackToMainMenu();
			break;
		case _enMainMenu::findClient:
			system("cls");
			_ShowFindClientScreen();
			_goBackToMainMenu();
			break;
		case _enMainMenu::transactions:
			system("cls");
			_showTransactionsMenu();
			_goBackToMainMenu();
			break;
		case _enMainMenu::manageUsers:
			system("cls");
			_showManageUsersMenu();
			_goBackToMainMenu();
			break;
		case _enMainMenu::exitMenu:
			system("cls");
			_showEndScreen();
			break;
		}
	
	}

public:
	static void showMainMenu() {
		_drawScreenHeader("Main Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
	   _performMainMenuOptions((_enMainMenu)_readMenuOption());
	}

	
};

