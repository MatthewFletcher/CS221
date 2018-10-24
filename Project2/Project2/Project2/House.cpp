/*******************************************************************
*   File name: House.h
*   Author's name: Matt Fletcher
*   Programming Assignment 2
*   
*   This program is entirely my own work
*******************************************************************/

#include <iostream>
#include "House.h"
#include <string.h>

using namespace std;

House::House()
	{
		//cout << "Creating instance of house class from default constructor" << endl;
		strcpy(m_sHouseName, ""); //Set house name to empty
		m_pHead = NULL; //setting m_pHead equal to null
	}

//Run this using delete (ptr);
House::~House()
	{


		//cout << "Destructor" << endl;	

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
		//cout << endl << "Add student function called in House.cpp" << endl;
		Student *back = NULL;
		Student *temp = m_pHead;


		while ((temp != NULL) && (stu->getStudentID() > temp->getStudentID()))
		{
			//cout << "." << stu->getStudentID() << "." << ">" << "." << temp->getStudentID() << "." << endl;
			//cout << "Looping through list" << endl;
			back = temp;
			temp = temp->m_pNext;
		}
		if (back==NULL)
		{
			//cout << "Inserting student "<< stu->getStudentID()<<" at head of list" << endl;
			stu->m_pNext = m_pHead; //insert at head of list
			m_pHead = stu;
			return true;
		}

		else
		{
			//Inserting 
			//cout <<"Inserting student "<< stu->getStudentID()<<" somewhere in list" << endl;
			back->m_pNext = stu;
			stu->m_pNext = temp;

			return true;
		}

		cout << "You should not be seeing this error message." << endl;
		return false;
	}
Student* House::RemoveStudent(int studentID)
	{
		//cout << "Remove student called from House.cpp" << endl;

		//cout << "Removing student with ID " << studentID << endl;
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
			//cout << "Temp ID: " << temp->getStudentID() << endl;
			back = temp;
			temp = temp->m_pNext;
			//getchar();
		}

		if (temp==NULL)
		{
			//cout << "Student not found" << endl;
			return NULL;
		} //This means the student was not found

		else if(back == NULL)
		{
			//cout << "Back is null, student removed from head of list" << endl;
			m_pHead = m_pHead->m_pNext;
			return temp;
		}

		else
		{
			//cout << "Deleted from somewhere in list" << endl;
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
			//cout << "temp is >> " << temp << endl;
			//cout << "Checking for student" << endl;
			//cout << "Temp student ID >> " << temp->getStudentID() << endl;
			temp = temp->m_pNext;
		}

		if (temp==NULL)
		{
			//cout << "Student not found" << endl;
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
		Student *temp = m_pHead;

		char tempfirst[64];
		char templast[64];

		// cout << "Name searching for: ";
		// cout << fname << " " << lname << endl;

		temp->getName(tempfirst, templast);
		while(  
				(temp != NULL) 
				&& (strcmp(fname, tempfirst)!=0) 
				&& (strcmp(lname, templast)!=0)
			 )

				{
					//cout << "Looping" << endl;
					temp = temp->m_pNext;
					
					if(temp!=NULL)
					{
						temp->getName(tempfirst, templast);
						//cout << "copying new name" << endl;
					} 

				}

		if (temp==NULL) 
		{
			//cout << "Student not found" << endl;
			return NULL;
		}

		else
		{
			//cout << "Name found" << endl;
			Student *retItem = new Student();
			*retItem = *temp;
			retItem->m_pNext = NULL;
			//*retItem->printStudentInfo();
			return retItem;
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
			cout << "Printing House List" << endl;
			temp = m_pHead;
			while (temp!=NULL)
			{
				temp->printStudentInfo();
				temp = temp->m_pNext;
			}
		}
		cout << endl;
		
	}
void House::SetHouseName(char *name)
	{
		strcpy(m_sHouseName, name);
		// cout << "SetHouseName is running" << endl;
		// cout << "House name set to >>> " << m_sHouseName << endl;
		// cout << "Exit SetHouseName" << endl;
	}
char *House::GetHouseName()
	{
		//cout << "GetHouseName" << endl;
		return m_sHouseName;
	}