#ifndef __TreeClass_H__
#define __TreeClass_H__

#include"ListClass.h"
#include"StackClass.h"

//Node tree

template<class typedata>
class treeClassNode
{

public:

	typedata					data;
	treeClassNode				parent;
	listClass<treeClassNode>	childs;

public:

	treeClassNode(const typedata& _data);
	void addChild(treeClassNode* node);
	bool delChild(treeClassNode* node);
	void preOrderRecursive(listClass<treeClassNode<typedata>*>* list);
	void inOrderRecursive(listClass<treeClassNode<typedata>*>* list);
	void postOrderRecursive(listClass<treeClassNode<typedata>*>* list);

};






#endif // !__TreeClass_H__
