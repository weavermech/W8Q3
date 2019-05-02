//
// Created by Weaver on 28/03/2019.
//

#ifndef EX1_MYSWAP_H
#define EX1_MYSWAP_H

#include "LList.h"

// function declaration
template<class T> void myswap(ListC<T>& a, ListC<T>& b);
// function definition
template<class T> void myswap(ListC<T>& a, ListC<T>& b)
{
	ListC<T> minList;
	IterC<T> minIter = minList;
	IterC<T> ita(a);
	IterC<T> itb(b);



	for (ita.First(), itb.First(); ita.IsElem(), itb.IsElem(); ita.Next(),itb.Next() )
	{
		if ( ita.Data() < itb.Data() )
		{
			minIter.InsAfter( ita.Data() );
		}
		else
		{
			minIter.InsAfter( itb.Data() );
		}

	}

	for (minIter.First(); minIter.IsElem(); minIter.Next())
	{
		cout << minIter.Data() << endl;
	}


}
#endif //EX1_MYSWAP_H
