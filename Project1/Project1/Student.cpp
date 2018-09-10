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
	cout << "Creating student class instance using default constructor" << endl;

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



		//Get and set the student's name and wizarding family name. 
	void Student::getName(char *mName, char *wName)
		{
			char mName_ptr = *mName;
			cout << "getName" << endl;
		}
	void Student::setName(char *mName, char *wName)
		{
			
		}

	//- Get and set the student's house name. 
	void Student::getHouse(char *hName)
		{
	
		}
	void Student::setHouse(char *hName)
		{
	
		}

	//Get and set a class name
	void Student::getClass(int idx, char *className)
		{
	
		}
	void Student::setClass(int idx, char *className)
		{
	
		}

	//Get and Set a grade
	void Student::setGrade(int idx, int grade)
		{
			
		}
	void Student::getGrade(int idx, int &iGrade, char &cGrade)
		{
			
		}
 //Reference function that returns a letter and number grade TODO use hogwarts grading scale
	void Student::getGrade(int idx, int *iGrade, char *cGrade)
		{
	
		}
 //Pointer function that returns a letter and umber grade



	void Student::printStudentInfo()
	{
	
		cout << "Printing Student Information" << endl;
	}


