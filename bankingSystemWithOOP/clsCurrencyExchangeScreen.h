#pragma once
#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
using namespace std;



class clsCurrencyExchangeScreen : protected clsScreen
{
private:
	enum _enCurrencyMenu { listCurrencies = 1, findCurrency = 2, updateRate = 3, calculateCurrency = 4, mainMenu = 5};

	static short _readMenuOption() {
		cout << setw(37) << left << "" << "Please select an option from the menu above(1 - 5) : ";
		short number = clsInputValidate::readIntNumberBetween(1, 8, "Option is out of range, please select a number between 1 to 5 : ");
		return number;
	}

	static void _goBackToCurrencyExchangeMenu() {
		cout << "\n\nPress any key to go back to Currency Exchange Menu...";
		system("pause>0");
		system("cls");
		showCurrencyExchangeMenu();
	}
	static void  _showFindCurrencyScreen() {
		clsFindCurrencyScreen::showFindCurrency();
	}
	static void _showListCurrenciesScreen() {
		clsListCurrenciesScreen::showCurrenciesList();
	}
	static void _showUpdateRateScreen() {
		clsUpdateCurrencyRateScreen::showUpdateCurrencyScreen();
	}

	static void _showCalculateCurrencyScreen() {
	
	}

	static void _showMainMenu() {}

	static void _performTransactionsOptions(_enCurrencyMenu transactionOption) {
		switch (transactionOption) {
		case _enCurrencyMenu::listCurrencies:
			system("cls");
			_showListCurrenciesScreen();
			_goBackToCurrencyExchangeMenu();
			break;
		case _enCurrencyMenu::findCurrency:
			system("cls");
			_showFindCurrencyScreen();
			_goBackToCurrencyExchangeMenu();
			break;
		case _enCurrencyMenu::updateRate:
			system("cls");
			_showUpdateRateScreen();
			_goBackToCurrencyExchangeMenu();
			break;
		case _enCurrencyMenu::calculateCurrency:
			system("cls");
			_showCalculateCurrencyScreen();
			_goBackToCurrencyExchangeMenu();
			break;
		case _enCurrencyMenu::mainMenu:
			_showMainMenu();
		}
	}

public:

	static void showCurrencyExchangeMenu() {

		_drawScreenHeader("Currency Exchange Main Screen");
		cout << setw(37) << left << "" << "=========================================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu \n";
		cout << setw(37) << left << "" << "=========================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "=========================================================\n";
		_performTransactionsOptions((_enCurrencyMenu)_readMenuOption());
	}

};

