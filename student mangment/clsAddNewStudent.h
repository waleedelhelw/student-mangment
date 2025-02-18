#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h";
#include"clsStudent.h"
using namespace std;
class clsAddNewStudent:protected clsScreen
{
    static void _printStudentInfo(clsStudent& student)
    {
        cout << "\n--------------------------------------\n";
        cout << " Student Information\n";
        cout << "--------------------------------------\n";
        cout << " Full Name     : " << student.FullName() << endl;
        cout << " ID            : " << student.Id() << endl;
        cout << " Academic Year : " << student.AcademicYear() << endl;
        cout << " GPA           : " << student.GPA() << endl;
        cout << " Email         : " << student.Email() << endl;
        cout << " Phone Number  : " << student.PhoneNumber() << endl;
        cout << " Nationality   : " << student.Nationality() << endl;
        cout << "--------------------------------------\n";
    }
public:
    static void ShowAddNewStudentScreen()
    {
        UpScreen("\t  Add New Student ");
        string Id;
        cout << "Enter a new Student ID : ";
        Id = clsInputValidate::ReadString();

        while (clsStudent::IsStudentExist(Id))
        {
            cout << "You can,t use this ID [" << Id << "] try another one: ";
            Id = clsInputValidate::ReadString();
        }

        clsStudent NewStudent = clsStudent::AddNewID(Id);
        NewStudent.readStudentInfo(NewStudent);

        clsStudent::enSaveResults saveData= NewStudent.Save();
        switch (saveData)
        {
        case clsStudent::svFaildEmptyObject:
            cout << "\n❌ Error: Data cannot be saved because the input is empty.\n";
            break;

        case clsStudent::svSucceeded:
            cout << "\n✅ Student has been saved successfully!\n";
            _printStudentInfo(NewStudent);
            break;

        case clsStudent::svFailedUsedAccount:
            cout << "\n❌ Error: Data cannot be saved because the ID is already in use!\n";
            break;

        default:
            cout << "\n⚠️ Unknown save status!\n";
            break;
        }

    }
};

