#pragma once
#include<iostream>
#include<string>
#include "clsUser.h"
#include "global.h"
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

