//------------------------------------------------------------------
// Book.h
//
// Define the Book structure for use in programming assignment 3
// Author: Dr. Rick Coleman
//------------------------------------------------------------------
#ifndef BOOK_H
#define BOOK_H

struct Book
{
    int     bookNumber;
    char    Title[128];
    char    Author[65];
    Book    *left;
    Book    *right;
};

#endif
