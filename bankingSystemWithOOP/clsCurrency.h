#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "clsString.h"
using namespace std;





class clsCurrency
{
private:
     enum enMode {emptyMode = 0, updateMode = 1};
     string _currencyName, _currencyCode, _country;
     float _rate;
     enMode _mode;

     static clsCurrency _convertLineToCurrencyObject(string line, string separator = "#//#") {
         vector<string> vCurrencyData = clsString::splitString(line, separator);
         return clsCurrency(enMode::updateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
     }

     static vector<clsCurrency> _loadDataFromFile() {
         vector<clsCurrency> vUsers;
         fstream MyFile;
         MyFile.open("currencies.txt", ios::in);//read Mode

         if (MyFile.is_open())
         {

             string Line;


             while (getline(MyFile, Line))
             {

                 clsCurrency currency = _convertLineToCurrencyObject(Line);

                 vUsers.push_back(currency);
             }

        MyFile.close();

    }
           return vUsers;

     }

        string _convertCurrencyObjectToLine(clsCurrency currency, string separator = "#//#") {
            string line = "";
            line += currency._country + separator;
            line += currency._currencyCode + separator;
            line += currency._currencyName + separator;
            line += to_string(currency._rate);
            return line;

        }
    


     void  _saveCurrencyDataToFile(vector<clsCurrency> vCurrencies) {
         fstream myFile;
         myFile.open("currencies.txt", ios::out);
         if (myFile.is_open()) {
             string line;
             for (clsCurrency& currency : vCurrencies) {
                     line = _convertCurrencyObjectToLine(currency);
                     myFile << line << endl;
                 }
             
             myFile.close();
         }
     }

     void _update() {
         vector<clsCurrency> vCurrencies = _loadDataFromFile();
         for (clsCurrency& currency : vCurrencies) {
             if (currency.getCurrencyCode() == getCurrencyCode()) {
                 currency = *this;
                 break;
             }
         }
         _saveCurrencyDataToFile(vCurrencies);
     }



     static clsCurrency _getEmptyCurrencyObject() {
         return clsCurrency(enMode::emptyMode, "", "", "", 0);
     }

public:
    clsCurrency(enMode mode, string country, string currencyCode, string currencyName, float rate) {
        _mode = mode;
        _country = country;
        _currencyName = currencyName;
        _currencyCode = currencyCode;
        _rate = rate;
    }

    bool isEmpty() {
        return (_mode == enMode::emptyMode);
    }

    //only read mode
    string getCountryName() {
        return _country;
    }

    string getCurrencyName() {
        return _currencyName;
    }

    string getCurrencyCode() {
        return _currencyCode;
    }

    void updateRate(float newRate) {
        _rate = newRate;
        _update();
    }

    static clsCurrency findByCountryName(string country) {
        fstream myFile;
        myFile.open("currencies.txt", ios::in);
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                clsCurrency currency = _convertLineToCurrencyObject(line);
                if (clsString::upperAllString(currency.getCountryName()) == clsString::upperAllString(country)) {
                    myFile.close();
                    return currency;
                }
            }
            myFile.close();
        }
        return _getEmptyCurrencyObject();

    }

    static clsCurrency findByCurrencyCode(string currencyCode) {
        fstream myFile;
        myFile.open("currencies.txt", ios::in);
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line)) {
                clsCurrency currency = _convertLineToCurrencyObject(line);
                if (currency.getCurrencyCode() == clsString::upperAllString(currencyCode)) {
                    myFile.close();
                    return currency;
                }
            }
            myFile.close();
        }
        return _getEmptyCurrencyObject();
    }

    static bool isCurrencyExists(string currencyCode) {
        clsCurrency currency = findByCurrencyCode(currencyCode);
        return (!currency.isEmpty());
    }

    static vector<clsCurrency> getCurrenciesList() {
        return _loadDataFromFile();
    }
};

