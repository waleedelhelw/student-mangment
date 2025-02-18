#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsStudent.h"
using namespace std;

class clsFindStudentScreen:protected clsScreen
{
private:
    static void _printStudentInfo(clsStudent& student)
    {
        cout << "\n--------------------------------------\n";
        cout << " Student Information\n";
        cout << "--------------------------------------\n";
        cout << " Full Name     : " << student. FullName() << endl;
        cout << " ID            : " << student.Id() << endl;
        cout << " Academic Year : " << student.AcademicYear() << endl;
        cout << " GPA           : " << student. GPA() << endl;
        cout << " Email         : " << student.Email() << endl;
        cout << " Phone Number  : " << student.PhoneNumber() << endl;
        cout << " Nationality   : " << student.Nationality() << endl;
        cout << "--------------------------------------\n";
    }
	

public:

	static void ShowFindStudentScreen()
	{
        UpScreen("\t Search Screen ");
        string Id;
        cout << "Enter Student ID to search: ";
        Id = clsInputValidate::ReadString();

        while (!clsStudent::IsStudentExist(Id))
        {
            cout << "There is no student with ID [" << Id << "] try another one: ";
            Id = clsInputValidate::ReadString();
        }

        clsStudent student = clsStudent::Find(Id);
        _printStudentInfo(student);


        string answer;
        cout << "\n\n Do you want to search again: ";
        answer = clsInputValidate::ReadString();
        while (answer == "Y" || answer=="y")
        {
            system("cls");
            ShowFindStudentScreen();
        }

        
    }
};

