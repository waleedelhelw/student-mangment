#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"clsString.h"
#include"clsPerson.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListStudentScreen.h"
#include"clsFindStudentScreen.h"
#include"clsAddNewStudent.h"
#include"clsDeleteStudentScreen.h"
#include"clsUpdateStudentScreen.h"
#include"clsRefreshStudentDataScreen.h"
#include"clsMainListStudensScreen.h"
class clsMainScreen:protected clsScreen
{
private:

    enum enMainMenuOptions {
        eListStudents = 1,       
        eAddNewStudent = 2,      
        eDeleteStudent = 3,      
        eUpdateStudent = 4,      
        eFindStudent = 5,        
        eShowGradesMenu = 6,     
        eManageUsers = 7,        
        eLoginRegisterScreen = 8,
        RefreshStdentsData=9,
        eLogout = 10                
    };


    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }


    static void _ShowStudentList()
    {
        //clsListStudentScreen::ShowStudentListScreen();
        clsMainListStudensScreen::ShowMainListScreen();
    }

    static void _AddNewStudent()
    {
        clsAddNewStudent::ShowAddNewStudentScreen();
    }

    static void _DeleteStudent()
    {
        clsDeleteStudentScreen::ShowDeleteStudentScreen();
    }

    static void _UpdateStudentInfo()
    {
        clsUpdateStudentScreen::ShowUpdateStudentScreen();
    }

    static void _FindStudent()
    {
        clsFindStudentScreen::ShowFindStudentScreen();
    }

    static void _ShowGradesMenu()
    {
        cout << "Displaying grades menu...\n";
    }

    static void _ManageUsers()
    {
        cout << "Managing users...\n";
    }

    static void _ShowLoginRegisterScreen()
    {
        cout << "Showing login/register screen...\n";
    }

    static void _ShowRefreshStudentDataScreen()
    {
        clsRefreshStudentDataScreen::RefreshStudentDataScreen();
    }
    
    static int _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }


    static void _PerformMainMenuOption(enMainMenuOptions choice)
    {
        switch (choice)
        {
        case clsMainScreen::eListStudents:
            system("cls");
            _ShowStudentList();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eAddNewStudent:
            system("cls");
            _AddNewStudent();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eDeleteStudent:
            system("cls");
            _DeleteStudent();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eUpdateStudent:
            system("cls");
            _UpdateStudentInfo();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eFindStudent:
            system("cls");
            _FindStudent();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eShowGradesMenu:
            system("cls");
            _ShowGradesMenu();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eManageUsers:
            system("cls");
            _ManageUsers();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::eLoginRegisterScreen:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;

        case clsMainScreen::RefreshStdentsData:
            system("cls");
            _ShowRefreshStudentDataScreen();
            //cout << "\t\t\tIN WORKING.....!!\n";
            _GoBackToMainMenue();

        case clsMainScreen::eLogout:
            system("cls");
            // it will be login screen

            cout << "\n\n\t\t\t\t\tProgram Has End :)\n\n\n";

            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            _GoBackToMainMenue();
            break;
        }
    }


public:
    static void ShowMainMenue()
    {
        system("cls");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Student List Menu.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Student.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Student.\n";
        cout << setw(37) << left << "" << "\t[4] Update Student Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Student.\n";
        cout << setw(37) << left << "" << "\t[6] Show Grades Menu.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login/Register Screen.\n";
        cout << setw(37) << left << "" << "\t[9] Refresh Student Data.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption(enMainMenuOptions(_ReadMainMenueOption()));

    }
};

