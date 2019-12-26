#include <iostream>
#include "XORList.h"

int main()
{
	XORLIST<int> list = { -20, 42, -19, -18 };
	
	list.InsertBefore(list.GetBegin(), 42);
	list.InsertBefore(list.GetEnd(), 42);

	list.PrintFromStart();

	const XORLIST<int> list2 = { 9, 81, 243, 81, 1764 };


	//XORLIST<int> res = list + list2;

	//list += list2;

	auto res = list2.GetNextNode(list2.GetBegin());

	auto list3 = list2.GetAllNodes(81);
	//list.JoinTwoXORLists(list2);

	list2.PrintFromStart();

	//list.PrintFromStart();

	//list.InsertAfter(res, 72);
	//list.InsertBefore(res, 32);

	//list.PrintFromStart();

	//XORLIST<int> list2 = list.GetAllNodes(42);
	//
	//list.PrintFromStart();

	//list2.PrintFromStart();

	//list2.Prepend(112123);

	//list2.PrintFromStart();

	return 0;
}