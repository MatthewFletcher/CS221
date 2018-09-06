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


//////////////////////////
	//Getters and Setters

	//Get and set the student ID
	void Student::setStudentID(int iID)
	{	
		cout << "ID set to " << iID << endl;
	}
	int Student::getStudentID()
	{
		//return iID;
		//TODO figure out why this is throwing a "not declared in this scope" error
		cout << "getter runs" << endl;
	}

