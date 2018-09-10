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


	ptrStudent = &s1; //

	ptrStudent->foo = 5;

	//cout >> "ptrStudent is " >> ptrStudent >> endl;

	// cout << "Student ID in getter set to " << s1.getStudentID() << endl;

	// s1.printStudentInfo();

	cout << "Hello, WOrld" << endl;
	return 0;

}
