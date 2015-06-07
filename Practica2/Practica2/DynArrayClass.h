#ifndef __DynArrayClass__
#define __DynArrayClass__

#include <stdio.h>
#include <assert.h>

#include "Utils.h"
#define DYNARRAY_BLOCK_SIZE 16

template <class typedata>
class dynArrayClass
{
private:
	typedata* data;
	unsigned int numElements;
	unsigned int allocatedMemory;
	

public:
	dynArrayClass(){ data = NULL; numElements = 0; allocatedMemory = 0; }

	dynArrayClass(const int MemorySize) { data = new typedata[MemorySize]; allocatedMemory = MemorySize; numElements = 0; }

	~dynArrayClass()
	{
		if (data != NULL) { delete data; }
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
		typedata* nwData = new typedata[nwSize];
		allocatedMemory = nwSize;
		if (data != NULL)
		{
			for (int n = 0; n <= MIN(newSize, numElements); n++)
			{
				nwData[n] = data[n];
			}

			delete data;
		}
		data = nwData;
		numElements = MIN(nwSize, numElements);
	}

	void push(const typedata value)
	{
		if (numElements + 1 > allocatedMemory)
		{
			reallocate(allocatedMemory + DYNARRAY_BLOCK_SIZE);
		}
		data[numElements] = value;
		numElements++;
	}

	typedata pop()
	{
		if (numElements >= 1)
		{
			numElements--;
			return data[numElements];
		}
		return 0;

	}

	void clear()
	{
		numElements = 0;
	}

	void insert(const typedata value, const int pos)
	{
		if (pos < allocatedMemory)
		{
			if (numElements + 1 > allocatedMemory)
			{
				reallocate(allocatedMemory + 1);
			}
			for (int n = numElements; n > pos; n--)
			{
				data[n] = data[n - 1];
			}
			data[pos] = value;
			numElements++;
		}
		else
		{
			LOG("\n\nSe intentó insertar un valor fuera de la memoria en un DynArray\n\n");
		}
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

	void bubbleSortOptimized()
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
				++retrn;
				if (data[i] > data[i + 1])
				{
					swap(data[i], data[i + 1]);
					last = i;
				}
			}
		}
		return retrn;
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