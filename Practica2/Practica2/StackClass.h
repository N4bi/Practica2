#ifndef __stackClass_H__
#define __stackClass_H__

#include <stdio.h>


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

	void push(const typedata &new_data)
	{
		if (num_elements == allocated_memory)
			reallocate(++allocated_memory);

		data[num_elements++] = new_data;
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

#endif // __stackClass_H__