// Use this as the base for your program 4
//==================================================================
// File: Prog4Main.cpp
// Basic file provided by Dr. Coleman for programming assignment 4.
// Look for places where you see TODO: here you are to insert your
//    code.
// Student Name: Matt Fletcher
// 
// This program is entirely my own work.
//==================================================================
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MicroSecondTimer.h"

using namespace std;

#define DATAFILE	"SortData.txt"
#define NUMRECS		10000
#define MAXKEY		99999.0
#define RADIX		10.0

struct SortData
{
    int     key;
    char    strnData[5];
    double  numData;
};

bool ReadData(SortData DA[], int count);
bool getNextLine(ifstream *inF, char *line, int lineLen);
bool CheckData(SortData DataArray[], int count);

// Sorting Algorithm Prototypes
//---------------------------------------------------------
// TODO: Prototype the 5 sort functions you will be testing here
//---------------------------------------------------------

void BubbleSort();
void ProxMapSort();


int main()
{
	SortData	DataArray[NUMRECS];	// Array into which unsorted data will be read
	SortData	DataArray2[NUMRECS]; // Array to hold sorted data if needed
	MicroSecondTimer *mst = new MicroSecondTimer();
	long		startTime, endTime;
	double		totalTime;
	double		averageTime;
	bool		sortError;

	cout << "============================================================\n";
	cout << " PROGRAMMING ASSIGNMENT 4\n";
	cout << " Name: Matt Fletcher \n";
	cout << "============================================================\n";
	cout << "Starting application\n\n";
	cout.flush();

	// TODO:  For each of your 5 sort algorithms do the following
	//---------------------- Begin Sort Algorithm -----------------------
	totalTime = 0.0; // Initialize the time variable
	sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here

		// Stop the microsecond timer
		mst->Stop();
		// Check for error in sorting
		if(!CheckData(DataArray, NUMRECS))
			sortError = true;
		else
			totalTime += mst->getTime(); // Add to the total time for this sort
	}
	// Calculate the average time
	averageTime = totalTime / 5.0;

	// Output the results after checking to be sure the sort worked
	if(sortError)
		cout << "Error in ---Give sort name here---\n\n";
	else
		cout << "---Sort Algorithm Name--- took " << averageTime << " seconds to complete\n\n";
	//------------------------ End Sort Algorithm -----------------------------

	cout << "Finished testing all sorting algorithms.\n";
	cout.flush();
	return 0;
}


//----------------------------------------------------
// ReadData()
// Reads all data from data file into the data array
//----------------------------------------------------
bool ReadData(SortData DArr[], int count)
{
	ifstream	inF;		// Input file stream
	char	line[64];	// Line read from file

	inF.open(DATAFILE, ifstream::in);
    if(!inF.is_open())
    {
        return false;
    }

	for(int i=0; i<count; i++)
	{
		getNextLine(&inF, line, 64);
		DArr[i].key = atoi(strtok(line, " "));
		strcpy(DArr[i].strnData, strtok(NULL, " "));
		DArr[i].numData = atof(strtok(NULL, " "));
	}

	inF.close();
	return true;
}

//-------------------------------------------
// GetNextLine()
// Read the next line from the file.
//-------------------------------------------
bool getNextLine(ifstream *inF, char *line, int lineLen)
{
    bool    done = false;

    while(!done)
    {
        inF->getline(line, lineLen);
        
        if(inF->good())    // If a line was successfully read
        {
           if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else done = true;  // Got a valid data line so return it
        }
        else
        {
            strcpy(line, "");
            return false;  // Flag end of file
        }
    } // end while
	return true;
}

//------------------------------------------------
// Checkdata()
// Check to make sure the data is in sorted order
//------------------------------------------------
bool CheckData(SortData DataArray[], int count)
{
	int i;
	for(i=0; i<(count-1); i++)
	{
		if(DataArray[i].key > DataArray[i+1].key)
		{
			return false;
		}
	}
	return true;
}

//=======================================================================
//         TODO: PUT YOUR SORTING ALGORITHM IMPLEMENTATIONS HERE
//=======================================================================
