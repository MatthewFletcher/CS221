#include <iostream>
#include <string.h>
#include "Student.h"
#include "House.h"
#include "HogwartsSWW.h"

using namespace std;


int main()
{



	Student *stu1 = new Student(1, "Harry", "Potter", "Gryffindor");
	

	Student *stu2 = new Student(2, "Hermione", "Granger", "Gryffindor");

	Student *head = stu1->m_pNext;

	House *h1 = new House();
	h1->SetHouseName("Gryffindor");

	h1->FindStudent(12345);


	h1->AddStudent(stu1);

	h1->AddStudent(stu2);






	return 0;
}