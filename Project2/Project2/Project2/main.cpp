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


	House *h = new House();

	return 0;
}