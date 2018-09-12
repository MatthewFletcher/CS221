/*******************************************************************
*   File name: Student.cpp
*   Author's name: Matt Fletcher
*   Programming Assignment 1:  //TODO Program Name
*   
*   This program is entirely my own work
*******************************************************************/

#include "Student.h"
#include <iostream>
#include <string.h>

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
			cout << "getName is running " << endl;
		}
	void Student::setName(char *mName, char *wName)
		{	

			int name_array_length = 64;
			char mName_array[name_array_length];
			mName = mName_array;

			cout << "Name Array Initializing 1" << endl;

			for (int i = 0; i++ < name_array_length;)
			{
				mName_array[i] = 'a';
			}



			char wName_array[name_array_length];
			wName = wName_array;
			cout << "Name Array Initializing 2" << endl;
			for (int i = 0; i++ < name_array_length;)
			{
				wName_array[i] = 'b';
			}


			mName = mName_array;
			
			
		}

	//- Get and set the student's house name. 
	void Student::getHouse(char *hName)
		{
			cout << "getHouse is running " << endl;
	
		}
	void Student::setHouse(char *hName)
		{
	
		}

	//Get and set a class name
	void Student::getClass(int idx, char *className)
		{
			cout << "getClass is running " << endl;
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
			cout << "getGrade with pointers is running " << endl;
		}
 //Reference function that returns a letter and number grade TODO use hogwarts grading scale
	void Student::getGrade(int idx, int *iGrade, char *cGrade)
		{
			cout << "getGrade with reference is running " << endl;
		}
 //Pointer function that returns a letter and umber grade



	void Student::printStudentInfo()
	{
		cout << " ID          Name        House" << endl;
		//cout s1.

	
		cout << "Printing Student Information" << endl;
	}


