/*******************************************************************
*   File name: Student.cpp
*   Author's name: Matt Fletcher
*   Programming Assignment 1:  //TODO Program Name
*   
*   This program is entirely my own work
*******************************************************************/

#include "Student.h"
#include <iostream>

using namespace std;

//Define Default Constructor
Student::Student()
{
	cout << "Student Class constructor run" << endl;

}

//Define overloaded constructor
Student::Student(int iID, char *mName, char *wName, char *hName)
{
	cout << "overloaded constructor" << endl;

}


//////////////////////////
	//Getters and Setters

	//Get and set the student ID
	void Student::setStudentID(int iID)
	{	
		cout << "ID set to " << iID << endl;

		m_iStudentID = iID;
	}
	int Student::getStudentID()
	{
		return m_iStudentID;
		//TODO figure out why this is throwing a "not declared in this scope" error
		cout << "getter runs" << endl;
	}



	void Student::printStudentInfo()
	{
		cout << "Printing Student Information" << endl;
	}

