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

	Student s1;

	s1.setStudentID(10);
	cout << "Student ID in getter set to " << s1.getStudentID() << endl;

	s1.printStudentInfo();

	cout << "Hello, WOrld" << endl;
	return 0;

}
