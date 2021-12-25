#ifndef SKIPLISTUNITTESTS_H_GUARD
#define SKIPLISTUNITTESTS_H_GUARD

#include "LinkedLists/SkipList.h"

struct SkipListUnitTests
{
	static void AddTest(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath);
	static void RemoveTest(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath);
	static void GetTest(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath);
	static void AddRemoveImmediately(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void AddThenRemoveEverythingAdded(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void AddGet(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void AddGetImmediately(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void RemoveGet(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void RemoveAddImmediately(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void RemoveThenAddEverythingRemoved(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void AddRemoveGet(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
};



#endif