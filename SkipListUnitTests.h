#ifndef SKIPLISTUNITTESTS_H_GUARD
#define SKIPLISTUNITTESTS_H_GUARD

#include "LinkedLists/SkipList.h"

struct SkipListUnitTests
{
	static SkipList<int> AddTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath);
	static SkipList<int> RemoveTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath);
	static SkipList<int> GetTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath);
	static SkipList<int> AddRemoveImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> AddThenRemoveEverythingAdded(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> AddGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> AddGetImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> RemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> RemoveAddImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> RemoveThenAddEverythingRemoved(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipList<int> AddRemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
};



#endif