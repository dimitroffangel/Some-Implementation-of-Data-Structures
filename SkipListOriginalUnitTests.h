#ifndef SKIPLISTORIGNALUNITTESTS_H_GUARD
#define SKIPLISTORIGNALUNITTESTS_H_GUARD

#include "SkipListOriginal.h"

struct  SkipListOriginalUnitTests
{
	static void AddTest(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath);
	static void RemoveTest(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath);
	static void GetTest(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath);
	static void AddRemoveImmediately(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void AddThenRemoveEverythingAdded(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void AddGet(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void AddGetImmediately(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void RemoveGet(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void RemoveAddImmediately(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void RemoveThenAddEverythingRemoved(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static void AddRemoveGet(const size_t probability, const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
};

#endif