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

	Student *stu3 = new Student(3, "Ron", "Weasley", "Gryffindor");

	Student *stu4 = new Student(4, "Ginny", "Weasley", "Gryffindor");

	Student *head = stu1->m_pNext;

	House *h1 = new House();
	h1->SetHouseName("Gryffindor");

	h1->FindStudent(12345);


	h1->AddStudent(stu1);

	h1->AddStudent(stu2);

	h1->AddStudent(stu3);

	h1->AddStudent(stu4);

	h1->RemoveStudent(3);
	h1->RemoveStudent(4);






	return 0;
}