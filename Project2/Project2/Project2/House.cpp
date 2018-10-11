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
		strcpy(m_sHouseName, ""); //Set house name to empty
		m_pHead = NULL; //setting m_pHead equal to null
	}
House::~House()
	{

		cout << "Destructor" << endl;	
	}
bool House::AddStudent(Student *stu)
	{
		Student *back = NULL;
		Student *temp = m_pHead;

		if (back==NULL)
		{
			cout << "Inserting student at head of list" << endl;
			stu->m_pNext = m_pHead; //insert at head of list
			m_pHead = stu;
			return true;
		}

		else
		{
			//Inserting 
			back->m_pNext = stu;
			stu->m_pNext = temp;
		}

		cout << "If you are seeing this, then I screwed up." << endl;
		return false;
	}
Student* House::RemoveStudent(int studentID)
	{
		Student *temp, *back;

		//Check for an empty list
		if(m_pHead == NULL) return NULL; //TODO CHECK FOR EMPTY LIST

		temp = m_pHead; //TODO SET TO HEAD
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
			m_pHead = m_pHead->m_pNext;
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
		temp = m_pHead; //initialize pointer to point ot head of list 

		while((temp != NULL) && (studentID != temp->getStudentID()))
		{
			temp = temp->m_pNext;
		}

		if (temp==NULL)
		{
			cout << "Student not found" << endl;
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
		Student *temp;
		temp = m_pHead;

		while((temp != NULL))
		{
			break;
		}
		return 0;
	}
void House::PrintHouseList()
	{
		
	}
void House::SetHouseName(char *name)
	{
		strcpy(m_sHouseName, name);
		cout << "SetHouseName is running" << endl;
		cout << "House name set to " << name << endl;
	}
char House::*GetHouseName()
	{

		return 0;
	}