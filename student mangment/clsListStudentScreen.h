#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h"
#include"clsStudent.h"
using namespace std;
class clsListStudentScreen:clsScreen
{
private:

    enum ListOptions
    {
        eAllStudentList = 1,eFirstYear,eSecondYear,
        eThirdYear,eFourthYear
    };

    void static printStudentCard(clsStudent& student)
    {
        cout << "\t| " << left << setw(25) << student.FullName();
        cout << "| " << left << setw(12) << student.Id();
        cout << "| " << left << setw(15) << student.AcademicYear();
        cout << "| " << left << setw(8) << student.GPA();
        cout << "| " << left << setw(25) << student.Email();
        cout << "| " << left << setw(15) << student.PhoneNumber();
        cout << "| " << left << setw(15) << student.Nationality();
    }

    

public:
	static void ShowStudentListScreen()
	{
        vector<clsStudent>vStudent;
        vStudent = clsStudent::ListOfStudent();

        UpScreen("\t  List student ");
        cout << "\n\t_____________________________________________________________________________________________________________________________________\n\n";

        cout << "\t| " << left << setw(25) << "Full Name"
            << "| " << left << setw(12) << "ID"
            << "| " << left << setw(15) << "Academic Year"
            << "| " << left << setw(8) << "GPA"
            << "| " << left << setw(25) << "Email"
            << "| " << left << setw(15) << "Phone"
            << "| " << left << setw(15) << "Country" << " |";

        cout << "\n\t_____________________________________________________________________________________________________________________________________\n\n";


        if (vStudent.empty())
        {
            cout << "\t\t\t\tNo students Available In the System!";
        }

        else

            for (clsStudent Student : vStudent)
            {

                printStudentCard(Student);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
	
};

