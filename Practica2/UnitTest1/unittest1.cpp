#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\Practica2\ListClass.h"
#include"..\Practica2\StackClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		//-- ListClass

		TEST_METHOD(ListClassAdd)
		{
			listClass<int> mylist;
			Assert::AreEqual((int)mylist.add(5), 1);
		}

		TEST_METHOD(ListClassDel)
		{
			listClass<int> mylist;
			mylist.add(5);
			Assert::IsTrue(mylist.del(mylist.start));
			Assert::AreEqual((int)mylist.getSize(), 0);
		}

		TEST_METHOD(ListClassClear)
		{
			listClass<int> mylist;
			mylist.add(1); mylist.add(2); mylist.add(3);
			mylist.clear();
			Assert::AreEqual((int)mylist.getSize(), 0);
		}

		TEST_METHOD(ListClassOpBrk)
		{
			listClass<int> mylist;
			mylist.add(5);
			Assert::AreEqual(mylist[0], 5);
		}

		//-- StackClass

		TEST_METHOD(Stack_test)
		{
			stackClass<int> lifo;

			lifo.push(10);
			lifo.push(20);
			lifo.push(30);
			lifo.push(40);

			Assert::AreEqual((int)lifo.getElements(), 4);
			Assert::AreEqual((int)*(lifo.Peek(1)), 20);

			int result;
			bool r = lifo.pop(result);

			Assert::AreEqual((int)result, 40);
			Assert::AreEqual((int)lifo.getElements(), 3);
		}





	};
}