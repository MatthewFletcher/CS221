/*******************************************************************
*   File name: Student.h
*   Author's name: Matt Fletcher
*   Programming Assignment 2:  //TODO Program Name
*   
*   This program is entirely my own work
*******************************************************************/

#include <iostream>
#include <string.h>


#ifndef STUDENT_H
#define STUDENT_H


class Student
{
public:

	int foo;

	Student* m_pNext;

	//Default Constructor
	Student();

	//Second constructor
	Student(int iID, char *mName, char *wName, char *hName);

	//TODO Destructor function

//////////////////////////
	//Getters and Setters

	//Get and set the student ID
	int getStudentID();
	void setStudentID(int iID);

	//Get and set the student's name and wizarding family name. 
	void getName(char *mName, char *wName);
	void setName(char *mName, char *wName);

	//- Get and set the student's house name. 
	void getHouse(char *hName);
	void setHouse(char *hName);

	//Get and set a class name
	void getClass(int idx, char *className);
	void setClass(int idx, char *className);

	//Get and Set a grade
	void setGrade(int idx, int grade);
	void getGrade(int idx, int &iGrade, char &cGrade); //Reference function that returns a letter and number grade TODO use hogwarts grading scale
	void getGrade(int idx, int *iGrade, char *cGrade); //Pointer function that returns a letter and umber grade

	//Print All student information
	void printStudentInfo();



	//Clone function
	Student* Student::Clone()
	{

		Student *stu1;

		return stu1;
		//See slide Testing_Program 2_9

		//When testing this function, where stu2 is the deep copy of stu1,
		//delete stu1 before printing stu2 info to ensure a deep copy has been properly made 


	}




private:
	//Holds the student's ID number
	int m_iStudentID;

	//Char array for Magical name
	char m_sMagicalName[64];

	//Char Array for Family name
	char m_sWizardFamilyName[64];

	//Char array for house name
	char m_sHouse[64];

	//2D array of char for all class names
	char m_sClasses[8][32];

	//Array of ints to hold student's numerical grades
	int m_iGrades[8];
	
};


#endif