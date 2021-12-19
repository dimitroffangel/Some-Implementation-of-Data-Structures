#include "RedBlackTreeUnitTests.h"

#include "RedBlackTreeUnitTests.h"

#include <chrono>
#include <fstream>
#include <iostream>

std::map<int, int> RedBlackTreeUnitTests::AddTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToAdd, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "RedBlackTreeUnitTests::AddTest: ";
	outputFile << "RedBlackTreeUnitTests::AddTest: ";

	std::map<int, int> redBlackTree;

	for (const int elementToHave : elementsToHaveInitially)
	{
		redBlackTree[elementToHave] = elementToHave;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToAdd)
	{
		redBlackTree[elementToAdd] = elementToAdd;
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return redBlackTree;
}

std::map<int, int> RedBlackTreeUnitTests::RemoveTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToRemove, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "RedBlackTreeUnitTests::RemoveTest: ";
	outputFile << "RedBlackTreeUnitTests::RemoveTest: ";

	std::map<int, int> redBlackTree;

	for (const int elementToHave : elementsToHaveInitially)
	{
		redBlackTree[elementToHave] = elementToHave;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToRemove)
	{
		std::map<int, int>::iterator it = redBlackTree.find(elementToAdd);

		if (it == redBlackTree.end())
		{
			continue;
		}

		redBlackTree.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return redBlackTree;
}

