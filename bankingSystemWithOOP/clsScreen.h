#pragma once
#include<iostream>
#include<string>
#include "clsUser.h"
#include "global.h"
#include "clsDate.h"
using namespace std;




class clsScreen
{
protected :
	static void _drawScreenHeader(string title, string subTitle = "") {
		cout << "\t\t\t\t\t___________________________________________________\n\n";
		cout << "\t\t\t\t\t\t   " << title << "\n";
		if (subTitle != "") {
			cout << "\t\t\t\t\t\t     " << subTitle << "\n";
		}
		cout << "\t\t\t\t\t___________________________________________________\n\n";

        cout << "\t\t\t\t\t User : " << currentUser.userName << endl;
        cout << "\t\t\t\t\t Date : ";
        clsDate().Print();
        cout << "\n\n";
	}

    static bool checkAccessRights(clsUser::enPermissions Permission)
    {

        if (!currentUser.checkAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }
};

