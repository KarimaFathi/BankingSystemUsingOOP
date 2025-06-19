#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsCalculateCurrencyScreen : clsScreen
{

    static void _printCurrencyInfo(clsCurrency currency, string title) {
        cout << title;
        cout << "\n___________________";
        cout << "\nCountry    : " << currency.getCountryName();
        cout << "\nCode       : " << currency.getCurrencyCode();
        cout << "\nName       : " << currency.getCurrencyName();
        cout << "\nRate(1$)   : " << currency.getCurrencyRate();
        cout << "\n___________________\n";
    }

    static string _printResult(string currency1Code, string currency2Code, float exchangedAmount, float amount) {
        return to_string(amount) + " " + currency1Code + " = " + to_string(exchangedAmount) + " " + currency2Code;
    }

    static clsCurrency _getCurrency(string message) {
        cout << message;
        string currencyCode = clsInputValidate::readString();
        while (!clsCurrency::isCurrencyExistsByCode(currencyCode)) {
            cout << "\nCurrency is not found, choose another one : ";
            currencyCode = clsInputValidate::readString();
        }
        return clsCurrency::findByCurrencyCode(currencyCode);
    }

    static void _printCalculationResults(clsCurrency currency1, clsCurrency currency2, float amount) {
        float exchangedAmount1 = 0, exchangedAmount2 = 0;
        _printCurrencyInfo(currency1, "\nConvert from :");
        exchangedAmount1 = currency1.exchangeCurrency(amount, 1);
        cout << _printResult(currency1.getCurrencyCode(), "USD" , exchangedAmount1, amount);
        if (currency2.getCurrencyCode() == "USD") {
            return;
        }
        else {
            _printCurrencyInfo(currency2, "\nConverting from USD :");
            exchangedAmount2 = currency1.exchangeCurrency(amount, currency2.getCurrencyRate());
            cout << _printResult("USD", currency2.getCurrencyCode(), exchangedAmount2, exchangedAmount1);
        }
    }
public:
	static void showCurrencyCalculatorScreen() {
        char answer = 'n';
        do {
            system("cls");
            string title = "Currency Calculator Screen";
            _drawScreenHeader(title);
          
            clsCurrency currency1 = _getCurrency("\nPlease enter currency1 code : ");
            clsCurrency currency2 = _getCurrency("\nPlease enter currency2 code : ");

            float amount = 0, exchangedAmount = 0;

            cout << "\nEnter amount to exchange : ";
            cin >> amount;

            _printCalculationResults(currency1, currency2, amount);
            cout << "\nDo you want to perform another currency exchange calculation ? (y/n) : ";
            cin >> answer;
        } while (answer == 'y' || answer == 'Y');
	}
};