std::map<int, int> RedBlackTreeUnitTests::GetTest(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& elementsToGet, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "RedBlackTreeUnitTests::GetTest: ";
	outputFile << "RedBlackTreeUnitTests::GetTest: ";

	std::map<int, int> redBlackTree;

	for (const int elementToHave : elementsToHaveInitially)
	{
		redBlackTree[elementToHave] = elementToHave;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : elementsToGet)
	{
		std::map<int, int>::iterator it = redBlackTree.find(elementToAdd);

		if (it == redBlackTree.end())
		{
			continue;
		}

		//redBlackTree.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return redBlackTree;
}

std::map<int, int> RedBlackTreeUnitTests::AddRemoveImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "RedBlackTreeUnitTests::AddRemoveImmediately: ";
	outputFile << "RedBlackTreeUnitTests::AddRemoveImmediately: ";

	std::map<int, int> redBlackTree;

	for (const int elementToHave : elementsToHaveInitially)
	{
		redBlackTree[elementToHave] = elementToHave;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		redBlackTree[elementToAdd] = elementToAdd;

		std::map<int, int>::iterator it = redBlackTree.find(elementToAdd);

		if (it == redBlackTree.end())
		{
			continue;
		}

		redBlackTree.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return redBlackTree;
}

std::map<int, int> RedBlackTreeUnitTests::AddThenRemoveEverythingAdded(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "RedBlackTreeUnitTests::AddThenRemoveEverythingAdded: ";
	outputFile << "RedBlackTreeUnitTests::AddThenRemoveEverythingAdded: ";

	std::map<int, int> redBlackTree;

	for (const int elementToHave : elementsToHaveInitially)
	{
		redBlackTree[elementToHave] = elementToHave;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		redBlackTree[elementToAdd] = elementToAdd;
	}

	for (const int elementToAdd : inputContainer)
	{

		std::map<int, int>::iterator it = redBlackTree.find(elementToAdd);

		if (it == redBlackTree.end())
		{
			continue;
		}

		redBlackTree.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return redBlackTree;
}

std::map<int, int> RedBlackTreeUnitTests::AddGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "RedBlackTreeUnitTests::AddGet: ";
	outputFile << "RedBlackTreeUnitTests::AddGet: ";

	std::map<int, int> redBlackTree;

	for (const int elementToHave : elementsToHaveInitially)
	{
		redBlackTree[elementToHave] = elementToHave;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		redBlackTree[elementToAdd] = elementToAdd;
	}

	for (const int elementToAdd : inputContainer)
	{
		std::map<int, int>::iterator it = redBlackTree.find(elementToAdd);

		if (it == redBlackTree.end())
		{
			continue;
		}

		//redBlackTree.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return redBlackTree;
}

std::map<int, int> RedBlackTreeUnitTests::AddGetImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "RedBlackTreeUnitTests::AddGetImmediately: ";
	outputFile << "RedBlackTreeUnitTests::AddGetImmediately: ";

	std::map<int, int> redBlackTree;
	
	for (const int elementToHave : elementsToHaveInitially)
	{
		redBlackTree[elementToHave] = elementToHave;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		redBlackTree[elementToAdd] = elementToAdd;

		std::map<int, int>::iterator it = redBlackTree.find(elementToAdd);

		if (it == redBlackTree.end())
		{
			continue;
		}

		//redBlackTree.Contains(elementToAdd);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return redBlackTree;
}

std::map<int, int> RedBlackTreeUnitTests::RemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "RedBlackTreeUnitTests::RemoveGet: ";
	outputFile << "RedBlackTreeUnitTests::RemoveGet: ";

	std::map<int, int> redBlackTree;

	for (const int elementToHave : elementsToHaveInitially)
	{
		redBlackTree[elementToHave] = elementToHave;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		//redBlackTree.Contains(elementToAdd);

		std::map<int, int>::iterator it = redBlackTree.find(elementToAdd);
		
		if (it == redBlackTree.end())
		{
			continue;
		}

		redBlackTree.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return redBlackTree;

}

std::map<int, int> RedBlackTreeUnitTests::RemoveAddImmediately(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "RedBlackTreeUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "RedBlackTreeUnitTests::RemoveThenAddEverythingRemoved: ";

	std::map<int, int> redBlackTree;

	for (const int elementToHave : elementsToHaveInitially)
	{
		redBlackTree[elementToHave] = elementToHave;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		std::map<int, int>::iterator it = redBlackTree.find(elementToAdd);

		if (it == redBlackTree.end())
		{
			continue;
		}

		redBlackTree.erase(it);

		redBlackTree[elementToAdd] = elementToAdd;
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return redBlackTree;
}

std::map<int, int> RedBlackTreeUnitTests::RemoveThenAddEverythingRemoved(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "RedBlackTreeUnitTests::RemoveThenAddEverythingRemoved: ";
	outputFile << "RedBlackTreeUnitTests::RemoveThenAddEverythingRemoved: ";

	std::map<int, int> redBlackTree;

	for (const int elementToHave : elementsToHaveInitially)
	{
		redBlackTree[elementToHave] = elementToHave;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{

		std::map<int, int>::iterator it = redBlackTree.find(elementToAdd);

		if (it == redBlackTree.end())
		{
			continue;
		}

		redBlackTree.erase(it);
	}

	for (const int elementToAdd : inputContainer)
	{
		redBlackTree[elementToAdd] = elementToAdd;
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return redBlackTree;
}

std::map<int, int> RedBlackTreeUnitTests::AddRemoveGet(const std::vector<int>& elementsToHaveInitially, const std::vector<int>& inputContainer, const std::string& filePath)
{
	std::ofstream outputFile(filePath, std::ofstream::app);
	std::cout << "RedBlackTreeUnitTests::AddRemoveGet: ";
	outputFile << "RedBlackTreeUnitTests::AddRemoveGet: ";

	std::map<int, int> redBlackTree;
	
	for (const int elementToHave : elementsToHaveInitially)
	{
		redBlackTree[elementToHave] = elementToHave;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for (const int elementToAdd : inputContainer)
	{
		redBlackTree[elementToAdd] = elementToAdd;
	}

	for (const int elementToAdd : inputContainer)
	{
		std::map<int, int>::iterator it = redBlackTree.find(elementToAdd);

		if (it == redBlackTree.end())
		{
			continue;
		}

		//redBlackTree.Contains(elementToAdd);
	}

	for (const int elementToAdd : inputContainer)
	{

		std::map<int, int>::iterator it = redBlackTree.find(elementToAdd);

		if (it == redBlackTree.end())
		{
			continue;
		}

		redBlackTree.erase(it);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';
	outputFile << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << '\n';

	return redBlackTree;
}
