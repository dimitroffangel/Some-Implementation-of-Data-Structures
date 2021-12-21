#include "UnitTests.h"

#include "DataStructureHelper.h"
#include "SkipListOriginalUnitTests.h"
#include "SkipListUnitTests.h"
#include "VectorUnitTests.h"
#include "LinkedListUnitTests.h"
#include "RedBlackTreeUnitTests.h"

std::vector<int> UnitTests::GenerateSomeList(const size_t sizeOfLists, int from, int to)
{
	std::vector<int> result;

	for (size_t i = 0; i < sizeOfLists; ++i)
	{
		const int element = DataStructureHelper::GenerateRandomNumber(from, to);
		result.push_back(element);
	}

	return result;
}

void UnitTests::TestDataStructures()
{
	std::vector<int> elementsToAdd = GenerateSomeList(1000);
	std::vector<int> elementstoAdd2 = GenerateSomeList(1000);

	std::vector<std::vector<int>> subLists;
	const size_t sizeOfSubList = DataStructureHelper::GenerateRandomNumber(0, elementsToAdd.size());

	for (size_t i = 0; i < sizeOfSubList; ++i)
	{
		std::vector<int> subList;

		for (const int element : elementsToAdd)
		{
			size_t randomNumber = DataStructureHelper::GenerateRandomNumber(0, 100);

			if (randomNumber < 50)
			{
				subList.push_back(element);
			}
		}

		subLists.push_back(subList);
	}

	TestSkipListOriginal(elementsToAdd, subLists, elementstoAdd2);
	TestSkipList(elementsToAdd, subLists, elementstoAdd2);
	TestVectorList(elementsToAdd, subLists, elementstoAdd2);
	TestLinkedList(elementsToAdd, subLists, elementstoAdd2);
	TestRedBlackTree(elementsToAdd, subLists, elementstoAdd2);
}

void UnitTests::TestSkipListOriginal(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2)
{
	const std::string filePath = "./skipListTestsOriginal.txt";

	SkipListOriginalUnitTests::AddTest({}, elementsToAdd, filePath);

	SkipListOriginalUnitTests::GetTest(elementsToAdd, elementsToAdd, filePath);
	SkipListOriginalUnitTests::AddRemoveImmediately(elementsToAdd, elementsToAdd2, filePath);
	SkipListOriginalUnitTests::AddThenRemoveEverythingAdded(elementsToAdd, elementsToAdd2, filePath);
	SkipListOriginalUnitTests::AddGet(elementsToAdd, elementsToAdd2, filePath);
	SkipListOriginalUnitTests::AddGetImmediately(elementsToAdd, elementsToAdd2, filePath);
	SkipListOriginalUnitTests::AddRemoveGet(elementsToAdd, elementsToAdd2, filePath);

	for (size_t i = 0; i < subLists.size(); ++i)
	{
		SkipListOriginalUnitTests::RemoveTest(elementsToAdd, subLists[i], filePath);
		SkipListOriginalUnitTests::RemoveGet(elementsToAdd, subLists[i], filePath);
		SkipListOriginalUnitTests::RemoveThenAddEverythingRemoved(elementsToAdd, subLists[i], filePath);
	}

}

void UnitTests::TestSkipList(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2)
{
	const std::string filePath = "./skipListTests.txt";

	SkipListUnitTests::AddTest({}, elementsToAdd, filePath);
	
	SkipListUnitTests::GetTest(elementsToAdd, elementsToAdd, filePath);
	SkipListUnitTests::AddRemoveImmediately(elementsToAdd, elementsToAdd2, filePath);
	SkipListUnitTests::AddThenRemoveEverythingAdded(elementsToAdd, elementsToAdd2, filePath);
	SkipListUnitTests::AddGet(elementsToAdd, elementsToAdd2, filePath);
	SkipListUnitTests::AddGetImmediately(elementsToAdd, elementsToAdd2, filePath);
	SkipListUnitTests::AddRemoveGet(elementsToAdd, elementsToAdd2, filePath);

	for (size_t i = 0; i < subLists.size(); ++i)
	{
		SkipListUnitTests::RemoveTest(elementsToAdd, subLists[i], filePath);
		SkipListUnitTests::RemoveGet(elementsToAdd, subLists[i], filePath);
		SkipListUnitTests::RemoveThenAddEverythingRemoved(elementsToAdd, subLists[i], filePath);
	}

}

