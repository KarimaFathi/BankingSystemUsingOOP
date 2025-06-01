#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "clsPerson.h"
#include "clsString.h"
using namespace std;


class clsBankClient : public clsPerson
{
	string _accountNumber, _pinCode;
	float _accountBalance;
	enum enMode { emptyMode = 0, updatedMode = 1, addMode = 2 };
	enMode _mode;
	bool _isMarkedToDelete = false;


	static clsBankClient _convertLineToClientObject(string line, string separator = "#//#") {
		vector<string> vClientData = clsString::splitString(line, separator);
		return clsBankClient(enMode::updatedMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static clsBankClient _getEmptyClientObject() {
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _loadDataFromFile() {
		vector<clsBankClient> vBankClients;
		fstream MyFile;
		MyFile.open("clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _convertLineToClientObject(Line);

				vBankClients.push_back(Client);
			}

			MyFile.close();

		}
		return vBankClients;

	}

	string _convertClientObjectToLine(clsBankClient client, string separator = "#//#") {
		string line = "";
		line += client.firstName + separator;
		line += client.lastName + separator;
		line += client.email + separator;
		line += client.phone + separator;
		line += client.accountNumber + separator;
		line += client.pinCode + separator;
		line += to_string(client.accountBalance);
		return line;

	}


	void _saveClientsDateToFile(vector<clsBankClient> vBankClients) {
		fstream myFile;
		myFile.open("clients.txt", ios::out);
		if (myFile.is_open()) {
			string line;
			for (clsBankClient& client : vBankClients) {
				if (client._isMarkedToDelete == false) {
					line = _convertClientObjectToLine(client);
					myFile << line << endl;
				}
			}
		}
	}

	void _update() {
		vector<clsBankClient> vBankClients = _loadDataFromFile();
		for (clsBankClient& client : vBankClients) {
			if (client.accountNumber == accountNumber) {
				client = *this;
				break;
			}
		}
		_saveClientsDateToFile(vBankClients);
	}


	void _addDataLineToFile(string dataLine) {
		fstream myFile;
		myFile.open("clients.txt", ios::out | ios::app);
		if (myFile.is_open()) {
			myFile << dataLine << endl;
			myFile.close();
		}
		
	}


	void _addNewClient() {
		return _addDataLineToFile(_convertClientObjectToLine(*this));
	}



public:
	clsBankClient(enMode mode,string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, float accountBalance) : clsPerson(firstName, lastName, email, phone) {
		_accountBalance = accountBalance;
		_accountNumber = accountNumber;
		_pinCode = pinCode;
		_mode = mode;
	}

	string getAccountNumber() {
		return _accountNumber;
	}

	void setAccountNumber(string accountNumber) {
		_accountNumber = accountNumber;
	}

	__declspec(property(get = getAccountNumber, put = setAccountNumber))string accountNumber;

	float getAccountBalance() {
		return _accountBalance;
	}

	void setAccountBalance(float accountBalance) {
		_accountBalance = accountBalance;
	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance))float accountBalance;

	string getPinCode() {
		return _pinCode;
	}

	void setPinCode(string pinCode) {
		_pinCode = pinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode))string pinCode;



	static clsBankClient find(string accountNumber) {
		fstream myFile;
		myFile.open("clients.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsBankClient client = _convertLineToClientObject(line);
				if (client.accountNumber == accountNumber) {
					myFile.close();
					return client;
				}
			}
			myFile.close();
		}
		return _getEmptyClientObject();

	}

	bool isEmpty() {
		return (_mode == enMode::emptyMode);
	}


	static bool isClientExists(string accountNumber) {
		clsBankClient client = clsBankClient::find(accountNumber);
		return (!client.isEmpty());
	}

	//void print() {
	//	cout << "\nClient Card:";
	//	cout << "\n___________________";
	//	cout << "\nFirstName   : " << firstName;
	//	cout << "\nLastName    : " << lastName;
	//	cout << "\nFull Name   : " << fullName();
	//	cout << "\nEmail       : " << email;
	//	cout << "\nPhone       : " << phone;
	//	cout << "\nAcc. Number : " << accountNumber;
	//	cout << "\nPassword    : " << pinCode;
	//	cout << "\nBalance     : " << accountBalance;
	//	cout << "\n___________________\n";

	//}

	enum enSaveResult {failedEmptyObject = 0, successeded = 1, failedAccountNumberExists = 2};

	enSaveResult save() {
		switch (_mode) {
		case enMode::emptyMode :
			return enSaveResult::failedEmptyObject;
		case enMode::updatedMode :
			_update();
			return enSaveResult::successeded;
		case enMode::addMode:
			if (isClientExists(accountNumber) == true) {
				return enSaveResult::failedAccountNumberExists;
			}
			else {
				_addNewClient();
				return enSaveResult::successeded;
			}
		}
	}

	static clsBankClient addNewClientObject(string accountNumber) {
		return clsBankClient(enMode::addMode, "", "", "", "", accountNumber,"", 0);
	}

	bool deleteClient() {
		vector<clsBankClient> vBankClients = _loadDataFromFile();
		for (clsBankClient& client : vBankClients) {
			if (client.accountNumber == accountNumber) {
				client._isMarkedToDelete = true;
				break;
			}
		}
		_saveClientsDateToFile(vBankClients);
		*this = _getEmptyClientObject();
		return true;
	}
	
	static vector<clsBankClient>  getClientsList(){
		return _loadDataFromFile();
	}


	static double getTotalBalances() {
		vector<clsBankClient> vBankClients = _loadDataFromFile();
		double totalBalances = 0;
		for (clsBankClient& client : vBankClients) {
			totalBalances += client.accountBalance;
		}
		return totalBalances;
	}

		void deposit(double amount) {
			accountBalance += amount;
			save();
		}
};





// Find Client Logic:
// Open the text file and read it line by line. For each line, convert it into a clsBankClient object with the corresponding member values.
// Then, compare the account number of that object with the one provided as an argument.
// If a match is found, close the file and return the client object.
// If not, continue reading the next line and repeat the process.
// If the entire file is read without finding a match, return a new client object with empty/default values.


