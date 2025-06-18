#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:
    static float _readRate() {
        float rate;
        cout << "\nEnter new rate : ";
        rate = clsInputValidate::readFloatNumber();
        return rate;
    }

    static void _printCurrencyInfo(clsCurrency currency) {
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry    : " << currency.getCountryName();
        cout << "\nCode       : " << currency.getCurrencyCode();
        cout << "\nName       : " << currency.getCurrencyName();
        cout << "\nRate(1$)   : " << currency.getCurrencyRate();
        cout << "\n___________________\n";
    }


public:
    static void showUpdateCurrencyScreen() {
     
        string title = "Update Currency Screen";
        _drawScreenHeader(title);
        string currencyCode = "";
        cout << "\nPlease enter the currency code : ";
        currencyCode = clsInputValidate::readString();
        while (!clsCurrency::isCurrencyExistsByCode(currencyCode)) {
            cout << "\nCurrency is not found, choose another one : ";
            currencyCode = clsInputValidate::readString();
        }
        clsCurrency currency = clsCurrency::findByCurrencyCode(currencyCode);
        _printCurrencyInfo(currency);

        char answer = 'n';

        cout << "\nAre you sure you want to update the current rate of this currency (y/n) : ";
        cin >> answer;
        
        if (answer == 'y' || answer == 'Y') {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";

            currency.updateRate(_readRate());
            cout << "\nCurrency rate updated successfully.\n";
            _printCurrencyInfo(currency);
        }
        else {
            cout << "\nNo updates were applied.";
        }
    }
};

