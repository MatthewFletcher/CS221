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

	for (int i = 0; i < 8; ++i)
	{
		strcpy(m_sClasses[i], "");  //Sets all elements of array to empty
		m_iGrades[i] = 0;	//Sets all grades to 0 for initialization
	}

	m_pNext = NULL;
	

}

//Define overloaded constructor
Student::Student(int iID, char *mName, char *wName, char *hName)
{
	m_pNext = NULL;
	cout << "overloaded constructor" << endl;

	for (int i = 0; i < 8; ++i)
	{
		strcpy(m_sClasses[i], "");  //Sets all elements of array to empty
		m_iGrades[i] = 0;	//Sets all grades to 0 for initialization
	}

	m_iStudentID = iID;
	strcpy(m_sMagicalName, mName);
	strcpy(m_sWizardFamilyName, wName);
	strcpy(m_sHouse, hName);

	cout << "ID set to " << iID << endl;
	cout << "First name set to " << m_sMagicalName << endl;
	cout << "Last name set to " << m_sWizardFamilyName << endl;
	cout << "House set to " << m_sHouse << endl;
		

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
		cout << "getter runs" << endl;
	}



		//Get and set the student's name and wizarding family name. 
	void Student::setName(char *mName, char *wName)
		{	
			strcpy(m_sMagicalName, mName);
			strcpy(m_sWizardFamilyName, wName);
			//cout << "setName is running" << endl;
		}

	void Student::getName(char *mName, char *wName)
		{
			strcpy(mName, m_sMagicalName);
			strcpy(wName, m_sWizardFamilyName);

			//cout << "getName is running" << endl;

		}

	//- Get and set the student's house name. 
	void Student::setHouse(char *hName)
		{
			strcpy(m_sHouse, hName);
			//cout <<  "setHouse is running " << endl;
	
		}

	void Student::getHouse(char *hName)
		{
			//cout << "getHouse is running " << endl;

			strcpy(hName, m_sHouse);
	
		}

	//Get and set a class name
	void Student::setClass(int idx, char *className)
		{
			//cout << "setClass is running" << endl;
			strcpy(m_sClasses[idx], className);
		}
	void Student::getClass(int idx, char *className)
		{
			//cout << "getClass is running " << endl;
			strcpy(className, m_sClasses[idx]);			
		}



	//Get and Set a grade
	void Student::setGrade(int idx, int grade)
		{
			//cout << "setGrade is running"  << endl;
			m_iGrades[idx] = grade;

	
			
				
		}

 //Reference function that returns a letter and number grade
	void Student::getGrade(int idx, int &iGrade, char &cGrade)
		{
			cout << "getGrade with pointers is running " << endl;
			iGrade = m_iGrades[idx];

			if (iGrade < 60)cGrade = 'T';
			else if (iGrade <=69)cGrade = 'D';
			else if (iGrade <=79)cGrade = 'P';
			else if (iGrade <=89)cGrade = 'A';
			else if (iGrade <=94)cGrade = 'E';
			else if (iGrade <=100)cGrade = 'O';

			cout << "Letter grade: "<<iGrade <<" is a " << cGrade << endl;


		}


 //Pointer function that returns a letter and numer grbade
	void Student::getGrade(int idx, int *iGrade, char *cGrade)
		{
			*iGrade = m_iGrades[idx];

			if (*iGrade < 60)*cGrade = 'T';
			else if (*iGrade <=69)*cGrade = 'D';
			else if (*iGrade <=79)*cGrade = 'P';
			else if (*iGrade <=89)*cGrade = 'A';
			else if (*iGrade <=94)*cGrade = 'E';
			else if (*iGrade <=100)*cGrade = 'O';

			cout << "Letter grade: "<<*iGrade <<" is a " << *cGrade << endl;
		}



	void Student::printStudentInfo()
	{
		cout << "Printing Student Information" << endl << endl;
		cout << " ID\tName\t\tHouse" << endl;
		cout << getStudentID() <<   "\t" <<  m_sMagicalName << "\t" << m_sWizardFamilyName << "\t" << m_sHouse << endl;

		for (int i = 0; i < 8; ++i)
		{
			if(strlen(m_sClasses[i]) != 0) cout << m_sClasses[i]<< "\t " << m_iGrades[i] << endl;
		}
 
	
	}

	Student* Student::Clone()
	{

		Student *theClone = new Student();
		theClone->setStudentID(m_iStudentID);
		theClone->setName(m_sMagicalName, m_sWizardFamilyName);
		theClone->setHouse(m_sHouse);
		// //Do the same thing for the house name 

		for (int i = 0; i < 8; i++)
		{
			//If the class name at this index is not NULL
			if (m_sClasses[i] != NULL)
			{
				theClone->setClass(i,m_sClasses[i]);
				//Tell the new instance of student to set its class grade at index i to this class grade 
			}
		}
		return theClone;

		//See slide Testing_Program 2_9

		//When testing this function, where stu2 is the deep copy of stu1,
		//delete stu1 before printing stu2 info to ensure a deep copy has been properly made 


	}