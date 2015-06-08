#include "stdafx.h"
#include "CppUnitTest.h"

#include"../Practica2/Utils.h"
#include"../Practica2/TreeClass.h"
#include"../Practica2/Point2D.h"
#include"../Practica2/Point2D.cpp"
#include"../Practica2/StringClass.h"
#include"../Practica2/StringClass.cpp"
#include"../Practica2/DynArrayClass.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		//--TREE_CLASS

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

		/*TEST_METHOD(TreesWidthIterative)
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

			myTree.witdhSearch(&list);

			Assert::AreEqual(list.getNode(0)->data, 'F');
			Assert::AreEqual(list.getNode(1)->data, 'B');
			Assert::AreEqual(list.getNode(2)->data, 'G');
			Assert::AreEqual(list.getNode(3)->data, 'A');
			Assert::AreEqual(list.getNode(4)->data, 'D');
			Assert::AreEqual(list.getNode(5)->data, 'H');
			Assert::AreEqual(list.getNode(6)->data, 'C');
			Assert::AreEqual(list.getNode(7)->data, 'E');
			Assert::AreEqual(list.getNode(8)->data, 'I');
		}*/

		//--POINT2D_CLASS

		TEST_METHOD(testSet0Check0)
		{
			// TODO: Your test code here
			Point2D a, p2, p3;
			p2.x = 1.0f;
			p2.y = 3.0f;

			p3.x = 1.0f;
			p3.y = 3.0f;


			a.setZero();
			Assert::IsTrue(a.check0());

		}

		TEST_METHOD(testOperatorAddition)
		{
			Point2D a, p2, p3;
			p2.x = 2.0f;
			p2.y = 3.0f;

			p3.x = 4.0f;
			p3.y = 5.0f;

			a = p2.operator + (p3);

			Assert::AreEqual(a.x, 6.0f);
			Assert::AreEqual(a.y, 8.0f);
		}

		TEST_METHOD(testOperatorSubtract)
		{
			Point2D a, p2, p3;
			p2.x = 2.0f;
			p2.y = 3.0f;

			p3.x = 4.0f;
			p3.y = 5.0f;

			a = p2.operator - (p3);

			Assert::AreEqual(a.x, -2.0f);
			Assert::AreEqual(a.y, -2.0f);
		}

		TEST_METHOD(testOperatorAddEqual)
		{
			Point2D p2, p3;
			p2.x = 2.0f;
			p2.y = 3.0f;

			p3.x = 4.0f;
			p3.y = 5.0f;

			p2.operator += (p3);

			Assert::AreEqual(p2.x, 6.0f);
			Assert::AreEqual(p2.y, 8.0f);
		}

		TEST_METHOD(testOperatorSubtractEqual)
		{
			Point2D p2, p3;
			p2.x = 2.0f;
			p2.y = 3.0f;

			p3.x = 4.0f;
			p3.y = 5.0f;

			p2.operator -= (p3);

			Assert::AreEqual(p2.x, -2.0f);
			Assert::AreEqual(p2.y, -2.0f);
		}

		TEST_METHOD(testSame)
		{
			Point2D p2, p3;
			p2.x = 4.0f;
			p2.y = 5.0f;

			p3.x = 4.0f;
			p3.y = 5.0f;


			Assert::IsTrue(p2.operator == (p3));


		}

		TEST_METHOD(testNotSame)
		{
			Point2D p2, p3;
			p2.x = 2.0f;
			p2.y = 3.0f;

			p3.x = 4.0f;
			p3.y = 5.0f;


			Assert::IsTrue(p2.operator != (p3));
		}

		TEST_METHOD(testDistance)
		{
			Point2D punto, p2, p3, b;
			p2.x = 2.0f;
			p2.y = 3.0f;

			p3.x = 2.0f;
			p3.y = 4.0f;

			Assert::AreEqual(p2.distanceTo(p3), 1.0f);

		}

		//-- STRING_CLASS

		TEST_METHOD(Void)
		{
			stringClass str1;
			char* str2 = "";
			Assert::IsTrue(strcmp(str1.getString(), str2) == 0);
		}

		TEST_METHOD(Char)
		{
			stringClass str1("Hola Mundo");
			char* str2 = "Hola Mundo";
			Assert::IsTrue(strcmp(str1.getString(), str2) == 0);
		}

		TEST_METHOD(String)
		{
			stringClass str1("String por chars");
			stringClass str2(str1);
			Assert::IsTrue(strcmp(str1.getString(), str2.getString()) == 0);
		}

		TEST_METHOD(OpEqualChar)
		{
			stringClass str1("Hola Mundo");
			Assert::IsTrue(str1 == "Hola Mundo");
			Assert::IsFalse(str1 == "Diferente");
		}

		TEST_METHOD(OpEqualString)
		{
			stringClass str1("Hola Mundo");
			stringClass str2("Hola Mundo");
			stringClass str3("Diferente");
			Assert::IsTrue(str1 == str2);
			Assert::IsFalse(str1 == str3);
		}

		TEST_METHOD(OpDifferentChar)
		{
			stringClass str1("Hola Mundo");
			Assert::IsFalse(str1 != "Hola Mundo");
			Assert::IsTrue(str1 != "Diferente");
		}

		TEST_METHOD(OpDifferentString)
		{
			stringClass str1("Hola Mundo");
			stringClass str2("Hola Mundo");
			stringClass str3("Diferente");
			Assert::IsFalse(str1 != str2);
			Assert::IsTrue(str1 != str3);
		}

		TEST_METHOD(OpAssignChar)
		{
			stringClass str1("Valor Inicial");
			char* str2 = "Valor final";
			str1 = str2;
			Assert::IsTrue(strcmp(str1.getString(), str2) == 0);
		}

		TEST_METHOD(OpAssignString)
		{
			stringClass str1("Valor str1");
			stringClass str2("Valor str2");
			str1 = str2;
			Assert::IsTrue(strcmp(str1.getString(), str2.getString()) == 0);
		}

		TEST_METHOD(OpIncreaseChar)
		{
			stringClass str1("str1");
			str1 += "añadido";
			Assert::IsTrue(strcmp(str1.getString(), "str1añadido") == 0);
		}

		TEST_METHOD(OpIncreaseString)
		{
			stringClass str1("str1");
			stringClass str2("añadido");
			str1 += str2;
			Assert::IsTrue(strcmp(str1.getString(), "str1añadido") == 0);
		}

		TEST_METHOD(replace)
		{
			stringClass myString("Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live");

			myString.replace("live", "are");
			myString.replace("h", "");

			Assert::IsTrue(myString == "Always code as if te guy wo ends up maintaining your code will be a violent psycopat wo knows were you are");
		}

		TEST_METHOD(clear)
		{
			stringClass str1("Esto es el String");
			stringClass str2;
			str1.clear();
			Assert::IsTrue(strcmp(str1.getString(), str2.getString()) == 0);
		}

		TEST_METHOD(Len)
		{
			stringClass str1("Hola Mundo");
			Assert::IsTrue(str1.len() == 10);
		}

		TEST_METHOD(Capacity)
		{
			stringClass str1("Hola Mundo");
			Assert::IsTrue(str1.capacity() == 11);
		}

		TEST_METHOD(getString)
		{
			stringClass str1("Hola Mundo");
			Assert::IsTrue(strcmp(str1.getString(), str1.getString()) == 0);
		}

		//--DYNAMIC_ARRAY


		TEST_METHOD(bubbleSortOptimized)
		{
			dynArrayClass<int> array;

			array.push(5);
			array.push(4);
			array.push(1);
			array.push(2);
			array.push(8);
			array.push(9);
		
			
		

			int n = array.bubbleSortOptimized();

			Assert::AreEqual((int)n, 7);
			Assert::AreEqual((int)array[0], 1);
			Assert::AreEqual((int)array[1], 2);
			Assert::AreEqual((int)array[2], 4);
			Assert::AreEqual((int)array[3], 5);
			Assert::AreEqual((int)array[4], 8);
			Assert::AreEqual((int)array[5], 9);
		
			
		}



};
}