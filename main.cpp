//#include "./LinkedLists/XORList.h"
#include "Trees/AVLTree.h"
#include "LinkedLists/SkipList.h"
#include "UnitTests.h"

//void TestXORList()
//{
//	XORList<int> list = { -20, 42, -19, -18 };
//
//	list.InsertBefore(list.GetBegin(), 42);
//	list.InsertBefore(list.GetEnd(), 42);
//
//	list.PrintFromStart();
//
//	const XORList<int> list2 = { 9, 81, 243, 81, 1764 };
//
//	//XORList<int> res = list + list2;
//
//	//list += list2;
//
//	auto res = list2.GetNextNode(list2.GetBegin());
//
//	auto list3 = list2.GetAllNodes(81);
//	//list.JoinTwoXORLists(list2);
//
//	list2.PrintFromStart();
//
//	//list.PrintFromStart();
//
//	//list.InsertAfter(res, 72);
//	//list.InsertBefore(res, 32);
//
//	//list.PrintFromStart();
//
//	//XORList<int> list2 = list.GetAllNodes(42);
//	//
//	//list.PrintFromStart();
//
//	//list2.PrintFromStart();
//
//	//list2.Prepend(112123);
//
//	//list2.PrintFromStart();
//}

void TestSkipList()
{
	SkipList<int> fooList(2, 50);

	for (size_t i = 3; i <= 10; ++i)
	{
		fooList.Add(i);
	}

	for (size_t i = 1; i <= 5; ++i)
	{
		fooList.Add(2);
	}

	fooList.Print();
}

int main()
{
	UnitTests::TestDataStructures();

	//TestSkipList();



	//AVLTree<int> tree;

	//tree.AddNode(1);
	//tree.AddNode(2);
	//tree.AddNode(3);
	//tree.AddNode(4);
	//tree.AddNode(5);
	//tree.AddNode(6);
	//tree.AddNode(7);
	//tree.AddNode(-5);


	//tree.DeleteNode(4);
	//tree.Print();
	//tree.DeleteNode(7);
	//tree.DeleteNode(6);

	//tree.AddNode(-5);

	return 0;
}