#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"clsString.h"
#include"clsPerson.h"
#include"clsInputValidate.h"
#include"clsStudent.h"
using namespace std;




class clsStudent:public clsPerson
{
private:
	enum enMode { enEmpty = 1, enUpdate = 2, enAddNew = 3 };
	
	enMode _Mode;
	//vector<string> _materials;
	/*static struct _stMaterials
	{
		string ID;
		string fullName;
		vector<string> materials;
	};*/
	 struct _stMaterials;

	static _stMaterials _materials;

	float _GPA;
	int _AcademicYear;
	bool _MarkForDelet = false;


	static string _ConvertDataToLine(clsStudent& student, string Seperator = "#//#")
	{
		string line = "";
		line += student.FirstName() + Seperator;
		line += student.LastName() + Seperator;
		line += student.Id() + Seperator;
		line += to_string( student.AcademicYear()) + Seperator;
		line += to_string(student.GPA()) + Seperator;
		line += student.Email() + Seperator;
		line += student.PhoneNumber() + Seperator;
		line += student.Nationality() + Seperator;

		return line;
	}



	static clsStudent _ConvertLinetoStudentObject(string Line, string Seperator = "#//#")
	{
		vector<string> vStudent;
		vStudent = clsString::Split(Line, Seperator);

		return clsStudent(enMode::enUpdate, stof(vStudent[4]), stoi(vStudent[3]), vStudent[0],
			vStudent[1], vStudent[5], vStudent[6], vStudent[2], vStudent[7]);

	}


	

	static _stMaterials ConvertMaterailLineToData(string line, string Seperator = "#//#")
	{
		vector<string> vMaterial = clsString::Split(line, Seperator);

		_stMaterials materialsData; 
		if (vMaterial.size() < 3)
			return materialsData; 

		
		materialsData.ID = vMaterial[0];
		materialsData.fullName = vMaterial[1];

		
		for (size_t i = 2; i < vMaterial.size(); i++)
		{
			materialsData.materials.push_back(vMaterial[i]);
		}

		return materialsData;
	}

	
	static string _ConvertMaterialsToLine(_stMaterials materials, string Seperator = "#//#")
	{
		string materialsLine = "";
		for (string L : materials.materials)
		{
			materialsLine += L+Seperator;
		}
		return materials.ID + Seperator + materials.fullName + Seperator+ materialsLine;
	}



	
	

	static vector<clsStudent> _LoadStudentDataFromFile()
	{
		vector<clsStudent> vStudents;
		fstream MyFile("E:\\Student Manger\\fiels\\Students.txt", ios::in);

		if (!MyFile.is_open())
		{
			cout << "Error: Unable to open file for reading!" << endl;
			return vStudents;
		}

		string Line;
		while (getline(MyFile, Line))
		{
			
			clsStudent Student = _ConvertLinetoStudentObject(Line);
			vStudents.push_back(Student);
		}

		MyFile.close();
		return vStudents;
	}

	static vector<_stMaterials>_loadStudentMterialFromFile(int acadimicYear)
	{
		vector<_stMaterials> vMaterials;
		string FilePath = _GetStudentFilePath(acadimicYear);

		fstream Myfile;
		Myfile.open(FilePath, ios::in);
		if (!Myfile.is_open())
		{
			cout << "\nFail to open Student material file";
			return {};
		}
		else
		{
			string lineOfMaterial;
			while (getline(Myfile, lineOfMaterial))
			{
				_stMaterials material = ConvertMaterailLineToData(lineOfMaterial);
				vMaterials.push_back(material);

			}
		}
		Myfile.close();
		return vMaterials;
	}
	

	static void _SaveDataToFile(vector<clsStudent>vStudets)
	{

		fstream MyFile;
		MyFile.open("E:\\Student Manger\\fiels\\Students.txt", ios::out);//overwrite


		if (!MyFile.is_open())
		{
			cout << "Error: Unable to open file for reading!" << endl;
		}

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsStudent S : vStudets)
			{
				if (S._MarkForDelet == false)
				{
					DataLine = _ConvertDataToLine(S);
					MyFile << DataLine << endl;
				}

			}

