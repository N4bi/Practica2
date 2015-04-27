#ifndef __listClass_H__
#define __listClass_H__

#include <stdio.h>

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

	bool at(unsigned int index, typedata &n_data) const
	{
		bool ret = false;
		unsigned int i = 0;
		listItem<typedata>*   searching_node = start;

		for (unsigned int i = 0; i < index - 1 && searching_node != NULL; ++i)
			searching_node = searching_node->next;

		if (searching_node != NULL)
		{
			ret = true;
			n_data = searching_node->data;
		}

		return ret;
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
