/*--------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include <stdlib.h>
#include "LList.h"
#include "myswap.h"
#include <string>



int main()
{
	ListC<int> listA;
	ListC<int> listB;
	int num;


	num = 1;
	listA.InsFirst(num);
	num = 9;
	listA.InsLast(num);


	num = 1;
	listB.InsFirst(num);
	num = 9;
	listB.InsLast(num);

	if (listA == listB)
		cout << "Winner!" << endl;

	exit(0);
}

/*--------------------------------------------------------------------------*/

