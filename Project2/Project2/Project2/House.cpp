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

		Student *temp;

		if(m_pHead != NULL)
		{
			temp = m_pHead;

			while(m_pHead != NULL)
			{
				temp = m_pHead;
				m_pHead=m_pHead->m_pNext;
				delete temp;
			}
		}
	}
bool House::AddStudent(Student *stu)
	{
		Student *back = NULL;
		Student *temp = m_pHead;

		while ((temp != NULL) && (stu->getStudentID() < temp->getStudentID()))
		{
			cout << "Looping through list" << endl;
			back = temp;
			temp = temp->m_pNext;
		}
		if (back==NULL)
		{
			cout << "Inserting student "<< stu->getStudentID()<<" at head of list" << endl;
			stu->m_pNext = m_pHead; //insert at head of list
			m_pHead = stu;
			return true;
		}

		else
		{
			//Inserting 
			cout <<"Inserting student "<< stu->getStudentID()<<" somewhere in list" << endl;
			back->m_pNext = stu;
			stu->m_pNext = temp;
		}

		cout << "You should not be seeing this error message." << endl;
		return false;
	}
Student* House::RemoveStudent(int studentID)
	{

		cout << "Removing student with ID " << studentID << endl;
		Student *temp, *back;

		//Check for an empty list
		if(m_pHead == NULL) 
			{
				cout << "List is empty" << endl;
				return NULL;
			} 

		temp = m_pHead;
		back = NULL;
		while((temp != NULL) && (studentID != temp->getStudentID()))
		{
			back = temp;
			temp = temp->m_pNext;
		}

		if (temp==NULL)
		{
			cout << "Student not found" << endl;
			return NULL;
		} //This means the student was not found

		else if(back == NULL)
		{
			cout << "Back is null, student removed from head of list" << endl;
			m_pHead = m_pHead->m_pNext;
			return temp;
		}

		else
		{
			cout << "Deleted from somewhere in list" << endl;
			back->m_pNext = temp->m_pNext;
			return temp;
		}

		return 0;
	}
Student*  House::FindStudent(int studentID)
	{
		//TODO, function not working (main does not find student)
		Student *temp;
		temp = m_pHead; //initialize pointer to point ot head of list 


		cout << "temp is >> " << temp << endl;
		while((temp != NULL) && (studentID != temp->getStudentID()))
		{
			cout << "Checking for student" << endl;
			cout << temp->getStudentID();
			temp = temp->m_pNext;
		}

		if (temp==NULL)  //TODO fix issue where temp is always null
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

		Student *temp;

		if (m_pHead==NULL)
		{
			cout << "List is empty" << endl;
		}

		else
		{
			temp = m_pHead;
			while (temp!=NULL)
			{
				temp->printStudentInfo();
				temp = temp->m_pNext;
			}
		}
		
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