void UnitTests::TestVectorList(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2)
{
	const std::string filePath = "./vectorListTests.txt";

	VectorUnitTests::AddTest({}, elementsToAdd, filePath);


	VectorUnitTests::GetTest(elementsToAdd, elementsToAdd, filePath);
	VectorUnitTests::AddRemoveImmediately(elementsToAdd, elementsToAdd2, filePath);
	VectorUnitTests::AddThenRemoveEverythingAdded(elementsToAdd, elementsToAdd2, filePath);
	VectorUnitTests::AddGet(elementsToAdd, elementsToAdd2, filePath);
	VectorUnitTests::AddGetImmediately(elementsToAdd, elementsToAdd2, filePath);
	VectorUnitTests::AddRemoveGet(elementsToAdd, elementsToAdd2, filePath);

	for (size_t i = 0; i < subLists.size(); ++i)
	{
		VectorUnitTests::RemoveTest(elementsToAdd, subLists[i], filePath);
		VectorUnitTests::RemoveGet(elementsToAdd, subLists[i], filePath);
		VectorUnitTests::RemoveThenAddEverythingRemoved(elementsToAdd, subLists[i], filePath);
	}
}

void UnitTests::TestLinkedList(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2)
{
	const std::string filePath = "./linkedListTests.txt";

	LinkedListUnitTests::AddTest({}, elementsToAdd, filePath);


	LinkedListUnitTests::GetTest(elementsToAdd, elementsToAdd, filePath);
	LinkedListUnitTests::AddRemoveImmediately(elementsToAdd, elementsToAdd2, filePath);
	LinkedListUnitTests::AddThenRemoveEverythingAdded(elementsToAdd, elementsToAdd2, filePath);
	LinkedListUnitTests::AddGet(elementsToAdd, elementsToAdd2, filePath);
	LinkedListUnitTests::AddGetImmediately(elementsToAdd, elementsToAdd2, filePath);
	LinkedListUnitTests::AddRemoveGet(elementsToAdd, elementsToAdd2, filePath);

	for (size_t i = 0; i < subLists.size(); ++i)
	{
		LinkedListUnitTests::RemoveTest(elementsToAdd, subLists[i], filePath);
		LinkedListUnitTests::RemoveGet(elementsToAdd, subLists[i], filePath);
		LinkedListUnitTests::RemoveThenAddEverythingRemoved(elementsToAdd, subLists[i], filePath);
	}
}

void UnitTests::TestRedBlackTree(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2)
{
	const std::string filePath = "./redBlackTreeTests.txt";

	RedBlackTreeUnitTests::AddTest({}, elementsToAdd, filePath);

	RedBlackTreeUnitTests::GetTest(elementsToAdd, elementsToAdd, filePath);
	RedBlackTreeUnitTests::AddRemoveImmediately(elementsToAdd, elementsToAdd2, filePath);
	RedBlackTreeUnitTests::AddThenRemoveEverythingAdded(elementsToAdd, elementsToAdd2, filePath);
	RedBlackTreeUnitTests::AddGet(elementsToAdd, elementsToAdd2, filePath);
	RedBlackTreeUnitTests::AddGetImmediately(elementsToAdd, elementsToAdd2, filePath);
	RedBlackTreeUnitTests::AddRemoveGet(elementsToAdd, elementsToAdd2, filePath);

	for (size_t i = 0; i < subLists.size(); ++i)
	{
		RedBlackTreeUnitTests::RemoveTest(elementsToAdd, subLists[i], filePath);
		RedBlackTreeUnitTests::RemoveGet(elementsToAdd, subLists[i], filePath);
		RedBlackTreeUnitTests::RemoveThenAddEverythingRemoved(elementsToAdd, subLists[i], filePath);
	}
}