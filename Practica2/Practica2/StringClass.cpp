#include "stringClass.h"
#include <stdio.h>

//--Constructor


stringClass::stringClass()
{
	alloc(1);
	strcpy_s(string, size, "");
}

stringClass::stringClass(const stringClass& nwString)
{
	alloc(nwString.len() + 1);
	strcpy_s(string, size, nwString.getString());
}

stringClass::stringClass(const char* format, ...)
{
	size = 0;

	if (format != NULL)
	{
		static char tmp[TMP_STRING_SIZE];
		static va_list ap;

		va_start(ap, format);
		int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
		va_end(ap);

		if (res > 0)
		{
			alloc(res + 1);
			strcpy_s(string, size, tmp);
		}
	}
	if (size == 0)
	{
		alloc(1);
		clear();
	}
}

//--Destructor

stringClass::~stringClass()
{
	if (string)
	{
		delete[] string;
	}
}

//-- Methods

void stringClass::alloc(int nwSize)
{
	size = nwSize;
	string = new char[size];
}

void stringClass::clear()
{
	if (string != NULL)
	{
		delete[] string;
		alloc(1);
		strcpy_s(string, size, "");
	}
}

unsigned int stringClass::len() const
{
	return strlen(string);
}

int stringClass::capacity() const
{
	return size;
}

const char* stringClass::getString() const
{
	return string;
}

void stringClass::trim(bool trimStart, bool trimEnd, char toRemove)
{
	int n = 0;
	int m = len();
	while (string[n] == toRemove && n < len() && trimStart == true)
	{
		n++;
	}
	while (string[m - 1] == toRemove && m >= 0 && trimEnd == true)
	{
		m--;
	}
	for (int i = 0; i <= m - n - 1; i++)
	{
		string[i] = string[i + n];
	}
	string[m - n] = '\0';
}


int  stringClass::replace(const char* toErase, const char* toInsert)
{
	int nOfreplacements = 0;
	if (toErase != NULL)
	{
		int sizeDifference = 0;
		int toEraselen = strlen(toErase);
		int toInsertlen = strlen(toInsert);
		
		sizeDifference = toEraselen - toInsertlen;

		for (int n = 0; n < strlen(string); n++)
		{
			int counter = 0;
			for (int m = 0; m < toEraselen && string[n + m] == toErase[m]; m++)
			{
				counter++;
			}

			if (counter >= toEraselen)
			{
				if (sizeDifference > 0)
				{
					for (int m = toInsertlen; m + n + sizeDifference <= strlen(string); m++)
					{
						string[m + n] = string[m + n + sizeDifference];
					}
				}
				else if (sizeDifference < 0)
				{
					if (strlen(string) - sizeDifference >= size)
					{
						stringClass tmp(*this);
						alloc(size - sizeDifference + 1);
						strcpy_s(string, tmp.size, tmp.string);
					}
					for (int m = strlen(string); m >= n + toEraselen; m--)
					{
						string[m - sizeDifference] = string[m];
					}
				}
				for (int m = 0; m < toInsertlen; m++)
				{
					string[m + n] = toInsert[m];
				}
				nOfreplacements++;
				n += toInsertlen;
			}
		}
	}
	return nOfreplacements;
}

unsigned int stringClass::find_char(char ch, int from_last)
{
	unsigned int  i = 0;

	if (string != NULL)
	{
		if (from_last == 1)
		{
			i = size - 1;
		}

		while (i < size && i >= 0)
		{
			if (string[i] != ch)
			{
				return(i);
			}

			if (from_last == 0)
			{
				++i;
			}
			else
			{
				--i;
			}
		}
	}

	return(i);
}


//--Operators

bool stringClass::operator== (const stringClass& str) const
{
	return strcmp(str.string, string) == 0;
}

bool stringClass::operator== (const char* str) const
{
	if (str != NULL)
	{
		return strcmp(str, string) == 0;
	}
	return false;
}

bool stringClass::operator!= (const stringClass& str) const
{
	return strcmp(str.string, string) != 0;
}

bool stringClass::operator!= (const char* str) const
{
	if (str != NULL)
	{
		return strcmp(str, string) != 0;
	}
	return false;
}


stringClass stringClass::operator= (const char* str)
{
	if (str != NULL)
	{
		if (strlen(str) + 1 > size)
		{
			delete[] string;
			alloc(strlen(str) + 1);
		}
		strcpy_s(string, size, str);
	}
	else
	{
		clear();
	}
	return(*this);
}

stringClass stringClass::operator= (const stringClass& str)
{
	if (str.string != NULL)
	{
		if (str.len() + 1 > size)
		{
			delete[] string;
			alloc(str.len() + 1);
		}
		strcpy_s(string, size, str.string);
	}
	else
	{
		clear();
	}

	return(*this);
}

const stringClass stringClass::operator+= (const char* str)
{
	if (str != NULL)
	{
		stringClass tmp(*this);
		delete[] string;
		alloc(strlen(str) + size);
		strcpy_s(string, tmp.size, tmp.string);
		strcat_s(string, size, str);
	}
	return(*this);
}

const stringClass stringClass::operator+= (const stringClass& str)
{
	if (str.string != NULL)
	{
		stringClass tmp(*this);
		delete[] string;
		alloc(strlen(str.string) + size);
		strcpy_s(string, tmp.size, tmp.string);
		strcat_s(string, size, str.string);
	}
	return(*this);
}