			MyFile.close();

		}

	}


	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("E:\\Student Manger\\fiels\\Students.txt", ios::out | ios::app); 
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
		else
		{
			cout << "Error: Unable to open file for writing.\n";
		}
	}


	vector<string>_GetStudentMatrials(int AcadimicYear)
	{
		enum calssficationOfStudent { firstYear = 1, secondYear = 2, thirdYear = 3, FourthYear = 4 };

		switch (calssficationOfStudent(AcadimicYear))
		{
		case calssficationOfStudent::firstYear:
			return { "Math", "Arabic", "Physics" };

		case calssficationOfStudent::secondYear:
			return { "Biology", "Chemistry", "English", "History" };

		case calssficationOfStudent::thirdYear:
			return { "Programming", "AI", "Databases", "Networking" };

		case calssficationOfStudent::FourthYear:
			return { "Machine Learning", "Software Engineering", "Cloud Computing", "Cyber Security" };

		default:
			return {};
		}
	}


	static string _GetStudentFilePath(int academicYear)
	{
		switch (academicYear)
		{
		case 1:
			return "E:\\Student Manger\\fiels\\Year1_Students.txt";
		case 2:
			return "E:\\Student Manger\\fiels\\Year2_Students.txt";
		case 3:
			return "E:\\Student Manger\\fiels\\Year3_Students.txt";
		case 4:
			return "E:\\Student Manger\\fiels\\Year4_Students.txt";
		default:
			return "";
		}
	}

	void _saveMaterialsToFile(clsStudent& student)
	{
		string FilePath = _GetStudentFilePath(student.AcademicYear());

		fstream MyFile;
		MyFile.open(FilePath, ios::out | ios::app);

		if (MyFile.is_open())
		{
			string DataLine = _ConvertMaterialsToLine(student.Material());
			MyFile << DataLine << endl;
			MyFile.close();
		}
		else
		{
			cout << "Error: Unable to open materials file for writing!" << endl;
		}
	}


	



	static clsStudent _GetEmptyStudentObject()
	{
		return clsStudent(enMode::enEmpty, 0.0,0,"","","","","","");
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertDataToLine(*this));
		_saveMaterialsToFile(*this);

	}

	void _Update()
	{
		vector<clsStudent> _vStudents = _LoadStudentDataFromFile();
		bool isAcademicYearChanged = false;

		for (clsStudent& S : _vStudents)
		{
			if (S.Id() == Id())
			{
				if (S.AcademicYear() != _AcademicYear) 
				{
					isAcademicYearChanged = true;
					_DeleteStudentFromMaterialsFile(S);
				}
				if (S.FullName() != FullName())
				{
					_UpdateStudentMaterials(*this);
				}
				S = *this;
				break;
			}
		}
		
		_SaveDataToFile(_vStudents);

		if (isAcademicYearChanged)
		{
			_saveMaterialsToFile(*this); 
		}
	}


	void _UpdateStudentMaterials(clsStudent& student)
	{
		vector<_stMaterials> vMaterial = _loadStudentMterialFromFile(student.AcademicYear());
		bool isUpdated = false;

		for (_stMaterials& material : vMaterial)
		{
			if (material.ID == student.Id())
			{
				material = student._materials;
				isUpdated = true;
				break;
			}
		}

		if (!isUpdated)
		{
			cout << "\nNo materials found for this student.\n";
			return;
		}

		fstream OutFile(_GetStudentFilePath(student.AcademicYear()), ios::out);
		if (!OutFile.is_open())
		{
			cout << "\nFail to open Student materials file for writing!" << endl;
			return;
		}

		for (const _stMaterials& material : vMaterial)
		{
			OutFile << _ConvertMaterialsToLine(material) << endl;
		}

		OutFile.close();
		cout << "\nStudent materials updated successfully!\n";
	}




