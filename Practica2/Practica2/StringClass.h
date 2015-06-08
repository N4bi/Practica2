

#ifndef __StringClass__
#define __StringClass__
#include <string.h>
#include <stdarg.h>
#define TMP_STRING_SIZE 4096
class stringClass
{

private:
	char* string;
	unsigned int size;
public:

	//-- Constructors

	stringClass();

	stringClass(const stringClass&);

	stringClass(const char* format, ...);

	//-- Destructors

	~stringClass();

	//-- Methods

	void alloc(int);

	void clear();

	unsigned int len() const;

	int capacity() const;

	const char* getString() const;

	void trim(bool trimStart = true, bool trimEnd = true, char toRemove = ' ');

	int replace(const char* toErase, const char* toInsert);

	unsigned int find_char(char ch, int from_last);

	//-- Operators

	bool operator== (const stringClass&) const;

	bool operator== (const char*) const;

	bool operator!= (const stringClass&) const;

	bool operator!= (const char*) const;

	stringClass operator= (const char*);

	stringClass operator= (const stringClass&);

	const stringClass operator+= (const char*);

	const stringClass operator+= (const stringClass&);

};

#endif //__StringClass__