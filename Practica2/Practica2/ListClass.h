#ifndef __listClass_H__
#define __listClass_H__

#include <stdio.h>
#include <assert.h>
#include "Utils.h"

template <class typedata>
struct listItem {
	typedata			data;
	listItem<typedata> *next;
	listItem<typedata> *prev;

	inline listItem(const typedata &n_data)
	{
		data = n_data;
		next = prev = NULL;
	}

	~listItem()
	{ }
};

template <class typedata>
class listClass {

private:

	listItem<typedata>* start;
	listItem<typedata>* end;
	unsigned int size;

public:

	inline listClass()
	{
		start = end = NULL;
		size = 0;
	}

	~listClass()
	{
		clear();
	}

	typedata& operator[] (const unsigned int index)
	{
		listItem<typedata>* ptr = start;
		for (int i = 0; n < index; i++)
		{
			if (i >= size){ assert(false); }
			ptr = ptr->next;	
		}
		return ptr->data;	
	}

	typedata& operator[](const unsigned int index) const
	{
		listItem<typedata>* ptr = start;
		for (int i = 0; n < index; i++)
		{
			if (i >= size){ assert(false); }
			ptr = ptr->next;
		}
		return ptr->data;
	}

	int bubbleSort()
	{
		int counter = 0;
		bool done = false;
		listItem<typedata>* ptr = start;
		listItem<typedata>* ptr2;

		while (!done)
		{
			ptr = start;
			done = true;
			while ( ptr != NULL && ptr->next != NULL)
			{
				counter++;
				ptr2 = ptr->next;
				if (ptr->data > ptr2->data)
				{
					if (ptr != start)
					{
						ptr->prev->next = ptr2;
					}
					else
					{
						start = ptr2;
					}
					if (ptr2 != end)
					{
						ptr2->next->prev = ptr;
					}
					else
					{
						end = ptr;
						ptr->next = ptr2->next;
						ptr2->prev = ptr->prev;
						ptr->prev = ptr2;
						ptr2->next = ptr;
						done = false;
					}
				}
				else
				{
					ptr = ptr2;
				}
			}
		}
		printf(" bubbleSort \n %i\n", counter);
		return counter;
	}

	int bubbleSortWithSwap()
	{
		int counter = 0;
		bool swapped = true;

		while (swapped)
		{
			swapped = false;
			listItem<typedata>* ptr = start;

			while (ptr != NULL && ptr->next != NULL)
			{
				++counter;
				if (ptr->data > ptr->next->data)
				{
					swap(ptr->data, ptr->next->data);
					swapped = true;
				}

				ptr = ptr->next;
			}
		}
		printf("bubbleSort \n %i\n", counter);
		return counter;
	}




	unsigned int count() const
	{
		return size;
	}

	unsigned int add(const typedata &n_data)
	{
		listItem<typedata> *new_node;
		new_node = new listItem<typedata>(n_data);
		new_node->data = n_data;

		if (start != NULL)
		{
			new_node->prev = end;
			end->next = new_node;
			end = new_node;
		}
		else
		{
			start = end = new_node;
		}

		return (++size);

	}

	listItem<typedata>* getNode(const int position) const
	{
		listItem<typedata>* tmp = start;
		for (int p = 0; p < position; p++)
		{
			if (tmp == NULL)
			{

				return 0;
				break;
			}
			tmp = tmp->next;
		}
		return tmp;
	}

	listItem<typedata>* getNode(const int position)
	{
		listItem<typedata>* tmp = start;
		for (int p = 0; p < position; p++)
		{
			if (tmp == NULL)
			{

				return 0;
				break;
			}
			tmp = tmp->next;
		}
		return tmp;
	}

	bool del(listItem<typedata>* node)
	{
		if (start != NULL)
		{
			if (node->prev != NULL)
			{
				node->prev->next = node->next;
				if (node->next != NULL)
					node->next->prev = node->prev;
				else
					end = node->prev;
			}
			else
			{
				if (node->next != NULL)
				{
					start = node->next;
					node->next->prev = NULL;
				}
				else
					start = end = NULL;
			}

			delete node;
			--size;
			return true;
		}
		return false;
	}

	bool clear() {

		if (start != NULL)
		{
			while (start->next != NULL)
			{
				listItem<typedata>* node = start;
				start = start->next;
				delete node;
			}
			start = end = NULL;
			size = 0;
			return true;
		}
		return false;
	}

	bool checkList(const listItem<typedata> *check_node) const
	{
		if (start != NULL && check_node != NULL)
		{
			listItem<typedata> *item = start;
			while (item != NULL)
			{
				if (item->data == check_node->data)
					return true;
				item = item->next;
			}
		}
		return false;
	}

	int find(const typedata& data)//(-1) if not found
	{
		listItem<typedata>* ptr = start;
		int index = 0;
		while (ptr != NULL)
		{
			if (ptr->data == data)
				return index;
			++index;
			ptr = ptr->next;
		}
		return(-1);
	}

	listItem<typedata>* getStart() const
	{
		return start;
	}

	listItem<typedata>* getEnd() const
	{
		return end;
	}

};


#endif // !__listClass_H__
