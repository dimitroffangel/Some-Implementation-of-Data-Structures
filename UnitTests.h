#ifndef UNITTESTS_H_GUARD
#define UNITTESTS_H_GUARD

#include <vector>

struct UnitTests
{
	static const size_t FROM_RANDOM_INTERVAL = 0;
	static const size_t TO_RANDOM_INTERVAL = 1000000000;

	static std::vector<int> GenerateIncreasingList(const size_t sizeOfLists, int from = FROM_RANDOM_INTERVAL, int to = TO_RANDOM_INTERVAL);
	static std::vector<int> GenerateDecreasingList(const size_t sizeOfLists);
	static std::vector<int> GenerateSomeList(const size_t sizeOfLists, int from = FROM_RANDOM_INTERVAL, int to = TO_RANDOM_INTERVAL);
	// for each ai in list ai <= a(i+1) && ai >= a(i-1) for existent adjacent elements
	static std::vector<int> GenerateIncreasingDecreasingList(const size_t sizeOfLists);

	static void TestDataStructures();

	static void TestSkipList(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2);
	static void TestVectorList(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2);
};

#endif

