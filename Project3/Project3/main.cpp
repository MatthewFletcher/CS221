#include <iostream>
#include "Library.h"

using namespace std;

int main()
{
	Library *lib = new Library();
	lib->buildLibrary("testDB.txt");
	
	// // TESTING Print Library
	//lib->printLibrary();

	// //Testing Getbookbynumber
	// Book *bk;
	// bk= lib->getBookByNumber(12485);
	// cout << bk->Title << "\t" << endl;



	int bookstoremove[] = {12385, 12365, 12405, 12355,12375,12395,12415};


	Book *bk;

	for (int i = 0; i <=6; ++i)
	{
		bk = lib->removeBook(bookstoremove[i]);
		
		if (bk!= NULL)
		cout << "Removed Book " << bookstoremove[i] << ": " << bk->Title << endl;

		cout << endl;
	}


	return 0;
}