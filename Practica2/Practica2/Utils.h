#include <Windows.h>
#include <stdio.h>
#include <cstdarg>

#ifndef __Utils_H__
#define __Utils_H__


#define MIN(a,b) (a < b ? a : b)
#define MAX(a,b) (a > b ? a : b)

template<class typedata> void swap(typedata& a, typedata& b)
{
	typedata tmp = a;
	a = b;
	b = tmp;
}









#endif //__Utils_H__