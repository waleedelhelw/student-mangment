#pragma once
#include<iostream>
#include<string>
using namespace std;
class clsPerson
{
private:
	string _firstName;
	string _lastName;
	string _Email;
	string _PhoneNumber;
	string _Id;
	string _Nationality;
public:
	clsPerson(string frisName, string lastName, string email, string phone,string Id, string Nationality)
	{

		_firstName = frisName;
		_lastName = lastName;
		_Email = email;
		_PhoneNumber = phone;
		_Id = Id;
		_Nationality = Nationality;
	}
	void SetFirstName(string name)
	{
		_firstName = name;
	}
	string FirstName()
	{
		return _firstName;
	}
	void SetLastName(string LastName)
	{
		_lastName = LastName;
	}

	string LastName()
	{
		return _lastName;
	}

	string FullName()
	{
		return _firstName + " " + _lastName;
	}

	void SetEmail(string email)
	{
		_Email = email;
	}
	string Email()
	{
		return _Email;
	}

	void setPhone(string phone)
	{
		_PhoneNumber = phone;
	}
	string PhoneNumber()
	{
		return _PhoneNumber;
	}

	string Id()
	{
		return _Id;
	}

	void setNationality( string& nationality)
	{
		_Nationality = nationality;
	}

	string Nationality() 
	{
		return _Nationality;
	}

};

