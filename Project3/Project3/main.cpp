#include <iostream>
#include "Library.h"

using namespace std;

int main()
{
	Library *lib = new Library();

	int choice;

	cout << "1. Test DB" << endl;
	cout << "2. Full DB" << endl;

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
	lib->printLibrary();

	// //Testing Getbookbynumber
	// Book *bk;
	// bk= lib->getBookByNumber(12485);
	// cout << bk->Title << "\t" << endl;



	// int bookstoremove[] = {12385, 12365, 12405, 12355,12375,12395,12415, 99999};


	// Book *bk;

	// for (int i = 0; i <=7; ++i)
	// {
	// 	bk = lib->removeBook(bookstoremove[i]);
		
	// 	if (bk!= NULL)
	// 	cout << "Removed Book " << bookstoremove[i] << ": " << bk->Title << endl;

	// 	cout << endl;
	// }


	return 0;
}