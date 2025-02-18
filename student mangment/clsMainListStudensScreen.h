#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsString.h"
#include"clsStudent.h"
#include"clsListStudentScreen.h"
#include"clsFirstAcadimicLIstScreen.h"
#include"clsSecondACDStudentListScreec.h"
#include"clsThirdStudentListScreen.h"
#include"clsFourthACDstudentsScreen.h"
using namespace std;

class clsMainListStudensScreen:clsScreen
{

private:

    enum enListOptions
    {
        eAllStudentList = 0, eFirstYear=1, eSecondYear=2,
        eThirdYear=3, eFourthYear=4
    };

    static int _ReadChoice()
    {
        int choice;
        cout << "choose list : ";
        choice = clsInputValidate::ReadIntNumberBetween(0, 5);
        return choice;
    }

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

	static void _ShowAllStudentListscrrn()
	{
		clsListStudentScreen::ShowStudentListScreen();
	}

    static void _ShowFirstAcadimicStudentListscrrn()
    {
        clsFirstAcadimicLIstScreen::ShowFirstAcdimicListScreen();

    }

    static void _ShowSecondAcadimicStudentListscrrn()
    {
        clsSecondACDStudentListScreec::ShowSceondAcdimicListScreen();
    }

    static void _ShowThirdAcadimicStudentListscrrn()
    {
        clsThirdStudentListScreen::ShowThirdAcdimicListScreen();

    }

    static void _ShowFourthAcadimicStudentListscrrn()
    {
        
        clsFourthACDstudentsScreen::ShowFourthAcdimicListScreen();
    }


    static  void _GoBackToListMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main List Menue...\n";

        system("pause>0");
        ShowMainListScreen();
    }


    static void _PerformMainMenuOption(enListOptions choice)
    {
        switch (choice)
        {
        case clsMainListStudensScreen::eAllStudentList:
            system("cls");
            _ShowAllStudentListscrrn();
            _GoBackToListMainMenue();
            break;


        case clsMainListStudensScreen::eFirstYear:
            system("cls");
            _ShowFirstAcadimicStudentListscrrn();
            _GoBackToListMainMenue();
            break;


        case clsMainListStudensScreen::eSecondYear:
            system("cls");
            _ShowSecondAcadimicStudentListscrrn();
            _GoBackToListMainMenue();
            break;


        case clsMainListStudensScreen::eThirdYear:
            system("cls");
            _ShowThirdAcadimicStudentListscrrn();
            _GoBackToListMainMenue();
            break;


        case clsMainListStudensScreen::eFourthYear:

            system("cls");
            _ShowFourthAcadimicStudentListscrrn();
            _GoBackToListMainMenue();
            break;


        default:
            break;
        }
    }


public:
	static void ShowMainListScreen()
	{
        system("cls");

        UpScreen("\t Students Lists Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Lists Menu Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[0] Show All Student List Menu.\n";
        cout << setw(37) << left << "" << "\t[1] Show First Acd. Student List Menu.\n";
        cout << setw(37) << left << "" << "\t[2] Show Second Acd. Student List Menu.\n";
        cout << setw(37) << left << "" << "\t[3] Show Third Acd. Student List Menu.\n";
        cout << setw(37) << left << "" << "\t[4] Show Fourt Acd. Student List Menu.\n";
        cout << setw(37) << left << "" << "\t[5] Go Back To Main Menu .\n";
        cout << setw(37) << left << "" << "\t--------------------------------------------\n\n";

        cout << setw(37) << left << "";
        _PerformMainMenuOption(enListOptions(_ReadChoice()));

	}
};

