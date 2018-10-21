#include <iostream>
#include <string.h>
#include <fstream>
#include "Book.h"
using namespace std;

#ifndef LIBRARY_H
#define LIBRARY_H

class Library
{

private:
	Book *m_pRoot;
	void printAll(Book *rt);
	bool getNextLine(ifstream& inFile, char *line, int lineLen);
	void destroyTree(Book *rt);
	Book *DupNode(Book *T);
	
public:
	Library();
	~Library();
	bool isEmpty();
	bool buildLibrary(const char *fileName);
	bool addBook(Book *newBook);
	Book *removeBook(int bookNum);
	Book *getBookByNumber(int bookNum);
	Book *getBookByTitle(const char *title);
	Book *getBookByTitle(const char *title, Book *rt);
	void printLibrary();
	void printOne(Book *book);




};

#endif