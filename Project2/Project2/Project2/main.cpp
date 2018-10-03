#include <iostream>
#include "Student.h"
#include "HogwartsSWW.h"
#include "House.h"
#include <string.h>

using namespace std;
int main()
{
	Student *s1 = new Student;

	s1->setStudentID(12345);

	delete s1;

	cout << s1->getStudentID() << endl;

	Student *s2 = new Student;
	s1->m_pNext = s2;

	s1->Clone();


	return 0;
}