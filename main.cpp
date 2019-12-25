#include <iostream>
#include "XORList.h"

int main()
{
	XORLIST<int> list;


	list.Prepend(1);
	list.Prepend(0);
	list.Append(2);
	list.InsertAfter(list.GetBegin(), 5);
	list.InsertAfter(list.GetEnd(), 62);
	//list.InsertBefore(list.GetBegin(), -42);
	//list.InsertBefore(list.GetEnd(), 42);

	auto res = list.GetNextNode(list.GetEnd());

	list.PrintFromStart();

	list.InsertAfter(res, 72);
	list.InsertBefore(res, 32);

	list.PrintFromStart();

	XORLIST<int> list2 = list;

	list2.Prepend(112123);

	return 0;
}