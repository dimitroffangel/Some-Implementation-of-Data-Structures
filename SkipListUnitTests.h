#ifndef SKIPLISTUNITTESTS_H_GUARD
#define SKIPLISTUNITTESTS_H_GUARD

#include "LinkedLists/SkipList.h"

struct SkipListUnitTests
{
	static SkipList<int> AddTest(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath);
	static SkipList<int> RemoveTest(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath);
	static SkipList<int> GetTest(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath);
	static SkipList<int> AddRemoveImmediately(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> AddThenRemoveEverythingAdded(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> AddGet(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> AddGetImmediately(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> RemoveGet(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> RemoveAddImmediately(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> RemoveThenAddEverythingRemoved(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> AddRemoveGet(size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
};



#endif