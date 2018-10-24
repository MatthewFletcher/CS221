#include "Library.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;



//Code obtained from code vault
void Library::printAll(Book *rt)
	{
		if(rt != NULL)
			{
				printAll(rt->left);
				printOne(rt);
				printAll(rt->right);
			}
	}

//Code obtained from code vault
bool Library::getNextLine(ifstream& inFile, char *line, int lineLen)
	{
	int	done = false;
	while(!done)
	{
		inFile.getline(line, lineLen);		
		if(inFile.good())	// If a line was successfully read
		{
			if(strlen(line) == 0)  // Skip any blank lines
				continue;
			else if(line[0] == '#')  // Skip any comment lines
				continue;
			else done = true;	// Got a valid data line so return with this line
		}
		else
		{
			strcpy(line, "");
			return false;	// Flag end of file with null string and return false
		}
	} // end while
	return true; // Flag successful read
	}

//Code obtained from code vault
void Library::destroyTree(Book *rt)
	{
		if(rt==NULL) return;  // Nothing to clear
		if(rt->left != NULL) destroyTree(rt->left); // Clear left sub-tree
		if(rt->right != NULL) destroyTree(rt->right); // Clear right sub-tree
		delete rt;	// Destroy this node
		return;
	}

//Code obtained from code vault
bool Library::isEmpty()
{
	return (m_pRoot==NULL);
}


Library::Library()
	{
		m_pRoot = NULL;
		
	}

Library::~Library()
	{
		destroyTree(m_pRoot);
	}


bool Library::buildLibrary(const char *fileName)
	{
	ifstream  inFile;
	Book *bk;
	char line[128];
	
	inFile.open(fileName, ifstream::in); 
	if(!inFile.is_open())
	{
		// inFile.is_open() returns false if the file could not be found or
		//	if for some other reason the open failed.
		cout << "Unable to open file " << fileName << ". \nProgram terminating...\n";
		return false;
	}

	//first time reading file: Set GraphNode ID and Data
	while (getNextLine(inFile, line, 127)) //while the next line is readable
	{		
		bk = new Book();
		bk->left = bk->right = NULL;
		bk->bookNumber = atoi(line);

		// Read the book title
		getNextLine(inFile, line, 127);
		strcpy(bk->Title, line);

		// Read the author
		getNextLine(inFile, line, 127);
		strcpy(bk->Author, line);

		// Add this book to the tree
		addBook(bk);
	}
	return true;
	}

//Code obtained from code vault
bool Library::addBook(Book *newBook)
	{
	Book *temp;
	Book *back;

	temp = m_pRoot;
	back = NULL;

	while(temp != NULL) // Loop till temp falls out of the tree 
	{
		back = temp;
		if(newBook->bookNumber < temp->bookNumber)
			temp = temp->left;
		else
			temp = temp->right;
	}

	// Now attach the new node to the node that back points to 
	if(back == NULL) // Attach as root node in a new tree 
		m_pRoot = newBook;
	else
	{
		if(newBook->bookNumber < back->bookNumber)
			back->left = newBook;
		else
			back->right = newBook;
	}
   return(true);
	}

