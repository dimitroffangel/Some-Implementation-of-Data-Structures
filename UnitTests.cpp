#include "UnitTests.h"

#include "DataStructureHelper.h"
#include "SkipListUnitTests.h"

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

	TestSkipList(elementsToAdd, subLists, elementstoAdd2);
}

void UnitTests::TestSkipList(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2)
{
	SkipListUnitTests::AddTest({}, elementsToAdd, "./skipListTests.txt");


	SkipListUnitTests::GetTest(elementsToAdd, elementsToAdd, "./skipListTests.txt");
	SkipListUnitTests::AddRemoveImmediately(elementsToAdd, elementsToAdd2, "./skipListTests.txt");
	SkipListUnitTests::AddThenRemoveEverythingAdded(elementsToAdd, elementsToAdd2, "./skipListTests.txt");
	SkipListUnitTests::AddGet(elementsToAdd, elementsToAdd2, "./skipListTests.txt");
	SkipListUnitTests::AddGetImmediately(elementsToAdd, elementsToAdd2, "./skipListTests.txt");
	SkipListUnitTests::AddRemoveGet(elementsToAdd, elementsToAdd2, "./skipListTests.txt");

	for (size_t i = 0; i < subLists.size(); ++i)
	{
		SkipListUnitTests::RemoveTest(elementsToAdd, subLists[i], "./skipListTests.txt");
		SkipListUnitTests::RemoveGet(elementsToAdd, subLists[i], "./skipListTests.txt");
		SkipListUnitTests::RemoveThenAddEverythingRemoved(elementsToAdd, subLists[i], "./skipListTests.txt");
	}

}
