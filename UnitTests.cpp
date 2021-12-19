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

void UnitTests::TestSkipList()
{
	std::vector<int> elementsToAdd = GenerateSomeList(1000);

	SkipListUnitTests::AddTest({}, elementsToAdd);
	SkipListUnitTests::GetTest(elementsToAdd, elementsToAdd);
	SkipListUnitTests::RemoveTest(elementsToAdd, elementsToAdd);
	SkipListUnitTests::AddGetImmediately(elementsToAdd, elementsToAdd);
	SkipListUnitTests::AddGet(elementsToAdd, elementsToAdd);
	

}
