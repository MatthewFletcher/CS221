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

using namespace std;

class House
{


private:


public:
	House();
	~House();
	bool AddStudent(Student *stu);
	Student *RemoveStudent(int studentID);
	Student *FindStudent(int studentID);
	Student *FindStudent(char *fname, char *lname);
	void PrintHouseList();


	void SetHouseName(char *name);
	char *GetHouseName();
};



#endif