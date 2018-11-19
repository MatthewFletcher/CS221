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

//Bubble
void BubbleSort(SortData DataArray[], int count);
//ProxMap
 void ProxmapSort(SortData DataArray[], SortData DataArray2[],int count);
  int Hash(int key, int KeyMax, int KeyMin, int count);
   void ProxMapInsertionSort(SortData DataArray[], SortData *theStruct, int startIdx, int listLen);


//Insertion
void InsertSort(SortData DataArray[], int count);

//QuickSort
void QuickSort(SortData DataArray[], int startIdx, int endIdx);
void Partition(SortData DataArray[], int *I, int *J);


//MergeSort
void MergeSort(SortData DataArray[], int startIdx, int endIdx);
void Merge(SortData Array1[], int start1, int end1,int start2, int end2);


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


	{
	//---------------------- Begin Sort Algorithm -----------------------
	totalTime = 0.0; // Initialize the time variable
	sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{


		//COPY PASTE THIS SECTION OF CODE 5 TIMES, ONE FOR EACH SORT ALGORITHM
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		BubbleSort(DataArray, NUMRECS);

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
		cout << "Error in ---BUBBLESORT---\n\n";
	else
		cout << "---BUBBLESORT--- took " << averageTime << " seconds to complete\n\n";
	//------------------------ End Sort Algorithm -----------------------------
	}

		//---------------------- Begin Sort Algorithm -----------------------
	totalTime = 0.0; // Initialize the time variable
	sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{


		//COPY PASTE THIS SECTION OF CODE 5 TIMES, ONE FOR EACH SORT ALGORITHM
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		ProxmapSort(DataArray, DataArray2,NUMRECS);

		// Stop the microsecond timer
		mst->Stop();
		// Check for error in sorting
		if(!CheckData(DataArray2, NUMRECS))
			sortError = true;
		else
			totalTime += mst->getTime(); // Add to the total time for this sort
	}
	// Calculate the average time
	averageTime = totalTime / 5.0;

	// Output the results after checking to be sure the sort worked
	if(sortError)
		cout << "Error in ---PROXMAPSORT---\n\n";
	else
		cout << "---PROXMAPSORT--- took " << averageTime << " seconds to complete\n\n";
	//------------------------ End Sort Algorithm -----------------------------



		//---------------------- Begin Sort Algorithm -----------------------
	totalTime = 0.0; // Initialize the time variable
	sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{


		//COPY PASTE THIS SECTION OF CODE 5 TIMES, ONE FOR EACH SORT ALGORITHM
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		InsertSort(DataArray, NUMRECS);

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
		cout << "Error in ---INSERTSORT---\n\n";
	else
		cout << "---INSERTSORT--- took " << averageTime << " seconds to complete\n\n";
	//------------------------ End Sort Algorithm -----------------------------



		//---------------------- Begin Sort Algorithm -----------------------
	totalTime = 0.0; // Initialize the time variable
	sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{


		//COPY PASTE THIS SECTION OF CODE 5 TIMES, ONE FOR EACH SORT ALGORITHM
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		QuickSort(DataArray, 0, NUMRECS);

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
		cout << "Error in ---QUICKSORT---\n\n";
	else
		cout << "---QUICKSORT--- took " << averageTime << " seconds to complete\n\n";
	//------------------------ End Sort Algorithm -----------------------------



		//---------------------- Begin Sort Algorithm -----------------------
	totalTime = 0.0; // Initialize the time variable
	sortError = false; // Initialize the error flag
	// For each of 5 runs on this algorithm
	for(int i=0; i<5; i++)
	{


		//COPY PASTE THIS SECTION OF CODE 5 TIMES, ONE FOR EACH SORT ALGORITHM
		// Read the data.  You must do this before each sort
		if(!ReadData(DataArray, NUMRECS))
		{
			cout << "Failed to read data file.\n Program Terminated\n";
			return 0;
		}
		// Start the microsecond timer
		mst->Start();

		// TODO: Call the sort function here
		MergeSort(DataArray, 0, NUMRECS);

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
		cout << "Error in ---MERGESORT---\n\n";
	else
		cout << "---MERGESORT--- took " << averageTime << " seconds to complete\n\n";
	//------------------------ End Sort Algorithm -----------------------------




	//##########################END ALL SORT ALGORITHMS############################

	cout << "Finished testing all sorting algorithms.\n";
	cout.flush();
	getchar();
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
			//cout << "Error on line " << i << endl;
			return false;
		}
	}
	return true;
}

//=======================================================================
//         TODO: PUT YOUR SORTING ALGORITHM IMPLEMENTATIONS HERE
//=======================================================================

/***************************************/
/* BubbleSort()                        */
/*                                     */
/* Sort records on integer key using   */
/*  a bubble sort.                     */
/***************************************/
void BubbleSort(SortData DataArray[], int count)
{
    int         i, j;
    SortData  temp;

    for(i=0; i<count; i++)
    {
        for(j=0; j<(count-i - 1); j++)
        {
            if(DataArray[j].key > DataArray[j+1].key)
             {
                 temp = DataArray[j];
                 DataArray[j] = DataArray[j+1];
                 DataArray[j+1] = temp;
             }

        }
    }
}




 /***************************************/
 /* ProxmapSort()                       */
 /*                                     */
 /* Sort records on integer key using   */
 /*  a proxmap sort.                    */
 /***************************************/
 void ProxmapSort(SortData DataArray[], SortData DataArray2[],int count)
	 {
		 int i;
		 int HitList[NUMRECS];
		 int Hidx;                  /* Hashed index */
		 int ProxMap[NUMRECS];
		 int RunningTotal;          /* Number of hits */
		 int Location[NUMRECS];
		 int KeyMax, KeyMin;        /* Used in Hash() */

		 /* Initialize hit list and proxmap */
		 for(i=0; i<count; i++)
		 {
			 HitList[i] = 0;           /* Init to all 0 hits */
			 ProxMap[i] = -1;          /* Init to all unused */
			 DataArray2[i].key = -1;   /* Init to all empty */
		 }
		  /* Find the largest key for use in computing the hash */
		 KeyMax = 0;        /* Guaranteed to be less than the smallest key */
		 KeyMin = 32767;    /* Guaranteed to be more than the largest key */
		 for(i=0; i<count; i++)
		 {
			 if(DataArray[i].key > KeyMax) KeyMax = DataArray[i].key;
			 if(DataArray[i].key < KeyMin) KeyMin = DataArray[i].key;
		 }
		  /* Compute the hit count list (note this is not a collision count, but
			 a collision count+1 */
		 for(i=0; i<count; i++)
		 {
			 Hidx = Hash(DataArray[i].key, KeyMax, KeyMin, count); /* Calculate hash index */
			 Location[i] = Hidx; /* Save this for later. (Step 1) */
			 HitList[Hidx]++;    /* Update the hit count (Step 2) */
		 }
		  /* Create the proxmap from the hit list. (Step 3) */
		 RunningTotal = 0;        /* Init counter */
		 for(i=0; i<count; i++)
		 {
			 if(HitList[i] > 0)    /* There were hits at this address */
			 {
				 ProxMap[i] = RunningTotal;    /* Set start index for this set */
				 RunningTotal += HitList[i];
			 }
		 }
		 // NOTE: UNCOMMENT THE FOLLOWING SECTION TO SEE WHAT IS IN THE ARRAYS, BUT
		 //       COMMENT IT OUT WHEN DOING A TEST RUN AS PRINTING IS VERY SLOW AND
		 //       WILL RESULT IN AN INACCURATE TIME FOR PROXMAP SORT.
		 /* ---------------------------------------------------- 
		 // Print HitList[] to see what it looks like
		 printf("HitList:\n");
		 for(i=0; i<count; i++)
			 printf("%d ", HitList[i]);
		 printf("\n\n");
		 getch();
		  // Print ProxMap[] to see what it looks like
		 printf("ProxMap:\n");
		 for(i=0; i<count; i++)
			 printf("%d ", ProxMap[i]);
		 printf("\n\n");
		 getch();
		  // Print Location[] to see what it looks like
		 printf("Location:\n");
		 for(i=0; i<count; i++)
			 printf("%d ", Location[i]);
		 printf("\n\n");
		 getch();
		 ---------------------------------------------  */
		 /* Move the keys from A1 to A2 */
		 /* Assumes A2 has been initialized to all empty slots (key = -1)*/
		 for(i=0; i<count; i++)
		 {
			 if((DataArray2[ProxMap[Location[i]]].key == -1))  /* If the location in A2 is empty...*/
			 {
				 /* Move the structure into the sorted array */
				 DataArray2[ProxMap[Location[i]]] = DataArray[i];
			 }
			 else    /* Insert the structure using an insertion sort */
			 {
				 ProxMapInsertionSort(DataArray2, &DataArray[i], ProxMap[Location[i]], HitList[Location[i]]);
			 }
		 }
	  }

	 /***************************************/
	 /* Hash()                              */
	 /*                                     */
	 /* Calculate a hash index.             */
	 /***************************************/
	 int Hash(int key, int KeyMax, int KeyMin, int count)
	 {
		 float    keyFloat;      /* Map integer key to float in the range 0 <= key < 1 */
		 keyFloat = (float)(key - KeyMin) / (float)(1 + KeyMax - KeyMin);
		 /* Map float key to indices in range 0 <= index < count */
		 return((int)floor(count * keyFloat));
	 }

	 /***************************************/
	 /* ProxMapInsertionSort()              */
	 /*                                     */
	 /* Use insertion sort to insert a      */
	 /*   struct into a subarray.           */
	 /***************************************/
	 void ProxMapInsertionSort(SortData DataArray[], SortData *theStruct,
								int startIdx, int listLen)
	 {
		 /* Args:    DataArray - Partly sorted array
					 *theStruct - Structure to insert
					 startIdx - Index of start of subarray
					 listLen - Number of items in the subarray */
		 int i;      /* Find the end of the subarray */
		 i = startIdx + listLen - 1;
		 while(DataArray[i-1].key == -1) i--;          /* Find the location to insert the key */
		  while((DataArray[i-1].key > theStruct->key) && (i > startIdx))
		 {
			 DataArray[i] = DataArray[i-1];
			 i--;
		 }
		  /* Insert the key */
		  DataArray[i] = *theStruct;
	 }



/***************************************/
/* InsertSort()                        */
/*                                     */
/* Sort records on integer key using   */
/*  an insertion sort.                 */
/***************************************/
void InsertSort(SortData DataArray[], int count)
{
    int i, j;
    SortData temp;
    int NotDone;
    int Key;
	
    for(i=1; i<count; i++)
    {
        Key = DataArray[i].key;
        j = i;
        NotDone = (DataArray[j-1].key > Key);

        temp = DataArray[j]; /* Remove and hold the one to be moved */

        while(NotDone)
        {
            /* Slide all others to the right */
            DataArray[j] = DataArray[j-1];
            j--;
            if(j > 0)
                NotDone = (DataArray[j - 1].key > Key);
            else
                NotDone = FALSE;
        }

        /* Put the removed record into it's correct slot */
        DataArray[j] = temp;
    }
}




/***************************************/
/* QuickSort()                         */
/*                                     */
/* Sort records on integer key using   */
/*  a quick sort.                      */
/***************************************/
void QuickSort(SortData DataArray[], int startIdx, int endIdx)
{
    int           i, j;

    if(startIdx < endIdx)
    {
        i=startIdx;
        j = endIdx;
        Partition(DataArray, &i, &j);
        /* On return i will be greater than j */
        QuickSort(DataArray, startIdx, j);
        QuickSort(DataArray, i, endIdx);
    }

}

	/***************************************/
	/* Partition()                         */
	/*                                     */
	/* Partition array into two sections   */
	/*  for quick sorting.                 */
	/***************************************/
	void Partition(SortData DataArray[], int *I, int *J)
	{
		int           Pivot;    /* Key data */
		SortData    temp;

		Pivot = DataArray[(*I + *J)/2].key; /* Choose an arbidrary pivot point like center of array */
		/* Divide the array into < and > Pivot */
		do
		{
			/* Find leftmost I such that DataArray[I].key > Pivot */
			while(DataArray[*I].key < Pivot) (*I)++;

			/* Find rightmost J such that DataArray[J].key < Pivot */
			while(DataArray[*J].key > Pivot) (*J)--;

			/* If i and J didn't cross over one another, then swap the structs */
			if(*I <= *J)
			{
				temp = DataArray[*I];
				DataArray[*I] = DataArray[*J];
				DataArray[*J] = temp;
				(*I)++;            /* Move i one space to the right */
				(*J)--;            /* Move j one space to the left */
			}
		}
		while(*I <= *J);
	}




/***************************************/
/* MergeSort()                         */
/*                                     */
/* Sort records on integer key using   */
/*  a merge sort.                      */
/***************************************/
void MergeSort(SortData DataArray[], int startIdx, int endIdx)
{
    int        start, end;

    if(startIdx < endIdx)    // If there is more than one item to sort 
    {
        start = startIdx;
        end = startIdx + ((endIdx - startIdx) / 2);
        MergeSort(DataArray, start, end);
        start = end + 1;
        end = endIdx;
        MergeSort(DataArray, start, end);
        Merge(DataArray, startIdx, start - 1, start, end);
    }
}

	/***************************************/
	/* Merge()                             */
	/* Merge the two sections of the array */
	/*  using Insertion Sort treating one  */
	/*  section as the sorted section and  */
	/*  the other as the unsorted section. */
	/***************************************/
	void Merge(SortData Array1[], int start1, int end1, 
			  int start2, int end2)
	{
		 int          i, j;
		 SortData     temp;
		 int          NotDone;
		 int          Key;

		 for(i=start2; i<=end2; i++)
		 {
			  Key = Array1[i].key;
			  j = i;
			  NotDone = (Array1[j-1].key > Key);
			  temp = Array1[j]; 
			  while(NotDone)
			  {
				   // Slide all others to the right 
				   Array1[j] = Array1[j-1];
				   j--;
				   if(j > start1)
						NotDone = (Array1[j - 1].key > Key);
				   else
						NotDone = FALSE;
			  }
			  // Put removed record into correct slot
			  Array1[j] = temp;
		 }
	}


