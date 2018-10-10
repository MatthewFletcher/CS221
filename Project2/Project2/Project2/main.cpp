#include <iostream>
#include "Student.h"
#include "HogwartsSWW.h"
#include "House.h"
#include <string.h>

using namespace std;
int main()
{
	Student *stu1 = new Student;

	stu1->setStudentID(12345);

	Student *root = NULL;
	root->m_pNext = 0;

	root = new Student(234, "Harry", "Potter", "OverloadedHouse");

	Student *head = root; 




	

	return 0;
}