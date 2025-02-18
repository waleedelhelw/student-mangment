#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h";
#include"clsStudent.h"
using namespace std;

class clsRefreshStudentDataScreen:clsScreen
{
public:
	static void RefreshStudentDataScreen()
	{
		UpScreen("\t  Refresh Screen");

		cout << "\t\t===============================================================\n";
		cout << "\t\t  WARING , this option will reset all students materisl,s data\n";
		cout << "\t\t===============================================================\n\n";


		string answer;
		cout << "\nDo you want to update data? : ";
		answer = clsInputValidate::ReadString();
		if (answer == "Y" || answer == "y")
		{
			clsStudent::RefreshData();
		}

	}
};

