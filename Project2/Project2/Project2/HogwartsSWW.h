//----------------------------------------------------------------------
// HogwartsSWW.h
// Inteface definition file for the HogwartsSWW class.
// Author: Dr. Rick Coleman
//
// This file is provided by the instructor for use in programming
//   assignment 2.
//
//----------------------------------------------------------------------
#pragma once

#include "House.h"
#include "Student.h"

class HogwartsSWW
{
	private:
		House	*m_pGryffindor;
		House	*m_pRavenclaw;
		House	*m_pHufflepuff;
		House	*m_pSlytherin;

	public:
		HogwartsSWW();									 // Default constructor
		~HogwartsSWW();									 // Destructor
		bool AddStudent(Student *stu);					 // Add a student to a house
		Student *RemoveStudent(char *house, int studentID);  // Remove a student given an ID
		Student *FindStudent(char *house, int studentID);// Find a student given the student ID
		Student *FindStudent(char *house, char *fname,   // Overloadef find function.  Find a student
						char *lname);				     //   given the first and last names
		void PrintHouses();
};