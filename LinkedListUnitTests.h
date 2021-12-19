#ifndef LINKEDLISTUNITTESTS_H_GUARD
#define LINKEDLISTUNITTESTS_H_GUARD

#include <list>
#include <vector>
#include <string>

struct LinkedListUnitTests
{
	static std::list<int> AddTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath);
	static std::list<int> RemoveTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath);
	static std::list<int> GetTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath);
	static std::list<int> AddRemoveImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static std::list<int> AddThenRemoveEverythingAdded(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static std::list<int> AddGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static std::list<int> AddGetImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static std::list<int> RemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static std::list<int> RemoveAddImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static std::list<int> RemoveThenAddEverythingRemoved(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);
	static std::list<int> AddRemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath);

};


#endif
