#ifndef __TreeClass_H__
#define __TreeClass_H__


#include "ListClass.h"
#include "StackClass.h"

//-- Node tree

template <class TYPE>
class treeNode
{
public:

	TYPE data;
	treeNode<TYPE>* parent;
	listClass<treeNode<TYPE>*> child;

public:

	treeNode() : data(NULL), parent(NULL)
	{}
	treeNode(const TYPE &n_data) : parent(NULL), data(n_data)
	{}

	void preOrderRecursive(listClass <TYPE>* list)
	{
		list->add(data);

		int n_node = child.count();
		for (int i = 0; i < n_node; i++)
		{
			child.getNode(i)->data->preOrderRecursive(list);
		}
	}

	void postOrderRecursive(listClass <TYPE>* list) const
	{
		int n_node = child.count();
		for (int i = 0; i < n_node; i++)
		{
			child.getNode(i)->data->postOrderRecursive(list);
		}
		list->add(data);
	}

	void inOrderRecursive(listClass<TYPE>* list)
	{
		int n_node = child.count();
		int i = 0;

		for (; i < n_node / 2; i++)
		{
			child.getNode(i)->data->inOrderRecursive(list);
		}

		list->add(data);

		for (; i < n_node; i++)
		{
			child.getNode(i)->data->inOrderRecursive(list);
		}
	}

};

//-- Tree Class

template<class TYPE>
class tree
{

private:

	treeNode<TYPE>* rootNode;

public:

	//-- Constructor

	tree()
	{
		rootNode = NULL;
	}

	//-- Destructor

	~tree()
	{
		clear();
	}

	const treeNode<TYPE>* getRootNode() const
	{
		return rootNode;
	}

	treeNode<TYPE>* add(const TYPE& data, treeNode<TYPE>* parent = NULL)
	{
		if (parent == NULL && rootNode != NULL)
		{
			return NULL;
		}
		treeNode<TYPE>* nwNode = new treeNode<TYPE>(data);
		if (rootNode == NULL)
		{
			nwNode->parent = NULL;
			rootNode = nwNode;
		}
		else if (parent != NULL)
		{
			parent->child.add(nwNode);
			nwNode->parent = parent;
		}
		return nwNode;
	}

	void clear(treeNode<TYPE>* del_node = NULL)
	{
		if (del_node == NULL && rootNode != NULL)
		{
			del_node = rootNode;
		}
		if (del_node != NULL)
		{
			if (del_node->child.getStart() != NULL)
			{
				int n_node = del_node->child.count();
				for (int i = 0; i < n_node; i++)
				{
					clear(del_node->child.getNode(i)->data);
				
				}
			}
			delete del_node;
		}
		if (del_node == rootNode)
		{
			rootNode = NULL;
		}
	}
	

	void preOrderRecursive(listClass<TYPE>* list)const
	{
		rootNode->preOrderRecursive(list);
	}

	void postOrderRecursive(listClass<TYPE>* list)const
	{
		rootNode->postOrderRecursive(list);
	}

	void inOrderRecursive(listClass<TYPE>* list)const
	{
		rootNode->inOrderRecursive(list);
	}

	void preOrderIterative(listClass<TYPE>* list) const
	{
		stackClass<treeNode<TYPE>*> Stack;
		treeNode<TYPE>* node = rootNode;
		while (node != NULL)
		{
			list->add(node->data);
			for (int i = node->child.count() - 1; i >= 0; i--)
			{
				Stack.push(node->child.getNode(i)->data);
			}
			node = Stack.pop();
		}
	}

	void postOrderIterative(listClass<TYPE>* list) const
	{ 
		stackClass<treeNode<TYPE>*> Stack;
		stackClass<treeNode<TYPE>*> Stack2;
		treeNode<TYPE>* node = rootNode;
		while (node != NULL)
		{
			Stack2.push(node);
			for (int i = 0; i < node->child.count(); i++)
			{
				Stack.push(node->child.getNode(i)->data);
			}
			node = Stack.pop();
		}
		while (true)
		{
			node = Stack2.pop();
			if (node == NULL) { break; }
			list->add(node->data);
		}
	}

	void inOrderIterative(listClass<TYPE>* list) const
	{
		stackClass<treeNode<TYPE>*> Stack;
		stackClass<treeNode<TYPE>*> Stack2;
		treeNode<TYPE>* node = rootNode;
		while (node != NULL)
		{
			int j = node->child.count() - 1;
			for (int i = j / 2; j >= i; j--)
			{
				Stack.push(node->child.getNode(j)->data);
			}
			Stack.push(node);
			Stack2.push(node);
			for (; j >= 0; j--)
			{
				Stack.push(node->child.getNode(j)->data);
			}
			while (Stack.peek() != NULL && Stack.peek() == Stack2.peek())
			{
				node = Stack.pop();
				list->add(Stack2.pop()->data);
			}
			node = Stack.pop();

		}
	}

	/*void witdhSearch(listClass<TYPE>* list) const 
	{
		stackClass<treeNode<TYPE>*> Stack;
		stackClass<treeNode<TYPE>*> Stack2;
		treeNode<TYPE>* node = rootNode;
		Stack.push(node);

		while (Stack.getElements() != 0)
		{
			Stack.pop(node);
			list->add(node);

			listItem<treeNode<TYPE>*>* item = node->child.getStart();
			for (; item != NULL; item = item->next)
				Stack2.push(item->data);

			if (Stack.getElements() == 0)
			{
				while (Stack2.getElements() != 0)
				{
					Stack2.pop(node);
					Stack.push(node);
				}
			}
		}
	}*/



};

#endif