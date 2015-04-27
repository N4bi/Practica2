#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Practica2/StackClass.h"
#include "../Practica2/TreeClass.h"
#include "../Practica2/ListClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{

	public:

		//-- Stack Class

		TEST_METHOD(StackConstructor)
		{
			stackClass<int> stack;

			stack.push(1);
			stack.push(2);
			stack.push(3);

			int res;
			Assert::IsTrue(stack.pop(res));
			Assert::AreEqual(res, 3);
			Assert::IsTrue(stack.pop(res));
			Assert::AreEqual(res, 2);
			Assert::IsTrue(stack.pop(res));
			Assert::AreEqual(res, 1);
		}

		TEST_METHOD(Tree_preOrderRecursive)
		{
			tree<char> myTree;
			treeNode<char>* ptr;
			treeNode<char>* ptr2;
			ptr = myTree.add('F');
			ptr2 = myTree.add('B', ptr);
			ptr = myTree.add('G', ptr);
			ptr = myTree.add('H', ptr);
			myTree.add('I', ptr);
			myTree.add('A', ptr2);
			ptr2 = myTree.add('D', ptr2);
			myTree.add('C', ptr2);
			myTree.add('E', ptr2);

			listClass<char> list;

			myTree.preOrderRecursive(&list);

			Assert::AreEqual(list.getNode(0)->data, 'F');
			Assert::AreEqual(list.getNode(1)->data, 'B');
			Assert::AreEqual(list.getNode(2)->data, 'A');
			Assert::AreEqual(list.getNode(3)->data, 'D');
			Assert::AreEqual(list.getNode(4)->data, 'C');
			Assert::AreEqual(list.getNode(5)->data, 'E');
			Assert::AreEqual(list.getNode(6)->data, 'G');
			Assert::AreEqual(list.getNode(7)->data, 'H');
			Assert::AreEqual(list.getNode(8)->data, 'I');
		}
	};
}

	