//Code obtained from code vault
Book *Library::removeBook(int bookNum)
	{
		Book *back;
		Book *temp;
		Book *delParent;	// Parent of node to delete
		Book *delNode;	  // Node to delete

		temp = m_pRoot;
		back = NULL;

		// Find the node to delete 
		while((temp != NULL) && (bookNum != temp->bookNumber))
		{
			back = temp;
			if(bookNum < temp->bookNumber)
				temp = temp->left;
			else
				temp = temp->right;
		}

		if(temp == NULL) // Didn't find the one to delete 
		{
			cout << "Book not found" << endl;
			return NULL;
		}
		else
		{
			// Use these pointers in case we need to reuse temp and back below
			delNode = temp;
			delParent = back;
		}

		// Case 1: Deleting node with no children or one child 
		if(delNode->right == NULL)
		{
			if(delParent == NULL)	// If deleting the m_pRoot	
			{
				m_pRoot = delNode->left;

				cout << "Deleting Root" << endl;
				return delNode;
			}
			else
			{
				if(delParent->left == delNode)
					delParent->left = delNode->left;
				else
					delParent->right = delNode->left;
				cout << "Deleting node with no children or 1 child" << endl;
				return delNode;
			}
		}
		else if(delNode->left == NULL)	// Only 1 child and it is on the right
		{
			if(delParent == NULL)	// If deleting the m_pRoot	
			{
				cout << "Deleting Root with 1 child on right" << endl;
				m_pRoot = delNode->right;
				return delNode;
			}
			else
			{
				cout << "Deleting node with 1 child on right" << endl;
				if(delParent->left == delNode)
					delParent->left = delNode->right;
				else
					delParent->right = delNode->right;
				return delNode;
			}
		}
		else // Case 2: Deleting node with two children 
		{
			cout  << "Deleting Node with 2 children" << endl;
			// Create a duplicate to return after overwriting the node to remove
			Book *retNode = this->DupNode(delNode);

			// Find the replacement value.  Locate the node  
			// containing the largest value smaller than the 
			// key of the node being deleted.				
			temp = delNode->left;
			back = delNode;
			while(temp->right != NULL)
			{
				back = temp;
				temp = temp->right;
			}
			// Copy the replacement values into the node to be deleted 
			delNode->bookNumber = temp->bookNumber;
			strcpy(delNode->Title, temp->Title);
			strcpy(delNode->Author, temp->Author);

			// Remove the replacement node from the tree 
			if(back == delNode)
				back->left = temp->left;
			else
				back->right = temp->left;
			delete temp;		// Delete this one that is now "moved"
			return retNode;		// Return the copy
		}
	
	}
//Code obtained from code vault
Book *Library::getBookByNumber(int bookNum)
	{
		Book *temp;

		temp = m_pRoot;
		while((temp != NULL) && (temp->bookNumber != bookNum))
		{
			if(bookNum < temp->bookNumber)
				temp = temp->left;  // Search key comes before this node.
			else
				temp = temp->right; // Search key comes after this node 
		}
		if(temp == NULL) return temp;	// Search key not found
		else
			return(DupNode(temp));	// Found it so return a duplicate
	}


//Public Function
Book *Library::getBookByTitle(const char *title)
	{

		return getBookByTitle(title, m_pRoot);
	}


//Private Function
//Using an In Order Traversal 
/*
if ( rt!= NULL) {
Left = getBookByTitle(title, rt->left);
If left is not null
Return left
// It should stop here if it found it in left
Right = the above but with rt->right
If right is not null
Return right
If still couldn't find it 
Return null
*/
Book *Library::getBookByTitle(const char *title, Book *rt)
    {

  	if (rt==NULL) return NULL;
  	cout << "Looking at book " << rt->Title << endl;

		if(strcmp(title, rt->Title) == 0)
		{
			return rt;
		}

		else
		{
			Book *temp = getBookByTitle(title, rt->left);

			if (temp!=NULL)
			{
				return temp;
			}
			else return getBookByTitle(title, rt->right);
		}

		return getBookByTitle(title, rt->right); 

    }

void Library::printLibrary()
{
	cout << "\n=====================================================================\n";
	cout << "					  NODES CONTAINED IN THE TREE\n";
	cout << "=======================================================================\n";
	cout << right << setw(6)  << "Book #"<< left << setw(64) << "\tTitle" << setw(28) << "Author" << endl;

	printAll(m_pRoot);
	cout << "============================================================\n";
}


void Library::printOne(Book *book)
	{

		cout << setw(5) << book->bookNumber << "\t" << setw(64) << book->Title << book->Author <<  endl;
	}


//Code obtained from code vault
Book *Library::DupNode(Book * T)
{
	Book *dupNode;

	dupNode = new Book();
	*dupNode = *T;	// Copy the data structure
	dupNode->left = NULL;	// Set the pointers to NULL
	dupNode->right = NULL;
	return dupNode;
}








