#ifndef UNITTESTS_H_GUARD
#define UNITTESTS_H_GUARD

#include <vector>

struct UnitTests
{
	static const size_t FROM_RANDOM_INTERVAL = 0;
	static const size_t TO_RANDOM_INTERVAL = 1000000000;

	static std::vector<int> GenerateIncreasingList(const size_t sizeOfLists, int from = FROM_RANDOM_INTERVAL, int to = TO_RANDOM_INTERVAL);
	static std::vector<int> GenerateDecreasingList(const size_t sizeOfLists, int from = FROM_RANDOM_INTERVAL, int to = TO_RANDOM_INTERVAL);
	static std::vector<int> GenerateSomeList(const size_t sizeOfLists, int from = FROM_RANDOM_INTERVAL, int to = TO_RANDOM_INTERVAL);
	static std::vector<int> GenerateIncreasingDecreasingList(const size_t sizeOfLists, int from = FROM_RANDOM_INTERVAL, int to = TO_RANDOM_INTERVAL);

	static void TestDataStructures();
	
	static void TestSkipListOriginal(size_t probability, const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2);
	static void TestSkipList(size_t probability, const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2);
	static void TestVectorList(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2);
	static void TestLinkedList(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2);
	static void TestXORList(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2);
	static void TestRedBlackTree(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2);
	static void TestAVLTree(const std::vector<int>& elementsToAdd, const std::vector<std::vector<int>>& subLists, const std::vector<int>& elementsToAdd2);
};

#endif

