/*******************************************************************
*   File name: main.cpp
*   Author's name: Matt Fletcher
*   Programming Assignment 1:  //TODO Program Name
*   
*   This program is entirely my own work
*******************************************************************/

#include <iostream>
#include "Student.h"

using namespace std;

int main()
{

	cout << "Harry Potter Assignment Main Tester" << endl << endl;

	Student s1;

	Student *ptrStudent; //Declare pointer to student class


	ptrStudent = &s1; //Create variable to hold pointer to s1 instance of Student class

	ptrStudent->foo = 5;

	cout << ptrStudent->foo << endl;

	
	ptrStudent->setStudentID(1234);
	cout << "Student ID in getter set to " << ptrStudent->getStudentID() << endl;

	ptrStudent->printStudentInfo();

	cout << "Hello, WOrld" << endl;
	return 0;

}
