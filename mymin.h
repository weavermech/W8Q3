//
// Created by Weaver on 28/03/2019.
//

#ifndef EX1_MYMIN_H
#define EX1_MYMIN_H

//function declaration
template<class T> T mymin(T& a, T& b);

//function definition
template<class T>

T mymin(T& a, T& b){
	if (a>b)
	{
		return b;
	}
	else return a;
}

/*
 * T T::operator>(const T & other)
{

}
 */
#endif //EX1_MYMIN_H
