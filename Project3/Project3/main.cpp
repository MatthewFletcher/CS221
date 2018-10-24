#include <iostream>
#include "Library.h"

using namespace std;

int main()
{
	Library *lib = new Library();

	int choice;

	cout << "1. Test DB" << endl;
	cout << "2. Full DB" << endl;
	cout << "Enter choice >>> ";
	cin >> choice;

	if (choice==1)
	{
		lib->buildLibrary("testDB.txt");
	
	}
	else if(choice ==2)
	{
		lib->buildLibrary("HWBookDB.txt");
	
	}

	else return 0;
	
	// // TESTING Print Library
	//lib->printLibrary();


	cout << "Testing search by title" << endl;
	char searchTitle[64] = {NULL};
	strcpy(searchTitle, "Broken Balls: When Fortunes Turn Foul");


	Book *bk = lib->getBookByTitle(searchTitle);
	if (bk != NULL)
	{
		cout << endl;
		cout << "Searching for: " << searchTitle << endl;
		cout << "Function returns: " << bk->Title << endl;
	}
	 else cout << "Fn returned NULL" << endl;




	int booklist[] = {12385, 12365, 12405, 12355,12375,12395,12415, 99999};

	//Testing Getbookbynumber
	

	cout << "Testing getBookByNumber" << endl;
	for (int i = 0; i <=7; ++i)
	{

		cout << "Searching for book #" << booklist[i] << "\t";
		bk= lib->getBookByNumber(booklist[i]);

		if (bk!=NULL) cout << bk->Title << "\t" << endl;
		else cout << "Book Not Found" << endl;
		Book *bk;
	}


	cout << "\n Testing remove book by number" << endl;
	for (int i = 0; i <=7; ++i)
	{
		bk = lib->removeBook(booklist[i]);
		
		if (bk!= NULL)
		cout << "Removed Book " << booklist[i] << ": " << bk->Title << endl;

		else cout << "Book to remove not found" << endl;

		cout << endl;
	}




	return 0;
}