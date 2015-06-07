#include<Windows.h>

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

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...)
{
	static char tmpString[4096];
	static char tmpString2[4096];
	static va_list ap;

	// Construct the string from variable arguments
	va_start(ap, format);
	vsprintf_s(tmpString, 4096, format, ap);
	va_end(ap);
	sprintf_s(tmpString2, 4096, "\n%s(%d) : %s", file, line, tmpString);
	OutputDebugString(tmpString2);
}









#endif //__Utils_H__