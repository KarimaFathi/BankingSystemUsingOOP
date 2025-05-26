#pragma once
#include <iostream>
#include "clsDate.h";
using namespace std;

class clsInputValidate
{
public:
	static bool isNumberBetween(int number, int from, int to) {
		return (number >= from && number <= to);
	}
	static bool isNumberBetween(short number, short from, short to) {
		return (number >= from && number <= to);
	}
	static bool isNumberBetween(float number, float from, float to) {
		return (number >= from && number <= to);
	}
	static bool isNumberBetween(double number, double from, double to) {
		return (number >= from && number <= to);
	}
	static bool isDateBetween(clsDate date, clsDate startDate, clsDate endDate) {
		return (date.areDatesEqual(startDate) || date.areDatesEqual(endDate) || (date.isDate1AfterDate2(startDate) && date.IsDate1BeforeDate2(endDate)));
	}
	static int readIntNumber(string errorMessage = "Invalid Number, Enter again\n") {
		int num;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
			cin >> num;
		}
		return num;
	}
	static int readIntNumberBetween(int from, int to, string message = "Number is not within range, Enter again:\n") {
		int num = readIntNumber();
		while (!isNumberBetween(num, from, to)) {
			cout << message;
			cin >> num;
		}
		return num;
	}
	static double readDblNumber(string errorMessage = "Invalid Number, Enter again\n") {
		double num;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage;
			cin >> num;
		}
		return num;
	}
	static string readString() {
		string s1;
		getline(cin >> ws, s1);
		return s1;
	}
	static float readFloatNumber(string errorMessage = "Invalid Number, Enter again\n") {
		float num;
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> num;
		}
		return num;
	}
	static int readDblNumberBetween(double from, double to, string message = "Number is not within range, Enter again:\n") {
		double num = readDblNumber();
		while (!isNumberBetween(num, from, to)) {
			cout << message;
			cin >> num;
		}
		return num;
	}
	static bool isDateValid(clsDate Date)
	{
		return	clsDate::isDateValid(Date);
	}

};
