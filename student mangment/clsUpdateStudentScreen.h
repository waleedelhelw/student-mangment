#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h";
#include"clsStudent.h"
using namespace std;
class clsUpdateStudentScreen:clsScreen
{
private:
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

    static void ShowUpdateStudentScreen()
    {
        UpScreen("Update Student Information");

        string StudentId;
        cout << "Please enter Student ID : ";
        StudentId = clsInputValidate::ReadString();

        
        while (!clsStudent::IsStudentExist(StudentId))
        {
            cout << "Can't find a student with ID [" << StudentId << "]\n";
            cout << "Try another one : ";
            StudentId = clsInputValidate::ReadString();
        }

        clsStudent student = clsStudent::Find(StudentId);
        _printStudentInfo(student);

        cout << "\n-------------\n";
        cout << " Update Student Data\n";
        cout << "-------------\n";

        clsStudent::readStudentInfo(student); 


        clsStudent::enSaveResults saveData = student.Save();

        switch (saveData)
        {
        case clsStudent::svFaildEmptyObject:
            cout << "❌ Error: Cannot save data because input is empty!\n";
            break;

        case clsStudent::svSucceeded:
            cout << "✅ Student data has been updated successfully!\n";
            _printStudentInfo(student);
            break;

        default:
            cout << "⚠️ Unknown error occurred!\n";
            break;
        }
    }

};
