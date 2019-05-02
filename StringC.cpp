/*--------------------------------------------------------------------------*/

#include  <string.h>
#include  <iostream>

#include  "StringC.h"

const int trace=0;

/*--------------------------------------------------------------------------*/

int count=0;

/*--------------------------------------------------------------------------*/
/*-------- Constructors, etc -----------------------------------------------*/
/*--------------------------------------------------------------------------*/
// Null Constructor 

StringC::StringC() 
{
   ps=new char[size=1];
  *ps='\0';
   if (trace) std::cout << "---Null Cons : " << count++ << "\n";
}

/*--------------------------------------------------------------------------*/
// Constructor from pointer to char, makes a copy

StringC::StringC(const char pc[]) 
{
  ps=new char[size=1 + strlen(pc)];  // lazy! no error checking
  strcpy(ps,pc);
  if (trace) std::cout << "---Std Cons: " << count++ << " : " << ps << std::endl;
}

/*--------------------------------------------------------------------------*/
// Constructor from pointer to char, makes a copy

StringC::StringC(const int i)
{
  ps=new char[size=i];  // lazy! no error checking
  int j;
  for (j=0; j<size; ++j) ps[j]='\0';
  if (trace) std::cout << "---Std Cons: " << count++ << " : " << ps << std::endl;
}

/*--------------------------------------------------------------------------*/
// Copy constructor, deep copy

StringC::StringC(const StringC & s)
{
  ps=new char[size=1 + strlen(s.ps)]; 
  strcpy(ps,s.ps);
  if (trace) std::cout << "---Copy Cons: " << count++ << " : " << ps << std::endl;
}

/*--------------------------------------------------------------------------*/
// Assignment, deep copy

StringC & 
StringC::operator=(const StringC & s)
{
  if (this != &s) {
    delete[] ps;
    ps=new char[size=1 + strlen(s.ps)]; 
    strcpy(ps,s.ps);
  }

  if (trace) std::cout << "---Assig: " << count << " : " << ps << std::endl;

  return *this;
}

/*--------------------------------------------------------------------------*/
// Destructor

StringC::~StringC()
{
  if (trace) std::cout << "---Dest: " << --count << " : " << ps << std::endl;
  delete[] ps;
  
}

/*--------------------------------------------------------------------------*/
/*------Operations----------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

StringC &
StringC::operator+=(const StringC & s)
{
  char * temp=new char[size=strlen(ps)+strlen(s.ps)+1];
  strcpy(temp,ps);
  strcat(temp,s.ps);
  delete[] ps;
  ps=temp;

  return *this;
}

/*--------------------------------------------------------------------------*/

char & 
StringC::operator[](const int i)
{
  if ((i<0)||(i>=(size-1))) {
    std::cerr << "Error : StringC=" << ps << "   Index out of range : " << i << std::endl;
    exit(1);
  }
  return ps[i];
}

/*--------------------------------------------------------------------------*/

const char & 
StringC::operator[](const int i) const
{
  if ((i<0)||(i>=(size-1))) {
    std::cerr << "Error : StringC=" << ps << "   Index out of range : " << i << std::endl;
    exit(1);
  }
  return ps[i];
}


/*--------------------------------------------------------------------------*/

int 
StringC::Length()
{
  return strlen(ps);
}

/*--------------------------------------------------------------------------*/
/*------Other functions-----------------------------------------------------*/
/*--------------------------------------------------------------------------*/

StringC operator+(const StringC &q, const StringC& p)
{
  StringC temp(q);
  temp += p;
  return temp;
}

/*--------------------------------------------------------------------------*/

std::ostream & operator<<(std::ostream & s, const StringC & st)
{
	s << st.ps;	
	return s;
}

/*--------------------------------------------------------------------------*/

std::istream & operator>>(std::istream & s, StringC & st)
{
	const int bufsize=1024;
	static char buffer[bufsize];

	// s >> buffer;
  
	s.get(buffer, bufsize, '\n');

	StringC temp(buffer);
	st=temp;

	return s;
}

/*--------------------------------------------------------------------------*/
