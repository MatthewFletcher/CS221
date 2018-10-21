#include <iostream>
#include <string.h>
#include "Student.h"
#include "House.h"
#include "HogwartsSWW.h"


#include <fstream>
using namespace std;

// Prototype functions to read lines from the file and build the houses
bool getNextLine(char *line, int lineLen);
void buildStudentLists(HogwartsSWW *h);

ifstream inFile;	// File to read from

// Define the name of the file to read from
#define STUDENT_FILE "students.txt"


int main()
{

	// House *hptr = new House();
	// h->SetHouseName("Gryffindor");
	// char tempName[64];
	// strcpy(tempName, h->GetHouseName());
	// if (strcmp(tempName, "Gryffindor") == 0)
	// {
	// 	cout << "Test successful" << endl;
	// }

	// delete(h);



	 HogwartsSWW *hptr = new HogwartsSWW();
	buildStudentLists(hptr);


	hptr->PrintHouses();

	// Student *stu1 = new Student(1, "Foo1", "McFoo1", "Gryffindor");
	// Student *stu2 = new Student(2, "Foo2", "McFoo2", "Gryffindor");
	// Student *stu3 = new Student(3, "Foo3", "McFoo3", "Gryffindor");
	// Student *stu4 = new Student(4, "Foo4", "McFoo4", "Gryffindor");


	// hptr->AddStudent(stu1);
	// hptr->AddStudent(stu2);
	// hptr->AddStudent(stu3);
	// hptr->AddStudent(stu4);



	// Student *s;

	// cout << "FIND BY ID" << endl;
	// for (int i = 1; i <= 5; ++i)
	// {
		
	// 	if (i == 5)
	// 	{
	// 		cout << "Testing out of range" << endl;
	// 	}
	
	//  	s = hptr->FindStudent(i);

	// 	if ((s!=NULL) && (s->getStudentID() == i))
	// 	{
	// 		cout << "Findstudent for id " << i << " worked" << endl;
	// 	}
	//  }



	// cout << "FIND BY NAME" << endl;
	// char mName[32], wName[32];
	// s = hptr->FindStudent("Foo1", "McFoo1");
	// if(s!=NULL)
	// {
	// 	s->getName(mName, wName);
	// 	if((strcmp(mName, "Foo1") == 0) && (strcmp(wName, "McFoo1") == 0))
	// 	{
	// 		cout << "Name find successful" << endl;
	// 	}
	// 	else cout << "FAILED  " << endl;
	// }
	// else
	// {
	// 	cout << "Name find failed" << endl;
	// }





	// //TESTING CLONE FUNCTION
	// Student *stu10 = new Student (9999, "Plz", "CloneMe", "Gryffindor");
	// stu10->printStudentInfo();
	// Student *stuclone = new Student();
	// cout << "Running clone function" << endl;
	// stuclone = stu10->Clone();
	// delete stu10;
	// stuclone->printStudentInfo();







	return 0;
}




void buildStudentLists(HogwartsSWW *h)
{ 	
	char line[128];// Declare a character array to hold lines read from file
	Student *s;
	char fname[32];
	char lname[32];
	int numClasses;

	// Open the data file
	inFile.open(STUDENT_FILE, ifstream::in); 
	if(!inFile.is_open())
	{
		cout << "Failed to open file: " << STUDENT_FILE << " application terminating.\n";
		exit(0);
    }

    cout << "File opened successfully" << endl;


	while(getNextLine(line, 128))
	{
		s = new Student();		// Create a new student
		s->setStudentID(atoi(line));	// Set the ID

		// Read and parse student name
		getNextLine(line, 128);
		sscanf(line, "%s %s", fname, lname);
		s->setName(fname, lname);

		// Read and parse house name
		getNextLine(line, 128);
		s->setHouse(line);

		// Read all classes
		getNextLine(line, 128);	// Read and parse number of classes
		numClasses = atoi(line);
		for(int i=0; i<numClasses; i++)
		{
			getNextLine(line, 128); // Get name of class
			s->setClass(i, line);
			getNextLine(line, 128); // Get grade
			s->setGrade(i, atoi(line));
		}

		// Add this student to the school
		h->AddStudent(s);
		//cout << "Adding student ID: "<< s->getStudentID() << endl;
	}
}

//-------------------------------------------
// GetNextLine()
// Read the next line from the file.
//-------------------------------------------
bool getNextLine(char *line, int lineLen)
{
    int    done = false;

    while(!done)
    {
        inFile.getline(line, lineLen);
        
        if(inFile.good())    // If a line was successfully read
        {
           if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else done = true;    // Got a valid data line so return 
                                 // with this line
        }
        else
        {
            strcpy(line, "");
            return false;
        }
    } // end while
    return true;
}