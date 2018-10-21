//----------------------------------------------------------------------
// HogwartsSWW.cpp
// Implementation file for the HogwartsSWW class.
// Author: Dr. Rick Coleman
//
// This file is provided by the instructor for use in programming
//   assignment 2.
//
//----------------------------------------------------------------------
#include "HogwartsSWW.h"
#include <iostream>
#include <stdio.h>

using namespace std;

//-----------------------------------------------------
// Default constructor
//-----------------------------------------------------
HogwartsSWW::HogwartsSWW()
{
	m_pGryffindor = new House();
	m_pGryffindor->SetHouseName("Gryffindor");
	m_pRavenclaw = new House();
	m_pRavenclaw->SetHouseName("Ravenclaw");
	m_pHufflepuff = new House();
	m_pHufflepuff->SetHouseName("Hufflepuff");
	m_pSlytherin = new House();
	m_pSlytherin->SetHouseName("Slytherin");
}

//-----------------------------------------------------
// Destructor
//-----------------------------------------------------
HogwartsSWW::~HogwartsSWW()
{
	delete m_pGryffindor;
	delete m_pRavenclaw;
	delete m_pHufflepuff;
	delete m_pSlytherin;
}

//-----------------------------------------------------
// AddStudent()
// Purpose: Add a student to a house
// Args: stu - pointer to a Student object
// Returns: bool - true if add was successful
//-----------------------------------------------------
bool HogwartsSWW::AddStudent(Student *stu)
{
	char house[64];
	stu->getHouse(house);

	if(strcmp(house, "Gryffindor") == 0)
		return m_pGryffindor->AddStudent(stu);
	else if(strcmp(house, "Ravenclaw") == 0)
		return m_pRavenclaw->AddStudent(stu);
	else if(strcmp(house, "Hufflepuff") == 0)
		return m_pHufflepuff->AddStudent(stu);
	else if(strcmp(house, "Slytherin") == 0)
		return m_pSlytherin->AddStudent(stu);
	else
		return false;
}

//-----------------------------------------------------------------
// RemoveStudent()
// Purpose: Remove a student from a house
// Args: house - Name of the student's house
//       stu - pointer to a Student object
// Returns: Pointer to removed student if removal was successful
//-----------------------------------------------------------------
Student *HogwartsSWW::RemoveStudent(char *house, int studentID)
{
	if(strcmp(house, "Gryffindor") == 0)
		return m_pGryffindor->RemoveStudent(studentID);
	else if(strcmp(house, "Ravenclaw") == 0)
		return m_pRavenclaw->RemoveStudent(studentID);
	else if(strcmp(house, "Hufflepuff") == 0)
		return m_pHufflepuff->RemoveStudent(studentID);
	else if(strcmp(house, "Slytherin") == 0)
		return m_pSlytherin->RemoveStudent(studentID);
	else
	{
		cout << "Unknown house given in RemoveStudent() function.\n";
		return NULL;
	}
}

//-----------------------------------------------------
// FindStudent()
// Purpose: Find a student in a house
// Args: house - Name of the student's house
//       stu - pointer to a Student object
// Returns: Pointer to a clone of the student record
//-----------------------------------------------------
Student *HogwartsSWW::FindStudent(char *house, int studentID)
{
	if(strcmp(house, "Gryffindor") == 0)
		return m_pGryffindor->FindStudent(studentID);
	else if(strcmp(house, "Ravenclaw") == 0)
		return m_pRavenclaw->FindStudent(studentID);
	else if(strcmp(house, "Hufflepuff") == 0)
		return m_pHufflepuff->FindStudent(studentID);
	else if(strcmp(house, "Slytherin") == 0)
		return m_pSlytherin->FindStudent(studentID);
	else
	{
		cout << "Unknown house given in FindStudent(char *, int) function.\n";
		return NULL;
	}
}

//-----------------------------------------------------
// FindStudent()
// Purpose: Find a student in a house
// Args: house - Name of the student's house
//       fname - Student's first name
//       lname - Student's last name
// Returns: Pointer to a clone of the student record
//-----------------------------------------------------
Student *HogwartsSWW::FindStudent(char *house, char *fname, char *lname)
{
	if(strcmp(house, "Gryffindor") == 0)
		return m_pGryffindor->FindStudent(fname, lname);
	else if(strcmp(house, "Ravenclaw") == 0)
		return m_pRavenclaw->FindStudent(fname, lname);
	else if(strcmp(house, "Hufflepuff") == 0)
		return m_pHufflepuff->FindStudent(fname, lname);
	else if(strcmp(house, "Slytherin") == 0)
		return m_pSlytherin->FindStudent(fname, lname);
	else
	{
		cout << "Unknown house given in FindStudent(char *, char *, char *) function.\n";
		return NULL;
	}
}


//-----------------------------------------------------
// PrintHouses()
// Purpose: Print all information on all students in
//				all houses
// Args: None
// Returns: void
//-----------------------------------------------------
void HogwartsSWW::PrintHouses()
{
	cout << "Students at Hogwarts\n\n";
	m_pGryffindor->PrintHouseList();
	cout << "\nPress any key to see the next house listing...";
	getchar();
	cout << "\n\n";
	m_pRavenclaw->PrintHouseList();
	cout << "\nPress any key to see the next house listing...";
	getchar();
	cout << "\n\n";
	m_pHufflepuff->PrintHouseList();
	cout << "\nPress any key to see the next house listing...";
	getchar();
	cout << "\n\n";
	m_pSlytherin->PrintHouseList();
}
