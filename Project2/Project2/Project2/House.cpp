/*******************************************************************
*   File name: House.h
*   Author's name: Matt Fletcher
*   Programming Assignment 2:  //TODO Program Name
*   
*   This program is entirely my own work
*******************************************************************/

#include <iostream>
#include "House.h"
#include <string.h>

using namespace std;

House::House()
	{
		cout << "Creating instance of house class from default constructor" << endl;
	
	}
House::~House()
	{
		cout << "Creating instance of house class from overloaded constructor" << endl;	
	}
bool House::AddStudent(Student *stu)
	{
			return 0;
	}
Student* House::RemoveStudent(int studentID)
	{


		return 0;
	}
Student*  House::FindStudent(int studentID)
	{
		return  0;
	}
Student* House::FindStudent(char *fname, char *lname)
	{
		return 0;
	}
void House::PrintHouseList()
	{
	
	}
void House::SetHouseName(char *name)
	{
	
	}
char House::*GetHouseName()
	{
		return 0;
	}