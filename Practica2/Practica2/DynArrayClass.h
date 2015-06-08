#ifndef __DynArrayClass__
#define __DynArrayClass__

#include <stdio.h>
#include <assert.h>

#include "Utils.h"
#include"Log.h"

#define DYNARRAY_BLOCK_SIZE 16

template <class typedata>
class dynArrayClass
{
private:
	typedata* data;
	unsigned int numElements;
	unsigned int allocatedMemory;
	

public:
	dynArrayClass() : allocatedMemory(0), numElements(0), data(NULL)
	{
		reallocate(DYNARRAY_BLOCK_SIZE);
	}

	dynArrayClass(const int MemorySize) : allocatedMemory(0), numElements(0), data(NULL)
	{
		reallocate(MemorySize);
	}

	~dynArrayClass()
	{
		if (data != NULL) { delete[] data; }
	}

	const unsigned int getCapacity() const
	{
		return allocatedMemory;
	}

	const unsigned int count() const
	{
		return numElements;
	}

	bool shrink()
	{
		if (numElements < allocatedMemory)
		{
			reallocate(numElements + 1);
			return true;
		}
		return false;
	}

	void reallocate(const int nwSize)
	{
		typedata* tmp = data;
		allocatedMemory = nwSize;
		data = new typedata[allocatedMemory];

		numElements = MIN(allocatedMemory, numElements);

		if (tmp != NULL)
		{
			for (int i = 0; i < numElements; ++i)
				data[i] = tmp[i];
			delete[] tmp;
		}

	}

	void push(const typedata& value)
	{
		if (numElements >= allocatedMemory)
		{
			reallocate(allocatedMemory + DYNARRAY_BLOCK_SIZE);
		}
		data[numElements++] = value;

	}

	bool pop(typedata& value)
	{
		if (numElements > 0)
		{
			value = data[--numElements];
			return true
		}
		return false;

	}

	void clear()
	{
		numElements = 0;
	}

	bool insert(int new_value, unsigned int position)
	{
		if (position <= numElements)
		{
			TYPE *tmp = new TYPE[allocatedMemory];
			for (unsigned int i = 0; i < numElements; i++)
			{
				tmp[i] = data[i];
			}

			if (numElements == allocatedMemory)
				reallocate(allocatedMemory + 1);

			for (unsigned int i = 0; i < position; i++)
			{
				data[i] = tmp[i];
			}
			data[position] = new_value;
			for (unsigned int i = position; i < numElements; i++)
			{
				data[i + 1] = tmp[i];
			}
			numElements++;
			delete[] tmp;
			return true;
		}
		return false;
	}


	void mirror()
	{
		for (int n = 0; n < (numElements - 1) / 2; n++)
		{
			swap(data[n], data[numElements - 1 - n]);
		}
	}

	typedata& operator[] (const unsigned int index)
	{
		if (index < numElements)
		{
			return data[index];
		}
		else
		{
			assert(false);
		}
	}

	const typedata& operator[] (const unsigned int index) const
	{
		if (index < numElements)
		{
			return data[index];
		}
		else
		{
			assert(false);
		}
	}

	typedata* at(unsigned int index)
	{
		typedata* result = NULL;

		if (index < numElements)
			result = &data[index];

		return result;
	}

	const typedata* at(unsigned int index) const
	{
		typedata* result = NULL;

		if (index < numElements)
			result = &data[index];

		return result;
	}

	void bubbleSortOld()
	{
		int counter = 0;
		bool done = false;

		while (done == false)
		{
			done = true;
			for (int n = 0; n < numElements - 1; n++)
			{
				counter++;
				if (data[n] > data[n + 1])
				{
					Swap(data[n], data[n + 1]);
					done = false;
				}
			}
		}
		printf(" BubbleSort Old \n %i\n", counter);
	}

	void bubbleSort()
	{
		int counter = 0;
		bool done = false;
		int loops = 1;

		while (done == false)
		{
			done = true;
			for (int n = 0; n < numElements - loops; n++)
			{
				counter++;
				if (data[n] > data[n + 1])
				{
					Swap(data[n], data[n + 1]);
					done = false;
				}
			}
			loops++;
		}
		printf(" BubbleSort \n %i\n", counter);
	}

	typedata bubbleSortOptimized()
	{
		int retrn = 0;
		int count;
		int last = numElements - 2;

		while (last != 0)
		{
			count = last;
			last = 0;
			for (int i = 0; i < count; i++)
			{
				retrn++;
				if (data[i] > data[i + 1])
				{
					swap(data[i], data[i + 1]);
					last = i;
				}
			}	
		}
		return retrn;
	}

	int bubbleSortSuperOptimized()
	{
		int counter = 0;
		int last = numElements;

		for (int i = 0; i < last - 1; i++)
		{
			for (int j = i + 1; j < last; j++)
			{
				counter++;
				if (data[i]>data[j])
				{
					swap(data[i], data[j]);
					last = j;
				}
			}
		}
		return counter;
	}

	void flip()
	{
		typedata* start = &data[0];
		typedata* end = &data[numElements - 1];

		while (start < end)
			swap(*start++, *end--);
	}

};
#endif // __DynArrayClass__