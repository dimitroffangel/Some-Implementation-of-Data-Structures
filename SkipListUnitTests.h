#ifndef SKIPLISTUNITTESTS_H_GUARD
#define SKIPLISTUNITTESTS_H_GUARD

#include "LinkedLists/SkipList.h"

struct SkipListUnitTests
{
	static SkipList<int> AddTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd);
	static SkipList<int> RemoveTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove);
	static SkipList<int> GetTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet);
	static SkipList<int> AddRemoveImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer);
	static SkipList<int> AddThenRemoveEverythingAdded(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer);
	static SkipList<int> AddGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer);
	static SkipList<int> AddGetImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer);
	static SkipList<int> RemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer);
	static SkipList<int> RemoveAddImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer);
	static SkipList<int> RemoveThenAddEverythingRemoved(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer);
	static SkipList<int> AddRemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer);
};



#endif