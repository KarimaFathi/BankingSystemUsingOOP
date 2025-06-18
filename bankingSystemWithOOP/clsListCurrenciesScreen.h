#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
using namespace std;



class clsListCurrenciesScreen : protected clsScreen
{
private:
    static void _printCurrencyRecordLine(clsCurrency currency) {
        cout << setw(8) << left << "" << "| " << left << setw(30) << currency.getCountryName();
        cout << "| " << left << setw(8) << currency.getCurrencyCode();
        cout << "| " << left << setw(45) << currency.getCurrencyName();
        cout << "| " << left << setw(10) << currency.getCurrencyRate() << endl;
    }

public:
    static void showCurrenciesList() {
        string title = "Currencies List Screen";
        vector<clsCurrency> vCurrencies = clsCurrency::getCurrenciesList();
        string subtitle = "(" + to_string(vCurrencies.size()) + ") currencies ";
        _drawScreenHeader(title, subtitle);

        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n\n";

        if (vCurrencies.size() == 0) {
            cout << "\t\t\t\tNo available currency in the system !";
        }
        else {
            for (clsCurrency& currency : vCurrencies) {
                _printCurrencyRecordLine(currency);
            }
        }
        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n";


    }
};

