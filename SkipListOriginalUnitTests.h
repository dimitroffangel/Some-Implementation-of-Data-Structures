#ifndef SKIPLISTORIGNALUNITTESTS_H_GUARD
#define SKIPLISTORIGNALUNITTESTS_H_GUARD

#include "SkipListOriginal.h"

struct  SkipListOriginalUnitTests
{
	static SkipListOriginal<int> AddTest(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath);
	static SkipListOriginal<int> RemoveTest(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath);
	static SkipListOriginal<int> GetTest(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath);
	static SkipListOriginal<int> AddRemoveImmediately(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipListOriginal<int> AddThenRemoveEverythingAdded(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipListOriginal<int> AddGet(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipListOriginal<int> AddGetImmediately(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipListOriginal<int> RemoveGet(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipListOriginal<int> RemoveAddImmediately(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipListOriginal<int> RemoveThenAddEverythingRemoved(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static SkipListOriginal<int> AddRemoveGet(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
};

#endif