#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


class clsFindCurrencyScreen : protected clsScreen
{
private:
    static void _printCurrencyInfo(clsCurrency currency) {
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry    : " << currency.getCountryName();
        cout << "\nCode       : " << currency.getCurrencyCode();
        cout << "\nName       : " << currency.getCurrencyName();
        cout << "\nRate(1$)   : " << currency.getCurrencyRate();
        cout << "\n___________________\n";
    }

    static short  readChoice() {
        short choice;
        choice = clsInputValidate::readIntNumber();
        while (choice != 1 && choice != 2) {
            cout << "\nInvalid input. Please enter 1 or 2: ";
            choice = clsInputValidate::readIntNumber();
        }
        return choice;
    }

    static void showResults(clsCurrency currency) {
        if (!currency.isEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _printCurrencyInfo(currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:
    static void showFindCurrency() {
        short choice;
        string currencyCode, currencyCountry;
        _drawScreenHeader("\tFind Currency Screen");
        cout << "\nFind By : [1] Code or [2] Country ? ";
        choice = readChoice();
        if (choice == 1) {
            cout << "\nPlease enter currency code : ";
            cin >> currencyCode;
            clsCurrency currency = clsCurrency::findByCurrencyCode(currencyCode);
            showResults(currency);
        }
        else {
            cout << "\nPlease enter the country : ";
            cin >> currencyCountry;
            clsCurrency currency = clsCurrency::findByCountryName(currencyCountry);
            showResults(currency);
        }
    }
};

