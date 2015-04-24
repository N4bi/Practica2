#ifndef __ListClass_H__
#define __ListClass_H__
#include <stdio.h>
#include "p2Defs.h"

//--Items for double linked list

template<class typedata>
struct listClass_item
{

	typedata					data;
	listClass_item<typedata>*	next;
	listClass_item<typedata>*	prev;

	inline listClass_item(const typedata& _data)
	{
		data = _data;
		prev = next = NULL;
	}

	~listClass_item()
	{}
};

//-- Double linked list

template<class typedata>
class listClass
{

public:

	listClass_item<typedata>* start;
	listClass_item<typedata>* end;

private:

	unsigned int size;

public:

	//-- Constructor

	inline listClass()
	{
		start = end = NULL;
		size = 0;
	}

	//-- Destructor

	~listClass()
	{
		clear();
	}

	//-- Get size

	unsigned int getSize()
	{
		return size;
	}

	//-- Add item

	unsigned int add(const typedata& item)
	{
		listClass_item<typedata>*			p_data_item;
		p_data_item = new listClass_item <typedata>(item);

		if (start == NULL)
		{
			start = end = p_data_item;
		}
		else
		{
			p_data_item->prev = end;
			end->next = p_data_item;
			end = p_data_item;
		}
		return (++size);
	}

	//-- Delete item

	bool del(listClass_item<typedata>* item)
	{
		if (item == NULL)
		{
			return false;
		}

		if (item->prev != NULL)
		{
			item->prev->next = item->next;
			if (item->next != NULL)
			{
				item->next->prev = item->prev;
			}
			else
			{
				end = item->prev;
			}
		}
		else
		{
			if (item->next)
			{
				item->next->prev = NULL;
				start = item->next;
			}
			else
			{
				start = end = NULL;
			}
		}	

		RELEASE(item);
		size--;
		return(true);
		
	}

	//-- Delete all

	void clear()
	{
		listClass_item<typedata>* p_data;
		listClass_item<typedata>* p_next;
		p_data = start;

		while (p_data != NULL)
		{
			p_next = p_data->next;
			RELEASE(p_data);
			p_data = p_next;
	
		}
		start = end = NULL;
		size = 0;
	}

	//-- Read and write operator for position

	typedata& operator [](const unsigned int index)
	{
		long	pos;
		listClass_item<typedata>* p_item;
		pos = 0;
		p_item = start;

		while (p_item != NULL)
		{
			if (pos == index)
			{
				break;
			}
			pos++;
			p_item = p_item->next;
		}

		return(p_item->data);
	}
	
	//-- Return first data as index 
	
	int find(const typedata& data)
	{
		listClass_item<typedata>* tmp = start;
		int index = 0;

		while (tmp != NULL)
		{
			if (tmp->data == data)
				return(index);
			index++;
			tmp = tmp->next;
		}
		return(-1);
	}

};


#endif // __ListClass_H__