public:
	clsStudent(enMode mode, float GPA, int AcademicYear ,
		string frisName, string lastName, string email, string phone
		, string Id, string Nationality)
		:clsPerson(frisName,lastName,email,phone,Id,Nationality)
	{
		_Mode = mode;
		_GPA = GPA;
		_AcademicYear = AcademicYear;
	}

	static struct _stMaterials
	{
		string ID;
		string fullName;
		vector<string> materials;
	};


	// Setter for GPA
	void setGPA(float gpa)
	{
		_GPA = gpa;
		
	}

	// Getter for GPA
	float GPA() 
	{
		return _GPA;
	}

	// Setter for Academic Year
	void setAcademicYear(int& academicYear) 
	{
		_AcademicYear = academicYear;
		 setMterials();

	}

	
	int AcademicYear()
	{
		return _AcademicYear;
	}


	void setMterials()
	{ 
		if (_AcademicYear < 1 || _AcademicYear > 4)
		{
			cout << "Error: Invalid Academic Year!" << endl;
			return;
		}

		
		_materials.fullName = FullName();
		_materials.ID = Id();
		_materials.materials = _GetStudentMatrials(_AcademicYear);
	}

	_stMaterials Material()
	{
		
		return _materials;
	}
	static clsStudent AddNewID(string ID)
	{
		return clsStudent(enMode::enAddNew,0,0,"","","","",ID,"");
	}
	static void readStudentInfo(clsStudent &studnt)
	{
		

		string firstName, lastName, email, phone, nationality;
		int academicYear;
		float gpa;

		cout << "\nFirst Name: ";
		firstName = clsInputValidate::ReadString();
		studnt.SetFirstName(firstName);

		cout << "Last Name: ";
		lastName = clsInputValidate::ReadString();
		studnt.SetLastName(lastName);


		cout << "Academic Year: ";
		academicYear = clsInputValidate::ReadIntNumber();
		while (academicYear < 1 || academicYear > 4)
		{
			cout << "\nError: Invalid Academic Year! enter from [1] to [4]: ";
			academicYear = clsInputValidate::ReadIntNumber();

		}
		studnt.setAcademicYear(academicYear);


		cout << "GPA: ";
		gpa = clsInputValidate::ReadFloatNumber();
		studnt.setGPA(gpa);

		cout << "Email: ";
		email = clsInputValidate::ReadString();
		studnt.SetEmail(email);

		cout << "Phone Number: ";
		phone = clsInputValidate::ReadString();
		studnt.setPhone(phone);
		cout << "Nationality: ";
		nationality = clsInputValidate::ReadString();
		studnt.setNationality(nationality);
		
	}

	bool Delete()
	{
		vector<clsStudent>_vStudent;

		_vStudent = _LoadStudentDataFromFile();

		for (clsStudent& S : _vStudent)
		{
			if (S.Id() == Id())
			{
				S._MarkForDelet = true;
				break;
			}
		}

		_SaveDataToFile(_vStudent);

		*this = _GetEmptyStudentObject();

		return true;
	}


	static void _DeleteStudentFromMaterialsFile(clsStudent& student)
	{
		string FilePath = _GetStudentFilePath(student.AcademicYear());
		vector<_stMaterials> vMaterials;

		fstream MyFile(FilePath, ios::in);
		if (!MyFile.is_open())
		{
			cout << "\nFail to open Student materials file for reading!" << endl;
			return;
		}

		string line;
		while (getline(MyFile, line))
		{
			_stMaterials material = ConvertMaterailLineToData(line);

			// حذف الطالب إذا كان الـ ID يطابق الطالب الحالي
			if (material.ID != student.Id())
			{
				vMaterials.push_back(material);
			}
		}
		MyFile.close();

		// إعادة حفظ البيانات إلى الملف بعد حذف الطالب
		fstream OutFile(FilePath, ios::out);
		if (!OutFile.is_open())
		{
			cout << "\nFail to open Student materials file for writing!" << endl;
			return;
		}

		for (const _stMaterials& material : vMaterials)
		{
			OutFile << _ConvertMaterialsToLine(material) << endl;
		}

		OutFile.close();
		cout << "\nStudent materials deleted successfully!" << endl;
	}


	static vector<clsStudent> ListOfStudent()
	{
		vector<clsStudent> vList;
		vList = _LoadStudentDataFromFile();
		return vList;
	}


	static bool IsStudentExist(string Student_Id)
	{
		vector<clsStudent>vStudent;
		vStudent = _LoadStudentDataFromFile();
		for (clsStudent& student : vStudent)
		{
			if (student.Id() == Student_Id)
			{
				return true;
			}
		}
		return false;
	}

	static clsStudent Find(string StudentId)
	{
		fstream MyFile("E:\\Student Manger\\fiels\\Students.txt", ios::in);

		if (!MyFile.is_open())
		{
			cout << "Error: Unable to open file for reading!" << endl;
			return _GetEmptyStudentObject();
		}

		string Line;
		while (getline(MyFile, Line))
		{
			clsStudent Student = _ConvertLinetoStudentObject(Line);
			if (Student.Id() == StudentId)
			{
				MyFile.close();
				return Student;
			}
		}

		MyFile.close();
		return _GetEmptyStudentObject();
	}

	

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFailedUsedAccount };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::enEmpty:
			return enSaveResults::svFaildEmptyObject;

		case enMode::enUpdate:
			_Update();
			
			return enSaveResults::svSucceeded;

		case enMode::enAddNew:
			_AddNew();
			
			_Mode = enMode::enUpdate; 
			return enSaveResults::svSucceeded;
		}

		return enSaveResults::svFaildEmptyObject;
	}


	static void DeleteFiles()
	{
		for (int i = 1; i <= 4; i++)
		{
			string fileName = _GetStudentFilePath(i);
			cout << fileName << " -- has deleted\n";
			ofstream file(fileName, std::ios::trunc);
			file.close();
		}
		
		
	}

	static void RefreshData()
	{
		vector<clsStudent> vStudents = _LoadStudentDataFromFile();
		
		if (vStudents.size() == 0)
		{
			cout << "Failed to load studens data \n\n";
			return;
		}

		DeleteFiles();

		for (clsStudent& student : vStudents)
		{

			student.setMterials();
			student._saveMaterialsToFile(student);
			//cout << "\t [" << student.Id() << "] -- had reset..\n";
		}
	}

	
	static vector<_stMaterials> GetListOfAcadimicStudentYear(int acadimicYear)
	{
		vector<_stMaterials> Vstudents = _loadStudentMterialFromFile(acadimicYear);
		return Vstudents;

	}

};

