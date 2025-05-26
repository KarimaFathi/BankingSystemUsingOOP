#pragma once
#include<iostream>
using namespace std;


class clsPerson
{

	string _firstName, _lastName, _email, _phone;

public:
	clsPerson(string firstName, string lastName, string email, string phone) {
		_firstName = firstName;
		_lastName = lastName;
		_email = email;
		_phone = phone;
	}

	string getFirstName() {
		return _firstName;
	}

	void setFirstName(string firstName) {
		_firstName = firstName;
	}

	__declspec(property(get = getFirstName, put = setFirstName))string firstName;

	

	string getLastName() {
		return _lastName;
	}

	void setLastName(string LastName) {
		_lastName = LastName;
	}

	__declspec(property(get = getLastName, put = setLastName))string lastName;

	string getPhone() {
		return _phone;
	}

	void setPhone(string phone) {
		_phone = phone;
	}

	__declspec(property(get = getPhone, put = setPhone))string phone;

	string getEmail() {
		return _email;
	}

	void setEmail(string email) {
		_email = email;
	}

	__declspec(property(get = getEmail, put = setEmail))string email;

	string fullName() {
		return firstName + " " + lastName;
	}
};

