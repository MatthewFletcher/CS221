/*******************************************************************
*   File name: main.cpp
*   Author's name: Matt Fletcher
*   Programming Assignment 1:  //TODO Program Name
*   
*   This program is entirely my own work
*******************************************************************/

#include <iostream>
#include "Student.h"
#include <string.h>

using namespace std;



int main()
{

	cout << "Harry Potter Assignment Main Tester" << endl << endl;

	Student s1;

	Student *s = new Student(567, "fooing", "foostuff", "fooHouse");

	Student *ptrStudent; //Declare pointer to student class


	ptrStudent = &s1; //Create variable to hold pointer to s1 instance of Student class

	
	ptrStudent->setStudentID(1234);
	cout << "Student ID in getter set to " << ptrStudent->getStudentID() << endl;

	//Testing House Name function

	cout << "=======================\n" << "setHouse, getHouse" << endl;

	cout << "Declaring housename array" << endl;
	char hName[32];

	ptrStudent->setHouse("Hufflepuff");
	ptrStudent->getHouse(hName);

	cout << strcmp("Hufflepuff", hName) << " <<<< strcmp for house name "<< endl;


	cout << "=======================\n" << "setName, getName" << endl;
	char mName[64];
	char fName[64];
	ptrStudent->setName("Harry", "Potter");
	ptrStudent->getName(mName, fName);

	cout << strcmp("Harry", mName) << " <<<< strcmp for first name "<< endl;
	cout << strcmp("Potter", fName) << " <<<< strcmp for last name " << endl;
		


	cout << "=======================\n" << "setGrade, getGrade" << endl;
	cout << "Declaring grades array " << endl;
	//char grades[8];

	int iGrade = 94;
	ptrStudent->setGrade(0, iGrade);

	//Reference function version
	char cGrade = '\0';
	ptrStudent->getGrade(0,iGrade,cGrade);
	cout << !(iGrade == 94) << " <<<< strcmp for Grade, digit, reference" << endl;
	cout << !(iGrade == 'O') << " <<<< strcmp for Grade, letter, reference" << endl;

	//Pointer function version
	iGrade = 35;
	cGrade = '\0';
	ptrStudent->getGrade(1,&iGrade,&cGrade);
	cout << !(iGrade == 94) << " <<<< strcmp for Grade, digit, pointer" << endl;
	cout << !(iGrade == 'O') << " <<<< strcmp for Grade, letter, pointer" << endl;

	



	cout << "=======================\n" << "setClass, getClass" << endl;
	cout << "Declaring class array" << endl;

	char cName[32];
	ptrStudent->setClass(0,"Charms");
	ptrStudent->getClass(0, cName);
	cout << strcmp("Charms", cName) << " <<<< strcmp for class " << endl;


	ptrStudent->setClass(1, "Other Magic Stuff");
	ptrStudent-> setGrade(1, 92);

	ptrStudent->setClass(5, "Trying to break stuff");
	ptrStudent-> setGrade(5, 53);






	

	cout << "=======================\n" << "printStudentInfo" << endl;
	ptrStudent->printStudentInfo();


	cout << "Thanks for playing, bye \n" << endl;

	int foo;

	cin >> foo;

	return 0;

}