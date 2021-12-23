#include "UnitTests.h"

#include "DataStructureHelper.h"
#include "SkipListOriginalUnitTests.h"
#include "SkipListUnitTests.h"
#include "VectorUnitTests.h"
#include "LinkedListUnitTests.h"
#include "RedBlackTreeUnitTests.h"
#include "AVLTreeUnitTests.h"
#include "XORListUnitTests.h"

std::vector<int> UnitTests::GenerateIncreasingList(const size_t sizeOfLists, int from, int to)
{
	std::vector<int> result;

	const int initialElement = DataStructureHelper::GenerateRandomNumber(from, to);
	result.push_back(initialElement);

	for (size_t i = 1; i < sizeOfLists; ++i)
	{
		const int element = DataStructureHelper::GenerateRandomNumber(result[i - 1], to);
		result.push_back(element);
	}

	return result;
}

std::vector<int> UnitTests::GenerateDecreasingList(const size_t sizeOfLists, int from, int to)
{
	std::vector<int> result;

	const int initialElement = DataStructureHelper::GenerateRandomNumber(from, to);
	result.push_back(initialElement);

	for (size_t i = 1; i < sizeOfLists; ++i)
	{
		const int element = DataStructureHelper::GenerateRandomNumber(from, result[i - 1]);
		result.push_back(element);
	}

	return result;
}

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

std::vector<int> UnitTests::GenerateIncreasingDecreasingList(const size_t sizeOfLists, int from, int to)
{
	std::vector<int> result;

	const int initialElement = DataStructureHelper::GenerateRandomNumber(from, to);
	result.push_back(initialElement);
	
	for (size_t i = 1; i < sizeOfLists; ++i)
	{
		
		if (i % 2 == 0)
		{
			const int element = DataStructureHelper::GenerateRandomNumber(from, result[i - 1]);
			result.push_back(element);
		}

		else
		{
			const int element = DataStructureHelper::GenerateRandomNumber(result[i - 1], to);
			result.push_back(element);
		}
		
	}

	return result;
}

void UnitTests::TestDataStructures()
{
	std::vector<int> elementsToAdd = GenerateIncreasingList(10000);
	std::vector<int> elementstoAdd2 = GenerateIncreasingList(10000);

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

	//TestSkipListOriginal(50, elementsToAdd, subLists, elementstoAdd2);
	//TestSkipList(50, elementsToAdd, subLists, elementstoAdd2);
	TestSkipList(75, elementsToAdd, subLists, elementstoAdd2);
	TestVectorList(elementsToAdd, subLists, elementstoAdd2);
	TestLinkedList(elementsToAdd, subLists, elementstoAdd2);
	TestXORList(elementsToAdd, subLists, elementstoAdd2);
	TestRedBlackTree(elementsToAdd, subLists, elementstoAdd2);
	//TestAVLTree(elementsToAdd, subLists, elementstoAdd2);
}

void UnitTests::TestSkipListOriginal(const size_t probability, const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2)
{
	const std::string filePath = "./skipListTestsOriginal.txt";

	SkipListOriginalUnitTests::AddTest(probability, {}, elementsToAdd, filePath);

	SkipListOriginalUnitTests::GetTest(probability, elementsToAdd, elementsToAdd, filePath);
	SkipListOriginalUnitTests::AddRemoveImmediately(probability,elementsToAdd, elementsToAdd2, filePath);
	SkipListOriginalUnitTests::AddThenRemoveEverythingAdded(probability,elementsToAdd, elementsToAdd2, filePath);
	SkipListOriginalUnitTests::AddGet(probability, elementsToAdd, elementsToAdd2, filePath);
	SkipListOriginalUnitTests::AddGetImmediately(probability, elementsToAdd, elementsToAdd2, filePath);
	SkipListOriginalUnitTests::AddRemoveGet(probability,elementsToAdd, elementsToAdd2, filePath);

	for (size_t i = 0; i < subLists.size(); ++i)
	{
		SkipListOriginalUnitTests::RemoveTest(probability, elementsToAdd, subLists[i], filePath);
		SkipListOriginalUnitTests::RemoveGet(probability, elementsToAdd, subLists[i], filePath);
		SkipListOriginalUnitTests::RemoveThenAddEverythingRemoved(probability, elementsToAdd, subLists[i], filePath);
	}

}

