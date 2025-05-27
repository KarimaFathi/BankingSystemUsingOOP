#pragma once
#include<iostream>
#include<string>
using namespace std;




class clsScreen
{
protected :
	static void _drawScreenHeader(string title, string subTitle = "") {
		cout << "\t\t\t\t\t______________________________________\n\n";
		cout << "\t\t\t\t\t\t   " << title << "\n";
		if (subTitle != "") {
			cout << "\t\t\t\t\t\t     " << subTitle << "\n";
		}
		cout << "\t\t\t\t\t______________________________________\n";
	}
};

