#ifndef __StackClass_H__
#define __StackClass_H__

#include "p2Defs.h"

#define STACK_BLOCK_SIZE 32

template<class VALUE>
class stackClass
{
private:

	VALUE*			data;
	unsigned int	mem_capacity;
	unsigned int	num_elements;

public:

	//-- Constructors
	stackClass() : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(STACK_BLOCK_SIZE);
	}

	stackClass(unsigned int capacity) : mem_capacity(0), num_elements(0), data(NULL)
	{
		Alloc(capacity);
	}

	//-- Destructor
	~stackClass()
	{
		delete[] data;
	}

	//-- Stack stuff

	void push(const VALUE& element)
	{
		if (num_elements >= mem_capacity)
		{
			Alloc(mem_capacity + STACK_BLOCK_SIZE);
		}
		data[num_elements++] = element;
	}

	bool pop(VALUE& result)
	{
		if (num_elements > 0)
		{
			result = data[--num_elements];
			return true;
		}
		return false;
	}

	void clear()
	{
		num_elements = 0;
	}

	const VALUE* Peek(unsigned int index)const
	{
		VALUE* result = NULL;

		if (index < num_elements)
			return result = &data[index];
		return result;

	}

	//-- Utils

	void Alloc(unsigned int mem)
	{
		VALUE* tmp = data;
		mem_capacity = mem;
		data = new VALUE[mem_capacity];

		num_elements = MIN(mem_capacity, num_elements);

		if (tmp != NULL)
		{
			for (int i = 0; i < num_elements; i++)
				data[i] = tmp[i];

			delete[] tmp;
		}
	}

	unsigned int getCapacity() const
	{
		return mem_capacity;
	}

	unsigned int getElements()const
	{
		return num_elements;
	}
};


#endif // !__StackClass_H__
