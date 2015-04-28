#include "stdafx.h"
#include "CppUnitTest.h"

#include"../Practica2/TreeClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Tree_add)
		{
			tree<char> myTree;
			treeNode<char>* ptr;
			treeNode<char>* ptr2;
			treeNode<char>* ptr3;
			treeNode<char>* ptr4;
			treeNode<char>* ptr5;
			treeNode<char>* ptr6;
			treeNode<char>* ptr7;
			treeNode<char>* ptr8;
			treeNode<char>* ptr9;
			treeNode<char>* test4add[3];

			ptr = myTree.add('F');
			ptr2 = myTree.add('B', ptr);
			ptr3 = myTree.add('G', ptr);
			ptr4 = myTree.add('H', ptr3);
			ptr5 = myTree.add('I', ptr4);
			ptr6 = myTree.add('A', ptr2);
			ptr7 = myTree.add('D', ptr2);
			test4add[2] = myTree.add('W', ptr2);
			ptr8 = myTree.add('C', ptr7);
			ptr9 = myTree.add('E', ptr7);

			Assert::AreEqual(test4add[2]->data, 'W');
		
		}

		TEST_METHOD(Tree_preOrderRecursive)
		{
			tree<char> myTree;
			treeNode<char>* ptr;
			treeNode<char>* ptr2;
			treeNode<char>* ptr3;
			treeNode<char>* ptr4;
			treeNode<char>* ptr5;
			treeNode<char>* ptr6;
			treeNode<char>* ptr7;
			treeNode<char>* ptr8;
			treeNode<char>* ptr9;

			ptr = myTree.add('F');
			ptr2 = myTree.add('B', ptr);
			ptr3 = myTree.add('G', ptr);
			ptr4 = myTree.add('H', ptr3);
			ptr5 = myTree.add('I', ptr4);
			ptr6 = myTree.add('A', ptr2);
			ptr7 = myTree.add('D', ptr2);
			ptr8 = myTree.add('C', ptr7);
			ptr9 = myTree.add('E', ptr7);



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

		TEST_METHOD(Tree_postOrderRecursive)
		{
			tree<char> myTree;
			treeNode<char>* ptr;
			treeNode<char>* ptr2;
			treeNode<char>* ptr3;
			treeNode<char>* ptr4;
			treeNode<char>* ptr5;
			treeNode<char>* ptr6;
			treeNode<char>* ptr7;
			treeNode<char>* ptr8;
			treeNode<char>* ptr9;

			ptr = myTree.add('F');
			ptr2 = myTree.add('B', ptr);
			ptr3 = myTree.add('G', ptr);
			ptr4 = myTree.add('H', ptr3);
			ptr5 = myTree.add('I', ptr4);
			ptr6 = myTree.add('A', ptr2);
			ptr7 = myTree.add('D', ptr2);
			ptr8 = myTree.add('C', ptr7);
			ptr9 = myTree.add('E', ptr7);



			listClass<char> list;

			myTree.postOrderRecursive(&list);

			Assert::AreEqual(list.getNode(0)->data, 'A');
			Assert::AreEqual(list.getNode(1)->data, 'C');
			Assert::AreEqual(list.getNode(2)->data, 'E');
			Assert::AreEqual(list.getNode(3)->data, 'D');
			Assert::AreEqual(list.getNode(4)->data, 'B');
			Assert::AreEqual(list.getNode(5)->data, 'I');
			Assert::AreEqual(list.getNode(6)->data, 'H');
			Assert::AreEqual(list.getNode(7)->data, 'G');
			Assert::AreEqual(list.getNode(8)->data, 'F');
		}

		TEST_METHOD(Tree_inOrderRecursive)
		{
			tree<char> myTree;
			treeNode<char>* ptr;
			treeNode<char>* ptr2;
			treeNode<char>* ptr3;
			treeNode<char>* ptr4;
			treeNode<char>* ptr5;
			treeNode<char>* ptr6;
			treeNode<char>* ptr7;
			treeNode<char>* ptr8;
			treeNode<char>* ptr9;

			ptr = myTree.add('F');
			ptr2 = myTree.add('B', ptr);
			ptr3 = myTree.add('G', ptr);
			ptr4 = myTree.add('H', ptr3);
			ptr5 = myTree.add('I', ptr4);
			ptr6 = myTree.add('A', ptr2);
			ptr7 = myTree.add('D', ptr2);
			ptr8 = myTree.add('C', ptr7);
			ptr9 = myTree.add('E', ptr7);



			listClass<char> list;

			myTree.inOrderRecursive(&list);

			Assert::AreEqual(list.getNode(0)->data, 'A');
			Assert::AreEqual(list.getNode(1)->data, 'B');
			Assert::AreEqual(list.getNode(2)->data, 'C');
			Assert::AreEqual(list.getNode(3)->data, 'D');
			Assert::AreEqual(list.getNode(4)->data, 'E');
			Assert::AreEqual(list.getNode(5)->data, 'F');
			Assert::AreEqual(list.getNode(6)->data, 'G');
			Assert::AreEqual(list.getNode(7)->data, 'H');
			Assert::AreEqual(list.getNode(8)->data, 'I');
		}

		TEST_METHOD(Tree_preOrderIterative)
		{
			tree<char> myTree;
			treeNode<char>* ptr;
			treeNode<char>* ptr2;
			treeNode<char>* ptr3;
			treeNode<char>* ptr4;
			treeNode<char>* ptr5;
			treeNode<char>* ptr6;
			treeNode<char>* ptr7;
			treeNode<char>* ptr8;
			treeNode<char>* ptr9;

			ptr = myTree.add('F');
			ptr2 = myTree.add('B', ptr);
			ptr3 = myTree.add('G', ptr);
			ptr4 = myTree.add('H', ptr3);
			ptr5 = myTree.add('I', ptr4);
			ptr6 = myTree.add('A', ptr2);
			ptr7 = myTree.add('D', ptr2);
			ptr8 = myTree.add('C', ptr7);
			ptr9 = myTree.add('E', ptr7);



			listClass<char> list;

			myTree.preOrderIterative(&list);

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

		TEST_METHOD(Tree_postOrderIterative)
		{
			tree<char> myTree;
			treeNode<char>* ptr;
			treeNode<char>* ptr2;
			treeNode<char>* ptr3;
			treeNode<char>* ptr4;
			treeNode<char>* ptr5;
			treeNode<char>* ptr6;
			treeNode<char>* ptr7;
			treeNode<char>* ptr8;
			treeNode<char>* ptr9;

			ptr = myTree.add('F');
			ptr2 = myTree.add('B', ptr);
			ptr3 = myTree.add('G', ptr);
			ptr4 = myTree.add('H', ptr3);
			ptr5 = myTree.add('I', ptr4);
			ptr6 = myTree.add('A', ptr2);
			ptr7 = myTree.add('D', ptr2);
			ptr8 = myTree.add('C', ptr7);
			ptr9 = myTree.add('E', ptr7);



			listClass<char> list;

			myTree.postOrderIterative(&list);

			Assert::AreEqual(list.getNode(0)->data, 'A');
			Assert::AreEqual(list.getNode(1)->data, 'C');
			Assert::AreEqual(list.getNode(2)->data, 'E');
			Assert::AreEqual(list.getNode(3)->data, 'D');
			Assert::AreEqual(list.getNode(4)->data, 'B');
			Assert::AreEqual(list.getNode(5)->data, 'I');
			Assert::AreEqual(list.getNode(6)->data, 'H');
			Assert::AreEqual(list.getNode(7)->data, 'G');
			Assert::AreEqual(list.getNode(8)->data, 'F');
		}

		TEST_METHOD(Tree_inOrderIterative)
		{
			tree<char> myTree;
			treeNode<char>* ptr;
			treeNode<char>* ptr2;
			treeNode<char>* ptr3;
			treeNode<char>* ptr4;
			treeNode<char>* ptr5;
			treeNode<char>* ptr6;
			treeNode<char>* ptr7;
			treeNode<char>* ptr8;
			treeNode<char>* ptr9;

			ptr = myTree.add('F');
			ptr2 = myTree.add('B', ptr);
			ptr3 = myTree.add('G', ptr);
			ptr4 = myTree.add('H', ptr3);
			ptr5 = myTree.add('I', ptr4);
			ptr6 = myTree.add('A', ptr2);
			ptr7 = myTree.add('D', ptr2);
			ptr8 = myTree.add('C', ptr7);
			ptr9 = myTree.add('E', ptr7);


			listClass<char> list;

			myTree.inOrderRecursive(&list);

			Assert::AreEqual(list.getNode(0)->data, 'A');
			Assert::AreEqual(list.getNode(1)->data, 'B');
			Assert::AreEqual(list.getNode(2)->data, 'C');
			Assert::AreEqual(list.getNode(3)->data, 'D');
			Assert::AreEqual(list.getNode(4)->data, 'E');
			Assert::AreEqual(list.getNode(5)->data, 'F');
			Assert::AreEqual(list.getNode(6)->data, 'G');
			Assert::AreEqual(list.getNode(7)->data, 'H');
			Assert::AreEqual(list.getNode(8)->data, 'I');
	}
		
		TEST_METHOD(Tree_clear)
		{
			tree<char> myTree;
			treeNode<char>* ptr;
			treeNode<char>* ptr2;
			treeNode<char>* ptr3;
			treeNode<char>* ptr4;
			treeNode<char>* ptr5;
			treeNode<char>* ptr6;
			treeNode<char>* ptr7;
			treeNode<char>* ptr8;
			treeNode<char>* ptr9;

			ptr = myTree.add('F');
			ptr2 = myTree.add('B', ptr);
			ptr3 = myTree.add('G', ptr);
			ptr4 = myTree.add('H', ptr3);
			ptr5 = myTree.add('I', ptr4);
			ptr6 = myTree.add('A', ptr2);
			ptr7 = myTree.add('D', ptr2);
			ptr8 = myTree.add('C', ptr7);
			ptr9 = myTree.add('E', ptr7);

			myTree.clear();

			ptr = myTree.add('J');
			ptr2 = myTree.add('K', ptr);

			listClass<char> list;

			myTree.preOrderRecursive(&list);

			Assert::IsTrue(list.count() == 2);
			Assert::AreEqual(list.getNode(0)->data, 'J');
			Assert::AreEqual(list.getNode(1)->data, 'K');

	
		}


};
}