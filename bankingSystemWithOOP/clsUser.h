#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtilities.h"
using namespace std;



class clsUser : public clsPerson
{
	int _permissions;
	enum enMode { emptyMode = 0, updatedMode = 1, addMode = 2 };
	

	enMode _mode;
	bool _isMarkedToDelete = false;
	string _userName, _password;

	static clsUser _convertLineToUserObject(string line, string separator = "#//#") {
		vector<string> vUserData = clsString::splitString(line, separator);
		return clsUser(enMode::updatedMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], ::clsUtilities::_decryptWord(vUserData[5]), stoi(vUserData[6]));
	}


	static clsUser _getEmptyUserObject() {
		return clsUser(enMode::emptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsUser> _loadDataFromFile() {
		vector<clsUser> vUsers;
		fstream MyFile;
		MyFile.open("users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsUser user = _convertLineToUserObject(Line);

				vUsers.push_back(user);
			}

			MyFile.close();

		}
		return vUsers;

	}

	

	static vector<string> _convertLineToDataObject(string line, string separator = "#//#") {
		vector<string> vData = clsString::splitString(line, separator);
		vData[2] = ::clsUtilities::_decryptWord(vData[2]);
		return vData;
	}

	static vector<vector<string>> _loadDataFromLoginFile() {
		vector<vector<string>> vLoginsData;
		fstream MyFile;
		MyFile.open("loginRegister.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;
			vector<string> lineData;


			while (getline(MyFile, Line))
			{

				lineData = _convertLineToDataObject(Line);
				vLoginsData.push_back(lineData);
			}

			MyFile.close();

		}
		return vLoginsData;
	}

	static vector<vector<string>> _loadDataFromTransferLogFile() {
		vector<vector<string>> vTransferLogsData;
		fstream MyFile;
		MyFile.open("transferLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;
			vector<string> lineData;


			while (getline(MyFile, Line))
			{

				lineData = _convertLineToDataObject(Line);
				vTransferLogsData.push_back(lineData);
			}

			MyFile.close();

		}
		return vTransferLogsData;
	}



	string _convertUserObjectToLine(clsUser user, string separator = "#//#") {
		string line = "";
		line += user.firstName + separator;
		line += user.lastName + separator;
		line += user.email + separator;
		line += user.phone + separator;
		line += user.userName + separator;
		line += clsUtilities::_encryptWord(user.password) + separator;
		line += to_string(user.permissions);
		return line;

	}

	void _saveUsersDateToFile(vector<clsUser> vUsers) {
		fstream myFile;
		myFile.open("users.txt", ios::out);
		if (myFile.is_open()) {
			string line;
			for (clsUser & user : vUsers) {
				if (user._isMarkedToDelete == false) {
					line = _convertUserObjectToLine(user);
					myFile << line << endl;
				}
			}
			myFile.close();
		}
	}

	void _update() {
		vector<clsUser> vUsers = _loadDataFromFile();
		for (clsUser& user : vUsers) {
			if (user.userName == userName) {
				user = *this;
				break;
			}
		}
		_saveUsersDateToFile(vUsers);
	}

	void _addDataLineToFile(string dataLine) {
		fstream myFile;
		myFile.open("users.txt", ios::out | ios::app);
		if (myFile.is_open()) {
			myFile << dataLine << endl;
			myFile.close();
		}
	}

	void _addNewUser() {
		return _addDataLineToFile(_convertUserObjectToLine(*this));
	}

	 string _convertLoginDataToLine(string separator = "#//#") {
		string line;
		line = clsDate::getCurrentDateTimeString() + separator;
		line += userName + separator;
		line += ::clsUtilities::_encryptWord(password) + separator;
		line += to_string(permissions);
		return line;
	}


public:
	clsUser(enMode mode, string firstName, string lastName, string email, string phone, string userName, string password, int permissions) : clsPerson(firstName, lastName, email, phone) {
		_permissions = permissions;
		_mode = mode;
		_userName = userName;
		_password = password;
	}


	string getUserName() {
				return _userName;
			}
		
	void setUserName(string userName) {
		_userName = userName;
	}
		
	__declspec(property(get = getUserName, put = setUserName))string userName;
		
	string getPassword() {
		return _password;
	}
		
	void setPassword(string password) {
		_password = password;
	}
		
	__declspec(property(get = getPassword, put = setPassword))string password;
		
	int getPermissions() {
		return _permissions;
	}
		
	void setPermissions(int permissions) {
		_permissions = permissions;
	}
		
	__declspec(property(get = getPermissions, put = setPermissions))int permissions;
		

	void registerLogin() {
		fstream myFile;
		string record = _convertLoginDataToLine();
		myFile.open("loginRegister.txt", ios::out | ios::app);
		if (myFile.is_open()) {
			myFile << record << endl;
			myFile.close();
		}
	}
	static clsUser find(string userName) {
		fstream myFile;
		myFile.open("users.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsUser user = _convertLineToUserObject(line);
				if (user.userName == userName) {
					myFile.close();
					return user;
				}
			}
			myFile.close();
		}
		return _getEmptyUserObject();
		
	}

	static clsUser find(string userName, string password) {
		fstream myFile;
		myFile.open("users.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsUser user = _convertLineToUserObject(line);
				if (user.userName == userName && user.password == password) {
					myFile.close();
					return user;
				}
			}
			myFile.close();
		}
		return _getEmptyUserObject();

	}
		bool isEmpty() {
		return (_mode == enMode::emptyMode);
	}

	static bool isUserExists(string userName) {
		clsUser user = clsUser::find(userName);
		return (!user.isEmpty());
	}

	enum enSaveResult { failedEmptyObject = 0, successeded = 1, failedUserExists = 2 };
	enum enPermissions { allPermissions = -1, showAllClients = 1, addNewClient = 2, deleteClients = 4, updateClients = 8, findClients = 16, manageTransactions = 32, AdministerUsers = 64, showLoginRegister = 128};


	enSaveResult save() {
		switch (_mode) {
		case enMode::emptyMode:
			return enSaveResult::failedEmptyObject;
		case enMode::updatedMode:
			_update();
			return enSaveResult::successeded;
		case enMode::addMode:
			if (isUserExists(userName) == true) {
				return enSaveResult::failedUserExists;
			}
			else {
				_addNewUser();
				return enSaveResult::successeded;
			}
		}
	}

	static clsUser addNewUserObject(string userName) {
		return clsUser(enMode::addMode, "", "", "", "", userName, "", 0);
	}

	bool deleteUser() {
		vector<clsUser> vUsers = _loadDataFromFile();
		for (clsUser& user : vUsers) {
			if (user.userName == userName) {
				user._isMarkedToDelete = true;
				break;
			}
		}
		_saveUsersDateToFile(vUsers);
		*this = _getEmptyUserObject();
		return true;
	}

	
	static vector<clsUser>  getUsersList() {
		return _loadDataFromFile();
	}

	static vector<vector<string>>  getLoginsDataList() {
		return _loadDataFromLoginFile();
	}


	static vector<vector<string>>  getTransferLogDataList() {
		return _loadDataFromTransferLogFile();
	}

	bool checkAccessPermission(enPermissions Permission)
	{
		if (this->permissions == enPermissions::allPermissions)
			return true;

		if ((Permission & this->permissions) == Permission)
			return true;
		else
			return false;

	}
	

    

};


