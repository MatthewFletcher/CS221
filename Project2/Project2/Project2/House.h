/*******************************************************************
*   File name: House.h
*   Author's name: Matt Fletcher
*   Programming Assignment 2:  //TODO Program Name
*   
*   This program is entirely my own work
*******************************************************************/

#include <iostream>
#include "Student.h"
#include <string.h>

#ifndef HOUSE_H
#define HOUSE_H

class House
{


private:
	Student *m_pHead;
	char m_sHouseName[65]; //Has to store a name up to 64 characters in length


public:
	House(); //Default constructor
	~House(); //Default destructor
	bool AddStudent(Student *stu);
	Student *RemoveStudent(int studentID);
	Student *FindStudent(int studentID);
	Student *FindStudent(char *fname, char *lname);
	void PrintHouseList();


	void SetHouseName(char *name);
	char *GetHouseName();
};



#endif