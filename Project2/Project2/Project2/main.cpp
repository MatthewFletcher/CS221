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

	Student *stu5 = new Student(5, "Ginny1", "Weasley1", "Gryffindor");

	Student *stu6 = new Student(6, "Ginny2", "Weasley2", "Gryffindor");

	Student *stu7 = new Student(7, "Ginny3", "Weasley3", "Gryffindor");

	Student *head = stu1->m_pNext;

	House *h1 = new House();
	h1->SetHouseName("Gryffindor");

	cout << "Finding student with id 1" << endl;
	h1->FindStudent(1);








	h1->AddStudent(stu7);
	h1->AddStudent(stu6);
	h1->AddStudent(stu5);
	h1->AddStudent(stu4);
	h1->AddStudent(stu3);
	h1->AddStudent(stu2);
	h1->AddStudent(stu1);



	h1->PrintHouseList();

	h1->RemoveStudent(3);
	h1->RemoveStudent(4);






	return 0;
}