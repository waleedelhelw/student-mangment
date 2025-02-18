#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h";
#include"clsStudent.h"

using namespace std;

class clsDeleteStudentScreen :protected clsScreen
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
    static void ShowDeleteStudentScreen()
    {
        UpScreen("\t  Delete S Screen");
        string Id;
        cout << "Enter student ID to Delete from SYS: ";
        Id = clsInputValidate::ReadString();
        while (!clsStudent::IsStudentExist(Id))
        {
            cout << "Un exist student with ID [" << Id << "], try another one: ";
            Id = clsInputValidate::ReadString();

        }

        clsStudent student = clsStudent::Find(Id);
        _printStudentInfo(student);

        string answer;
        cout << "\nAre you sure you want to delete student with ID [" << student.Id() << "] ?: ";
        answer = clsInputValidate::ReadString();

        if (answer == "Y" || answer == "y")
        {
            student.Delete();
            cout << "Student has deleted succesfully :)\n";
            _printStudentInfo(student);
        }
        else
        {
            cout << "Erorr can,t delete client :(\n";
        }
    }
};

