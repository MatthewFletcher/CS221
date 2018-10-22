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
	// lib->printLibrary();

	char searchTitle[64] = {NULL};
	strcpy(searchTitle, "One Thousand Magical Herbs and Fungi");


	Book *bk = lib->getBookByTitle(searchTitle);
	if (bk != NULL)
	{
		cout << endl;
		cout << "Searching for: " << searchTitle << endl;
		cout << "Function returns: " << bk->Title << endl;
	}
	 else cout << "Fn returned NULL" << endl;

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



	 int foo;
	 cin >> foo;

	return 0;
}