#ifndef __stackClass_H__
#define __stackClass_H__

#include <stdio.h>
#include "ListClass.h"
#define STACK_BLOCK_SIZE 32 

template<class typedata>
class stackClass
{

private:

	typedata			*data;
	unsigned int		allocated_memory;
	unsigned int		num_elements;


public:

	//-- Constructors

	stackClass() : data(NULL), allocated_memory(0), num_elements(0)
	{}

	stackClass(unsigned int new_memory) : data(NULL), num_elements(0)
	{
		reallocate(new_memory);
	}

	//-- Destructor

	~stackClass()
	{
		 delete[] data;
	}

	//-- Manage Stack

	void push(const typedata new_data)
	{
		if (num_elements + 1 > allocated_memory)
		{
			reallocate(allocated_memory + STACK_BLOCK_SIZE);
		}
		data[num_elements] = new_data;
		num_elements++;
	}


	typedata pop()
	{
		if (num_elements >= 1)
		{
			num_elements--;
			return data[num_elements];
		}
		return NULL;

	}

	typedata peek()
	{
		if (num_elements >= 1)
		{
			return data[num_elements];
		}
		return NULL;
	}
	

	void clear()
	{
		num_elements = 0;
	}

	//-- Utils

	unsigned int getElements() const
	{
		return num_elements;
	}

	unsigned int getCapacity() const
	{
		return allocated_memory;
	}


	//--Private utils


private:

	void reallocate(unsigned int new_memory)
	{
		allocated_memory = new_memory;

		if (data != NULL)
		{
			typedata *tmp = new typedata[allocated_memory];

			for (unsigned int i = 0; i < num_elements; i++)
				tmp[i] = data[i];

			delete[] data;
			data = tmp;
		}
		else
		{
			data = new typedata[allocated_memory];
		}
	}

};

template<class typedata>

class stackClassList
{
private:
	listItem<typedata> *start;
	listItem<typedata> *end;
	unsigned int numElements;

public:
	stackClassList()
	{
		start = end = NULL;
		numElements = 0;
	}

	~stackClassList(){}

	void push(const typedata& nwData)
	{
		listItem<typedata>* item = new listItem<typedata>(nwData);

		if (start != NULL)
		{
			end->next = item;
			item->prev = end;
			end = item;
		}
		else
		{
			start = end = item;
		}
		++numElements;
	}

	bool pop(typedata& popData)
	{
		if (numElements > 0)
		{
			popData = end->data;
			listItem<typedata>* toDelete = end;

			if (numElements > 1)
			{
				end = end->prev;
				end->next = NULL;
			}
			else
			{
				start = end = NULL;

				delete toDelete;
				--numElements;
				return true;
			}
		}
		return false;
	}

	const typedata* peek(unsigned int position) const
	{
		listItem<typedata>* item = NULL;
		if (position<numElements)
		{
			item = start;
			for (int i = 0; i != position; ++i)
				item = item->next;
		}
		return &(item->data);
	}

	int getElements()const
	{
		return numElements;
	}

};


#endif // __stackClass_H__