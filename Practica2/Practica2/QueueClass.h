

#ifndef __QueueClass__
#define __QueueClass__

#include <stdio.h>
#include "Utils.h"

#define QUEUE_BLOCK_SIZE 16

template <class typedata>
class queueClass
{
private:
	typedata*				data;
	unsigned int			numElements;
	unsigned int			allocatedMemory;
	unsigned int		    element0;

	void Reallocate(const int nwSize)
	{
		typedata* nwData = new typedata[nwSize];
		allocatedMemory = nwSize;
		if (data != NULL)
		{
			for (unsigned int i = 0; i <= MIN(nwSize, (numElements + element0)); i++)
			{
				nwData[i] = data[i];
			}

			delete data;
		}
		data = nwData;
		numElements = MIN(nwSize, numElements);
	}

public:
	queueClass(){ data = NULL; numElements = 0; element0 = 0; allocatedMemory = 0; }

	~queueClass()
	{
		if (data != NULL) { delete data; }
	}

	const unsigned int Count() const
	{
		return numElements;
	}

	bool Shrink()
	{
		if (numElements < allocatedMemory)
		{
			Reallocate(numElements);
			return true;
		}
		return false;
	}

	void Push(const typedata value)
	{
		if (numElements + element0 + 1 > allocatedMemory)
		{
			if (element0 >= QUEUE_BLOCK_SIZE)
			{
				for (unsigned int i = 0; i < numElements; i++)
				{
					data[i] = data[element0];
					element0++;
				}
				element0 = 0;
			}
			else
			{
				Reallocate(allocatedMemory + QUEUE_BLOCK_SIZE);
			}
		}
		data[numElements + element0] = value;
		numElements++;
	}

	typedata Pop()
	{
		if (numElements >= 1)
		{
			numElements--;
			element0++;
			return data[element0 - 1];
		}

		return NULL;

	}

	void Clear()
	{
		numElements = 0;
	}

	const typedata* Peek(unsigned int index) const
	{
		typedata* result = NULL;

		if (index + element0 < numElements)
		{
			result = &data[index + element0];
		}

		return result;
	}

};

#endif //__QueueClass__