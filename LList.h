/*--------------------------------------------------------------------------*/

#ifndef LIST_H
#define LIST_H
 
/*--------------------------------------------------------------------------*/
// A double linked list class. The data is incorporated into NodeC
// which is not accessible to the user. (private constructor)
//
// The ListC has a head element, used to detect empty lists/invalid elements.
// It has only minimal access, and access is mainly achieved through
// a separate iterator class.
//
// Caution: The iterator can be become stale if the element it 
// points to is deleted.
// 
/*--------------------------------------------------------------------------*/
 
template<class T> class NodeC;
template<class T> class ListC;
template<class T> class IterC;

/*--------------------------------------------------------------------------*/

template<class T> class NodeC
{

  private:

    T                data;
    NodeC<T>*        next;
    NodeC<T>*        prev;

  private:

    NodeC();
    // Null Constructor 
 
    NodeC(const NodeC<T> & s);
    // Copy constructor
 
    NodeC<T> & operator=(const NodeC<T> & s);
    // Assignment 
 
    ~NodeC();
    // Destructor
 
  friend class IterC<T>;
  friend class ListC<T>;
};

/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

template<class T> class ListC
{
    NodeC<T>*        head;

  public:
 
    // Constructors,  destructor, assignment
    // -------------------------------------
 
    ListC();
    // Null Constructor 
 
    ListC(const ListC & s);
    // Copy constructor

    ListC<T> & operator=(const ListC<T> & s);
    // Assignment 
 
    ~ListC();
    // Destructor
 
    // Operations
	bool operator==(ListC<T> & itb);

    void InsFirst(T & d);
    void InsLast(T & d);

    int FindPos(T & d);
    // returns the integer position of the element in the list, 0 if not there

  private: 

    void InsAfter(NodeC<T>*, T & d);
    // An insert needing only a pointer
    
    void Delete(NodeC<T>*);
    // delete
    
  friend class IterC<T>;
};

/*--------------------------------------------------------------------------*/

template<class T>
class IterC
{
    ListC<T>&     list;
    NodeC<T>*     pnode;

  public:
 
  // Constructors,  destructor, assignment
  // -------------------------------------
 
    // no null constructor

    IterC(ListC<T>& list);
    // Constructor, list must be specified, iterator points to first 
 
    IterC(const IterC & s);
    // Copy constructor
 
    IterC<T> & operator=(const IterC<T> & s);
    // Assignment 
 
    ~IterC();
    // Destructor
 
  // Operations
  // ----------
 
    T & Data();
    // returns a reference to the data, 
    // access to data in header element is not an error

    IterC<T> & Delete(void);
    // delete this node, move iterator up one

    IterC<T> & InsAfter(T& d);
    // Insert data after present position, move iterator up one

    IterC<T> & First();
    // Make iterator point to first element
   
    IterC<T> & Nth(int n);
    // Make iterator point to n'th element, points to header if n too large
   
    IterC<T> & Last();
    // Make iterator point to last element
   
    IterC<T> & Next();
    // Make iterator point to next element
   
    IterC<T> & Prev();
    // Make iterator point to previous element
   
    int IsElem(void);
    // TRUE if Iterator points to element, FALSE if points to head
};

/*--------------------------------------------------------------------------*/

#include "LList.tcc"

#endif
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/

