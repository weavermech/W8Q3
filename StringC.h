/*--------------------------------------------------------------------------*/
#ifndef STRINGC_H
#define STRINGC_H
 
#include  <iostream>
#include <stdlib.h>

/*--------------------------------------------------------------------------*/
// 
// The physical size of the string is how much memory is allocated
// The logical length of a string is the number of characters before
// a string termination character 0.
//
// The user may shorten the string by inserting a termination character
// but cannot modify the final termination character to make it longer.
// 

class StringC 
{
    char *           ps;
    int              size;
    static int        count;
  
  public:  
    
    // Constructors,  destructor, assignment
    // -------------------------------------
 
    StringC();
    // Default Constructor 
 
    StringC(const char pc[]);
    // Constructor from pointer to char, makes a copy
 
    StringC(const int i);
    // Constructor from specified size, initialized to termination characters
 
    StringC(const StringC & s);
    // Copy constructor
 
    StringC & operator=(const StringC & s);
    // Assignment 
 
    ~StringC();
    // Destructor
 
    // Operations
    // ----------
 
    char & operator[](const int i);
    // this is a put char command - the string termination 
    // cannot be overwritten

    const char & operator[](const int i) const;
    // this is a get character command

	void Print(){std::cout << ps << std::endl;}
	// Prints the string to stdout

    int Length();
    // return number of characters excluding trailing 0
 
    StringC & operator+=(const StringC & s);
    // concatenate

    friend std::ostream & operator<<(std::ostream & s, const StringC & st);
    friend std::istream & operator>>(std::istream & s, StringC & st);
};
 
// -------------------------------------------------------------------------

StringC operator+(const StringC &q, const StringC& p);
// concatenates 2 strings

std::ostream & operator<<(std::ostream & s, const StringC & st);
std::istream & operator>>(std::istream & s, StringC & st);

#endif
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/




