#pragma once
#include <iostream>
#include <iomanip>  
#include "clsStudent.h"
#include "clsScreen.h"
#include "clsString.h"

using namespace std;

class clsFirstAcadimicLIstScreen : protected clsScreen
{
private:
    static void _printStudentMaterialInfo(clsStudent::_stMaterials& material)
    {
        
        cout << "| " << left << setw(20) << material.fullName << "| "
            << setw(10) << material.ID << "| ";
        
        for (const string& subject : material.materials)
        {
            cout << setw(15) << subject << "| ";
        }
        cout << endl;
      
    }

public:
    static void ShowFirstAcdimicListScreen()
    {
        UpScreen("\t   First ACD studenst");

        vector<clsStudent::_stMaterials> vMaterials;
        vMaterials = clsStudent::GetListOfAcadimicStudentYear(1);

        cout << "========================================================================================\n";
        cout << left << setw(20) << "Student Name" << "| "
            << setw(10) << "ID" << "| "
            << "Materials\n";
        cout << "========================================================================================\n";

        if (vMaterials.empty())
        {
            cout << "\nNo student in this Academic year\n";
        }
        else
        {
            for (clsStudent::_stMaterials& material : vMaterials)
            {
                _printStudentMaterialInfo(material);
            }
        }
        cout << "========================================================================================\n";
    }
};
