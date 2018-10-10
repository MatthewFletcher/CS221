/*******************************************************************
*   File name: House.h
*   Author's name: Matt Fletcher
*   Programming Assignment 2:  //TODO Program Name
*   
*   This program is entirely my own work
*******************************************************************/

#include <iostream>
#include "House.h"
#include <string.h>

using namespace std;

House::House()
	{
		cout << "Creating instance of house class from default constructor" << endl;
	
	}
House::~House()
	{
		cout << "Creating instance of house class from overloaded constructor" << endl;	
	}
bool House::AddStudent(Student *stu)
	{
			return 0;
	}
Student* House::RemoveStudent(int studentID)
	{
		Student *temp, *back;

		//Check for an empty list
		if(0) return NULL; //TODO CHECK FOR EMPTY LIST

		temp = head; //TODO SET TO HEAD
		back = NULL;
		while((temp != NULL) && (studentID != temp->getStudentID()))
		{
			back = temp;
			temp = temp->m_pNext;
		}

		if (temp==NULL)
		{
			return NULL;
		}

		else if(back == NULL)
		{
			head = head->m_pNext;
			return temp;
		}

		else
		{
			back->m_pNext = temp->m_pNext;
			return temp;
		}

		return 0;
	}
Student*  House::FindStudent(int studentID)
	{
		Student *temp;
		//temp = head; //initialize pointer to point ot head of list 

		while((temp != NULL) && (studentID != temp->getStudentID()))
		{
			temp = temp->m_pNext;
		}

		if (temp==NULL)
		{
			return NULL;
		}

		else
		{
			Student *retItem = new Student();
			*retItem = *temp;
			retItem->m_pNext = NULL;
			return retItem;
		}
		return  0;
	}
Student* House::FindStudent(char *fname, char *lname)
	{
		return 0;
	}
void House::PrintHouseList()
	{
	
	}
void House::SetHouseName(char *name)
	{
	
	}
char House::*GetHouseName()
	{
		return 0;
	}