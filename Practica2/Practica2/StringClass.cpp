#include "stringClass.h"
#include <stdio.h>

//--Constructor


stringClass::stringClass()
{
	Alloc(1);
	strcpy_s(string, size, "");
}

stringClass::stringClass(const stringClass& nwString)
{
	Alloc(nwString.Len() + 1);
	strcpy_s(string, size, nwString.GetString());
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
			Alloc(res + 1);
			strcpy_s(string, size, tmp);
		}
	}
	if (size == 0)
	{
		Alloc(1);
		Clear();
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

void stringClass::Alloc(int nwSize)
{
	size = nwSize;
	string = new char[size];
}

void stringClass::Clear()
{
	if (string != NULL)
	{
		delete[] string;
		Alloc(1);
		strcpy_s(string, size, "");
	}
}

unsigned int stringClass::Len() const
{
	return strlen(string);
}

int stringClass::Capacity() const
{
	return size;
}

const char* stringClass::GetString() const
{
	return string;
}

void stringClass::Trim(bool trimStart, bool trimEnd, char toRemove)
{
	int n = 0;
	int m = Len();
	while (string[n] == toRemove && n < Len() && trimStart == true)
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


int  stringClass::Replace(const char* toErase, const char* toInsert)
{
	int nOfReplacements = 0;
	if (toErase != NULL)
	{
		int sizeDifference = 0;
		int toEraseLen = strlen(toErase);
		int toInsertLen = strlen(toInsert);
		//Getting how much we'll have to move the characters after the substitution
		sizeDifference = toEraseLen - toInsertLen;

		for (int n = 0; n < strlen(string); n++)
		{
			int counter = 0;
			//Comparing our string to the characters to substitute
			for (int m = 0; m < toEraseLen && string[n + m] == toErase[m]; m++)
			{
				counter++;
			}

			//Moving the characters following our replacement
			if (counter >= toEraseLen)
			{
				if (sizeDifference > 0)
				{
					for (int m = toInsertLen; m + n + sizeDifference <= strlen(string); m++)
					{
						string[m + n] = string[m + n + sizeDifference];
					}
				}
				else if (sizeDifference < 0)
				{
					if (strlen(string) - sizeDifference >= size)
					{
						stringClass tmp(*this);
						Alloc(size - sizeDifference + 1);
						strcpy_s(string, tmp.size, tmp.string);
					}
					for (int m = strlen(string); m >= n + toEraseLen; m--)
					{
						string[m - sizeDifference] = string[m];
					}
				}
				//Replacing the word
				for (int m = 0; m < toInsertLen; m++)
				{
					string[m + n] = toInsert[m];
				}
				nOfReplacements++;
				n += toInsertLen;
			}
		}
	}
	return nOfReplacements;
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
			Alloc(strlen(str) + 1);
		}
		strcpy_s(string, size, str);
	}
	else
	{
		Clear();
	}
	return(*this);
}

stringClass stringClass::operator= (const stringClass& str)
{
	if (str.string != NULL)
	{
		if (str.Len() + 1 > size)
		{
			delete[] string;
			Alloc(str.Len() + 1);
		}
		strcpy_s(string, size, str.string);
	}
	else
	{
		Clear();
	}

	return(*this);
}

const stringClass stringClass::operator+= (const char* str)
{
	if (str != NULL)
	{
		stringClass tmp(*this);
		delete[] string;
		Alloc(strlen(str) + size);
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
		Alloc(strlen(str.string) + size);
		strcpy_s(string, tmp.size, tmp.string);
		strcat_s(string, size, str.string);
	}
	return(*this);
}