void UnitTests::TestSkipList(size_t probability, const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2)
{
	const std::string filePath = "./skipListTests.txt";

	SkipListUnitTests::AddTest(probability, {}, elementsToAdd, filePath);
	
	SkipListUnitTests::GetTest(probability, elementsToAdd, elementsToAdd, filePath);
	SkipListUnitTests::AddRemoveImmediately(probability, elementsToAdd, elementsToAdd2, filePath);
	SkipListUnitTests::AddThenRemoveEverythingAdded(probability, elementsToAdd, elementsToAdd2, filePath);
	SkipListUnitTests::AddGet(probability, elementsToAdd, elementsToAdd2, filePath);
	SkipListUnitTests::AddGetImmediately(probability, elementsToAdd, elementsToAdd2, filePath);
	SkipListUnitTests::AddRemoveGet(probability, elementsToAdd, elementsToAdd2, filePath);

	for (size_t i = 0; i < subLists.size(); ++i)
	{
		SkipListUnitTests::RemoveTest(probability, elementsToAdd, subLists[i], filePath);
		SkipListUnitTests::RemoveGet(probability, elementsToAdd, subLists[i], filePath);
		SkipListUnitTests::RemoveThenAddEverythingRemoved(probability, elementsToAdd, subLists[i], filePath);
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

void UnitTests::TestXORList(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2)
{
	const std::string filePath = "./xorListTests.txt";

	XORListUnitTests::AddTest({}, elementsToAdd, filePath);


	XORListUnitTests::GetTest(elementsToAdd, elementsToAdd, filePath);
	XORListUnitTests::AddRemoveImmediately(elementsToAdd, elementsToAdd2, filePath);
	XORListUnitTests::AddThenRemoveEverythingAdded(elementsToAdd, elementsToAdd2, filePath);
	XORListUnitTests::AddGet(elementsToAdd, elementsToAdd2, filePath);
	XORListUnitTests::AddGetImmediately(elementsToAdd, elementsToAdd2, filePath);
	XORListUnitTests::AddRemoveGet(elementsToAdd, elementsToAdd2, filePath);

	for (size_t i = 0; i < subLists.size(); ++i)
	{
		XORListUnitTests::RemoveTest(elementsToAdd, subLists[i], filePath);
		XORListUnitTests::RemoveGet(elementsToAdd, subLists[i], filePath);
		XORListUnitTests::RemoveThenAddEverythingRemoved(elementsToAdd, subLists[i], filePath);
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

void UnitTests::TestAVLTree(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2)
{
	const std::string filePath = "./avlTreeTests.txt";

	AVLTreeUnitTests::AddTest({}, elementsToAdd, filePath);

	AVLTreeUnitTests::GetTest(elementsToAdd, elementsToAdd, filePath);
	AVLTreeUnitTests::AddRemoveImmediately(elementsToAdd, elementsToAdd2, filePath);
	AVLTreeUnitTests::AddThenRemoveEverythingAdded(elementsToAdd, elementsToAdd2, filePath);
	AVLTreeUnitTests::AddGet(elementsToAdd, elementsToAdd2, filePath);
	AVLTreeUnitTests::AddGetImmediately(elementsToAdd, elementsToAdd2, filePath);
	AVLTreeUnitTests::AddRemoveGet(elementsToAdd, elementsToAdd2, filePath);

	for (size_t i = 0; i < subLists.size(); ++i)
	{
		AVLTreeUnitTests::RemoveTest(elementsToAdd, subLists[i], filePath);
		AVLTreeUnitTests::RemoveGet(elementsToAdd, subLists[i], filePath);
		AVLTreeUnitTests::RemoveThenAddEverythingRemoved(elementsToAdd, subLists[i], filePath);
	}
}
